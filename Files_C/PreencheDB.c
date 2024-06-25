#include "../Files_H/libs.h"

Desc * PreencherDataBase(int op, Desc *descritor){
    char *token, linha[100], endereco[256];
    int reproducoes, size, cont=0;
    Music *MusicItem = (Music*)malloc(sizeof(Music));
    FILE *arquivo;

    switch (op)
    {
        case 1:
            while (getchar() != '\n');
            puts("Entre com o caminho: ");
            scanf(" %[^\n]", endereco);
            break;
        case 0:
            strcpy(endereco,"./DB/DataBase.csv");            
            break;
    }

    // Abre o arquivo para leitura
    arquivo = fopen(endereco, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return descritor;
    }

    size = sizeof(linha); //recebe tamanho da lista

    // Lê e processa as linhas restantes
    while (fgets(linha, sizeof(linha), arquivo) != NULL) //loop do arquivo
    {
        free(MusicItem);
        MusicItem = (Music*)malloc(sizeof(Music)); //aloca espaço para MusicItem
        token = strtok(linha,";");
        strcpy(MusicItem->Titulo,token);
        token = strtok(NULL,";");
        strcpy(MusicItem->Artista,token);
        token = strtok(NULL,";");
        strcpy(MusicItem->Letra,token);
        token = strtok(NULL,";");

        MusicItem->id = atoi(token);
        MusicItem->Reproducoes=0;
        descritor = insertListDB(descritor, MusicItem);
        cont ++;
    }
    if (op == 1){
        if (size == cont){//compara se a quantia de musicas dada pelo arquivo é igual a quantia lida
            descritor->size=size;//Aloca o tamanho da lista
        }
        else{
            descritor->size=cont;//Aloca o tamanho da lista
            printf("Quantia de musicas presentes no arquivo não bate com quantia dada.");
        }
    }
    
    // Fecha o arquivo
    fclose(arquivo);
    return descritor;
}