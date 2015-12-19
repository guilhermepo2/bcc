#include "register.hpp"
#include <iostream>
#include <math.h>

Register::Register()
{
  this->sizeInBytes = 0;
}

void Register::insertChar(std::string name, std::string word)
{
  attributes.push_back(new VARCHAR(word));
  attributeNames.push_back(name);
  this->sizeInBytes += (sizeof(short int) +
			pow(2, (4 + word.size()/16)));
}

void Register::insertInt(std::string name, int entry)
{
  attributes.push_back(new FIXINT(entry));
  attributeNames.push_back(name);
  this->sizeInBytes += sizeof(int);
}

void Register::showInfo()
{
  //std::cout << "Total size: " << this->sizeInBytes << " bytes." << std::endl;
  if(this->attributes.size() == 0)
    {
      std::cout << "No Attributes in the Register." << std::endl;
    }
  else
    {
      std::cout << "(";
      for(int i = 0; i < attributes.size() - 1; i++)
	{
	  //std::cout << this->attributeNames[i] << ": ";
	  attributes[i]->showInfo();
	  std::cout << ", "; 
	}
      attributes[attributes.size()-1]->showInfo();
      std::cout << ") - Size: " << this->sizeInBytes << " bytes." << std::endl;
    }
}

int Register::getSize()
{
  return this->sizeInBytes;
}

std::string Register::getFormattedRegister()
{
  std::string myRegister = "(";
  if(this->attributes.size() > 0)
    {
      for(int i = 0; i < attributes.size()-1; i++)
	{
	  myRegister += attributes[i]->toString();
	  myRegister += ", ";
	}
      myRegister += attributes[attributes.size()-1]->toString();
    }
  myRegister += ")";
  
  return myRegister;
}
