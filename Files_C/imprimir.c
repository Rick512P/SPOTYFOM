#include "../Files_H/libs.h"

void imprimir(Desc *descritor){
    Nodo *aux = descritor->first;
    while (aux != NULL)
    {
        printf("Título: %s\n", aux->info->Titulo);
        printf("Artista: %s\n", aux->info->Artista);
        printf("Letra: %s\n", aux->info->Letra);
        printf("Código: %d\n", aux->info->id);
        printf("Número de Reproduções: %d\n", aux->info->Reproducoes);
        puts("");
        puts("");
        aux = aux->next;
    }
}
