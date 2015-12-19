.data
getn: .asciiz "Digite N: "
#shown: .asciiz "Valor de N: "
preencha: .asciiz "Preencha a Matriz: "
#somatorio: .asciiz "Somatorio: "
#exibir_matriz: .asciiz "Exibindo Matriz: "
resultado_somatorio: .asciiz "Resultado do Somatorio: "

.text

#lendo N do teclado
addi $v0, $zero, 4
la $a0, getn
syscall #print da string "Digite N: "

li $v0, 5
syscall #pega input do teclado
move $t0, $v0 #agora N esta em t0

#mostrando o valor de N:

#addi $v0, $zero, 4
#la $a0, shown
#syscall

#addi $v0, $zero, 1
#move $a0, $t0
#syscall

#alocando espaco de N * N
mul $t1, $t0, $t0 # t1 = N * N
addi $t2, $zero, 4
mul $a0, $t1, $t2 # a0 <- N*N * 4 (numero de bytes a alocar)
li $v0, 9 
syscall #call para alocar a0 bytes, o endereco estara em v0
move $s1, $v0

#endereco de um array de N * N bytes esta em s1
# N esta em t0

#preencher a matriz

preencher_matriz:
addi $v0, $zero, 4
la $a0, preencha
syscall

#loop para preencher a matriz usando como contador t6 e t7
#t6 = i
#t7 = j
#auxiliares para ajudar a calcular o deslocamento
addi $t4, $zero, 4
mul $t4, $t4, $t0
addi $t5, $zero, 4
add $t6, $zero, $zero
preencher_externo:
	add $t7, $zero, $zero
preencher_interno:
	#pegando o valor da matriz
	#calculando o deslocamento
	mul $t3, $t4, $t6 # t3 <- i * 8
	mul $t2, $t5, $t7 # t2 <- j * 4
	add $t3, $t3, $t2 # t3 <- t3 + t2 = deslocamento em bytes
	#pegando input do teclado para a posicao
	la $t1, ($s1) # t1 <- endereco(s1)
	add $t1, $t1, $t3 #t1 += deslocamento
	
	addi $v0, $zero, 5
	syscall #pega input do teclado
	sw $v0, ($t1)
	# move $t1, $v0 #agora o valor esta em t3
	#loop stuff
	addi $t7, $t7, 1 #j++
	bge $t7, $t0, preencher_externo_fim # if (j >= N) goto preencher_externo_fim
	j preencher_interno # else goto preencher_interno
	
preencher_externo_fim:
	addi, $t6, $t6, 1 #i++
	bge $t6, $t0, calculo_somatorio #if (i >= N) goto calculo_somatorio
	j preencher_externo #else goto preencher_externo
	
calculo_somatorio:
	# exibindo a matriz para assegurar de que tudo ocorreu bem
	# endereco da matriz: $s1
	# N: $t0
	# addi $v0, $zero, 4
	# la $a0, exibir_matriz
	# syscall #print da string "Exibindo a Matriz: "
	
	# move $t1, $s1 # <- t1 <- endereco(s1)
	# mul $t2, $t0, $t0 # t2 <- N * N
	# add $t3, $zero, $zero # t3 <- 0

	# loop_exibir_matriz:
	#	# print da posicao atual do vetor
	#	addi $v0, $zero, 1
	#	lw $a0, 0($t1)
	#	syscall
	#	addi $t1, $t1, 4 # t1 += 4
	#	addi $t3, $t3, 1
	#	blt $t3, $t2, loop_exibir_matriz # if t1 < t2 goto loop_exibir_matriz
		
	# matriz impressa com sucesso
	# agora deve ser calculada a somatoria
	
# endereco da matriz: $s1
# N: $t0
#colocando o resultado da soma em t1
add $t1, $zero, $zero # t1 <- 0 - vai guardar o resultado da soma
addi $t2, $zero, 2 # t2 <- 2
rem $t3, $t0, $t2 # t3 = N % 2
beqz $t3, calculo_somatoria_se_par # goto calculo_somatoria_se_par if t3 == 0

