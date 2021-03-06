hashtable newHashtable(int size)
{
  int i;
  hashtable h = (struct hash *) malloc(sizeof(struct hash));
  h->size = size;
  h->table = (struct item **) calloc(size, sizeof(struct item *));
  // for (i=0; i<size; i++)
  //      h->table[i] = NULL;
  return h;
}

int insertHash(hashtable h,  struct item elem)
{
  int idx;
  struct item *head, *curr;
  idx = hashFun(elem.key, h->size);
  curr = head = h->table[idx];
  while (curr)
  {
    if(strcmp(curr->key, elem.key) == 0)
        return (0);
    curr = curr->next;
  }
  h->table[idx] = newItem(elem.key, elem.intero1, elem.intero2);
  h->table[idx]->next = head;
  return (1);
}  
  
struct item *hashDelete(hashtable h, char *key)
{
  int idx;
  struct item *prev, *curr, *head, *temp;
  idx = hashFun(key, h->size);
  prev = curr = head = h->table[idx];
  while (curr)
  {
    if (!strcmp(curr->key, key))
    {
        if (curr == head) h->table[idx] = curr->next;
        else prev->next = curr->next;
        return (curr);
    }
    prev = curr;
    curr = curr->next;
  }
  return NULL;
}

void DestroyHashtable(hashtable h)
{
  int i;
  for (i=0; i<h->size; i++)
      deleteList(h->table[i]);
  free(h->table);
  free(h);
  return;
}

static void deleteList(struct item *p)
{
  if (p==NULL) return;
  deleteList(p->next);
  free(p);
  return;
}

struct item *hashSearch(hashtable h, char *key);

int hashFun(char *k, int m);
