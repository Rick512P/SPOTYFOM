#include "../Files_H/libs.h"

void RelatorioPilha(DescPilha *descritor)//Gera um arquivo .txt Com a PLaylist Pessoal do Usuário
{
    if (descritor != NULL)
    {
        FILE *arquivo;
        NodoPilha *auxiliar = descritor->pilha;

        arquivo = fopen("Playlist_Pessoal.txt", "w");

        if (arquivo == NULL)
            printf("Erro ao abrir o arquivo!\n");
        else 
        {
            fprintf(arquivo, "%d\n", descritor->tamanho);
            while (auxiliar != NULL)
            {
                fprintf(arquivo, "%s;%d;%s;%s;%d\n",auxiliar->info->artista, auxiliar->info->codigo, auxiliar->info->titulo, auxiliar->info->letra, auxiliar->info->execucoes);
                auxiliar = auxiliar->prox;
            }
        }
        fclose(arquivo);

        printf("Playlist Pessoal Salva!\n\n");
    }
    
}

void RelatorioFila(DescFila *descritor) //Gera um arquivo .txt Com a PLaylist Pessoal do Usuário
{
    if (descritor != NULL)
    {
        FILE *arquivo;
        NodoFila *auxiliar = descritor->head;

        arquivo = fopen("Playlist_Aleatória.txt", "w");

        if (arquivo == NULL)
            printf("Erro ao abrir o arquivo!\n");
        else{
            fprintf(arquivo, "%d\n", descritor->tamanho);
            while (auxiliar != NULL)
            {
                fprintf(arquivo, "%s;%d;%s;%s;%d\n",auxiliar->info->artista, auxiliar->info->codigo, auxiliar->info->titulo, auxiliar->info->letra, auxiliar->info->execucoes);
                auxiliar = auxiliar->prox;
            }
        }

        fclose(arquivo);

        printf("Playlist Aleatória Salva!\n\n");
    }
}


void RelatorioDB(Desc *descritor) //Gera um arquivo .txt Com a PLaylist Pessoal do Usuário
{
    FILE *arquivo;
    Nodo *auxiliar = descritor->first;

    arquivo = fopen("DataBase.txt", "w");

    if (arquivo == NULL)
        printf("Erro ao abrir o arquivo!\n");
    else{
        fprintf(arquivo, "%d\n", descritor->size);
        while (auxiliar != NULL)
        {
            fprintf(arquivo, "%s;%d;%s;%s;%d\n",auxiliar->info->Artista, auxiliar->info->id, auxiliar->info->Titulo, auxiliar->info->Letra, auxiliar->info->Reproducoes);
            auxiliar = auxiliar->next;
        }
    }

    fclose(arquivo);

    printf("Banco de Músicas Atualizado Gerado!\n\n");
}
