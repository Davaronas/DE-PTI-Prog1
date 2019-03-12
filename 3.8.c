#include <stdio.h>

int main()
{
// Egész  
int a;

// Egészre mutató mutató 
int *b;

// Egész referenciája
int &&c = 5;

// Egészek tömbje
int d[5] = {3,2,1,5,6};

// Egészek tömbjének referenciája
int* &&e = d;

// Egészre mutató mutatók tömbje
int *f[5];
}

// Egészre mutató mutatót visszaadó függvény
int AA()
{

int *b1;

return *b1;

}

// Egészre mutató mutatót visszaadó függvényre mutató mutató
int (*CC)(int);

int BB()
{
}
