#include "../Files_H/libs.h"

Desc * PreencherDataBase(int op, Desc *descritor){
    char *token, linha[256], endereco[256];
    int reproducoes, size;
    Music *MusicItem = (Music*)malloc(sizeof(Music));
    
    FILE *arquivo;

    switch (op)//Verifica Se é o caminho padrão ou um novo arquivo
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
        if (descritor->size != -1){
            MusicItem = (Music*)malloc(sizeof(Music)); //aloca espaço para MusicItem
            token = strtok(linha,";");
            strcpy(MusicItem->Artista,token);
            token = strtok(NULL,";");
            MusicItem->id = descritor->size;
            token = strtok(NULL,";");
            strcpy(MusicItem->Titulo,token);
            token = strtok(NULL,";");
            strcpy(MusicItem->Letra,token);
            token = strtok(NULL,";");
            switch (op)
            {
            case 0:
                MusicItem->Reproducoes = 0;
                break;
            
            case 1:
                MusicItem->Reproducoes = atoi(token);
                break;
            }
            

            insertListDB(descritor, MusicItem);//Chama função para Adicionar Musica a Lista
        }
        else{
            size = atoi(linha);
            descritor->size = 0;
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