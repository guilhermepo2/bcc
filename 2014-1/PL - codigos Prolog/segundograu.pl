%Equação de Segundo Grau

resolve_2o_grau(A,B,C) :-
    A \== 0,
    Delta is B*B-4*A*C,
    raizes(Delta,A,B).

raizes(Delta) :-
    Delta < 0,
    write('não há raizes reais').
raizes(Delta,A,B) :-
    Delta = 0,
    R is -B/(2*A),
    write(R).
raizes(Delta,A,B) :-
    Delta > 0,
    RD is sqrt(Delta),
    R1 is (-B + RD)/(2*A),
    R2 is (-B -RD)/(2*A),
    write(R1 - R2).
