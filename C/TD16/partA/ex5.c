#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTHDICO 20
#define MAXWORD 256

typedef struct sMot
{
    char *mot;    /* chaîne du mot (terminée par '\0') */
    int longueur; /* longueur sans compter le '\0' */
} sMot;

/* parcourt le tableau et libère la mémoire de chaque structure mot rencontrée. */
void effaceMots(sMot *dictionnaire[LENGTHDICO])
{
    for (int i = 0; i < LENGTHDICO; ++i)
    {
        if (dictionnaire[i] != NULL)
        {
            free(dictionnaire[i]->mot);
            free(dictionnaire[i]);
            dictionnaire[i] = NULL;
        }
    }
}

/* Renvoie le nombre de mots dans le dictionnaire */
int longueurDico(sMot *dictionnaire[LENGTHDICO])
{
    int cnt = 0;
    for (int i = 0; i < LENGTHDICO; ++i)
        if (dictionnaire[i] != NULL)
            ++cnt;
    return cnt;
}

/* Ajoute un mot au dictionnaire (demande à l'utilisateur). */
void ajouteMot(sMot *dictionnaire[LENGTHDICO])
{
    int idx = -1;
    for (int i = 0; i < LENGTHDICO; ++i)
    {
        if (dictionnaire[i] == NULL)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        printf("Le dictionnaire est plein, impossible d'ajouter.\n");
        return;
    }

    char buffer[MAXWORD];
    printf("Entrez un mot: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        printf("Erreur de lecture.\n");
        return;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
        --len;
    }

    sMot *m = malloc(sizeof(sMot));
    if (!m)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    m->mot = malloc(len + 1);
    if (!m->mot)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(m->mot, buffer);
    m->longueur = (int)len;

    dictionnaire[idx] = m;
}

/* Affiche les mots du dictionnaire */
void afficheDict(sMot *dictionnaire[])
{
    for (int i = 0; i < LENGTHDICO; ++i)
    {
        if (dictionnaire[i] != NULL)
        {
            printf("Mot %d: %s\n", i, dictionnaire[i]->mot);
        }
    }
}

int main(void)
{
    sMot *dictionnaire[LENGTHDICO] = {0};
    int n = 0;

    printf("Combien de mots souhaitez-vous stocker?\n");
    if (scanf("%d", &n) != 1)
    {
        printf("Lecture du nombre impossible.\n");
        return 1;
    }
    if (n < 0)
        n = 0;
    if (n > LENGTHDICO)
        n = LENGTHDICO;

    /* consommer le '\n' laissé par scanf */
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Remplissage du dictionnaire\n");

    for (int i = 0; i < n; ++i)
    {
        ajouteMot(dictionnaire);
    }

    printf("\nAffichage du dictionnaire\n");
    afficheDict(dictionnaire);

    //demande de stocker dictionnaire
    char reponse;
    printf("\nVoulez-vous stocker le dictionnaire dans un fichier? (o/n): ");
    scanf("%c", &reponse);

    if (reponse == 'o' || reponse == 'O')
    {
       FILE *f = fopen("dico.txt", "w");
         if (f == NULL)
         {
              perror("Problème lors de l'ouverture du fichier");
              effaceMots(dictionnaire);
              return 1;
         }
            for (int i = 0; i < LENGTHDICO; ++i)
            {
                if (dictionnaire[i] != NULL)
                {
                    fprintf(f, "%s\n", dictionnaire[i]->mot);
                }
            }
            fclose(f);
            printf("Dictionnaire stocké dans 'dico.txt'\n");
    }
    


    int lg = longueurDico(dictionnaire);
    printf("Longueur du dictionnaire: %d\n", lg);

    if (lg > 0)
    {
        srand((unsigned)time(NULL));
        int r = rand() % lg;
        printf("Choix au hasard d'un element:\n");
        printf("Mot %d de longueur %d: %s\n", r, dictionnaire[r]->longueur, dictionnaire[r]->mot);
    }
    else
    {
        printf("Dictionnaire vide, aucun mot à tirer au hasard.\n");
    }

    printf("Effacement du dictionnaire \n");
    effaceMots(dictionnaire);

    return 0;
}
