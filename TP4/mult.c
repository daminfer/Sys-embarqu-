#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s [taille de la table]\n", argv[0]);
        return 1;
    }

    int taille_table = atoi(argv[1]);

    if (taille_table <= 0) {
        printf("La taille de la table doit être un entier positif.\n");
        return 1;
    }

    FILE *fichier = fopen("table_multiplication.txt", "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    for (int i = 1; i <= taille_table; i++) {
        for (int j = 1; j <= taille_table; j++) {
            fprintf(fichier, "%3d ", i * j);
        }
        fprintf(fichier, "\n");
    }

    fclose(fichier);
    printf("Table de multiplication de %d générée dans 'table_multiplication.txt'.\n", taille_table);

    return 0;
}