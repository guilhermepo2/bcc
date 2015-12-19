dados <- mtcars

#padronização dos dados
dados_pad <- scale(dados)

#calculando distância euclidiana
eucl_dist <- dist(dados_pad, method="euclidean")

#critério de ligação WARD.D
dend <- hclust(eucl_dist, method="ward.D")
plot(dend)

#cortando em 7 grupos
grupos <- cutree(dend, k=7.0) # não será utilizado

#variacao1
distancia_nopad <- dist(dados, method="euclidean")
dend_nopad <- hclust(distancia_nopad, method="ward.D")

#variacao2
distancia_manhattan <- dist(dados_pad, method="manhattan")
dend_manhattan <- hclust(distancia_manhattan, method="ward.D")

#variacao3
distancia_chebychev <- dist(dados_pad, method="maximum")
dend_chebychev <- hclust(distancia_chebychev, method="ward.D")

#variacao4
dend_single <- hclust(eucl_dist, method="single")

#variacao5
dend_complete <- hclust(eucl_dist, method="complete")


#CORTES
#rect.hclust(dend, k=7.0, border="red") # euclidiano padronizado
#rect.hclust(dend_nopad, k=7.0, border="blue") # 1 euclidiano nao padronizado
#rect.hclust(dend_manhattan, k=7.0, border="green") # 2 manhattan padronizado
#rect.hclust(dend_chebychev, k=7.0, border="orange") # 3 chebychev padronizado
#rect.hclust(dend_single, k=7.0, border="red") # 4 euclidiano padronizado single
#rect.hclust(dend_complete, k=7, border="blue") # 5 euclidiano padronizado complete
#rect.hclust(dend, k=6, border="red") # euclidiano padronizado com 6 grupos
rect.hclust(dend, k=8, border="orange") # euclidiano padronizado com 8 grupos