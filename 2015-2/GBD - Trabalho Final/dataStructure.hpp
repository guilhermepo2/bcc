#include <vector>
#include "definitions.hpp"

/*
ENUM para o atributo discriminador na classe base de Atributo, o atributo dentro dessa clase pode ser do tipo _FIXINT, int de tamanho fixo (4 bytes) e _VARCHAR, uma dupla de um int de 2 bytes para contar o tamanho da string de entrada e a string de entrada.
 */
enum varType { _FIXINT, _VARCHAR };


/*
  CLASSE BASE ATRIBUTO

  A classe base serve para generalizar os tipos basicos que vão ser utilizados no banco de dados, ela possui um atributo discriminador enum (que pode ser _FIXINT e _VARCHAR) e um ponteiro do tipo atributo. O ponteiro do tipo atributo apontará para uma classe especializada do tipo VARCHAR ou FIXINT

 */
class Attribute
{
private:
  varType dataType;
  Attribute * attribute;
public:
  virtual const void showInfo();
  varType getDataType();
  void setDataType(varType dataType);
  virtual const std::string toString();
};

/*
  CLASSE VARCHAR

  A Classe VARCHAR é uma especialização da classe atributo, ela possui um int de 2 bytes para medir o tamanho da string de entrada, também possui a própria string de entrada, que é um ponteiro para char, para que tenha tamanho variável.
  O Ponteiro para char é alocado no tamanho de um unsigned short int, para que as strings possam ir de 0 a 64kB

 */

class VARCHAR : public Attribute
{
private:
  short int varchar_size;
  char * varchar_entry;
public:
  VARCHAR(std::string varchar_entry);
  virtual const void showInfo();
  virtual const std::string toString();
};

/*
  CLASSE FIXINT

  A Classe FIXINT é uma especialização da classe Atributo e possui apenas um inteiro de 4 bytes para a entrada no banco de dados.
 */

class FIXINT : public Attribute
{
private:
  int fixint_entry;
public:
  FIXINT(int fixint_entry);
  virtual const void showInfo();
  virtual const std::string toString();
};
