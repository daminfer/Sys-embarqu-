#include <stdio.h>

int main() {
    FILE *fichier = fopen("donnees.don", "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier donnees.don");
        return 1;
    }

    double col1, col2, somme;
    int ligne = 0; // Variable pour compter le nombre de lignes lues

    printf("Colonne 1\tColonne 2\tSomme\n");

    while (fscanf(fichier, "%lf : %lf", &col1, &col2) == 2) {
        somme = col1 + col2;
        printf("%lf\t%lf\t%lf\n", col1, col2, somme);
        ligne++;
    }

    fclose(fichier);

    printf("Nombre de lignes lues : %d\n", ligne);

    return 0;
}