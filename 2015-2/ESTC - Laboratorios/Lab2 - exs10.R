clubes <- c("Corinthians", "Atlético-MG", "Grêmio", "Palmeiras", "São Paulo", "Atlético-PR", "Fluminense", "Sport", "Santos", "Flamengo", "Chapecoense", "Internacional", "Ponte Preta", "Figueirense", "Avaí", "Cruzeiro", "Goiás", "Coritiba", "Joinville", "Vasco")

pontuacoes <- c(46, 42, 38, 34, 34, 33, 33, 31, 30, 29, 28, 28, 27, 26, 23, 22, 22, 22, 19, 13)

golsm <- c(33, 37, 29, 36, 29, 26, 24, 32, 31, 24, 18, 16, 21, 21, 23, 15, 19, 14, 17, 8)
golss <- c(15, 20, 17, 22, 23, 23, 22, 24, 26, 29, 21, 24, 24, 27, 33, 21, 19, 23, 25, 35)

DF <- data.frame(CLUBE=clubes, PONTUACAO=pontuacoes, GOLS_MARCADOS=golsm, GOLS_SOFRIDOS = golss)
