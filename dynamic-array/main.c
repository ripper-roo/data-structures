#include <stdio.h>
#include <stdlib.h>

#include "vetor_dinamico_ordenado.h"

int main()
{
    p_vetor v = criar_vetor(5);
    int value;

    char choice;
    do
    {
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'a':
                scanf(" %d", &value);
                adicionar_elemento(v, value);
                break;
            case 'r':
                scanf(" %d", &value);
                remover_elemento(v, value);
                break;
            case 'b':
                scanf(" %d", &value);
                printf("%d\n", busca(v, value));
                break;
            case 'p':
                imprime(v);
        }
    } while (choice != 'q');

    destruir_vetor(v);
    
    return 0;
}