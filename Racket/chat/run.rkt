#lang racket

(require (only-in "chat-client.rkt" join-chat)
         (only-in "chat-server.rkt" start-server)
         2htdp/universe)

(define (chat)
  (launch-many-worlds
   (start-server)
   (join-chat "Zezim" "127.0.0.1")
   (join-chat "Joaozin" "127.0.0.1")))