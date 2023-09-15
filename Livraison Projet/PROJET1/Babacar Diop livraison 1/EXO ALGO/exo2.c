#include <stdio.h>
int main(int argc, char const *argv[])
{
	int i,s,n;
    double m;
    
    printf("saisir un nombre");
    scanf("%d",&n);
    s=0;
    i=1;
    while(i<=n){
        s=s+i;
        i++ ;

    }
    printf("la somme est %d \n",s);

    m=s/n;
    printf("la division est %f \n",m);

	return 0;
}


