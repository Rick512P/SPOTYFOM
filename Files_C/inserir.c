#include "../Files_H/libs.h"

Desc * insertListDB(Desc *descritor, Music *MusicItem) //Função Responsável por Adicionar MusicItem na lista
{
    Nodo *auxiliary = descritor->first, *novoElemento;
    novoElemento = criaNodo(); //Cria Nó para receber MusicItem e adicionar na lista
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