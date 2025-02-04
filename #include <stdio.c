#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50

int main() {
    int vector1[N], vector2[N], sum[N];

    // Initialisation de la graine pour la generation de nombres aleatoires
    srand(time(NULL));

    // Initialisation des vecteurs avec des valeurs aleatoires
    for (int i = 0; i < N; i++) {
        vector1[i] = rand() % 100; // Valeurs entre 0 et 99
        vector2[i] = rand() % 100;
    }

    // Somme des deux vecteurs
    for (int i = 0; i < N; i++) {
        sum[i] = vector1[i] + vector2[i];
    }

    // Affichage des resultats
    printf("Vecteur 1 :\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vector1[i]);
    }
    printf("\n\nVecteur 2 :\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vector2[i]);
    }
    printf("\n\nSomme des vecteurs :\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", sum[i]);
    }
    printf("\n");

    return 0;
}