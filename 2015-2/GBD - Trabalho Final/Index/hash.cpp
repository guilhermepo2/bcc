#include "hash.hpp"
#include <iostream>

int Hash::h(int key)
{
  if(key == -1)
    return 0;
  else
    return (key%(this->N));
}

Hash::Hash()
{
  this->level = 0;
  this->next = 0;
  this->N = 4;

  std::vector<kstar> temp;
  for(int i = 0; i < this->N; i++)
    {
      this->buckets.push_back(temp);
    }
  std::cout << this->buckets.size() << std::endl;
}

void Hash::hinsert(kstar k)
{

}
