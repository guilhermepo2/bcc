#include "dataStructure.hpp"

/*
  REGISTRO
  A classe do Registro tem um inteiro para indicar o tamanho em bytes do registro, um vetor do tipo Attribute para que possam ser colocados os VARCHAR e os FIXINT dentro do registro, e um vetor de strings, com o nome dos atributos a serem inseridos no registro.
 */

class Register
{
private:
  int sizeInBytes;
  std::vector<Attribute*> attributes;
  std::vector<std::string> attributeNames;
public:
  Register();
  void insertChar(std::string name, std::string word);
  void insertInt(std::string name, int entry);
  int getSize();
  void showInfo();
  std::string getFormattedRegister();
};
