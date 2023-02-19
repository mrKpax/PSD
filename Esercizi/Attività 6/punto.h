#define NULLITEM NULL

typedef struct Punto *punto;

punto creaPunto(float x, float y);
void printItem(punto p);
float getAscissa(punto p);
float getOrdinata(punto p);
int eq(punto p1, punto p2);
float distanza(punto p1, punto p2);
