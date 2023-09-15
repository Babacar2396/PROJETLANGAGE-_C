#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define FICHIER "operateurs.txt"

#define MAX_OPERATEURS 10 // nombre maximum d'opérateurs
#define MAX_CLIENTS 100 // nombre maximum de clients
#define MAX_NOM 50 // longueur maximale du nom et prénom
#define MAX_NUMERO 20 // longueur maximale du numéro de téléphone

// Définition de la structure Client
struct Client {
    char nom[MAX_NOM];
    char prenom[MAX_NOM];
    char numero[MAX_NUMERO];
};

// Déclaration de la matrice de clients
struct Client clients[MAX_OPERATEURS][MAX_CLIENTS];      
int nbClients[MAX_OPERATEURS] = {0}; // nombre de clients pour chaque opérateur

// Déclaration des opérateurs
char operateurs[MAX_OPERATEURS][MAX_NOM] = {
    "Orange", "Tigo", "Expresso"
};
int nbOperateurs = 3;

// Fonction pour vérifier si un numéro est valide
bool numeroValide(char* numero) {
    int len = strlen(numero);
    if (len != 9 || len != 12) {
        return false;
    }
    if (numero[0] != '7') {
        return false;
    }
    if (numero[1] != '7' ||  numero[1] != '8' || numero[1] != '6' || numero[1] != '0' || numero[1] != '5')
    {
        return false;
    }
    
    for (int i = 1; i < len; i++) {
        if (numero[i] < '0' || numero[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int main() {
    // Charger les données du fichier s'il existe
    FILE* f = fopen("clients.txt", "r");
    if (f != NULL) {
        for (int i = 0; i < nbOperateurs; i++) {
            fscanf(f, "%d", &nbClients[i]);
            for (int j = 0; j < nbClients[i]; j++) {
                fscanf(f, "%s %s %s", clients[i][j].nom, clients[i][j].prenom, clients[i][j].numero);
            }
        }
        fclose(f);
    }
    
    // Menu principal
    int choix = 0;
    do {
        printf("\nMenu principal\n");
        printf("1. Ajouter un client\n");
        printf("2. Afficher les clients par opérateurs\n");
        printf("3. Afficher les clients d'un opérateur\n");
        printf("4. Afficher les numéros de téléphone d'un client\n");
        printf("5. Modifier ou ajouter un numéro de téléphone\n");
        printf("6. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        
        // Traitement du choix de l'utilisateur
        switch (choix) {
            case 1: // Ajouter un client
                {
                    // Saisir les informations du client
                    char nom[MAX_NOM], prenom[MAX_NOM], numero[MAX_NUMERO];
                    int operateur = -1;
                    do {
                        printf("\nSaisir le nom : ");
                        scanf("%s", nom);
                        printf("Saisir le prénom : ");
                        scanf("%s", prenom);
                        printf("Saisir le numéro de téléphone : ");
                        scanf("%s", numero);
                    
                    // Vérifier si le numéro est valide
                    if (!numeroValide(numero)) 
                    {
                        printf("Le numéro de téléphone est invalide.\n");
                        continue;
                    }
                    
                    // Chercher l'opérateur correspondant au numéro
                    for (int i = 0; i < nbOperateurs; i++) {
                        if (strstr(numero, operateurs[i]) == numero)
                         {
                            operateur = i;
                             break;
                         }
                    }
                    
                    // Si l'opérateur est trouvé, sortir de la boucle
                    if (operateur >= 0) {
                        break;
                    }
                    
                    printf("L'opérateur n'est pas reconnu.\n");
                } while (true);
                
                // Vérifier si le numéro n'existe pas déjà
                for (int i = 0; i < nbClients[operateur]; i++) {
                    if (strcmp(numero, clients[operateur][i].numero) == 0) {
                        printf("Le numéro de téléphone existe déjà.\n");
                        continue;
                    }
                }
                
                // Ajouter le client à la matrice
                strcpy(clients[operateur][nbClients[operateur]].nom, nom);
                strcpy(clients[operateur][nbClients[operateur]].prenom, prenom);
                strcpy(clients[operateur][nbClients[operateur]].numero, numero);
                nbClients[operateur]++;
                
                printf("Le client a été ajouté avec succès.\n");
            }
            break;
            
        case 2: // Afficher les clients par opérateurs
            for (int i = 0; i < nbOperateurs; i++) {
                printf("%s :\n", operateurs[i]);
                for (int j = 0; j < nbClients[i]; j++) {
                    printf("%s %s (%s)\n", clients[i][j].nom, clients[i][j].prenom, clients[i][j].numero);
                }
                printf("\n");
            }
            break;
            
        case 3: // Afficher les clients d'un opérateur
            {
                // Saisir l'opérateur
                int operateur = -1;
                do {
                    printf("\nSaisir l'opérateur (1. Orange, 2. Tigo, 3. Expresso) : ");
                    scanf("%d", &operateur);
                    operateur--;
                    if (operateur < 0 || operateur >= nbOperateurs) {
                        printf("L'opérateur n'est pas reconnu.\n");
                    }
                } while (operateur < 0 || operateur >= nbOperateurs);
                
                // Afficher les clients de l'opérateur
                printf("%s :\n", operateurs[operateur]);
                for (int i = 0; i < nbClients[operateur]; i++) {
                    printf("%s %s (%s)\n", clients[operateur][i].nom, clients[operateur][i].prenom, clients[operateur][i].numero);
                }
                printf("\n");
            }
            break;
            
        case 4: // Afficher les numéros de téléphone d'un client
            {
                // Saisir le nom et prénom du client
                char nom[MAX_NOM], prenom[MAX_NOM];
                printf("\nSaisir le nom : ");
                scanf("%s", nom);
                printf("Saisir le prénom : ");
                scanf("%s", prenom);
                // Chercher le client dans la matrice
                int clientTrouve = 0;
                for (int i = 0; i < nbOperateurs; i++) {
                    for (int j = 0; j < nbClients[i]; j++) {
                        if (strcmp(clients[i][j].nom, nom) == 0 && strcmp(clients[i][j].prenom, prenom) == 0) {
                            printf("Les numéros de téléphone de %s %s sont :\n", nom, prenom);
                            printf("- %s\n", clients[i][j].numero);
                            clientTrouve = 1;
                        }
                    }
                }
                
                if (!clientTrouve) {
                    printf("Le client n'a pas été trouvé.\n");
                }
            }
            break;
            
        case 5: // Modifier ou ajouter un numéro de téléphone pour un client
            {
                // Saisir le nom et prénom du client
                char nom[MAX_NOM], prenom[MAX_NOM];
                printf("\nSaisir le nom : ");
                scanf("%s", nom);
                printf("Saisir le prénom : ");
                scanf("%s", prenom);
                
                // Chercher le client dans la matrice
                int operateur = -1, index = -1;
                for (int i = 0; i < nbOperateurs; i++) {
                    for (int j = 0; j < nbClients[i]; j++) {
                        if (strcmp(clients[i][j].nom, nom) == 0 && strcmp(clients[i][j].prenom, prenom) == 0) {
                            operateur = i;
                            index = j;
                            break;
                        }
                    }
                    if (operateur >= 0) {
                        break;
                    }
                }
                
                // Si le client n'a pas été trouvé, afficher un message et sortir de la fonction
                if (operateur < 0 || index < 0) {
                    printf("Le client n'a pas été trouvé.\n");
                    break;
                }
                
                // Saisir le nouveau numéro de téléphone
                char nouveauNumero[MAX_NUMERO];
                do {
                    printf("Saisir le nouveau numéro de téléphone : ");
                    scanf("%s", nouveauNumero);
                    
                    // Vérifier si le numéro est valide
                    if (!numeroValide(nouveauNumero)) {
                        printf("Le numéro de téléphone est invalide.\n");
                        continue;
                    }
                    
                    // Vérifier si le numéro n'existe pas déjà
                    int existeDeja = 0;
                    for (int i = 0; i < nbOperateurs; i++) {
                        for (int j = 0; j < nbClients[i]; j++) {
                            if (strcmp(clients[i][j].numero, nouveauNumero) == 0) {
                                existeDeja = 1;
                                break;
                            }
                        }
                        if (existeDeja) {
                            break;
                        }
                    }
                    if (existeDeja) {
                        printf("Le numéro de téléphone existe déjà.\n");
                        continue;
                    }
                    
                    // Copier le nouveau numéro dans la matrice
                    strcpy(clients[operateur][index].numero, nouveauNumero);
                    printf("Le numéro de téléphone a été modifié avec succès.\n");
                    break;
                } while (true);
            }
            break;
            
        case 6: // Enregistrer les données dans un fichier texte et quitter le programme
            {
                // Ouvrir le fichier en mode écriture
                FILE* fichier =
                fopen("operateurs.txt", "w");
                
                // Ecrire les données de la matrice dans le fichier
                for (int i = 0; i < nbOperateurs; i++) {
                    fprintf(fichier, "%s\n", operateurs[i]);
                    for (int j = 0; j < nbClients[i]; j++) {
                        fprintf(fichier, "%s,%s,%s\n", clients[i][j].nom, clients[i][j].prenom, clients[i][j].numero);
                    }
                }
                
                // Fermer le fichier et sortir du programme
                fclose(fichier);
                printf("Les données ont été enregistrées dans le fichier operateurs.txt.\n");
                return 0;
            }
            break;
            
        default:
            printf("Option invalide.\n");
    }
} while (true);

return 0;
}