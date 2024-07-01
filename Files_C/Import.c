#include "../Files_H/libs.h"

void importLista(Desc *descritor){
    apagaDB(descritor);
    printf("Base de dados anterior excluida!");
    printf("A lista a ser importada deve possuir a seguinte estrutura:\n");
    printf("--> Primeira linha deve conter apenas o número de músicas na lista\n");
    printf("--> As linhas na sequência devem possuir apenas um título em cada com ; como separação\n");
    printf("--> Ex.: Artista;Codigo;Título;Letra\n");
    
    // Limpar o buffer do teclado

    PreencherDataBase(1, descritor);
}