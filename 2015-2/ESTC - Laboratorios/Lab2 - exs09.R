matriz <- array(c(seq(from=1,to=20)), dim=c(4,5))

media <- mean(matriz)
mediaColunas <- colMeans(matriz)
mediaLinhas <- rowMeans(matriz)

r1 <- sprintf("Media Global: %.1f", media)
r2 <- sprintf("Media Colunas: %.1f", mediaColunas)
r3 <- sprintf("Media Linhas: %.1f", mediaLinhas)

print(r1)
print(r2)
print(r3)