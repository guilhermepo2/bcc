#lang racket

(require 2htdp/image 2htdp/universe)

;;-------------------------------------------------------------------------------------
;; A Server is (make-server worlds)
;; Where worlds -> [ListOf iworld]
(define-struct server (worlds))

; CONSTANTS
(define WELCOME-MESSAGE "Bem Vindo ao Chat Racket!")
;;-------------------------------------------------------------------------------------
;; handle-msg : Server iworld String -> Bundle
;; Handles messages coming from the clients.
;; if it receives a string it makes a bundle with a list of eveyone's mails and with the string received.
(define (handle-msg server iw string)
  (cond [(string? string) (make-bundle server
                                    (map (lambda (w)
                                           (make-mail w string))
                                         (server-worlds server))
                                    (list))]
        [else (make-bundle server (list) (list))]))

;;-------------------------------------------------------------------------------------
;; handle-new : Server iworld -> Bundle
;; Handles new Connection
;; Update the server so it includes the new iworld adress received
;;          and sends WELCOME-MESSAGE to the new user and a message to every other user saying that a new member joined.
(define (handle-new srv iw)
  (make-bundle (make-server (cons iw (server-worlds srv)))
               (cons (make-mail iw WELCOME-MESSAGE)
               (map (lambda (w)
                      (make-mail w (string-append (iworld-name iw) " entrou.")))
                    (server-worlds srv)))
               (list)))
;;-------------------------------------------------------------------------------------
;; handle-disconnect : Server iworld -> Bundle
;; Handle disconnections
;; create a new server state without the adress that disconnected and sends a message to
;;          the users on the chat saying the user has disconnected.
(define (handle-disconnect srv iw)
  (local [(define new-worlds (remove iw (server-worlds srv)))]
    (make-bundle (make-server new-worlds)
                 (map (lambda (w)
                        (make-mail w (string-append (iworld-name iw) " desconectou.")))
                      new-worlds)
                 (list iw))))
;;-------------------------------------------------------------------------------------
;; Start-Server: -> Universe
;; Creates a Chat Universe
(define (start-server)
  (universe (make-server empty)
            (on-msg handle-msg)
            (on-new handle-new)
            (on-disconnect handle-disconnect)))
                    