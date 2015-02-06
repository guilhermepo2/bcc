#lang racket
;; SIMPLE CHAT CLIENT

(require 2htdp/image 2htdp/universe)
(require test-engine/racket-tests)

(provide join-chat)

;;-------------------------------------------------------------------------------------
;; A client is (make-client name lines editor curse-on?)
;; name -> String
;; Lines -> [listof String]
;; editor -> String
;; curse-on? is a boolean used for making the cursor blink
;; A client is a local world
(define-struct client (name lines editor curse-on?))

;; The client needs:
;;     - the NAME of the person
;;     - a list of the previous lists on the chat (together with the NAME)
;;     - a line being edited
;;     - the state of the cursor, used for marking

;;-------------------------------------------------------------------------------------
;; CONSTANTS
(define HEIGHT 600)
(define WIDTH 600)
(define FONT-SIZE 14)
(define FONT-COLOR "black")
(define LINE-SPACING 5)
(define LINE-INDENT 5)
(define DIVIDING-COLOR "red")
(define NICK-DIVIDER " : ")
(define CURSOR-ON (rectangle 4 (+ 4 (* 2 LINE-SPACING)) "solid" "red"))
(define CURSOR-OFF (rectangle 3 (+ 4 (* 2 LINE-SPACING)) "solid" "white"))

(define MID-HEIGHT (/ HEIGHT 2))
(define MID-WIDTH (/ WIDTH 2))

;; CONSTANT FOR CHAT AREA FROM CCS.NEU.EDU
(define CHAT-AREA
  (local [(define SEP-Y (- HEIGHT FONT-SIZE (* 2 LINE-SPACING)))]
    (scene+line (empty-scene WIDTH HEIGHT)
                0 SEP-Y WIDTH SEP-Y DIVIDING-COLOR)))

;;-------------------------------------------------------------------------------------
;; wdht/2 : Image -> Number
;; Calculate the image width divided by 2
(define (wdth/2 img)
  (/ (image-width img) 2))

;; hght/2 : Image -> Number
;; Calculate the image height divided by 2
(define (hght/2 img)
  (/ (image-height img) 2))
;;-------------------------------------------------------------------------------------
;; to-image: String-> Image
;; Receives a String and return an image
(define (to-image s)
  (text (if (string? s) s "sem-entrada") FONT-SIZE FONT-COLOR))

;;-------------------------------------------------------------------------------------
;; render-client : Client -> Image
;; Render the chat
(define (render-client c)
  (local [(define editor (to-image (client-editor c)))]
  (add-to-chat (client-lines c) (- HEIGHT (image-height editor) (* LINE-SPACING 2))
               (place-image (if (client-curse-on? c) CURSOR-ON CURSOR-OFF)
                            (+ LINE-INDENT (image-width editor) 4)
                            (- HEIGHT (hght/2 editor))
                            (place-image editor
                                         (+ LINE-INDENT (wdth/2 editor))
                                         (- HEIGHT (hght/2 editor))
                                         CHAT-AREA)))))
   
;;-------------------------------------------------------------------------------------
;; add-to-chat : [ListOfString] Number Scene -> Scene
;; Add the strings to the chat scene
(define (add-to-chat los n scene)
  (cond [(empty? los) scene]
        [else (local [(define txt (to-image (first los)))]
              (place-image txt
                           (+ LINE-INDENT (wdth/2 txt))
                           (- n (hght/2 txt))
                           (add-to-chat (rest los) (- n (image-height txt)
                                        LINE-SPACING) scene)))]))
;;-------------------------------------------------------------------------------------
; String -> String
; Removes the last character of a string

(check-expect (string-remove-last "hello") "hell")
(check-expect (string-remove-last "world") "worl")
(check-expect (string? (string-remove-last "hello")) #t)

(define (string-remove-last string)
        (substring string 0 (- (string-length string) 1)))
;;-------------------------------------------------------------------------------------
;; handle-key: Client Key -> Client (Package)
;; receive a key and handle it

(define (handle-key c ke)
  (cond    
    [(key=? ke "\r")
     (make-package (make-client (client-name c)
                                (client-lines c)
                                ""
                                (client-curse-on? c))
                   (string-append (client-name c)
                                  NICK-DIVIDER
                                  (client-editor c)))]
    [(key=? ke "\b")
     (make-client (client-name c) (client-lines c)
                  (string-remove-last (client-editor c))
                  (client-curse-on? c))]
    [(= (string-length ke) 1)
     (make-client (client-name c) (client-lines c)
                  (string-append (client-editor c) ke)
                  (client-curse-on? c))]
    [else c]))
;;-------------------------------------------------------------------------------------
;; update: Client -> Client
;; enable the cursor to blink
(define (update w)
  (make-client (client-name w)
               (client-lines w)
               (client-editor w)
               (not (client-curse-on? w))))
;;-------------------------------------------------------------------------------------
;; handle-msg : Client Message -> Client or Package
(define (handle-msg c msg)
  (make-client (client-name c)
               (cons msg (client-lines c))
               (client-editor c)
               (client-curse-on? c)))

;;-------------------------------------------------------------------------------------
;; join-chat : String String -> Client
;; Runs the chat, String is a nickname and a SERVER
(define (join-chat nick server)
  (big-bang (make-client nick (list) "" false)
            (on-draw render-client)
            (on-key handle-key)
            (on-tick update 3/4)
            (register server)
            (name nick)
            (on-receive handle-msg)))
