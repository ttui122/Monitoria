#include <stdio.h>
#include <string.h>
#include "restaurante.h"

int main(){
    char comando;
    
    tRestaurante restaurante = leRestaurante();

    do {
        scanf("%c", &comando);

        if (comando == 'A'){
            tAlimento alimento = leAlimento();
            restaurante = cadastraAlimento(restaurante, alimento);
        }
        else if (comando == 'C'){
            float qtd;
            char nome[32];

            scanf(" %[^\n]", nome);
            scanf("%f", &qtd);
            restaurante = consumirAlimentoRestaurante(restaurante, nome, qtd);
        }
        else if (comando == 'I'){
            imprimeRestaurante(restaurante);
        }

    } while (comando != 'E');


    return 0;
}