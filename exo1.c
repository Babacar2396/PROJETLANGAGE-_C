#include <stdio.h>
int main(int argc, char const *argv[])
{
int choice; 

 char english_months[12][12] = {"January", "April" ,"July" , "October","February", "May" ,"August", "November", "March" , "June" , "September" , "December"};
 char frenche_months[12][12]= {"Janvier", "Avril", "Juillet" , "Octobre" , "Fevrier" , "Mai" , "Aout",
 "Novembre" , "Mars" , "Juin" ,"Septembre" , "Decembre"};

 do
 {
    printf("choissisez un option\n");
    printf("1.mois en francais\n");
    printf("2.mois en Anglais \n");
    printf("3.Quitter\n");
    scanf("%d" , &choice);
    
 }while (choice!= 1 && choice != 2 && choice !=3);
 
 switch (choice)
 {
   case 1 :
            printf("\n+________________+_______________+_______________+________________\n");
        
    for (int i = 0; i < 12; i++)
    {   
        printf("%12s\t |" ,frenche_months[i]) ;
        if ((i + 1) % 4 == 0)
        { 
            printf("\n+________________+_______________+_______________+________________\n");
        }
        
    }
    
    break;
     
    case 2 :
            printf("\n+________________+_______________+_______________+________________\n");
        
    for (int i = 0; i < 12; i++)
    {
        printf("%12s\t|" , english_months[i]) ;
        if ((i + 1) % 4 == 0)
        {
            printf("\n+________________+_______________+_______________+________________\n");
        
        }
        
    }
    

    break;
 }
 
 


	return 0;
}