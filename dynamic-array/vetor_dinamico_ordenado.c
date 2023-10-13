#include <stdio.h>
#include <stdlib.h>

#include "vetor_dinamico_ordenado.h"

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

    // move elements to the right
    int index;
    for (index = v->blocosUsados - 1; index >= 0 && v->dados[index] > value; index--)
        v->dados[index + 1] = v->dados[index];
    v->dados[index + 1] = value;
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

    // move elements to the right
    for(; index < v->blocosUsados - 1; index++)
        v->dados[index] = v->dados[index + 1];
    v->blocosUsados--;
}

int busca_binaria(int *dados, int l, int r, int x) {
    int m = (l+r)/2;
    if (l > r)
        return -1;
    if (dados[m] == x)
        return m;
    else if (dados[m] < x)
        return busca_binaria(dados, m + 1, r, x);
    else
        return busca_binaria(dados, l, m - 1, x);
}

int busca(p_vetor v, int value) {
    return busca_binaria(v->dados, 0, v->blocosUsados - 1, value);
}

void imprime(p_vetor v) {
    int i;
    for (i = 0; i < v->blocosUsados; i++)
        printf("%d ", v->dados[i]);
    printf("\n");
}


