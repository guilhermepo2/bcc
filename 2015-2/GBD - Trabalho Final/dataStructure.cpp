#include "dataStructure.hpp"
#include <iostream>
#include <math.h>
#include <malloc/malloc.h>
#include <sstream>
#include <string>

/*
A Alocação do VARCHAR é feita em blocos de 16 bytes
Cada byte é capaz de alocar 1 char, então uma alocação de 16 bytes é capaz de alocar
15 caracteres + \0

ENTRADA: DARKSOULS (10 caracteres) -> deve alocar 16 bytes
ENTRADA PlayTerminal 456 (17 caracteres) -> deve alocar 32 bytes
a quantidade de bytes alocadas: 2^(4 + entrada/16)

 */
/*--------------------------------------------------------------------------
                       CLASSE ATRIBUTO
--------------------------------------------------------------------------*/
const void Attribute::showInfo()
{
  std::cout << "Generic Show" << std::endl;
}

const std::string Attribute::toString()
{
  std::string str="error";
  return str;
}

varType Attribute::getDataType()
{
  return this->dataType;
}

void Attribute::setDataType(varType dataType)
{
  this->dataType = dataType;
}
/*--------------------------------------------------------------------------
                       CLASSE VARCHAR
--------------------------------------------------------------------------*/
VARCHAR::VARCHAR(std::string varchar_entry)
{
  int sizeAllocated = pow(2, MACHINE_BASE_POWER + (varchar_entry.size()/16));
  this->setDataType(_VARCHAR);
  this->varchar_entry = (char*)malloc(sizeAllocated);
  
  for(int i = 0; i < varchar_entry.size(); i++)
    {
      this->varchar_entry[i] = varchar_entry[i];
    }
  this->varchar_entry[varchar_entry.size()] = '\0';
  
  this->varchar_size = malloc_size(this->varchar_entry);
}

const void VARCHAR::showInfo()
{
  std::cout << this->varchar_entry;
}

const std::string VARCHAR::toString()
{
  std::string str = "";
  str += this->varchar_entry;

  return str;
}
/*--------------------------------------------------------------------------
                       CLASSE FIXINT
--------------------------------------------------------------------------*/
FIXINT::FIXINT(int fixint_entry)
{
  this->fixint_entry = fixint_entry;
  this->setDataType(_FIXINT);
}

const void FIXINT::showInfo()
{
  std::cout << this->fixint_entry;
}

const std::string FIXINT::toString()
{
  std::string str="";
  char myInteger[10];
  sprintf(myInteger, "%d", this->fixint_entry);
  str = myInteger;
  //str+= static_cast<std::ostringstream*>( & (std::ostringstream() << this->fixint_entry))->str();
  return str;
}
