// PAGE SIZE
#define PAGESIZE 4096
// NOME DO ARQUIVO DO CATALOGO
#define CATALOG_FILE_NAME "catalogo.txt"

//definicoes para MAC OS X
#define LIMPAR_TELA system("clear");
#define PAUSA system( "read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"" );


// DEBUG
#define DEBUG 1

#if __GNUC__
#if __x86_64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

#ifdef ENVIRONMENT64
#ifndef MACHINE_BASE_POWER
#define MACHINE_BASE_POWER 4
#endif
#endif
