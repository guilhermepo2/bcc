#lang racket

(require (only-in "chat-client.rkt" join-chat string-remove-last)
         2htdp/universe 2htdp/image)
;;-------------------------------------------------------------------------------------
;; Idea: Get the Name and server from the client
(define-struct user [nick flag cursor?])
;; A User is (make-user String1 flag cursor)
;; String1 its users' nickname
;; Flag is a Boolean that will tell if the user is ready to join the chat
;; CURSOR? is a Boolean that shows a blinking cursor

; Constants

(define HEIGHT 300)
(define WIDTH 600)
(define FONT-SIZE 22)
(define FONT-COLOR "black")
(define CURSOR-ON (rectangle 4 FONT-SIZE "solid" "red"))

;;-------------------------------------------------------------------------------------
;; to-image: String-> Image
;; Receives a String and return an image
(define (to-image s)
  (text (if (string? s) s "sem-entrada") FONT-SIZE FONT-COLOR))

(define NICK-IMG (to-image "Enter your nickname: "))
(define FINISH-CHAT (to-image "Hope you enjoyed your chatting time!"))

;;-------------------------------------------------------------------------------------

;; render-client : User -> Image
;; Render the intro to chat
(define (render-editor u)
  (local [(define editor (to-image (user-nick u)))]
    (place-image NICK-IMG (/ WIDTH 2) (- (/ HEIGHT 2) 25)
      (place-image CURSOR-ON
                   (+ (/ WIDTH 2) (/ (image-width editor) 2))
                   (/ HEIGHT 2)
                   (place-image editor (/ WIDTH 2) (/ HEIGHT 2) (empty-scene WIDTH HEIGHT))))))
;;-------------------------------------------------------------------------------------
;; handle-key: User Key -> User
(define (handle-key u ke)
  (cond    
    [(key=? ke "\r")
     (make-user (user-nick u) #t (user-cursor? u))]
    
    [(key=? ke "\b") (delete-key u)]
    
    [(= (string-length ke) 1)
     (make-user (string-append (user-nick u) ke) (user-flag u) (user-cursor? u))]
    [else u]))
;;-------------------------------------------------------------------------------------
;; delete-key : User -> User
;; receive a user and delete the last char from the string being typed

(define (delete-key u)
  (cond [(string=? "" (user-nick u)) u]
        [else (make-user (string-remove-last (user-nick u)) (user-flag u) (user-cursor? u))]))
;;-------------------------------------------------------------------------------------
;; Stop Function: User -> Boolean
(define (stop-function u)
  (if (user-flag u)
      #t
      #f))
;;-------------------------------------------------------------------------------------
;; Stop Function: User -> Chat
(define (final-render u)
  (join-chat (user-nick u) "127.0.0.1")
  (place-image FINISH-CHAT (/ WIDTH 2) (/ HEIGHT 2) (empty-scene WIDTH HEIGHT)))
;;-------------------------------------------------------------------------------------
;; Big-Bang: -> Scene
(define (main)
  (big-bang (make-user "" #f #t)
            (on-draw render-editor)
            (on-key handle-key)
            (stop-when stop-function final-render)))
;;-------------------------------------------------------------------------------------
(define (teste-chat)
  (launch-many-worlds
   (join-chat "pessoa1" "127.0.0.1")
   (join-chat "pessoa2" "127.0.0.1")
   (join-chat "pessoa3" "127.0.0.1")))

; pegar ip -> ipconfig getifaddr en1