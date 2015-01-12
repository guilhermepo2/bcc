//Typedefs e Protótipos referentes à edição de alunos. - alunos_funcoes.c
typedef struct aluno aluno_nodo; //nodo aluno
typedef struct nodo_aluno ALUNO; //lista de alunos
aluno_nodo * aluno_criar_aluno(char * nome, char * matricula);
ALUNO * aluno_criar_lista(void);
ALUNO * aluno_inserir_aluno_arquivo(ALUNO * ptl, aluno_nodo * elemento);
ALUNO * aluno_inserir_aluno(ALUNO * ptl, aluno_nodo * elemento);
ALUNO * aluno_remover_aluno(ALUNO * ptl, char * chave);
ALUNO * aluno_arquivo_para_lista(void);
void aluno_imprimir_alunos(ALUNO * ptl);
void aluno_gravar_em_arquivo(ALUNO * ptl);

//Typedefs e Protótipos referentes à edicação das disciplinas. disciplinas_funcoes.c
typedef struct disciplina disciplina_nodo;
typedef struct nodo_disciplina DISCIPLINA;
DISCIPLINA * disciplina_criar_lista(void);
disciplina_nodo * disciplina_criar_disciplina(char * nome, char * codigo, int creditos);
DISCIPLINA * disciplina_inserir_disciplina_arquivo(DISCIPLINA * ptl, disciplina_nodo * elemento);
DISCIPLINA * disciplina_inserir_disciplina(DISCIPLINA * ptl, disciplina_nodo *elemento);
DISCIPLINA * disciplina_remover_disciplina(DISCIPLINA * ptl, char * chave);
void disciplina_imprimir_disciplinas(DISCIPLINA * ptl);
DISCIPLINA * disciplina_arquivo_para_lista(void);
void disciplina_gravar_em_arquivo(DISCIPLINA * ptl);
int verificar_existencia_disciplina(DISCIPLINA * ptl, char * codigo,char * disciplina);
//retorna 1 se determinada disciplina existe, caso contrário, retorna 0.
//essa função é utilizada na hora de cadastrar uma matéria que um aluno esteja cursando.

//Função do arquivo editar_aluno.c - que faz a ponte entre o arquivo principal e o arquivo de edição de alunos.
void EDICAO_DE_ALUNO(void);

//Typedefs e protótipos referente ao arquivo de edição de alunos. - editar_aluno_funcoes.c
typedef struct editar edicao_nodo;
typedef struct nodo_editar EDICAO;
EDICAO * edicao_criar_lista(void);
edicao_nodo * edicao_criar_disciplina(int estado, char * nome, char * codigo, int nota, int vezes_cursadas);
edicao_nodo * edicao_criar_disciplina_cursando(char * nome, char * codigo);
//cria uma disciplina na qual o aluno estará cursando pela primeira vez.
edicao_nodo * edicao_criar_disciplina_reprovado(char * nome, char * codigo, int vezes_cursadas);
//cria uma disciplina na qual o aluno já tenha cursado e reprovado.
EDICAO * edicao_inserir_disciplina_lista(EDICAO * ptl, edicao_nodo * elemento);
EDICAO * edicao_arquivo_para_lista(char * matricula);
void edicao_gravar_em_arquivo(EDICAO * disciplinas_cursadas, char * nome, char * matricula);
void edicao_imprimir_disciplinas_aprovadas(EDICAO * disciplinas);
void edicao_imprimir_disciplinas_reprovadas(EDICAO * disciplinas);
void edicao_imprimir_disciplinas_cursando(EDICAO * disciplinas);
EDICAO * edicao_alterar_nota(EDICAO * disciplinas, char * codigo, int nota);
EDICAO * edicao_encerrar_disciplina(EDICAO * disciplinas, char * codigo);
int verificar_disciplina(EDICAO * disciplinas, char * codigo);
//verifica se o aluno nunca fez a matéria, se está cursando, se já foi aprovado ou se foi reprovado.
int verificar_quantidade_cursada(EDICAO * disciplinas, char * codigo);
//retorna quantas vezes uma determinada disciplina já foi cursadas.
int quantidade_disciplinas_sendo_cursadas(EDICAO * disciplinas);
//retorna quantas disciplinas o aluno está cursando no momento.
