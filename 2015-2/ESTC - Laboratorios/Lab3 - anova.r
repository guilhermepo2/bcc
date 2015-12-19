concentracao_5 <- c(7,8,15,11,9,10)
concentracao_10 <- c(12,17,13,18,19,15)
concentracao_15 <- c(14,18,19,17,16,18)
concentracao_20 <- c(19,25,22,23,18,20)
concentracao_total <- c(concentracao_5, concentracao_10, concentracao_15,concentracao_20)

qtd_concentracoes = 4 # a
qtd_observacoes = 6 # n

# 1 - Testar as hipoteses

#somando tudo
somac5 <- sum(concentracao_5) # y1p
somac10 <- sum(concentracao_10) # y2p
somac15 <- sum(concentracao_15) # y3p
somac20 <- sum(concentracao_20) # y4p
somatotal <- sum(concentracao_total) # ypp
soma_media = (somatotal / length(concentracao_total)) # yppm
conjunto_somas <- c(somac5, somac10, somac15, somac20) # yip

# SOMA TOTAL DOS QUADRADOS
STQ <- sum((concentracao_total - soma_media)^2)
# SOMA DOS QUADRADOS DA REGRESSAO
SQReg <- qtd_observacoes * sum((conjunto_somas/qtd_observacoes-soma_media)^2)
# SOMA DOS QUADRADOS DO RESIDUO OU DO ERRO
SQR <- STQ - SQReg

# MEDIA DOS QUADRADOS DA REGRESSAO
MQReg <- SQReg / (qtd_concentracoes - 1)
# MEDIA DOS QUADRADOS DO RESIDUO
MQR <- SQR / (qtd_concentracoes * (qtd_observacoes - 1))

# F
fzero <- MQReg / MQR

# alfa = 0.01
alfa <- 0.01

# F Critico
Fc <- qf(1-alfa, (qtd_concentracoes - 1), (qtd_concentracoes*(qtd_observacoes - 1)))

fzeros <- sprintf("F0 = %f", fzero)
print(fzeros)
fcs <- sprintf("Fc = %f", Fc)
print(fcs)
if(fzero > Fc) { print("Hipotese Nula Rejeitada") } else { print("Hipotese Nula Aceita") }