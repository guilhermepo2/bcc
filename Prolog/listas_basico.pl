% X é membro da lista?

membro(X,[X|_]).
membro(X,[_|T]) :-
	membro(X,T).

% ?- membro(3,[1,2,3]).
% true .
% ?- membro(3,[3,2,1]).
% true .
% ?- membro(3,[1,2,4]).
% false.

% Selecionar um membro da Lista (?)

selecionar(X, [X|T], T).
selecionar(X, [H|T], [H|T1]) :-
	selecionar(X,T,T1).

% ?- selecionar(X,[1,2,3],R).
% X = 1,
% R = [2, 3] ;
% X = 2,
% R = [1, 3] ;
% X = 3,
% R = [1, 2] ;
% false.

% Descobrir o tamanho de uma lista.
% tamanho(N, LISTA).
tamanho(0,[]).
tamanho(N,[_|T]) :-
	tamanho(M,T),
	N is 1+M.

% ?- tamanho(N,[1,2,3]).
% N = 3.

%anexar duas listas

anexar([],L2,L2).
anexar([H|T1],L2,[H|T]) :-
	anexar(T1, L2, T).

% ?- tamanho(N,[1,2,3]).
% N = 3.
