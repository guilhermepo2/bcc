#include <vector>

//quantidade de entradas em um bucket

#define FULL 4

struct rid
{
  int pageid;
  int slotid;
};

struct kstar
{
  int key;
  rid rid;
};

class Hash
{
private:
  int level;
  int N;
  int next;
  std::vector<std::vector<kstar> > buckets;
public:
  Hash();
  int h(int key);
  void hinsert(kstar k);
};
