#include "../Files_H/libs.h"

Desc * DataBase() //Função Responsável por alocar o Descritor e Preencher Lista
{
    Desc *desc = (Desc*)malloc(sizeof(Desc));
    desc->first = NULL;
    desc->size = -1;

    //Criação da Lista
    desc = PreencherDataBase(0, desc); //Função responsável por Preencher a lista

    return desc;
}

Nodo * criaNodo() //Função Responsável por Criar o nó
{
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->info = NULL;
    nodo->next = NULL;
    return nodo;
}