#lang scheme

"multi-conditional procedures"
(define grade
  (lambda (n)
    (cond
      ((>= n 900) 'A)
      ((>= n 800) 'B)
      ((>= n 700) 'C)
      ((>= n 600) 'D)
      (else 'F))))
(grade 100)
(grade 899)
(grade 901)

"Working with define & functions"
(define (increment a) (+ a 1))  ; note that a has local scope
(increment 5)
((lambda (a) (+ a 1)) 5)        ; unnamed procedure
(define increment-lambda        ; define names the unnamed procedure
  (lambda (a)
    (+ a 1)))
(increment-lambda 5)

(define x 10)
(increment 10)
(increment x)
(increment-lambda 10)

"lambda example"
(lambda (x) (* x 2))
((lambda (x) (* x 2)) 10)

(define do
  (lambda (this that)
    (this that)))
(do increment 8)
(do (lambda (x) (* x 2)) 8)
(do - 10)

"Multiply-all"
(define multiply-all
  (lambda (lst)
    (if (null? lst)
        1
        (* (car lst) (multiply-all (cdr lst))))))
(multiply-all '(1 2 3 4))

(newline)
"Reduce"
(define red
  (lambda (operator base-case lst)
    (if (null? lst)
        base-case
        (operator (car lst)  (red operator base-case (cdr lst))))))

(red * 1 '(1 2 3 4))
(red + 0 '(1 2 3 4))
(define sum-all
  (lambda (lst)
    (red + 0 lst)))
(define mult-all
  (lambda (lst)
    (red * 1 lst)))
(sum-all '(1 2 3 4))
(mult-all '(1 2 3 4))

(define double-lst
  (lambda (lst)
    (red (lambda (x y) (cons (* 2 x) y)) '() lst)))
(double-lst '(1 2 3 4))

(newline)
; (red proc base-case '(1 2 3 4 5 6 7))
"length"
(red (lambda (x y) (+ 1 y)) 0 '(1 2 3 4 5 6 7))
"square list"
(red (lambda (x y) (cons (* x x) y)) '() '(1 2 3 4 5 6 7))
"get-odds"
(red (lambda (x y) (if (= 0 (remainder x 2)) y (cons x y))) '() '(1 2 3 4 5 6 7))
"reverse"
(red (lambda (x y) (append y (list x))) '() '(1 2 3 4 5 6 7))


(newline)
"Defined lists"
(define lst '(1 2 3 4 5 6 7 8 9 10 11 12 13))
(define lstn '(0 -1 2 -3 4 -5 6 -7 8 -9 10 -11 12 -13))
(define badlst (list "CGCC" 1 'a + 10 'hello lst '(1 2 3) '(a . b) red 8 6 -3))
lst
lstn
badlst

(newline)
"Higher-order functions - apply"
(apply + lst)
(apply + lstn)
(apply * lst)
(apply * lstn)

(newline)
"Higher-order functions - map"
(map (lambda (x) (* x 5)) lst)
(map (lambda (x) (if (< x 0) (- x) x)) lstn)
(map increment lst)
(map (lambda (x) (* x x)) lst)
(map (lambda (x) (* x x)) lstn)
(map (lambda (x) (if (>= x 0) #t #f)) lstn)
(map pair? badlst)
(map string? badlst)

(newline)
"Higher-order functions - filter"
(filter (lambda (x) (if (>= x 0) #t #f)) lstn)
(filter pair? badlst)
(filter string? badlst)
(filter number? badlst)

(newline)
"Combine higher-order functions"
(map (lambda (x) (* x x)) (filter number? badlst))
(apply + (map (lambda (x) (* x x)) (filter number? badlst)))

; Function to calculate the sum of the squares of numbers in a lsit
(define sum-num-square
  (lambda (lst)
    (apply + (map (lambda (x) (* x x)) (filter number? lst)))))
(sum-num-square lstn)
(sum-num-square badlst)

(newline)
"Currying"
(define secret-num
  (lambda (secret guess)
    (= secret guess)))
(secret-num 10 5)
(secret-num 10 10)

; secret-num-curr returns a function with only 1 argument (the guess)
(define secret-num-curr
  (lambda (secret)
    (lambda (guess)
      (= secret guess))))
(secret-num-curr 10)
(define guessing-game (secret-num-curr 10))
guessing-game
(guessing-game 5)
(guessing-game 10)

(define in-range
  (lambda (min max)
    (lambda (x)
      (and (>= x min) (<= x max)))))
(filter (in-range 10 20) '(1 8 43 17 9 12 20 26 64 15))

(define increase
  (lambda (n)
    (lambda (x)
      (+ x n))))
(map (increase 10) '(1 2 3 4 5))

(newline)
"Define a polynomial"
(define quad
  (lambda (a b c)
    (lambda (x)
      (+ (* a x x) (* b x) c))))
(quad 1 1 1)
(define f1 (quad 1 1 1))    ; f(x) = x^2 + x + 1
(define f2 (quad 1 2 3))    ; f(x) = x^2 + 2x + 3
(define f3 (quad 2 4 2))    ; f(x) = 2x^2 + 4x + 2
(define f4 (quad 1 (/ 1 2) (/ 1 4))) ; f(x) = x^2 + 1/2 x + 1/4
f1
(f1 2)
(f1 -2)
(f2 2)
(f2 -2)
(f3 2)
(f3 -2)
(f4 2)
(f4 -2)

(newline)
"Including a module"
(require "scheme3inc.scm")
(fib-tail 10)

(newline)
"Towers of Hanoi"
(define hanoi
  (lambda (n source center destination)
    (if (= n 1)  ; stopping condition
      (list 'Move source destination)
      (list
          (hanoi (- n 1) source destination center)
          (hanoi 1 source center destination)
          (hanoi (- n 1) center source destination))
      )))
(hanoi 3 'red 'green 'blue)

(newline)
"let structures (scope)"
(define a 100)
a

(let
    ((a 4)
     (b 3))
  (+ a b))

(let
    ((a 4)
     (b (+ a 1)))    ; a comes from the outer scope
  (* a b))

(let
    ((a 4))
  (let
      ((b (+ a 1)))  ; a comes from the inner scope
    (* a b)))

; You can make things confusing
(let
    ((x 9))
  (let
      ((x 3)
       (y (* 5 x)))
    (+ x y)))

(let
    ((map apply)
     (filter map)
     (apply length)
     (absolutely-do-not-filter filter))
  (map + (filter (lambda (x) (* x x)) (absolutely-do-not-filter number? badlst))))

"Define a function that uses let"
(define let-test
  (lambda (x)
    (let
        ((a (* 2 x x))
         (b (+ 1 x))
         (c 5))
      (+ a b c))))
(let-test 6)

(define habitat-material
  (lambda (height radius thickness)
    (let
        ((pi 3.14159265))
      (let
          ((cylinder_volume
            (lambda (r h)
              (* h (* pi (* r r))))))
        (-
         (cylinder_volume radius height)
         (cylinder_volume (- radius thickness) (- height (* 2 thickness))))))))
(habitat-material 10 5 1)

(let
    ((+ 10)
     (- 4)
     (* (lambda (x y) (min x y))))
  (* + -))

(newline)
"lambda->let, let->lambda"
(let
    ((a 4)
     (b 5))
  (+ a b))

((lambda (a b) (+ a b)) 4 5)

((lambda (x y) (+ (* x x) (* y y))) 3 4)

(let
    ((x 3)
     (y 4))
  (+ (* x x) (* y y)))

(newline)
"Advanced topics - not required for project or final"
"case-lambda"
(define hello
  (case-lambda
    (() "Hello, world!")
    ((name) (string-append "Hello, " name))))
(hello)
(hello "John")

(newline)
"match"
(define multiple-of-2-and-5
  (lambda (n)
    (match (list (remainder n 2) (remainder n 5))
      ((list 0 0) "Divisible by 2 and 5")  ; both remainders are 0
      ((list 0 _) "Divisible only by 2")   ; only divisible by 2
      ((list _ 0) "Divisible only by 5")   ; only divisible by 5
      (_ "Not divisible by 2 or 5"))))
(multiple-of-2-and-5 20)
(multiple-of-2-and-5 15)               
(multiple-of-2-and-5 17)
(multiple-of-2-and-5 8)
