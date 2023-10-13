#include <stdio.h>
#include <stdlib.h>

#include "vetor_dinamico_desordenado.h"

p_vetor criar_vetor(int tamanho) {
    p_vetor v;
    v = malloc(sizeof(struct vetor));
    v->dados = malloc(tamanho * sizeof(int));
    v->blocosUsados = 0;
    v->blocosAlocados = tamanho;
    return v;
}

void destruir_vetor(p_vetor v) {
    free(v->dados);
    free(v);
}

void adicionar_elemento(p_vetor v, int value) {

    // check if expansion is needed
    if (v->blocosUsados == v->blocosAlocados) {
        int *temp = v->dados;
        v->blocosAlocados *= 2;
        v->dados = malloc(v->blocosAlocados * sizeof(int));
        for (int i = 0; i < v->blocosUsados; i++)
            v->dados[i] = temp[i];
        free(temp);
    }

    v->dados[v->blocosUsados] = value;
    v->blocosUsados++;
}

void remover_elemento(p_vetor v, int index){

    // check if index is out of border
    if(index < 0 || index >= v->blocosUsados)
        return;

    // check if shrinking is needed
    if (v->blocosUsados == v->blocosAlocados/4) {
        int *temp = v->dados;
        v->blocosAlocados /= 2;
        v->dados = malloc(v->blocosAlocados * sizeof(int));
        for (int i = 0; i < v->blocosUsados; i++)
            v->dados[i] = temp[i];
        free(temp);
    }

    v->dados[index] = v->dados[v->blocosUsados-1];
    v->blocosUsados--; 
}

int busca(p_vetor v, int value) {
    for (int i = 0; i < v->blocosUsados; i++)
        if (v->dados[i] == value)
            return i;
    return -1;
}

void imprime(p_vetor v) {
    int i;
    for (i = 0; i < v->blocosUsados; i++)
        printf("%d ", v->dados[i]);
    printf("\n");
}


