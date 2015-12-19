#include "page.hpp"
#include <iostream>
#include <fstream>

class Heap
{
private:
  std::string fileName;
  std::string tableName;

public:
  std::vector<std::string> attributeNames;
  std::vector<std::string> attributeTypes;
  Heap(std::string tableName, Page * p);
  Page openFile(); // Read
  void saveFile(Page * p); // Write
};
