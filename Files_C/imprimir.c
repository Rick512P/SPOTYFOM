#include "../Files_H/libs.h"

void imprimir(Desc *descritor) //Função Responsável por exibir todas as músicas
{
    Nodo *aux = descritor->first;
    int cont = 0, i = 20;
    char verifica;

    while (aux != NULL)
    {   
        if (aux->info->id < i)//Imprime um número limitado de Músicas por vez
        {
            cont++;
            printf("Título: %s\n", aux->info->Titulo);
            printf("Artista: %s\n", aux->info->Artista);
            printf("Letra: %s\n", aux->info->Letra);
            printf("Código: %d\n", aux->info->id);
            printf("Número de Reproduções: %d\n", aux->info->Reproducoes);
            puts("");
            puts("");
            aux = aux->next;
        }
        else if (descritor->size >  i)//Verifica se o usuário deseja continuar a visualização das músicas
        {
            puts(" ");
            puts("--------------------------------");
            puts("Deseja Continuar a Exibição? s/n");
            getchar();
            scanf(" %c", &verifica);
            puts(" ");
            switch (verifica)
            {
            case 's':
            case 'S':
                i += cont;
                cont = 0;
                break;
            
            default://Caso não queira continuar, coloca aux como NULL para encerrar o loop
                aux = NULL;
                break;
            }
        }      
    }      
}

void ExibirPilha(DescPilha *descritor) //Função Responsável por exibir todas as músicas da playlist Pessoal
{
    NodoPilha *aux = descritor->pilha;
    int cont = 0, i = 20;
    char verifica;

    while (aux != NULL)
    {   
        if (cont < i)//Imprime um número limitado de Músicas por vez
        {
            cont++;
            printf("Título: %s\n", aux->info->titulo);
            printf("Artista: %s\n", aux->info->artista);
            printf("Letra: %s\n", aux->info->letra);
            printf("Código: %d\n", aux->info->codigo);
            printf("Número de Reproduções: %d\n", aux->info->execucoes);
            puts("");
            puts("");
            aux = aux->prox;
        }
        else if (descritor->tamanho >  i)//Verifica se o usuário deseja continuar a visualização das músicas
        {
            puts(" ");
            puts("--------------------------------");
            puts("Deseja Continuar a Exibição? s/n");
            getchar();
            scanf(" %c", &verifica);
            puts(" ");
            switch (verifica)
            {
            case 's':
            case 'S':
                i += cont;
                cont = 0;
                break;
            
            default://Caso não queira continuar, coloca aux como NULL para encerrar o loop
                aux = NULL;
                break;
            }
        }      
    }      
}

void ExibirFila(DescFila *descritor) //Função Responsável por exibir todas as músicas da playlist Aleatória
{
    NodoFila *aux = descritor->head;
    int cont = 0, i = 20;
    char verifica;

    while (aux != NULL)
    {   
        if (cont < i)//Imprime um número limitado de Músicas por vez
        {
            cont++;
            printf("Título: %s\n", aux->info->titulo);
            printf("Artista: %s\n", aux->info->artista);
            printf("Letra: %s\n", aux->info->letra);
            printf("Código: %d\n", aux->info->codigo);
            printf("Número de Reproduções: %d\n", aux->info->execucoes);
            puts("");
            puts("");
            aux = aux->prox;
        }
        else if (descritor->tamanho >  i)//Verifica se o usuário deseja continuar a visualização das músicas
        {
            puts(" ");
            puts("--------------------------------");
            puts("Deseja Continuar a Exibição? s/n");
            getchar();
            scanf(" %c", &verifica);
            puts(" ");
            switch (verifica)
            {
            case 's':
            case 'S':
                i += cont;
                cont = 0;
                break;
            
            default://Caso não queira continuar, coloca aux como NULL para encerrar o loop
                aux = NULL;
                break;
            }
        }      
    }     
}