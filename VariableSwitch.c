#include <stdio.h>

int main()
{

int a;
int b;

printf("Enter first number(integer)");
printf("\n");
scanf("%d", &a);
printf("\n");

printf("Enter second number(integer)");
printf("\n");
scanf("%d", &b);
printf("\n");


a = a - b;
b = a + b;
a = b - a;

printf("%d", a);
printf("\n");
printf("%d", b);
printf("\n");

}
