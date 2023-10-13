#ifndef VETOR_DESORDENADO
#define VETOR_DESORDENADO

typedef struct vetor *p_vetor;

struct vetor {
    int *dados;
    int blocosUsados;
    int blocosAlocados;
};

p_vetor criar_vetor(int tam);

void destruir_vetor(p_vetor v);

void adicionar_elemento(p_vetor v, int value);

void remover_elemento(p_vetor v, int index);

int busca_binaria(int *dados, int l, int r, int x);

int busca(p_vetor v, int value);

void imprime(p_vetor v);

#endif