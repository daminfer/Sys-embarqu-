#include <stdio.h>

int atoi(const char *str) {
    int result = 0;
    int sign = 1;  // Par défaut, le signe est positif

    // Ignorer les espaces au début de la chaîne
    while (*str == ' ' || *str == '\t') {
        str++;
    }

    // Gérer le signe s'il y en a un
    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;  // Si le signe est négatif
        }
        str++;
    }

    // Convertir les caractères numériques en entier
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    // Appliquer le signe
    return sign * result;
}

int main() {
    const char *str = "12345";
    int num = atoi(str);
    printf("La valeur entière est : %d\n", num);
    return 0;
}