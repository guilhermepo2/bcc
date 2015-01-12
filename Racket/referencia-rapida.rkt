#lang racket ;define a linguagem a ser utilizada.

;;; Comentários

;;; Comentários de uma única linha podem ser feitos com um ponto-e-vírgula.

#| Comentarios em Bloco
   Podem ser feitos em multiplas linhas e...
   #|
      eles podem ser aninhados
    |#
|#

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;; 1. Tipos Primitivos de Dados e Operadores;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Numeros

99999999 ; inteiros
#b111 ; binarios => 7.
#o111 ; octal => 73
#x111 ; hexadecimal => 273
3.14 ; numeros reais
6.02e+23
1/2 ; racionais
1+2i ; numeros complexos

;;; Funcoes sao escritas (f x y z ...)
;;; Onde f e a funcao e x,y,z,... sao operandos
;;; Para criar uma lista literal de dados, use ' para a expressao nao ser avaliada.

'(+ 1 2) ; => (+ 1 2)

;;; Operações Aritméticas:

(+ 1 1) ; => 2
(- 8 1) ; => 7
(* 10 2) ; => 20
(expt 2 3) ; => 8
(quotient 5 2) ; => 2
(remainder 5 2) ; => 1
(/ 35 5) ; => 7
(/ 1 3) ; => 1/3
(exact->inexact 1/3) ; => 0.333333333
(+ 1+2i 2-3i) ; => 3-1i

;;; Operacoes Booleanas

