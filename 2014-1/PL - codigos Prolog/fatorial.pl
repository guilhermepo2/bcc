% Código que dá o resultado de um fatorial
fatorial(0,1).
fatorial(N,F) :-
	N > 0,
	N1 is N-1,
	fatorial(N1,F1),
	F is N*F1.

% ?- fatorial(5,X).
% X = 120 .
% ?- fatorial(20,F).
% F = 2432902008176640000 .
