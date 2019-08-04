(define (twoOperatorCalculator lst)
	(if (null? lst)
		0
		(if (eq? (length lst) 1)
			(car lst)
			(if (eq? (cadr lst) '+)
				(twoOperatorCalculator (cons (+ (car lst) (caddr lst)) (cdddr lst)))
				(if (eq? (cadr lst) '-)
					(twoOperatorCalculator (cons (- (car lst) (caddr lst)) (cdddr lst)))
					(car lst)
				)
			)
		)
	)
)

(define (fourOperatorCalculator lst)
	(if (null? lst)
		lst
		(if (eq? (length lst) 1)
			lst
			(if (eq? (cadr lst) '*)
				(cons (* (car lst) (caddr lst)) (fourOperatorCalculator (cdddr lst)))
				(if (eq? (car (cdr lst)) '/)
					(cons (/ (car lst) (caddr lst)) (fourOperatorCalculator (cdddr lst)))
					(cons (car lst) (fourOperatorCalculator (cdr lst)))
				)
			)
		)
	)
)

(define (mapListNested lst)
	(if (pair? lst)
		(twoOperatorCalculator (fourOperatorCalculator (calculatorNested lst)))
		lst
	)
)

(define (calculatorNested lst)
	(map mapListNested lst)
)

(define (flatten lst)
	(cond
		((null? lst) '())
		((pair? lst) (append (flatten (car lst)) (flatten (cdr lst))))
		(else (list lst))
	)
)

(define (checkChar lst)
	(if (null? lst)
		#t
		(if (or (number? (car lst)) (eq? (car lst) '+) (eq? (car lst) '-) (eq? (car lst) '*) (eq? (car lst) '/))
			(checkChar (cdr lst))
			#f
		)
	)
)

(define (checkOperators lst)
	(checkChar (flatten lst))
)

(define (calculator lst)
	(if (checkOperators lst)
		(twoOperatorCalculator (fourOperatorCalculator (calculatorNested lst)))
		#f
	)	
)