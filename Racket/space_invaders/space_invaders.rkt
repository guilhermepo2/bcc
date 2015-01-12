#lang racket
(require 2htdp/universe 2htdp/image)

(define VELOCITY-X 1)
(define VELOCITY-Y 0.2)
(define WIDTH 400)
(define HEIGHT 600)
(define SHOT-IMG (rectangle 3 10 "solid" "black"))
(define INV-SHOT-IMG (rectangle 3 10 "solid" "red"))
(define SHIP (scale 1.5 (bitmap "graphics/ship.png")))
(define INVADER1 (scale 2.5 (bitmap "graphics/invader1.png")))
(define INVADER2 (scale 2 (bitmap "graphics/invader2.png")))
(define INVADER3 (scale 2.75 (bitmap "graphics/invader3.png")))
(define SHOT-SPEED 5)
(define INVADER-SPEED 5)
(define INVADER-SIZE 20)
(define PLAYER-SIZE 10)

(define-struct world (ship shots inv-shots invaders dir) #:transparent)
(struct pos (x y) #:transparent #:mutable)
(struct ship (pos) #:transparent #:mutable)
(struct invader (img pos) #:transparent #:mutable)
(struct shot (pos) #:transparent #:mutable)
(struct inv-shots (pos) #:transparent #:mutable)

(define (move-right ship)
  (define pos (ship-pos ship))
  (set-pos-x! pos (+ (pos-x pos) 10))
  ship)

(define (move-left ship)
  (define pos (ship-pos ship))
  (set-pos-x! pos (- (pos-x pos) 10))
  ship)

(define (add-shots ship-pos shots-list)
  (cons (shot (pos (pos-x ship-pos) (- HEIGHT 30))) shots-list))

(define (add-inv-shots shots invaders)
  (define position (invader-pos (first invaders)))
  (cons (inv-shots (pos (random WIDTH) (pos-y position))) shots))

(define (control-invader w a-key)
  (cond [(key=? "d" a-key) (make-world (move-right (world-ship w)) (world-shots w) (world-inv-shots w) (world-invaders w)  (world-dir w))]
        [(key=? "a" a-key) (make-world (move-left (world-ship w)) (world-shots w) (world-inv-shots w) (world-invaders w) (world-dir w))]
        [(key=? " " a-key) (make-world (world-ship w) (add-shots (ship-pos (world-ship w)) (world-shots w)) (add-inv-shots (world-inv-shots w) (world-invaders w)) (world-invaders w) (world-dir w))]
        [else w]))

(define (initialize-ship)
  (ship (pos 30 (- HEIGHT 30))))

(define (initialize-invaders)
  (list
   (invader INVADER3 (pos 40 50))
   (invader INVADER3 (pos 70 50))
   (invader INVADER3 (pos 100 50))
   (invader INVADER3 (pos 130 50))
   (invader INVADER3 (pos 160 50))
   (invader INVADER3 (pos 190 50))
   (invader INVADER3 (pos 220 50))
   (invader INVADER3 (pos 250 50))
   (invader INVADER3 (pos 280 50))
   (invader INVADER3 (pos 310 50))
   (invader INVADER3 (pos 340 50))
   (invader INVADER1 (pos 40 80))
   (invader INVADER1 (pos 70 80))
   (invader INVADER1 (pos 100 80))
   (invader INVADER1 (pos 130 80))
   (invader INVADER1 (pos 160 80))
   (invader INVADER1 (pos 190 80))
   (invader INVADER1 (pos 220 80))
   (invader INVADER1 (pos 250 80))
   (invader INVADER1 (pos 280 80))
   (invader INVADER1 (pos 310 80))
   (invader INVADER1 (pos 340 80))
   (invader INVADER1 (pos 40 110))
   (invader INVADER1 (pos 70 110))
   (invader INVADER1 (pos 100 110))
   (invader INVADER1 (pos 130 110))
   (invader INVADER1 (pos 160 110))
   (invader INVADER1 (pos 190 110))
   (invader INVADER1 (pos 220 110))
   (invader INVADER1 (pos 250 110))
   (invader INVADER1 (pos 280 110))
   (invader INVADER1 (pos 310 110))
   (invader INVADER1 (pos 340 110))
   (invader INVADER2 (pos 40 140))
   (invader INVADER2 (pos 70 140))
   (invader INVADER2 (pos 100 140))
   (invader INVADER2 (pos 130 140))
   (invader INVADER2 (pos 160 140))
   (invader INVADER2 (pos 190 140))
   (invader INVADER2 (pos 220 140))
   (invader INVADER2 (pos 250 140))
   (invader INVADER2 (pos 280 140))
   (invader INVADER2 (pos 310 140))
   (invader INVADER2 (pos 340 140))
   (invader INVADER2 (pos 40 170))
   (invader INVADER2 (pos 70 170))
   (invader INVADER2 (pos 100 170))
   (invader INVADER2 (pos 130 170))
   (invader INVADER2 (pos 160 170))
   (invader INVADER2 (pos 190 170))
   (invader INVADER2 (pos 220 170))
   (invader INVADER2 (pos 250 170))
   (invader INVADER2 (pos 280 170))
   (invader INVADER2 (pos 310 170))
   (invader INVADER2 (pos 340 170))
   ))

(define (initialize-world)
  (define ship (initialize-ship))
  (define invaders (initialize-invaders))
  (world ship empty empty invaders 5))

(define (render w)
  (render-ship (world-ship w)
          (render-invaders (world-invaders w)
                        (render-shots (world-shots w)
                                      (render-inv-shots (world-inv-shots w)
                                        (empty-scene WIDTH HEIGHT))))))
  
(define (render-invaders inv w)
  (cond
    [(empty? inv) w]
    [(cons? inv) (place-image (invader-img (first inv)) (pos-x (invader-pos (first inv))) (pos-y (invader-pos (first inv)))
                              (render-invaders (rest inv) w))]))

(define (render-shots s w)
  (cond
    [(empty? s) w]
    [(cons? s) (place-image SHOT-IMG (pos-x (shot-pos (first s))) (pos-y (shot-pos (first s)))
                              (render-shots (rest s) w))]))

(define (render-inv-shots s w)
  (cond
    [(empty? s) w]
    [(cons? s) (place-image INV-SHOT-IMG (pos-x (inv-shots-pos (first s))) (pos-y (inv-shots-pos (first s)))
                            (render-inv-shots (rest s) w))]))

(define (render-ship ingame-ship scene)
  (define position (ship-pos ingame-ship))
  (place-image SHIP (pos-x position) (pos-y position) scene))


(define (shot-sucess? shot invaders)
  (cond
    [(empty? invaders) #f]
    [(near? (first invaders) shot) #t]
    [else (shot-sucess? shot (rest invaders))]))


(define (move-shots shots invaders)
  (cond
    [(empty? shots) empty]
    [(shot-sucess? (car shots) invaders) (move-shots (rest shots) invaders)]
    [else (cons (shot (pos (pos-x (shot-pos (first shots))) (- (pos-y (shot-pos (first shots))) SHOT-SPEED)))
                         (move-shots (rest shots) invaders))]))




(define (move-inv-shots shots)
  (cond
    [(empty? shots) empty]
    [(cons? shots) (cons (inv-shots (pos (pos-x (inv-shots-pos (first shots))) (+ (pos-y (inv-shots-pos (first shots))) SHOT-SPEED)))
                         (move-inv-shots (rest shots)))]))

(define (distance p1 p2)
  (sqrt (+ (sqr (- (pos-x (invader-pos p1)) (pos-x (shot-pos p2)))) 
           (sqr (- (pos-y (invader-pos p1)) (pos-y (shot-pos p2)))))))

(define (near? shot invader)
  (cond
    [(<= (distance shot invader) INVADER-SIZE) true]
    [else false]))

(define (near-any? invader shots)
  (cond
    [(empty? shots) false]
    [(cons? shots) (cond
                     [(near? invader(first shots)) true]
                     [else (near-any? invader (rest shots))])]))

(define (remove-invaders invaders shots)
  (cond
    [(empty? invaders) empty]
    [(cons? invaders) (cond
                   [(near-any? (first invaders) shots) (rest invaders)]
                   [else (cons (first invaders) (remove-invaders (rest invaders) shots))])]))

(define (shift-invader  inv dir)
  (invader (invader-img inv) (pos (+ (pos-x (invader-pos inv)) dir) (+ (pos-y (invader-pos inv)) VELOCITY-Y))))

(define (update-invaders invaders dir)
  (cond 
    [(empty? invaders) invaders]
    [else (cons (shift-invader (first invaders) dir) (update-invaders (rest invaders) dir))]))

(define (next-dir dir)
  (if (= dir VELOCITY-X) (- VELOCITY-X) VELOCITY-X))

(define (update w)
  (make-world (world-ship w)
              (move-shots (world-shots w) (world-invaders w))
              (move-inv-shots (world-inv-shots w))
              (update-invaders (remove-invaders (world-invaders w) (world-shots w)) (world-dir w) )
              (next-dir (world-dir w))
              ))

(define (player-distance p1 p2)
  (sqrt (+ (sqr (- (pos-x (ship-pos p1)) (pos-x (inv-shots-pos p2)))) 
           (sqr (- (pos-y (ship-pos p1)) (pos-y (inv-shots-pos p2)))))))

(define (shot-near-player? ship shot)
    (cond
    [(<= (player-distance ship shot) PLAYER-SIZE) true]
    [else false]))

(define (player-hit? s is)
  (cond
    [(empty? is) false]
    [(cons? is) (or (shot-near-player? s (first is)) (player-hit? s (rest is)))]))

(define (game-over? w)
  (or (player-hit? (world-ship w) (world-inv-shots w)) (empty? (world-invaders w))))

(define (render-end w)
  (overlay (text "Game Over" 50 "black") (render w)))

(define (start)
(big-bang (initialize-world)
          (on-tick update)
          (to-draw render)
          (on-key control-invader)
          (stop-when game-over? render-end)))