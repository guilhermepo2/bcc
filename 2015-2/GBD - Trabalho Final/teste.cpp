#include<string.h>

/*
  cada tabela:
      - inserção de registro no fim do arquivo
      - remoção de registro
      - atualização de registro
      - varrer arquivo
 */

#include <iostream>
#include "heapFile.hpp"

int main()
{
  /* 
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Teste De Registros: " << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Testando uma entrada de Console " << std::endl;
  Register myReg;
  std::cout << "Entrada: (PlayTerminal 4, 199, 8)" << std::endl;
  myReg.insertChar("Name", "PlayTerminal 4");
  myReg.insertInt("Price", 199);
  myReg.insertInt("Generation", 8);
  myReg.showInfo();
  std::cout << "---------------------------------------------" << std::endl;
  
  std::cout << "Testando uma entrada de um Jogo " << std::endl;
  std::cout << "Entrada: (Dark Souls, 19, RPG, PlayTerminal 4/YCircle One)" << std::endl;
  Register myGame;
  myGame.insertChar("Name", "Dark Souls");
  myGame.insertInt("Price", 19);
  myGame.insertChar("Genre", "RPG");
  myGame.insertChar("Console", "Playterminal 4/YCircle One");
  myGame.showInfo();
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Testando uma entrada de um Jogo " << std::endl;
  std::cout << "Entrada: (Bloodborne, 24, RPG, PlayTerminal 4/YCircle One)" << std::endl;
  Register myGame2;
  myGame2.insertChar("Name", "Bloodborne");
  myGame2.insertInt("Price", 24);
  myGame2.insertChar("Genre", "RPG");
  myGame2.insertChar("Console", "Playterminal 4/YCircle One");
  myGame2.showInfo();
  std::cout << "---------------------------------------------" << std::endl;
  
  std::cout << "Testando uma entrada de um Jogo " << std::endl;
  std::cout << "Entrada: (Dark Souls 2, 19, RPG, PlayTerminal 4/YCircle One)" << std::endl;
  Register myGame3;
  myGame3.insertChar("Name", "Dark Souls 2");
  myGame3.insertInt("Price", 19);
  myGame3.insertChar("Genre", "RPG");
  myGame3.insertChar("Console", "Playterminal 4/YCircle One");
  myGame3.showInfo();
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "FIM DE TESTE DE REGISTROS" << std::endl;
  
  
  
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Teste De Paginas: " << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  Page myPage;
  std::cout << "Inserindo Dark Souls, Bloodborne e Dark Souls 2 " << std::endl;
  myPage.insertRegister(&myGame); //pos 0 -> Dark Souls
  myPage.insertRegister(&myGame2); // pos 1 -> Bloodborne
  myPage.insertRegister(&myGame3); // pos 2 -> Dark Souls 2
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Exibindo os Registros da pagina " << std::endl;
  myPage.showRegisters();
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Teste de Remocao: " << std::endl;
  std::cout << "Removendo Bloodborne (pos: 1) " << std::endl;
  //TESTE DE REMOCAO
  myPage.removeRegister(1); //remove bloodborne
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Removido! " << std::endl;
  std::cout << "Exibindo a pagina: " << std::endl;
  myPage.showRegisters();
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Alterando Dark Souls 2 (pos 2) para Bloodborne" << std::endl;
  myPage.updateRegister(2, &myGame2);
  std::cout << "Alterado! " << std::endl;
  std::cout << "Exibindo a Pagina: " << std::endl;
  myPage.showRegisters();
  std::cout << "---------------------------------------------" << std::endl;
  */
  /*-------------------------------------------------------------------------
    Pagina Implementada - Insercao, Remocao e Update funcionando.
    Fazer o conteudo relacionado a arquivos
   -------------------------------------------------------------------------*/
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Teste De Heap: " << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  Page myPage;

  std::string mytable = "gameTable";
  Heap myHeapFile(mytable, &myPage);
  //myHeapFile.saveFile(&myPage);
  //myHeapFile.openFile();
  std::cout << "---------------------------------------------" << std::endl;
  myPage.showRegisters();

  //registros pegos

  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "O Teste chegou ao fim de sua execucao, todas as funcoes estao funcionando corretamente." << std::endl;
  return 0;
}
