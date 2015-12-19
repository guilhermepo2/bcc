#include "heapFile.hpp"
#include <iostream>
#include <string.h>

void consoleTable()
{
  Register * consoleRegister;
  Page consolePage;
  Heap consoleHeap("consoleTable", &consolePage);

  int insertInt;
  std::string insertString;
  
  int consoleInput;
  while(consoleInput != 5)
    {
      LIMPAR_TELA
      std::cout << "--------------------------------------------"   << std::endl;
      std::cout << "Banco de Dados YOUDIEDGames - Consoles"            << std::endl;
      std::cout << "Selecione a opcao desejada: "                   << std::endl;
      std::cout << "1 - Inserir Registro no Fim do Arquivo"         << std::endl;
      std::cout << "2 - Remover Registro de uma Posicao"            << std::endl;
      std::cout << "3 - Atualizar um Registro de uma Posicao"       << std::endl;
      std::cout << "4 - Varrer o Arquivo"                           << std::endl;
      std::cout << "5 - Voltar para o Banco de Dados"               << std::endl;
      std::cout << "--------------------------------------------"   << std::endl;
      std::cout << "Escolha: "; std::cin >> consoleInput;

      switch(consoleInput)
	{
	case 1:
	  consoleRegister = new Register();
	  for(int i = 0; i < consoleHeap.attributeTypes.size(); i++)
	    {
	      std::cin.ignore();
	      
	      std::cout << consoleHeap.attributeTypes[i] << " "
			<< consoleHeap.attributeNames[i] << ": ";
	      if(consoleHeap.attributeTypes[i] == "varchar")
		{
		  getline(std::cin, insertString);
		  consoleRegister->insertChar(consoleHeap.attributeNames[i],
					      insertString);
		}
	      else
		{
		  std::cin >> insertInt;
		  consoleRegister->insertInt(consoleHeap.attributeNames[i],
					      insertInt);
		}
	    }
	  consolePage.insertRegister(consoleRegister);
	  PAUSA
	  break;
	  
	case 2:
	  int positionToRemove;
	  std::cout << "Digite a posicao que deseja remover: ";
	  std::cin >> positionToRemove;
	  consolePage.removeRegister(positionToRemove);
	  PAUSA
	  break;
	case 3:
	  int positionToUpdate;
	  std::cout << "Digite a posicao a ser atualizada: ";
	  std::cin >> positionToUpdate;

	  consoleRegister = new Register();
	  for(int i = 0; i < consoleHeap.attributeTypes.size(); i++)
	    {
	      std::cin.ignore();
	      std::cout << consoleHeap.attributeTypes[i] << " "
			<< consoleHeap.attributeNames[i] << ": ";
	      if(consoleHeap.attributeTypes[i] == "varchar")
		{
		  getline(std::cin, insertString);
		  consoleRegister->insertChar(consoleHeap.attributeNames[i],
					      insertString);
		}
	      else
		{
		  std::cin >> insertInt;
		  consoleRegister->insertInt(consoleHeap.attributeNames[i],
					      insertInt);
		}
	    }

	  consolePage.updateRegister(positionToUpdate, consoleRegister);
	  PAUSA
	  break;
	case 4:
	  LIMPAR_TELA
	  consolePage.showRegisters();
	  PAUSA
	  break;
	case 5:
	  std::cout << "Saindo..." << std::endl;
	  consoleHeap.saveFile(&consolePage);
	  break;
	default:
	  std::cout << "Opcao Invalida..." << std::endl;
	  PAUSA
	  break;
	}
    }
}

