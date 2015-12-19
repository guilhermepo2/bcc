% Solução correta e completa do Problema Lógico Festival de Bandas do site Racha Cuca
% Link do problema: http://rachacuca.com.br/logica/problemas/festival-de-bandas/
%vocalista(camiseta,estilo,nome,formacao,apresentacao,estado).

solucao_bandas(B) :-
    B = banda(V1,V2,V3,V4,V5),

    %clausulas simples
    formacao(V5,2007),
    nome(V3,fred),
    estilo(V1,punk),
    estado(V5,amazonas),

    %clausulas que envolvem um membro apenas
    membro(B, A),
    camiseta(A, vermelho),
    estado(A, amazonas),
    membro(B, C),
    nome(C,andre),
    apresentacao(C,20),
    membro(B,D),
    estilo(D, gotico),
    apresentacao(D,20),

    %clausulas em que alguem está a esquerda de alguem
    esquerda(B,E,F),
    estado(E,mato_grosso),
    estado(F,sao_paulo),
    esquerda(B,G,H),
    formacao(G,2005),
    apresentacao(H,21),
    esquerda(B,I,J),
    apresentacao(I,23),
    formacao(J,2006),

    %algum lugar à esquerda
    algum_esquerda(B,K,L),
    camiseta(K,amarelo),
    nome(L,andre),

    esquerda(B,M,N),
    formacao(M,2006),
    estado(N,sao_paulo),

    %clausulas em que alguem está a direita de alguem.
    %algum lugar a direita

    algum_direita(B,O,P),
    nome(O,david),
    camiseta(P,azul),
    algum_direita(B,Q,R),
    nome(Q,fred),
    camiseta(R,amarelo),

    %exatamente à direita
    direita(B,S,T),
    estilo(S,hardcore),
    apresentacao(T,20),
    direita(B,U,V),
    estado(U,minas_gerais),
    camiseta(V,azul),

    %clausulas onde alguem está entre outros dois
    entre(B,W,X,Y),
    apresentacao(W,19),
    apresentacao(X,22),
    apresentacao(Y,20),
    entre(B,Aa,Bb,Cc),
    camiseta(Aa,amarelo),
    nome(Bb, marcelo),
    estilo(Cc,grunge),

    %clausulas onde alguém está do lado de alguém
    lado(B,Dd,Ee),
    ((formacao(Dd,2006),formacao(Ee,2008));
     (formacao(Dd,2008),formacao(Ee,2006))),
    lado(B,Ff,Gg),
    ((nome(Ff,andre),formacao(Gg,2008));
     formacao(Ff,2008),nome(Gg,andre)),
    lado(B,Hh,Ii),
    ((estilo(Hh,grunge),formacao(Ii,2006));
     formacao(Hh,2006),estilo(Ii,grunge)),
    lado(B,Jj,Kk),
    ((camiseta(Jj,branco),estado(Kk,mato_grosso));
     estado(Jj,mato_grosso),camiseta(Kk,branco)),
    
     %o que sobrou
    membro(B,Ll),
    camiseta(Ll,verde),
    membro(B,Mm),
    estilo(Mm,pop_rock),
    membro(B,Nn),
    nome(Nn,chris),
    membro(B,Oo),
    formacao(Oo,2009),
    membro(B,Pp),
    estado(Pp,ceara).
    
    

camiseta(vocalista(C,_,_,_,_,_),C).
estilo(vocalista(_,E,_,_,_,_),E).
nome(vocalista(_,_,N,_,_,_),N).
formacao(vocalista(_,_,_,F,_,_),F).
apresentacao(vocalista(_,_,_,_,A,_),A).
estado(vocalista(_,_,_,_,_,Es),Es).

membro(banda(V,_,_,_,_),V).
membro(banda(_,V,_,_,_),V).
membro(banda(_,_,V,_,_),V).
membro(banda(_,_,_,V,_),V).
membro(banda(_,_,_,_,V),V).

esquerda(banda(V1,V2,_,_,_),V1,V2).
esquerda(banda(_,V2,V3,_,_),V2,V3).
esquerda(banda(_,_,V3,V4,_),V3,V4).
esquerda(banda(_,_,_,V4,V5),V4,V5).

direita(banda(V1,V2,_,_,_),V2,V1).
direita(banda(_,V2,V3,_,_),V3,V2).
direita(banda(_,_,V3,V4,_),V4,V3).
direita(banda(_,_,_,V4,V5),V5,V4).

entre(banda(V1,V2,V3,_,_),V2,V1,V3).
entre(banda(_,V2,V3,V4,_),V3,V2,V4).
entre(banda(_,_,V3,V4,V5),V4,V3,V5).

lado(banda(V1,V2,_,_,_),V1,V2).
lado(banda(_,V2,V3,_,_),V2,V3).
lado(banda(_,_,V3,V4,_),V3,V4).
lado(banda(_,_,_,V4,V5),V4,V5).

algum_esquerda(banda(V1,V2,_,_,_),V1,V2).
algum_esquerda(banda(V1,_,V3,_,_),V1,V3).
algum_esquerda(banda(V1,_,_,V4,_),V1,V4).
algum_esquerda(banda(V1,_,_,_,V5),V1,V5).
algum_esquerda(banda(_,V2,V3,_,_),V2,V3).
algum_esquerda(banda(_,V2,_,V4,_),V2,V4).
algum_esquerda(banda(_,V2,_,_,V5),V2,V5).
algum_esquerda(banda(_,_,V3,V4,_),V3,V4).
algum_esquerda(banda(_,_,V3,_,V5),V3,V5).
algum_esquerda(banda(_,_,_,V4,V5),V4,V5).

algum_direita(banda(V1,V2,_,_,_),V2,V1).
algum_direita(banda(V1,_,V3,_,_),V3,V1).
algum_direita(banda(V1,_,_,V4,_),V4,V1).
algum_direita(banda(V1,_,_,_,V5),V5,V1).
algum_direita(banda(_,V2,V3,_,_),V3,V2).
algum_direita(banda(_,V2,_,V4,_),V4,V2).
algum_direita(banda(_,V2,_,_,V5),V5,V2).
algum_direita(banda(_,_,V3,V4,_),V4,V3).
algum_direita(banda(_,_,V3,_,V5),V5,V3).
algum_direita(banda(_,_,_,V4,V5),V5,V4).
