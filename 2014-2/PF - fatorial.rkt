#lang racket

(define (fatorial n)
  (if (= n 0)
      1
      (* n (fatorial ( - n 1)))))