void gameTable()
{
  Register * gameRegister;
  Page gamePage;
  Heap gameHeap("gameTable", &gamePage);

  int insertInt;
  std::string insertString;
  
  int gameInput;
  while(gameInput != 5)
    {
      LIMPAR_TELA
      std::cout << "--------------------------------------------"   << std::endl;
      std::cout << "Banco de Dados YOUDIEDGames - Jogos"            << std::endl;
      std::cout << "Selecione a opcao desejada: "                   << std::endl;
      std::cout << "1 - Inserir Registro no Fim do Arquivo"         << std::endl;
      std::cout << "2 - Remover Registro de uma Posicao"            << std::endl;
      std::cout << "3 - Atualizar um Registro de uma Posicao"       << std::endl;
      std::cout << "4 - Varrer o Arquivo"                           << std::endl;
      std::cout << "5 - Voltar para o Banco de Dados"               << std::endl;
      std::cout << "--------------------------------------------"   << std::endl;
      std::cout << "Escolha: "; std::cin >> gameInput;

      switch(gameInput)
	{
	case 1:
	  gameRegister = new Register();
	  for(int i = 0; i < gameHeap.attributeTypes.size(); i++)
	    {
	      //std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
	      std::cin.ignore();
	      
	      std::cout << gameHeap.attributeTypes[i] << " " << gameHeap.attributeNames[i] << ": ";
	      if(gameHeap.attributeTypes[i] == "varchar")
		{
		  getline(std::cin, insertString);
		  gameRegister->insertChar(gameHeap.attributeNames[i], insertString);
		}
	      else
		{
		  std::cin >> insertInt;
		  gameRegister->insertInt(gameHeap.attributeNames[i], insertInt);
		}
	    }
	  gamePage.insertRegister(gameRegister);
	  PAUSA
	  break;
	case 2:
	  int positionToRemove;
	  std::cout << "Digite a posicao que deseja remover: ";
	  std::cin >> positionToRemove;
	  gamePage.removeRegister(positionToRemove);
	  PAUSA
	  break;
	case 3:
	  int positionToUpdate;
	  std::cout << "Digite a posicao a ser atualizada: ";
	  std::cin >> positionToUpdate;
	  
	  gameRegister = new Register();
	  for(int i = 0; i < gameHeap.attributeTypes.size(); i++)
	    { 
	      std::cin.ignore();
	      
	      std::cout << gameHeap.attributeTypes[i] << " " << gameHeap.attributeNames[i] << ": ";
	      if(gameHeap.attributeTypes[i] == "varchar")
		{
		  getline(std::cin, insertString);
		  gameRegister->insertChar(gameHeap.attributeNames[i], insertString);
		}
	      else
		{
		  std::cin >> insertInt;
		  gameRegister->insertInt(gameHeap.attributeNames[i], insertInt);
		}
	    }
	  gamePage.updateRegister(positionToUpdate, gameRegister);
	  PAUSA
	  break;
	case 4:
	  LIMPAR_TELA
	  gamePage.showRegisters();
	  PAUSA
	  break;
	case 5:
	  std::cout << "Saindo..." << std::endl;
	  gameHeap.saveFile(&gamePage);
	  break;
	default:
	  std::cout << "Opcao Invalida..." << std::endl;
	  PAUSA
	  break;
	}
    }
}

int main()
{
  int input;
  while(input != 3)
    {
      LIMPAR_TELA
      std::cout << "--------------------------------------------" << std::endl;
      std::cout << "Banco de Dados YOUDIEDGames" << std::endl;
      std::cout << "Selecione em qual tabela deseja operar: " << std::endl;
      std::cout << "1 - Tabela de Consoles" << std::endl;
      std::cout << "2 - Tabela de Jogos" << std::endl;
      std::cout << "3 - Sair do Banco de Dados" << std::endl;
      std::cout << "--------------------------------------------" << std::endl;
      std::cout << "Escolha: "; std::cin >> input;

      switch(input)
	{
	case 1:
	  consoleTable();
	  PAUSA
	  break;
	case 2:
	  gameTable();
	  PAUSA
	  break;
	case 3:
	  std::cout << "Saindo..." << std::endl;
	  break;
	default:
	  std::cout << "Escolha Invalida." << std::endl;
	  PAUSA
	  break;
	}
    }
  return 0;
}
