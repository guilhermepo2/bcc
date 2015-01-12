viagem_direta(a,c).
viagem_direta(c,b).
viagem_direta(a,d).
viagem(A,B) :- 
	viagem_direta(A,B).
viagem(A,B) :- 
	viagem_direta(A,C),
	viagem(C,B).

% ?- viagem(a,b).
% true .
% ?- viagem(a,c).
% true .
% ?- viagem(c,d).
% false.
