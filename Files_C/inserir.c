#include "../Files_H/libs.h"

Desc * insertListDB(Desc *descritor, Music *MusicItem){
    Node *auxiliary = descritor->first, *nodo = (Node*)malloc(sizeof(Node));
    nodo->info = MusicItem;
    if (descritor->size == 0)
    {
        nodo->next = NULL;
        descritor->first = nodo;
        descritor->size++;
    }
    else{
        while(auxiliary->next != NULL){
            auxiliary=auxiliary->next;
        }
        nodo->next=NULL;
        auxiliary->next = nodo;
        descritor->size++;
    }
    return descritor;
}

Descpl * insertListPL(Descpl *descritor, Musicpl *MusicItem){
    Nodepl *auxiliary = descritor->first, *nodo = (Nodepl*)malloc(sizeof(Nodepl));
    nodo->info = MusicItem;
//Corrigir pois esta como se fosse uma pilha, mas pode ser uma fila também
    if (descritor->size == 0)
    {
        nodo->next=NULL;
        nodo->previous = NULL;
        descritor->first = nodo;
        descritor->last = nodo;
        descritor->size++;
    }
    else{
        while(auxiliary->next != NULL){
            auxiliary=auxiliary->next;
        }
        nodo->next=NULL;
        auxiliary->next = nodo;
        descritor->size++;
    }

    return descritor;
}