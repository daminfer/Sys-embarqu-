#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Utilisation : %s [nom du fichier] [mot à rechercher]\n", argv[0]);
        return 1;
    }

    char *nom_fichier = argv[1];
    char *mot_a_rechercher = argv[2];

    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char ligne[1024]; // Une ligne peut avoir jusqu'à 1024 caractères

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        if (strstr(ligne, mot_a_rechercher) != NULL) {
            printf("Le mot '%s' a été trouvé dans la ligne : %s", mot_a_rechercher, ligne);
        }
    }

    fclose(fichier);
    return 0;
}

