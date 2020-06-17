#lang racket

(require racklog)

(provide solve)

;; transpozycja tablicy zakodowanej jako lista list
(define (transpose xss)
  (cond [(null? xss) xss]
        ((null? (car xss)) (transpose (cdr xss)))
        [else (cons (map car xss)
                    (transpose (map cdr xss)))]))

;; procedura pomocnicza
;; tworzy listę n-elementową zawierającą wyniki n-krotnego
;; wywołania procedury f
(define (repeat-fn n f)
  (if (eq? 0 n) null
      (cons (f) (repeat-fn (- n 1) f))))

;; tworzy tablicę n na m elementów, zawierającą świeże
;; zmienne logiczne
(define (make-rect n m)
  (repeat-fn m (lambda () (repeat-fn n _))))

(define %valid-part
  (%rel (n m xs)
        [(0 '())]
        [(0 (cons '_ xs))]
        [(n (cons '* xs))
         (%is m (- n 1))
         (%valid-part m xs)]))

(define %only-star
    (%rel (xs)
        [(null)]
        [((cons '* xs))
         (%only-star xs)]))

(define %skip-star
    (%rel ()
      [(xs ys)
       ]

;; predykat binarny
;; (%row-ok xs ys) oznacza, że xs opisuje wiersz (lub kolumnę) ys
(define %row-ok
  (%rel (n m ns xs zs)
        [(null null)]
        [((cons 0 null) null)]
        [(null (cons '_ xs))
         (%row-ok null xs)]
        [((cons 0 ns) (cons '_ xs))
         (%row-ok ns xs)]
        [((cons n ns) (cons '_ xs))
         (%=/= n 0)
         (%row-ok (cons n ns) xs)]
        [((cons n ns) (cons '* xs))
         (%valid-part n (cons '* xs))
         (%skip-star xs ys)
         (%row-ok ns ys)]))

;; TODO: napisz potrzebne ci pomocnicze predykaty

(define %check-all
  (%rel (xs xss ns nss)
        [(null null)]
        [((cons ns nss) (cons xs xss))
         (%row-ok ns xs)
         (%check-all nss xss)]))

;; funkcja rozwiązująca zagadkę
(define (solve rows cols)
  (define board (make-rect (length cols) (length rows)))
  (define tboard (transpose board))
  (define ret (%which (xss) 
                      (%= xss board)
                      (%check-all rows board)
                      (%check-all cols tboard)                     
                      ))
  (and ret (cdar ret)))

;; testy
(equal? (solve '((2) (1) (1)) '((1 1) (2)))
        '((* *)
          (_ *)
          (* _)))

(equal? (solve '((2) (2 1) (1 1) (2)) '((2) (2 1) (1 1) (2)))
        '((_ * * _)
          (* * _ *)
          (* _ _ *)
          (_ * * _)))

(equal? (solve '((4) (6) (2 2) (2 2) (6) (4) (2) (2) (2))
               '((9) (9) (2 2) (2 2) (4) (4)))
        '((* * * * _ _)
          (* * * * * *)
          (* * _ _ * *)
          (* * _ _ * *)
          (* * * * * *)
          (* * * * _ _)
          (* * _ _ _ _)
          (* * _ _ _ _)
          (* * _ _ _ _)))

;; TODO: możesz dodać własne testy

;(make-rect 2 2)