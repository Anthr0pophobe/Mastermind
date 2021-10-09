
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void makeCode(char secretCode[50])
{
    int i, randCode, diff, interval;
    char input;
    printf("Veuillez indiquer votre niveau de difficulté 1,2,3 ou 0 pour quitter.\n");
    scanf("%s", &input);
    if(input =='\n'){
            scanf("%c", &input);
        }
    diff = atoi(&input);

    switch(diff) //Selectionne la difficulté
            {
            case 1: 
                diff = 4, interval = 5;
            break;
            case 2: 
                diff = 6; interval = 7;
            break;
                case 3: diff = 8; interval = 9;
            break;
            case 4: diff = 0; break;
        }

    for(i=0; i<diff; i++){
        randCode = 1 + rand() % interval; 
        switch(randCode) //converti en string
            {
            case 1: strcpy(&secretCode[i], "1"); break;
            case 2: strcpy(&secretCode[i], "2"); break;
            case 3: strcpy(&secretCode[i], "3"); break;
            case 4: strcpy(&secretCode[i], "4"); break;
            case 5: strcpy(&secretCode[i], "5"); break;
            case 6: strcpy(&secretCode[i], "6"); break;
            case 7: strcpy(&secretCode[i], "7"); break;
            case 8: strcpy(&secretCode[i], "8"); break;
        }
    }

}

int main(){
    char solution[50];
    char combinaisonUser[50];
    int tour;

    makeCode(solution);
    //printf("%s \n", solution); // pour afficher la solution générée

    //mets fin a la partie si le joueur entre 0
    if (solution == "0") return 0; 

    printf("Veuillez entrée une combinaison de chiffre pour trouver le code. \n");
    scanf("%s", combinaisonUser);
    if(combinaisonUser =='\n'){
            scanf("%c", &combinaisonUser);
        }
    
    
    while (atoi(solution) != atoi(combinaisonUser)) //condition de victoire
    {
        //la longueur de la réponse doit être de la meme valeur que celle du joueur
        while(strlen(solution)!=strlen(combinaisonUser)){   
            printf("Veuillez entrée une combinaison de chiffre valide. \n");
            scanf("%s", combinaisonUser);
            if(combinaisonUser =='\n'){
                scanf("%c", &combinaisonUser);
            }
        }
    
        for (int i = 0; i < strlen(combinaisonUser); i++){
            // pour chaque elem on verif si le contenue de combinaisonUser est dans le tableau solution
            for (int j = 0; j < strlen(solution)+1; j++){
                //Verifie si le chiffre saisi correspond au chiffre de la solution
                if (solution[i] == combinaisonUser[i]){
                    printf("A");
                break;
            }
                if (solution[j] == combinaisonUser[i]){
                    printf("B");
                break;
                }
                printf("C");
                break;
            }
            
        }
        //la on a fini de vérifier on print donc l'indice
        tour = tour + 1;
        printf("\nTour suivant, vueillez à nouveau entrer des valeurs\n");
        scanf("%s", combinaisonUser);
        if(combinaisonUser =='\n'){
                scanf("%c", &combinaisonUser);
            }

    }
    
    printf("bien joué tu l'as fini en %d coup(s) t'es moins bête que tu en a l'air !\n", tour);
    return(0);


}

