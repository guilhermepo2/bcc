#criando a acp USJudgeRatings
acp_jr <- princomp(x = USJudgeRatings, cor=TRUE)

# autovalores

(acp_jr$sdev)^2

# criando a acp de quakes
acp_q <- princomp(x = quakes, cor=TRUE)

# autovalores de quakes
(acp_q$sdev)^2

#princomp fornece o desvio padrao - para obter a variance(autovetores) deve-se elevar o desvio padrao ao quadrado

# funcao eigen da a variancia