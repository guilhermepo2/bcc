#include "heapFile.hpp"
#include <string.h>
#include <stdio.h>
#include <sstream>


/* -------------------------------------------------------
   CONSTRUTOR
   Cria um novo arquivo de heap recebendo o nome de uma tabela como argumento
   
   -------------------------------------------------------*/
Heap::Heap(std::string tableName, Page * p)
{
  // le o catalogo, pega o nome do arquivo e nome da tabela
  std::ifstream catalog (CATALOG_FILE_NAME);      // arquivo do catalogo
  std::string line;
  std::string prefix = "table:";
  std::string token;
  Register * myReg;
  
  if(catalog.is_open())
    {
      while(getline(catalog, line))
	{
	  if(line.substr(0,prefix.size()) == prefix)
	    {
	      //std::cout << line << std::endl;
	      line = line.substr(prefix.size()+2, line.size()); // retirando o escrito "table: "
	      //std::cout << line << std::endl;
	      
	      //formata
	      token = line.substr(0, line.find(','));            // pegando o nome
	      line = line.substr(line.find(',')+2, line.size()); // movendo string
	      //std::cout << token << std::endl;
	      
	      if(token == tableName)
		{
		  std::cout << "Arquivo de Heap Criado" << std::endl;
		  this->tableName = token;
		  token = line.substr(0, line.find(','));
		  //std::cout << token << std::endl;
		  this->fileName = token;
		  std::ifstream f(this->fileName);
		  if(!f.good()) // o arquivo nao existia entao ele e criado
		    {
		      std::ofstream tableFile(this->fileName);
		      tableFile.close();
		    }
		  else // o arquivo existe entao faz load
		    {
		      getline(catalog,line);

		      //pegando as informacoes de variavel e atributos
		      line=line.substr(line.find('('), line.size());
		      token = line.substr(1,line.find(',')-1);
		      line = line.substr(line.find(',')+1, line.size());
		      while(token[token.size()-1] != ')')
		      {
			this->attributeTypes.push_back(token.substr(0,token.find(' ')));
			this->attributeNames.push_back(token.substr(token.find(' ')+1,token.size()));
			token = line.substr(1,line.find(',')-1);
			line = line.substr(line.find(',')+1, line.size());
		      }
		      token = line.substr(1, line.find(')')-1);
		      this->attributeTypes.push_back(token.substr(0,token.find(' ')));
		      this->attributeNames.push_back(token.substr(token.find(' ')+1,token.size()));
		      //nome das variaveis e seus atributos salvo nos vetores.
		      //agora deve-se abrir o arquivo e carregar a pagina para memoria
		      std::cout << "ATRIBUTOS PEGOS!" << std::endl;
	       
		      while(getline(f, line))
			{
			  if(line != "Removed")
			    {
			      //para cada linha, pegar attributeTypes.size() tokens
			      //std::cout << line << std::endl;
			      line = line.substr(1, line.size()-2);
			      //std::cout << line << std::endl;
			      myReg = new Register();
			      for(int i = 0; i < attributeTypes.size(); i++)
				{
				  token = line.substr(0,line.find(','));
				  line = line.substr(line.find(',')+2, line.size());

				  //std::cout << token << std::endl;
				  //TOKEN PEGO
				  // DEVE SER ADICIONADO A PAGINA
				  if(attributeTypes[i] == "varchar")
				    {
				      //std::cout << "hey" << std::endl;
				      //std::cout << attributeNames[i] << std::endl;
				      //std::cout << token << std::endl;
				      
				      myReg->insertChar(attributeNames[i],token);
				      //std::cout << "hey" << std::endl;
				    }
				  else
				    {
				      //std::cout << "hey" << std::endl;
				      std::istringstream buffer(token);
				      int value;
				      buffer >> value;
				      myReg->insertInt(attributeNames[i],value);
				      //std::cout << "hey" << std::endl;
				    }
				}
			      std::cout << "Registro: " << std::endl;
			      myReg->showInfo();
			      p->insertRegister(myReg);
			    }
			}
		    }
		  f.close();
		}
	    }
	}
      catalog.close();
    }
  else std::cout << "Unable to open file." << std::endl;
}

/*
Page Heap::openFile()
{
  Page myPage;
  this->attributeNames.clear();
  this->attributeTypes.clear();
  
  std::ifstream tableFile(this->fileName);
  std::string line;
  //pegar o catalogo
  std::ifstream catalog(CATALOG_FILE_NAME);
  //pegar no catalogo o nome e tipo dos atributos
  

  
  //ler linhas
  while(getline(tableFile,line))
    {
      if(line != "Removed")
	std::cout << line << std::endl;
    }
  //retirar do arquivo as linahs que sao colocadas na memoria
  tableFile.close();
  
  return myPage;
  } */


void Heap::saveFile(Page * p)
{
  std::ofstream tableFile(this->fileName);
  //std::fstream tableFile(this->fileName, std::fstream::in | std::fstream::out | std::fstream::app);

  for(int i = 0; i < p->getRegisterCount(); i++)
    {
      tableFile << p->getFormattedPageRegister(i) << '\n';
      //std::cout << p->getFormattedPageRegister(i) << std::endl;
    }
  tableFile.close();
}
