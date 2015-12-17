#include <stdio.h>
int val, i=0;
int dec2bin(int n)
{
    if (n==1)
    {
        printf("1");
        return 0;
    }
    else if (n==0)
        {   printf("0");
            return 0;
        }
    else
    {

        dec2bin(n/2);
        val=n%2;
        printf("%i", val);
        return 0;
    }
}
int main()
{   int y;
    int n;
    printf("Qual numero deseja tranformar para sua forma binaria:");
    scanf("%i", &n);
    y=dec2bin(n);
    return 0;

}