#t1 = somatorio
	
calculo_somatoria_se_impar:
# t6 = i
# t7 = aux
add $t6, $zero, $zero # t6 <- 0
div $t7, $t0, $t2 # <= t7 = N/2
# somatorio += (matriz[i][aux] * matriz[aux][i])
loop_somatorio_impar:
	
	#pegando o deslocamento necessario para se avancar de linha
	addi $t2, $zero, 4
	mul $t5, $t2, $t0 # t5 <- 4 * N
	#pegando o endereco do array
	move $t2, $s1 # t2 <- s1
	add $t3, $zero, $t5# t3 <- t5
	mul $t3, $t3, $t6 # <- t3 <- t3 * i
	add $t2, $t2, $t3 # deslocando as linhas da matriz
	
	addi $t3, $zero, 4
	mul $t3, $t3, $t7
	add $t2, $t2, $t3 # deslocando as colunas da matriz
	lw $t2, 0($t2)
	# t2 possui agora matriz[i][aux]
	
	move $t3, $s1
	add $t4, $zero, $t5 # t4 <- 8
	mul $t4, $t4, $t7  # t4 <- t4 * aux
	add $t3, $t3, $t4  # deslocando as linhas da matriz
	
	addi $t4, $zero, 4
	mul $t4, $t4, $t6
	add $t3, $t3, $t4 # deslocando as colunas da matriz
	lw $t3, 0($t3)
	# t3 possui agora matriz[aux][i]
	
	mul $t4, $t3, $t2
	add $t1, $t1, $t4
	addi $t6, $t6, 1 # t6++
	
	bge $t6, $t0, imprimir_somatorio # imprimir_somatorio if i >= N
	j loop_somatorio_impar
	

calculo_somatoria_se_par:

# t6 = i
# t7 = j
add $t6, $zero, $zero # t6 <- 0
add $t7, $t0, -1 # t7 <- N-1
# somatorio += (matriz[i][i] * matriz[i][j])
# pegar matriz[i][i] - registradores disponiveis: t2 t3 t4 t5

	#pegando o deslocamento necessario para se avancar de linha
	addi $t2, $zero, 4
	mul $t5, $t2, $t0 # t5 <- 4 * N
loop_somatorio_par:
	#pegando o endereco do array
	move $t2, $s1 # t2 <- s1
	add $t3, $zero, $t5 # t3 <- t5
	mul $t3, $t3, $t6 # <- t3 <- t3 * i
	add $t2, $t2, $t3 # deslocando as linhas da matriz
	
	addi $t3, $zero, 4
	mul $t3, $t3, $t6
	add $t2, $t2, $t3 # deslocando as colunas da matriz
	lw $t2, 0($t2)
	# t2 possui agora matriz[i][i]
	
	move $t3, $s1
	add $t4, $zero, $t5 # t4 <- t5
	mul $t4, $t4, $t6 # <- t4 <- t4 * i
	add $t3, $t3, $t4 # deslocando as linhas da matriz
	
	addi $t4, $zero, 4
	mul $t4, $t4, $t7
	add $t3, $t3, $t4 # deslocando as colunas da matriz
	lw $t3, 0($t3)
	# t3 possui agora matriz[i][j]
	
	mul $t4, $t3, $t2
	add $t1, $t1, $t4
	addi $t7, $t7, -1 # t7--
	addi $t6, $t6, 1 # t6++
	bge $t6, $t0, imprimir_somatorio # imprimir_somatorio if i >= N
	j loop_somatorio_par
	
imprimir_somatorio:

	addi $v0, $zero, 4
	la $a0, resultado_somatorio
	syscall

	addi $v0, $zero, 1
	move $a0, $t1
	syscall

fim:
	addi $v0, $zero, 10
	syscall