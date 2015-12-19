#include "page.hpp"
#include <malloc/malloc.h>
#include <iostream>

Page::Page()
{
  this->registers = (Register*)malloc(PAGESIZE);
  this->registerCount = 0;
  this->freeSpace = registers;
  this->bytesLeft = PAGESIZE;

  #if DEBUG
  std::cout << "registers: " << registers << std::endl;
  std::cout << "&registers: " << &registers << std::endl;
  std::cout << "freeSpace: " << freeSpace << std::endl;
  #endif
}

void Page::insertRegister(Register * reg)
{
  this->freeSpace = reg;
  this->registerAdress.push_back(this->freeSpace);
  this->isRemoved.push_back(false);
  this->freeSpace += reg->getSize();
  this->bytesLeft -= reg->getSize();
  this->registerCount++;
}

void Page::removeRegister(int position)
{
  if(position > registerCount || isRemoved[position] == true)
    {
      std::cout << "There is no such register position" << std::endl;
      return;
    }
  
  isRemoved[position] = true;
}

void Page::updateRegister(int position, Register * newReg)
{
  this->removeRegister(position);
  this->insertRegister(newReg);
}

void Page::showRegisters()
{
  std::cout << "Bytes Left on page: " << this->bytesLeft << std::endl;
  Register * myReg;
  for(int i = 0; i < registerAdress.size(); i++)
    {
      std::cout << i << ": ";
      if(!(isRemoved[i]))
	{
	  myReg = registerAdress[i];
	  myReg->showInfo();
	}
      else std::cout << std::endl;
    }
}

int Page::getRegisterCount()
{
  return this->registerCount;
}

std::string Page::getFormattedPageRegister(int index)
{
  std::string registerString;
  Register * myReg;
  if(isRemoved[index])
    {
      return "Removed";
    }
  else myReg = registerAdress[index];

  registerString = myReg->getFormattedRegister();
  
  return registerString;
}
