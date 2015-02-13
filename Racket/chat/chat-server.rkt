#lang racket

(require 2htdp/image 2htdp/universe)
(require test-engine/racket-tests)
(provide start-server)

;;-------------------------------------------------------------------------------------
;; A Server is (make-server worlds)
;; Where worlds -> [ListOf iworld]
(define-struct server (worlds))

; CONSTANTS
(define WELCOME-MESSAGE "Bem Vindo ao Chat Racket!")
;;-------------------------------------------------------------------------------------
;; handle-msg : Server iworld String -> Bundle
;; Handles messages coming from the clients.
(define (handle-msg server iw string)
  (cond [(string? string) (make-bundle server
                                    (map (lambda (w)
                                           (make-mail w string))
                                         (server-worlds server))
                                    (list))]
        [else (make-bundle server (list) (list))]))

;(define (handle-msg srv i str)
;  (cond [(string? str) 
;         (make-bundle srv
;               (map (lambda (w)
;                      (make-mail w str))
;                    (server-worlds srv))
;               (list))]
;        [else (make-bundle srv (list) (list))])) ; reject bogus message

;;-------------------------------------------------------------------------------------
;; handle-new : Server iworld -> Bundle
;; Handles new Connection
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
                    