/*
  Autor: Érick Santos Matos
  Matrícula: 2310100966
  Atividade Semi-presencial 5 - Fila Músicas
*/

#include "../Files_H/libs.h"

DescFila * criaDescFila(){
    DescFila *DescFilaritor = (DescFila *)malloc(sizeof(DescFila));
    DescFilaritor->head=NULL;
    DescFilaritor->tail=NULL;
    DescFilaritor->tamanho=0;
    return DescFilaritor;
}

NodoFila * criaNodoFila(){
    NodoFila *elemento = (NodoFila *)malloc(sizeof(NodoFila));
    elemento->prox=NULL;
    elemento->ante=NULL;
    return elemento;
}

DescFila * ENQUEUE(DescFila *descritor, NodoFila *elemento, MusicaFIla *MusicaFIla)
{
    elemento->info = MusicaFIla;
    if (descritor->tamanho == 0) // Verifica se a Fila esta Vazia
    {   
        descritor->head = elemento;
        descritor->tail = elemento;
        descritor->tamanho++;
    }
    else{
        NodoFila *aux=descritor->tail;
        aux->prox = elemento;
        elemento->ante = aux;
        descritor->tail = elemento;
        descritor->tamanho++;
    }
    return descritor;
}

NodoFila * DEQUEUE(DescFila *descritor)//remove o primeiro elemento da Fila
{
    if (descritor->tamanho == 0)
    {
        puts("Queue vazia!");
    }
    else if(descritor->tamanho == 1){
        descritor->head = NULL;
        descritor->tail = NULL;
        descritor->tamanho = 0;
    }
    else{
        NodoFila *aux = descritor->head;
        descritor->head->prox->ante = NULL;
        descritor->head = descritor->head->prox;
        descritor->tamanho--;
        return aux;
    }

}

void ShowQueue(DescFila *descritor, Desc *desc){
    if (descritor->tamanho == 0)
    {
        puts("Queue vazia!");
    }
    else{
        NodoFila *aux = descritor->head;
        Nodo *auxiliar = desc->first;
        while (aux != NULL)
        {
            auxiliar = desc->first;
            aux->info->execucoes++;
            while (auxiliar->info->id != aux->info->codigo)
            {
                auxiliar = auxiliar->next;
            }
            auxiliar->info->Reproducoes++;
            
            printf("Artista/Banda: %s\n",aux->info->artista);
            printf("Título: %s\n",aux->info->titulo);
            printf("Letra: %s\n",aux->info->letra);
            printf("Execuções: %d\n",aux->info->execucoes);
            printf("ID: %d\n",aux->info->codigo);
            puts("");
            aux = aux->prox;
        }
    }
}

void limpaQueue(DescFila *descritor){
   
    NodoFila *aux=descritor->head;
    while (aux != NULL)
    {
        if (descritor->tamanho == 1)
            free(descritor);
        else
            free(aux->ante);
        aux = aux->prox;
    }
}

void DELETE(DescFila *desc)
{
    desc->tail = NULL;
    desc->head = desc->tail;
    desc->tamanho = 0;    
}