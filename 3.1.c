#include <stdio.h>
int main()
{
    printf("Kérek egy decimális számot! ");
    char decimal[1024];
    scanf("%s", decimal);
    char unary[1024];
    char szamok[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int hely = 0;
    int hely1 = 0;
    int hely3 = 0;
    printf("\n\n");
    while(decimal[0] != '0')
    {
        while(decimal[hely+1] != 0)
            hely++;

        while(decimal[hely] != szamok[hely1])
            hely1++;

        if(szamok[hely1] != '0')
        {
            hely1--;
            decimal[hely] = szamok[hely1];
        }
        else
        {
            hely1 = 9;
            decimal[hely] = szamok[hely1];
        }
        unary[hely3] = '1';
        hely3++;

        printf("%s\n", decimal);
        printf("%s\n", unary);
    }

    return 0;
}
