#include "../Files_H/libs.h"

void importLista(Desc *descritor){
    apagaDB(descritor);
    printf("Base de dados anterior excluida!");//Descrição de como deve ser o arquivo
    printf("A lista a ser importada deve possuir a seguinte estrutura:\n");
    printf("--> Primeira linha deve conter apenas o número de músicas na lista\n");
    printf("--> As linhas na sequência devem possuir apenas uma música em cada com o símbolo ';' como separação\n");
    printf("--> Ex.: Artista;Código;Título;Letra;Execuções\n");

    PreencherDataBase(1, descritor); //Chama Função Responsável por Abrir o Arquivo e Preencher a Lista
}