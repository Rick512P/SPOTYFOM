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

MusicaFIla * preencheElementoFila(){
    MusicaFIla *elemento = (MusicaFIla *)malloc(sizeof(MusicaFIla));
    char auxiliar[256];
    puts("Entre com o nome do artista/banda: ");
    scanf(" %255[^\n]", auxiliar);
    strcpy(elemento->artista, auxiliar);
    puts("Entre com o Título da Música: ");
    scanf(" %255[^\n]", auxiliar);
    strcpy(elemento->titulo, auxiliar);
    puts("Entre com a Letra da Música: ");
    scanf(" %255[^\n]", auxiliar);
    strcpy(elemento->letra, auxiliar);
    puts("Entre com o código Único da Música: ");
    scanf("%d", &elemento->codigo);
    elemento->execucoes = 0;
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

void ShowQueue(DescFila *descritor){
    if (descritor->tamanho == 0)
    {
        puts("Queue vazia!");
    }
    else{
        NodoFila *aux = descritor->head;
        while (aux != NULL)
        {
            printf("Artista/Banda: %s\n",aux->info->artista);
            printf("Título: %s\n",aux->info->titulo);
            printf("Letra: %s\n",aux->info->letra);
            printf("Execuções: %d\n",aux->info->execucoes);
            printf("ID: %d\n",aux->info->codigo);
            puts("");
            aux->info->execucoes++;
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
