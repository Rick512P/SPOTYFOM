#include "../Files_H/libs.h"

Desc * PreencherDataBase(int op, Desc *descritor){
    char *token, linha[100], endereco[256];
    int reproducoes, size, cont=-1;
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

    // Lê e processa as linhas restantes
    while (fgets(linha, sizeof(linha), arquivo) != NULL) //loop do arquivo
    {   
        if (cont != -1){
            MusicItem = (Music*)malloc(sizeof(Music)); //aloca espaço para MusicItem
            token = strtok(linha,";");
            strcpy(MusicItem->Artista,token);
            token = strtok(NULL,";");
            MusicItem->id = cont;
            token = strtok(NULL,";");
            strcpy(MusicItem->Titulo,token);
            token = strtok(NULL,";");
            strcpy(MusicItem->Letra,token);
            token = strtok(NULL,";");
            
            MusicItem->Reproducoes=0;
            cont ++;

            insertListDB(descritor, MusicItem);
        }
        else{
            size = atoi(linha);
            cont = 0;
        }
    }
    if (op == 1){
        if (size != descritor->size){//compara se a quantia de musicas dada pelo arquivo é igual a quantia lida
            printf("Quantia de musicas presentes no arquivo não bate com quantia dada.\n Foi lido um total de %dMúsicas!\n", descritor->size);
        }
    }
    
    // Fecha o arquivo
    fclose(arquivo);
    return descritor;
}