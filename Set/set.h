typedef struct c_set *set;

set newSet(void);
int emptySet(set s);
int cardinality(set s);
int contains(set s, item e);

int insertSet(set s, item e); //inserisce e in s
int removeSet(set s, item e); //rimuove e da s

int unionSet(set s1, set s2); //aggiunge elementi di s2 ad s1
int intersectSet(set s1, set s2); //rimuove da s1 gli elementi che non sono in s2
