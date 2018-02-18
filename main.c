#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define MAX_COUPS 15
#define TAILLE_CHAINE 5
#define MAX_TAILLE 1000

int main(int argc, char *argv[])
{
    char chaine[MAX_TAILLE] = "USUALLY";
    char answer[MAX_TAILLE];
    FILE* fichier = NULL;
    fichier = fopen("word.txt", "r");

    char essai;
    int win = 0;
    int i = 0, j = 0, coups = MAX_COUPS;
    int Count = 0;
    int r = 0;
    srand(time(NULL));

    if(fichier != NULL)
    {
        fgets(chaine, MAX_TAILLE, fichier);
        for(i = 0; i < strlen(chaine); i++)
            answer[i] = '*';
        fclose(fichier);
    }
    else
        printf("unable to open the file");

    while(1)
    {
        printf("%d attempts left !\n", coups);
        printf("What's the word to guess ?\n");
        for(i = 0; i < strlen(chaine); i++)
            printf("%c", answer[i]);
        if(coups < 0)
            break;
        printf("\nPlease give a letter\n");
        do
        {
            essai = getchar();
        }   while(essai == '\n');

        for(i = 0; i < strlen(chaine); i++)
        {
            if(chaine[i] == essai)
                answer[i] = essai;
            printf("%c", answer[i]);
        }
        printf("\n\n");
        coups--;
        if(strncmp(answer, chaine, strlen(chaine)) == 0)
        {
            win = 1;
            break;
        }
    }

    if(win)
        printf("Game finished ! You won !");
    else
        printf("You lost !");
    printf("\n");
    system("pause");
    return 0;
}
