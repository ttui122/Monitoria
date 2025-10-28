#include <stdio.h>
#include <string.h>
#include "restaurante.h"

tRestaurante criaRestaurante(char *nome){
    tRestaurante restaurante;

    strcpy(restaurante.nome, nome);
    restaurante.numeroAlimentos = 0;

    return restaurante;
}

tRestaurante leRestaurante(){
    char nome[32];
    char linha[32];
    
    scanf(" %[^\n]", nome);

    tRestaurante restaurante = criaRestaurante(nome);

    return restaurante;
}

tRestaurante cadastraAlimento(tRestaurante r, tAlimento a){
    tRestaurante restauranteL = r;

    restauranteL.alimentos[r.numeroAlimentos] = a;

    restauranteL.numeroAlimentos++;

    return restauranteL;
}

tRestaurante consumirAlimentoRestaurante(tRestaurante r, char *nome, float qtd){
    tRestaurante rL = r;
    
    for (int i = 0; i < rL.numeroAlimentos; i++){
        if (strcmp(nome, rL.alimentos[i].nome) == 0){
            rL.alimentos[i] = consumirAlimento(rL.alimentos[i], qtd);
        }
    }

    return rL;
}

float quantidadeConsumida(tRestaurante r){
    int qtdConsumidaTotal = 0;

    for (int i = 0; i < r.numeroAlimentos; i++){
        qtdConsumidaTotal += r.alimentos[i].qtdConsumida;
    }

    return qtdConsumidaTotal;
}

float rendaTotal(tRestaurante r){
    float rendaTotal = 0.0;

    for (int i = 0; i < r.numeroAlimentos; i++){
        rendaTotal += rendaAlimento(r.alimentos[i]);
    }

    return rendaTotal;
}

 void imprimeRestaurante(tRestaurante r){
    
    printf("Nome: %s", r.nome);
    printf("Alimentos:\n");
    
    for (int i = 0; i < r.numeroAlimentos; i++){
        imprimeAlimento(r.alimentos[i]);
    }

    printf("Quantidade total consumida: %.2f\n", quantidadeConsumida(r));
    printf("Renda total: R$ %.2f\n", rendaTotal(r));

 }