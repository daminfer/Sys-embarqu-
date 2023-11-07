#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOTS 1000
#define MAX_TAILLE_MOT 50

int main(int argc, char *argv[]) {
    // Liste de tout les mots rencontrer sans aucune occurence
    if (argc != 2) {
        printf("Utilisation : %s [nom du fichier]\n", argv[0]);
        return 1;
    }

    char *nom_fichier = argv[1];
    FILE *fichier = fopen(nom_fichier, "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char mots[MAX_MOTS][MAX_TAILLE_MOT];
    int nb_mots = 0;

    char ligne[1024];

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        char *token = strtok(ligne, " \t\n"); // Divise la ligne en mots

        while (token != NULL) {
            int est_doublon = 0;

            // Vérifie si le mot est un doublon
            for (int i = 0; i < nb_mots; i++) {
                if (strcmp(mots[i], token) == 0) {
                    est_doublon = 1;
                    break;
                }
            }

            if (!est_doublon) {
                strcpy(mots[nb_mots], token);
                nb_mots++;
            }

            token = strtok(NULL, " \t\n"); // Passe au mot suivant
        }
    }

    printf("Liste des mots uniques dans le fichier :\n");
    for (int i = 0; i < nb_mots; i++) {
        printf("%s\n", mots[i]);
    }

    fclose(fichier);
    return 0;
}
