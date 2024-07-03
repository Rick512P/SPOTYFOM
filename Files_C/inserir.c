#include "../Files_H/libs.h"

Desc * insertListDB(Desc *descritor, Music *MusicItem){
    Nodo *auxiliary = descritor->first, *novoElemento;
    novoElemento = criaNodo();
    novoElemento->info = MusicItem;
    if (descritor->first == NULL)
    {
        descritor->first = novoElemento;
        descritor->size++;
    }
    else{
        while(auxiliary->next != NULL){
            auxiliary=auxiliary->next;
        }
        auxiliary->next = novoElemento;
        descritor->size++;
    }
}

/*
Descpl * insertListPL(Descpl *descritor, Musicpl *MusicItem){
    Nodopl *auxiliary = descritor->first, *novoElemento;
    novoElemento = criaNodoPL();
    novoElemento->info = MusicItem;
//Corrigir pois esta como se fosse uma pilha, mas pode ser uma fila também
    if (descritor->size == 0)
    {
        descritor->first = novoElemento;
        descritor->last = novoElemento;
        descritor->size++;
    }
    else{
        while(auxiliary->next != NULL){
            auxiliary=auxiliary->next;
        }
        auxiliary->next = novoElemento;
        descritor->size++;
    }

    return descritor;
}
*/