#include "register.hpp"

class Page {
private:
  int pageSize = PAGESIZE;
  int bytesLeft;
  Register * registers;
  std::vector<Register*> registerAdress;
  std::vector<bool> isRemoved; // false = not removed, true = removed
  int registerCount;
  Register * freeSpace;
public:
  Page();
  void insertRegister(Register * reg);
  void removeRegister(int position);
  void updateRegister(int position, Register * newReg);
  void showRegisters();
  int getRegisterCount();
  std::string getFormattedPageRegister(int index);
};
