#include "../Files_H/libs.h"

void apagaDB(Desc *descritor){
    Node *auxiliary = descritor->first;
    Node *previous;
    while (auxiliary->next != NULL){
        previous = auxiliary;
        auxiliary = auxiliary->next;
        free(previous);//remove a lista desde o primeiro elemento, usando o aux como guia
    }
    free(auxiliary);
    descritor->size = -1;
    descritor->first = NULL;
}
