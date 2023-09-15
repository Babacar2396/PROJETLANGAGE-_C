#include <stdio.h>
int main(int argc, char const *argv[])
{
	int nbr,n;
    printf("saisir un nombre a deviner");
    scanf("%d", &nbr);
     printf("saisir un nombre");
    scanf("%d",&n);
    while (nbr!=n){
    printf("saisir un nombre");
    scanf("%d",&n);
    
        if (nbr>n)
    {
        printf("nombre plus petit\n");
    }
    
    else if (nbr<n)
    {
        printf("nombre plus grand\n");
    }
    }
      printf("bravo");
    
    
    
    
    
}

