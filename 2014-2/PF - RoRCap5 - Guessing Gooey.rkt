#lang racket

(require 2htdp/universe 2htdp/image)

;; Definições

(define WIDTH 400)
(define HEIGHT 600)
(define SIZE 12)
(define COLOR "red")
(define TEXT-SIZE 12)
(define TEXT-X 4)
(define TEXT-UPPER-Y 10)
(define TEXT-LOWER-Y 15)

;; estrutura intervalo
(struct intervalo (menor maior))

;; função que inicializa o jogo
(define (comecar menor maior)
  (big-bang (intervalo menor maior)
            (on-key lidar-com-adivinhacao)
            (to-draw render)
            (stop-when single? render-ultima-cena)))

;; definições de constantes

(define HELP-TEXT
  (text "↑ para numeros maiores e ↓ para numeros menores"
        TEXT-SIZE
        "blue"))
(define HELP-TEXT2
  (text "Aperte = quando o numero for adivinhado; q para sair."
        TEXT-SIZE
        "blue"))

(define MT-SC
  (place image/align
         HELP-TEXT TEXT-X TEXT-UPPER-Y "left" "top"
         (place-image/align
          HELP-TEXT2 TEXT-X TEXT-LOWER-Y "left" "bottom"
          (empty-scene WIDTH HEIGHT))))


;; lidando com as entradas

(define (lidar-com-adivinhacao w chave)
  (cond [(key=? chave "up") (maior w)]
        [(key=? chave "down") (menor w)]
        [(key=? chave "q") (stop-with w)]
        [(key=? chave "=") (stop-with w)]
        [else w]))
 
(define (menor w)
  (intervalo (intervalo-menor w)
             (max (intervalo-menor w) (sub1 (adivinhacao w)))))

(define (maior w)
  (intervalo (intervalo-maior w) (add1 (adivinhacao w)))
  (intervalo-maior w))

(define (adivinhacao w)
  (quotient (+ (intervalo-menor w) (intervalo-maior w)) 2))

(define (single? w)
  (= (intervalo-menor w) (intervalo-maior w)))

;; render

(define (render w)
  (overlay (text (number->string (adivinhacao w)) SIZE COLOR) MT-SC))

(define (render-ultima-cena w)
  (overlay (text "FIM" SIZE COLOR) MT-SC))