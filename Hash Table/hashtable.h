struct hash {
  int size;
  struct item **table; //vettore di puntatori a struct elem.
};

typedef struct hash* hashtable;

struct item {
  char *key;
  int intero1;
  int intero2;
  struct item *next;
};

hashtable newHashtable(int size);
int insertHash(hashtable h, item x);
struct item *hashSearch(hashtable h, char *key);
struct item *hashSearch(hashtable h, char *key);
void DestroyHashtable(hashtable h);

int hashFun(char *k, int m);