#t ; verdadeiro
#f ; falso - qualquer valor alem de #f e verdadeiro
(not #t) ; => #f
(and 0 #f (error "nao chega aqui")) ; => #f
(or #f 0 (error "nao chega aqui")) ; => 0

;;; Caracteres
#\A ; => #\A
#\λ ; => #\λ
#\u03BB ; #\λ

;;; Strings sao vetores de caracteres com tamanho fixado.

"Hello, World!"
"Benjamin \"Bugsy\"Siegel"
"Foo\tbar\41\x21\u0021\a\r\n"
"λx:(μα.α→α).xx"

;;; Strings tem a propriedade de adicao
(string-append "Hello " "World!") ; => "Hello World!"
;;; Uma string pode ser tratada como uma lista de caracteres
(string-ref "Apple" 0) ; => #\A
;;; format pode ser usado para formatar strings
(format "~a can be ~a" "strings" "formatted")
;;; Imprimir na tela e bem facil
(printf "I'm Racket. Nice to meet you!\n")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;; 2. Variaveis                             ;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Uma variavel pode ser criada usando define
;;; O nome de uma variavel pode ter qualquer caractere, exceto ()[]{}",'`;#|\

(define some-var 5)
some-var ; => 5

;;; Tambem podem ser usados caracteres unicode.
(define ⊆ subset?)
(⊆ (set 3 2) (set 1 2 3)) ; => #t

;;; Acessar variaveis nao declaradas e uma excecao
;;; x ; => x: undefined

;; Local binding: `me' is bound to "Bob" only within the (let ...)
(let ([me "Bob"])
  "Alice"
  me) ; => "Bob"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;; 2. Estruturas e Colecoes                 ;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;Estruturas
(struct dog(name breed age))
(define my-pet 
  (dog "lassie" "collie" 5))
my-pet ; => #<dog>
(dog? my-pet) ; => #t
(dog-name my-pet) ; => "lassie"

;;; Pares imutaveis
;;; 'cons' constroi pares, 'car' e 'cdr' extraem o primeiro e segundo elemento.
(cons 1 2) ; => '(1 . 2)
(car (cons 1 2)) ; => 1
(cdr (cons 1 2)) ; => 2

;;; Listas

;;; Listas sao estruturas de listas encadeadas, feito de pares 'cons' e um fim.
;;; com um 'null'(ou '()) para demarcar o fim das listas.
(cons 1(cons 2(cons 3 null))) ; => '(1 2 3)
;;; 'list' e um termo conveniente que constroi listas.
(list 1 2 3) ; => '(1 2 3).
;;; uma aspa ' pode ser utilizada para demarcar uma lista de valores literais
'(1 2 3)

;;; O 'cons' tambem pode ser utilizado para adicionar um item para o inicio de uma lista.
(cons 4 '(1 2 3)) ; => '(4 1 2 3).

;;; Pode-se usar 'append' para juntar duas listas.
(append '(1 2) '(3 4)) ; => '(1 2 3 4).

;; Listas sao tipos basicos de estruturas, por isso existem varias funcionalidades para elas.
;; Exemplos
(map add1 '(1 2 3))          ; => '(2 3 4)
(map + '(1 2 3) '(10 20 30)) ; => '(11 22 33)
(filter even? '(1 2 3 4))    ; => '(2 4)
(count even? '(1 2 3 4))     ; => 2
(take '(1 2 3 4) 2)          ; => '(1 2)
(drop '(1 2 3 4) 2)          ; => '(3 4)

;;; Vetores

;;; Vetores sao vetores de tamanho fixado.
#(1 2 3) ; => '(1 2 3)
;;; 'vector-append' para concatenar dois vetores
(vector-append #(1 2 3) #(4 5 6)) ; => #(1 2 3 4 5 6).

;;; Sets

;;; Criando um set a partir de uma lista.
(list->set '(1 2 3 1 2 3 3 2 1 3 2 1)) ; => (set 1 2 3).
;;; Adicione um membro com o termo 'set-add'
(set-add (set 1 2 3) 4) ; => (set 1 2 3 4)
;;; Remova um elemento usando 'set-remove'
(set-remove (set 1 2 3) 1) ; => (set 2 3).
;;; Teste para a existencia usando 'set-member?'
(set-member? (set 1 2 3) 1) ; => #t
(set-member? (set 1 2 3) 4) ; => #f

;;; Hashes

;;; Criar um hash imutavel
(define m (hash 'a 1 'b 2 'c 3))
;;; Pegar um valor
(hash-ref m 'a) ; => 1

;;; Pegar um valor nao existente e uma excecao 
; (has-ref m'd) => no value found

;;; Voce pode definir um valor para chaves inexistentes
(hash-ref m 'd 0) ; => 0

;; Use `hash-set' para extender um hash imutavel
;; (Retorna o hash extendido inves de extender o ja existente)
(define m2 (hash-set m 'd 4))
m2 ; => '#hash((b . 2) (a . 1) (d . 4) (c . 3))

;; Lembrete que hashes sao imutaveis
m ; => '#hash((b . 2) (a . 1) (c . 3))  <-- sem 'd'

;; Use `hash-remove' para mover palavras chaves e seu valor
(hash-remove m 'a) ; => '#hash((b . 2) (c . 3))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;; 3. Funcoes                               ;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Use 'lambda' para criar funcoes.
;;; Uma funcao sempre retorna o valor de sua ultima expressao.
(lambda () "Hello World") ; => #<procedure>
;;; Voce tambem pode usar o caractere 'λ'
(λ () "Hello World")

;;; Use parenteses para chamar a funcao, incluindo a expressao lambda
((lambda () "Hello World")) ; => Hello World
((λ () "Hello World")) ; => Hello World

;;; Atribuindo uma funcao para uma variavel
(define hello-world (λ () "Hello World"))
(hello-world) ; => Hello World

;;; Isso pode ser simplificado:
(define (hello-world2) "Hello World")
(hello-world2) ; => Hello World

;;; () sao os argumentos que a funcao recebe
(define hello
  (lambda  (name)
    (string-append "Hello " name)))
(hello "Steve") ; => Hello Steve
(hello "Guilherme") ; => Hello Guilherme

;;; De modo mais simples
(define (hello2 name)
  (string-append "Hello " name))
(hello2 "Steve") ; => Hello Steve

;;; Voce pode criar funcoes com varias retornos usando 'case-lambda'
(define hello3
  (case-lambda
    [() "Hello World"]
    [(name) (string-append "Hello " name)]))
(hello3 "Jake") ; => Hello Jake
(hello3) ; => Hello World


;;; voce tambem pode especificar arguments opcionais com um valor padrao na expressao
(define (hello4 [name "World"])
  (string-append "Hello " name))
(hello4 "Jake") ; => Hello Jake

;;; Funções podem armazenar mais de um argumento em forma de uma lista

(define (count-args . args)
  (format "You passed ~a args: ~a" (length args) args))
(count-args 1 2 3) ; => You passed 3 args: (1 2 3)

;;; Isso também pode ser feito através da forma lambda
(define count-args2
  (lambda args
    (format "You passed ~a args: ~a" (length args) args)))
(count-args2 1 2 3) ; => You passed 3 args: (1 2 3)

;;; Voce pode misturar argumentos `normais` com listas de argumentos:
(define (hello-count name . args)
  (format "Hello ~a, you passed ~a extra args" name (length args)))
(hello-count "Finn" 1 2 3) ; => "Hello Finn, you passed 3 extra args"

;;; Forma menos simplificada:
(define hello-count2
  (lambda (name . args)
    (format "Hello ~a, you passed ~a extra args" name (length args))))
(hello-count "Jake" 1 2 3) ; => "Hello Jake, you passed 3 extra args"

;;; Sem palavras chave
(define (hello-k #:name [name "World"] #:greeting[g "Hello"] . args)
  (format "~a ~a, ~a extra args" g name (length args)))
(hello-k) ; => "Hello World, 0 extra args"
(hello-k 1 2 3) ; => "Hello World, 3 extra args"
(hello-k #:greeting "Hi") ; => "Hi World, 0 extra args"
(hello-k #:name "Finn" #:greeting "Hey") ; => "Hey Finn, 0 extra args"
(hello-k 1 2 3 #:name "Finn" #:greeting "Hello" 4 5 6) ; => "Hello Finn, 6 extra args"

;;;;;;;;;;;;;;;;;;;;;;
;;; 4. Igualdades ;;;;
;;;;;;;;;;;;;;;;;;;;;;

;;; Para numeros use `=`
(= 3 3.0) ; => #t
(= 2 1) ; => #f

;;; Para identidade de objetos utilize `eq?`
(eq? 3 3) ; => #t
(eq? 3 3.0) ; => #f
(eq? (list 3) (list 3)) ; => #f

;;; Para listas ou `colecoes` utilize `equal?`
(equal? (list 'a 'b) (list 'a 'b)) ; => #t
(equal? (list 'a 'b) (list 'b 'a)) ; => #f

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Expressoes de Controle e Lacos ;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Condicionais

(if #t               ;;; expressao de teste
    "this is true"   ;;; expressao if
    "this is false") ;;; expressao else

;;; Em condicionais, tudo que nao e #f e tratado como true.
(if (member 'Jao '(Jose Jao Jonas))
    'yep
    'nope)

;;; 'cond' faz uma serie de testes para escolher um resultado
(cond [(> 2 2) (error "errado!!")]
      [(< 2 2) (error "errado denovo!")]
      [else 'ok])

;;; Encontrando Padroes

(define (fizzbuzz? n)
  (match (list (remainder n 3) (remainder n 5))
    [(list 0 0) 'fizzbuzz]
    [(list 0 _) 'fizz]
    [(list _ 0) 'buzz]
    [_        #f]))

(fizzbuzz? 15) ; => fizzbuzz
(fizzbuzz? 37) ; => #f

;;; Loops

;;; Loops podem ser feitos atraves de recusao de cauda
(define (loop i)
  (when (< i 10)
    (printf "i=~a\n" i)
    (loop (add1 i))))

(loop 5)

;;; Tambem pode ser feito usando o termo 'let'
(let loop ((i 0))
  (when (< i 10)
    (printf "i=~a\n" i)
    (loop (add1 i))))

;;; O Racket tambem ja possui o loop 'for' 
(for ([i 10])
  (printf "i=~a\n" i))
(for ([i (in-range 5 10)])
  (printf "i=~a\n" i))

;;; O for tambem pode ser usado para fazer o loop atraves de vetores, listas, strings, sets, hashs, etc...

(for ([i (in-list '(l i s t))])
  (displayln i))
(for ([i (in-vector #(v e c t o r))])
  (displayln i))

(for ([i (in-string "string")])
  (displayln i))

(for ([i (in-set (set 'x 'y 'z))])
  (displayln i))

(for ([(k v) (in-hash (hash 'a 1 'b 2 'c 3 ))])
  (printf "key:~a value:~a\n" k v))

;;; Intercoes mais complexas em loops

;;; Sobre multiplas sequencias.
(for ([i 10] [j '(x y z)]) (printf "~a:~a\n"i j)) ; => 0:x 1:y 2:z

;;; loops aninhados
(for* ([i 2] [j '(x y z)]) (printf "~a:~a\n" i j)) ; => 0:x, 0:y, 0:z, 1:x, 1:y, 1:z

;;; Condicoes dentro de loops
(for ([i 1000]
      #:when (> i 5)
      #:unless (odd? i)
      #:break (> i 10))
  (printf "i=~a\n" i)) ; => i=6, i=8, i=10

;;; "Comprehensions:
;;; Muito similares a 'for' -- porem, coleta os resultados.

(for/list ([i '(1 2 3)])
  (add1 i)) ; => '(2 3 4)

(for/list ([i '(1 2 3)] #:when (even? i))
  i) ; => '(2)

(for/list ([i 10] [j '(x y z)])
  (list i j)) ; => '((0 x) (1 y) (2 z))

(for/list ([i 1000] #:when (> i 5) #:unless (odd? i) #:break (> i 10))
  i) ; => '(6 8 10)

(for/hash ([i '(1 2 3)])
  (values i (number->string i))) ; => '#hash((1 . "1") (2 . "2") (3 . "3"))

;;; Existem varias outras maneiras de coletar valores de um loop
(for/sum ([i 10]) (* i i)) ; => 285 - realiza a soma
(for/product ([i (in-range 1 11)]) (* i i)) ; => 13168189440000 - realiza o produto
(for/and ([i 10] [j (in-range 10 20)]) (< i j)) ; => #t
(for/or ([i 10] [j (in-range 0 20 2)]) (= i j)) ; => #t
;;; para qualquer combinacao arbitraria, usar 'for/fold'
(for/fold ([sum 0]) ([i '(1 2 3 4)]) (+ sum i)) ; => 10
;;; Esses loops podem substituir loops comuns imperativos.

;;; Exceptions

;;; Para pegar excecoes, usar o termo 'with-handlers'
(with-handlers ([exn:fail? (lambda (exn) 999)])
  (+ 1 "2")) ; => 999
(with-handlers ([exn:break? (lambda (exn) "no time")])
  (sleep 3)
  "phew") ; => "phew", mas se der 'break => "no time"

;; use 'raise' para usar excecoes ou outro valor
(with-handlers ([number?    ; pega os valores numericos
                 identity]) ; retorna o valor
  (+ 1 (raise 2))) ; => 2

;;;;;;;;;;;;;;;;;;;;;;
;;; 6. Mutacoes   ;;;;
;;;;;;;;;;;;;;;;;;;;;;

;;; Use 'set!' para dar um novo valor a uma variavel existente
(define n 5)
(set! n (add1 n ))
n ; => 6

;;; usar 'boxes' para valores mutaveis explicitos (equivalente a ponteiro)
(define n* (box 5))
(set-box! n* (add1 (unbox n*)))
(unbox n*) ; => 6

;;; varios valores em racket sao imutaveis (pares, listas, etc) alguns podem vir
;;; de forma mutavel e imutavel (strings, vetores, hash tables, etc)

;;; use 'vector' ou 'make-vector' para criar vetores mutaveis
(define vec (vector 2 2 3 4))
(define wall (make-vector 100 'bottle-of-beer))
;;; use vector-set! para alterar um espaco de um vetor
(vector-set! vec 0 1)
(vector-set! wall 99 'down)
vec ; => (1 2 3 4)

;;; Como criar um hash mutavel e manipula-lo
(define m3 (make-hash))
(hash-set! m3 'a 1)
(hash-set! m3 'b 2)
(hash-set! m3 'c 3)
(hash-ref m3 'a) ; => 1
(hash-ref m3 'd 0)
(hash-remove! m3 'a)

;;;;;;;;;;;;;;;;;;;;;;
;;; 7. Modulos  ;;;;;;
;;;;;;;;;;;;;;;;;;;;;;

;; Fazer os assuntos 7 ao 11 quando estivermos mais avançados na linguagem.

