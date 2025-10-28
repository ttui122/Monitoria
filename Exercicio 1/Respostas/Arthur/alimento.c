#include "alimento.h"
#include <string.h>


tAlimento criaAlimento(char *nome, float preco, float qtd){
    tAlimento alimento;

    strcpy(alimento.nome, nome);
    alimento.preco = preco;
    alimento.quantidade = qtd;
    alimento.qtdConsumida = 0;

    return alimento;
}

tAlimento leAlimento(){
    char nome[32];
    float preco = 0.0, qtdDisponivel = 0.0;

    scanf(" %[^\n]", nome);
    scanf("%f", &preco);
    scanf("%f", &qtdDisponivel);

    tAlimento alimento = criaAlimento(nome, preco, qtdDisponivel);

    return alimento;
}

tAlimento consumirAlimento(tAlimento alimento, float qtd){
    tAlimento alimentoL = alimento;

    alimentoL.qtdConsumida += qtd;
    alimentoL.quantidade -= qtd;

    return alimentoL;
}

float rendaAlimento(tAlimento alimento){
    return alimento.preco * (alimento.qtdConsumida/1000.0);
}

void imprimeAlimento(tAlimento alimento){
    printf("--------------------\n");
    printf("Nome: %s\n", alimento.nome);
    printf("Quantidade: %.2f\n", alimento.quantidade);    
    printf("Preco: R$ %.2f\n", alimento.preco);
    printf("Quantidade consumida: %.2f\n", alimento.qtdConsumida);
    printf("Renda: R$ %.2f\n", rendaAlimento(alimento));
    printf("--------------------\n");

}