#include "../Files_H/libs.h"


DescFila * playlitaleatoria(Desc *descritor, DescFila *Fila)
{
    int tamanho, *vetor, i;
    MusicaFIla *MusicItem = (MusicaFIla*)malloc(sizeof(MusicaFIla));
    Nodo *auxiliar = descritor->first;
    NodoFila *nodo = NULL;

    printf("Entre com o número de musica a adicionar na playlist que faremos o resto!\n");
    getchar();
    scanf("%d", &tamanho);

    srand(time(NULL));

    vetor = (int*)malloc(tamanho * sizeof(int)); //Aloca memória para o vetor de acordo com a preferência do usuário

    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return Fila;
    }

    // Preencher o vetor com valores aleatórios únicos no intervalo [0, MAX-1]
    for (int i = 0; i < tamanho; i++) {
        int novoValor;
        do {
            novoValor = rand() % descritor->size;
        } while (jaPresente(vetor, i, novoValor));
        vetor[i] = novoValor;
    }

    qsort(vetor, tamanho, sizeof(int), compare); //Ordena os valores

    // Imprimir o vetor
    for (int i = 0; i < tamanho; i++) {
        printf("Vetor ordenado %d, %d\n", i, vetor[i]);
    }

    //inserção
    while (auxiliar->next != NULL){
        for (i = 0; i<tamanho; i++){ 
            if (auxiliar->info->id==vetor[i])
            {
                MusicItem = (MusicaFIla*)malloc(sizeof(MusicaFIla)); //aloca espaço para MusicItem
                strcpy(MusicItem->artista,auxiliar->info->Artista);
                strcpy(MusicItem->letra,auxiliar->info->Letra);
                strcpy(MusicItem->titulo,auxiliar->info->Titulo);
                MusicItem->codigo = auxiliar->info->id;
                MusicItem->execucoes = auxiliar->info->Reproducoes;
                i = tamanho;
                nodo = criaNodoFila();
                Fila = ENQUEUE(Fila, nodo, MusicItem);
            }
        }
        auxiliar = auxiliar->next;
    }

    free(vetor);
    return Fila;
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// Função para verificar se um valor já está presente no vetor
int jaPresente(int *vetor, int tamanho, int valor)
{
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return 1;
        }
    }
    return 0;
}