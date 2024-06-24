#include "../Files_H/libs.h"

Descpl * playlitaleatoria(Descpl *descritorpl, Desc *descritor){
    int tamanho, cont=0, *vetor, i;
    Musicpl *MusicItem = (Musicpl*)malloc(sizeof(Musicpl));
    Node *auxiliar = descritor->first;

    printf("Entre com o número de musica a adicionar na playlist que faremos o resto!");
    scanf("!%d",&tamanho);
    srand(time(NULL));

    vetor = (int*)malloc(tamanho * sizeof(int)); //Aloca memória para o vetor de acordo com a preferência do usuário

    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return descritorpl;
    }

    for (i = 0; i<tamanho; i++)
    {
        /*
            Função para gerar valores aleatórios de 0 até descritor->size e salvar eles dentro do vetor
        */
       vetor[i] = rand() % (descritor->size + 1);
    }

    qsort(vetor, tamanho, sizeof(int), compare); //Ordena os valores

    //inserção
    while (auxiliar->next != NULL){
        for (i; i<tamanho; i++){
            if (cont==vetor[i])
            {
                strcpy(MusicItem->Artista,auxiliar->info->Artista);
                strcpy(MusicItem->Letra,auxiliar->info->Letra);
                strcpy(MusicItem->Titulo,auxiliar->info->Titulo);
                MusicItem->id=auxiliar->info->id;
                MusicItem->Reproducoes = auxiliar->info->Reproducoes;
                i = tamanho;
            }
        }
        cont++;
        descritorpl = insertListPL(descritorpl, MusicItem);
        auxiliar = auxiliar->next;
    }

    free(vetor);
    return descritorpl;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}