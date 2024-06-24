#include "../Files_H/libs.h"

void apagaDB(Desc *descritor){
    Node *auxiliar = descritor->first; //declara que auxiliar é igual ao primeiro elemento da lista
    Node *Del; //declara variavel que receberá os valores a serem liberados
    for (int i = 0; i < descritor->size; i++)//loop para remover todos os elementos 
    {
        Del = auxiliar;//variavel Del recebe o valor de auxiliar
        free(Del);//libero o elemento atua
        if (auxiliar->next == NULL)
            i = descritor->size;
        auxiliar = auxiliar->next; //auxiliar anda para o proximo elemento
    }
    free(auxiliar);
    descritor->first = NULL;
    descritor->size = 0;
}