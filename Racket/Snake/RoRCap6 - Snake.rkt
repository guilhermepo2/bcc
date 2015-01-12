#lang racket

(require 2htdp/image 2htdp/universe)


;; -------------------------------------------
;; Definições de Dados

(struct pit (snake goos) #:transparent)
(struct snake (dir segs) #:transparent)
(struct posn (x y) #:transparent)
(struct goo (loc expire) #:transparent)
;; -------------------------------------------

;; CONSTANTES
;; Tick Rate 
(define TICK-RATE 1/10)

;; Board Size Constants
(define SIZE 30)

;; Snake Constants
(define SEG-SIZE 15)

;; Goo Constants
(define MAX-GOO 5)
(define EXPIRATION-TIME 150)

;; GRAPHICAL BOARD
(define WIDTH-PX  (* SEG-SIZE 30))
(define HEIGHT-PX (* SEG-SIZE 30))

;; Visual constants
(define MT-SCENE (empty-scene WIDTH-PX HEIGHT-PX))
(define GOO-IMG (bitmap "graphics/goo.gif"))
(define SEG-IMG  (bitmap "graphics/body.gif"))
(define HEAD-IMG (bitmap "graphics/head.gif"))

(define HEAD-LEFT-IMG HEAD-IMG)
(define HEAD-DOWN-IMG (rotate 90 HEAD-LEFT-IMG))
(define HEAD-RIGHT-IMG (flip-horizontal HEAD-LEFT-IMG))
(define HEAD-UP-IMG (flip-vertical HEAD-DOWN-IMG))

(define ENDGAME-TEXT-SIZE 15)

;; -------------------------------------------
;; ROTTING GOO

;; Age-goo
(define (age-goo goos)
  (rot (renew goos)))
;; Rot Goos
(define (rot goos)
  (cond [(empty? goos) empty]
        [else (cons (decay (first goos)) (rot (rest goos)))]))

;;
(define (decay g)
  (goo (goo-loc g) (sub1 (goo-expire g))))

;; Renovar 'goos'
(define (renew goos)
  (cond [(empty? goos) empty]
        [(rotten? (first goos))
         (cons (fresh-goo) (renew (rest goos)))]
        [else
         (cons (first goos) (renew (rest goos)))]))

;; 'Rotten?' -> detecta qual 'goo' deve ser substituida
(define (rotten? g)
  (zero? (goo-expire g)))

;; 'Fresh-goos' - > cria aleatoriamente um novo 'goo'
(define (fresh-goo)
  (goo (posn (add1 (random (sub1 SIZE)))
             (add1 (random (sub1 SIZE))))
       EXPIRATION-TIME))
;; -------------------------------------------
;;Movimentando
;; Função para mover posições
(define (posn-move p dx dy)
  (posn (+ (posn-x p) dx)
        (+ (posn-y p) dy)))

;;Função next-head -> responsavel por movimentar a cobra
(define (next-head sn)
  (define head (snake-head sn))
  (define dir (snake-dir sn))
  (cond [(string=? dir "up") (posn-move head 0 -1)]
        [(string=? dir "down") (posn-move head 0 1)]
        [(string=? dir "left") (posn-move head -1 0)]
        [(string=? dir "right") (posn-move head 1 0)]))

;; Função all-but-last -> retorna a lista sem a ultima posição
(define (all-but-last segs)
  (cond [(empty? (rest segs)) empty]
        [else (cons (first segs) 
                    (all-but-last (rest segs)))]))

;;Movimentando a cobra
(define (slither sn)
  (snake (snake-dir sn)
         (cons (next-head sn) (all-but-last (snake-segs sn)))))

;; -------------------------------------------
;; Comendo e Crescendo - Eating and Growing

;; Função para crescer a cobra
(define (grow sn)
  (snake (snake-dir sn)
         (cons (next-head sn) (snake-segs sn))))

;; Função para comer um 'goo'
(define (eat goos goo-to-eat)
  (cons (fresh-goo) (remove goo-to-eat goos)))

;; close?
(define (close? s g)
  (posn=? s (goo-loc g)))

;; Função que determina se uma 'goo' pode ser comida
(define (can-eat snake goos)
  (cond [(empty? goos) #f]
        [else (if(close? (snake-head snake) (first goos))
              (first goos)
              (can-eat snake (rest goos)))]))

;; -------------------------------------------
;; Clock Ticks
;; Função de atualização da cena
(define (next-pit w)
  (define snake (pit-snake w))
  (define goos (pit-goos w))
  (define goo-to-eat(can-eat snake goos))
  (if goo-to-eat
      (pit (grow snake) (age-goo (eat goos goo-to-eat)))
      (pit (slither snake) (age-goo goos))))
;; -------------------------------------------


;; -------------------------------------------
;; Função de Início
(define (start-snake)
  (big-bang (pit (snake "right" (list (posn 1 1)))
            (list (fresh-goo)
                  (fresh-goo)
                  (fresh-goo)
                  (fresh-goo)
                  (fresh-goo)
                  (fresh-goo)))
  (on-tick next-pit TICK-RATE)
  (on-key direct-snake)
  (to-draw render-pit)
  (stop-when dead? render-end)))
;; -------------------------------------------
;; KEY-EVENTS
;; Direção da Cobra
(define (direct-snake w ke)
  (cond [(dir? ke) (world-change-dir w ke)]
        [else w]))

;; 'dir?' verifica se o jogador apertou alguma tecla
(define (dir? x)
  (or (key=? x "up")
      (key=? x "down")
      (key=? x "left")
      (key=? x "right")))

;; 'world-change-dir' -> muda a direção da cobra
(define (world-change-dir w d)
  (define the-snake (pit-snake w))
  (cond [(and (opposite-dir? (snake-dir the-snake) d)
              (cons? (rest (snake-segs the-snake)))) (stop-with w)]
        [else
         (pit (snake-change-dir the-snake d) (pit-goos w))]))

;; 'opposite-dir?' verifica se duas direção são opostas
(define (opposite-dir? d1 d2)
  (cond [(string=? d1 "up") (string=? d2 "down")]
        [(string=? d1 "down") (string=? d2 "up")]
        [(string=? d1 "left") (string=? d2 "right")]
        [(string=? d1 "right") (string=? d2 "left")]))


;; --------------------------------------------
;; RENDERIZANDO
;; função principal de renderização
(define (render-pit w)
  (snake+scene (pit-snake w)
               (goo-list+scene (pit-goos w) MT-SCENE)))

;; 'função snake+scene' -> 
(define (snake+scene snake scene)
  (define snake-body-scene
    (img-list+scene (snake-body snake) SEG-IMG scene))
  (define dir (snake-dir snake))
  (img+scene (snake-head snake)
             (cond [(string=? "up" dir) HEAD-UP-IMG]
                   [(string=? "down" dir) HEAD-DOWN-IMG]
                   [(string=? "left" dir) HEAD-LEFT-IMG]
                   [(string=? "right" dir) HEAD-RIGHT-IMG])
             snake-body-scene))

;; 'função auxiliar 'img-list+scene'
(define (img-list+scene posns img scene)
  (cond [(empty? posns) scene]
        [(img+scene
          (first posns)
          img
          (img-list+scene (rest posns) img scene))]))

;; função 'img+scene'
(define (img+scene posn img scene)
  (place-image img
               (* (posn-x posn) SEG-SIZE)
               (* (posn-y posn) SEG-SIZE)
               scene))

;; função 'goo-list+scene' que desenha os 'goos'
(define (goo-list+scene goos scene)
  (define (get-posns-from-goo goos)
    (cond [(empty? goos) empty]
          [else (cons (goo-loc (first goos))
                               (get-posns-from-goo (rest goos)))]))
  (img-list+scene (get-posns-from-goo goos) GOO-IMG scene))
;; --------------------------------------------
;; TERMINANDO O JOGO
(define (dead? w)
  (define snake (pit-snake w))
  (or (self-colliding? snake) (wall-colliding? snake)))

(define (render-end w)
  (overlay (text "GAME OVER" ENDGAME-TEXT-SIZE "black")
           (render-pit w)))

(define (self-colliding? snake)
  (cons? (member (snake-head snake) (snake-body snake))))

(define (wall-colliding? snake)
  (define x (posn-x (snake-head snake)))
  (define y (posn-y (snake-head snake)))
  (or (= 0 x) (= x SIZE)
      (= 0 y) (= y SIZE)))
;; --------------------------------------------
;; FUNÇÔES AUXILIARES
(define (posn=? p1 p2)
  (and (= (posn-x p1) (posn-x p2))
       (= (posn-y p1) (posn-y p2))))

(define (snake-head sn)
  (first (snake-segs sn)))
(define (snake-body sn)
  (rest (snake-segs sn)))
(define (snake-tail sn)
  (last (snake-segs sn)))
(define (snake-change-dir sn d)
  (snake d (snake-segs sn)))
;; --------------------------------------------