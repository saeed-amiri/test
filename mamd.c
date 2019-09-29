#include <stdlib.h>
#include <stdio.h>
int main()
{
long long len = 1000;
unsigned char* s;
s = malloc( sizeof(*s) * len );
    FILE *fptr;
    if ((fptr = fopen("f.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
fscanf(fptr,"%[^\n]", s);
printf("%s\n", s);
double d[3];
int i;
for ( i = 0; i < 3; i++)
{
    sscanf(s, "%lf%n", &d[i]);
    printf("%lf\n", d[i]);
}
    
exit( 0 );
}