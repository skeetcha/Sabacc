#include "card.h"

Card::Card(const char * n, int n_size, int v, int s, int c, bool f)
{
    for (int i = 0; i < n_size; i++)
    {
	   name[i] = n[i];
    }

    value = v;
    suit = s;
    copy = c;
    face = f;
}

Card::Card() { /* This is just for typing */ }