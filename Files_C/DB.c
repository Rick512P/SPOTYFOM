#include "../Files_H/libs.h"

Desc * DataBase(){
    Desc *desc = (Desc*)malloc(sizeof(Desc));
    desc->first = NULL;
    desc->size = -1;

    //Criação da Lista
    desc = PreencherDataBase(0, desc);

    return desc;
}