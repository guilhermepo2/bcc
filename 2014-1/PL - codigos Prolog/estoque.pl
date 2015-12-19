%Estoque em Prolog

imprime(Cod) :- 
    estoque(Cod,Prod,Est),
    write(Prod - Est),nl.

estoque(1,prego,100).
estoque(2,alicate,200).
estoque(3, martelo,5).
