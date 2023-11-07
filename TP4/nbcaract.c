#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Nombre d'occurence du mot recherche:
    
    if (argc != 2) {
        printf("Utilisation : %s [nom du fichier]\n", argv[0]);
        return 1;
    }

    FILE *fichier = fopen(argv[1], "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char voyelles[] = "aeiou";
    int compteur_voyelles[5] = {0};  // Un compteur pour chaque voyelle

    int caractere;

    while ((caractere = fgetc(fichier)) != EOF) {
        caractere = tolower(caractere);

        for (int i = 0; i < 5; i++) {
            if (caractere == voyelles[i]) {
                compteur_voyelles[i]++;
                break;  // Sortir de la boucle si une voyelle est trouvée
            }
        }
    }

    fclose(fichier);

    printf("Nombre de voyelles dans le fichier:\n");
    for (int i = 0; i < 5; i++) {
        printf("%c: %d\n", voyelles[i], compteur_voyelles[i]);
    }

    return 0;
}
