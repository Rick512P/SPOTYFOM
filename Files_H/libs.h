/*
Author: Érick Santos Matos
Id: 2310100966
Date: 07/05/2024
*/


//Inclusão das bibliotecas nativas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

//Declaração das structs DB

typedef struct node Node;
typedef struct music Music;
typedef struct desc Desc;

//Declaração das structs Playlist
typedef struct nodepl Nodepl;
typedef struct musicpl Musicpl;
typedef struct descpl Descpl;

//Criação das structs db

struct music
{
    char Titulo[256];
    char Artista[256];
    char Letra[256];
    int Reproducoes;
    int id;
};


struct node
{
    Music *info;
    Node *next;
};


struct desc
{
    int size;
    Node *first;
};

//Criação das structs playlist

struct musicpl
{
    char Titulo[256];
    char Artista[256];
    char Letra[256];
    int Reproducoes;
    int id;
};


struct nodepl
{
    Musicpl *info;
    Nodepl *next;
    Nodepl *previous;
};


struct descpl
{
    int size;
    Nodepl *first;
    Nodepl *last; 
};

//Declaração das Funções DB

void importLista(Desc *descritor); //Importa a lista contendo as musicas
Desc * DataBase(); //cria a lista db
Desc * PreencherDataBase(int op, Desc *descritor);//preenche a lista DB
void printLista(); //exibe a lista completa de musicas
void apagaDB(Desc *descritor); //liibera a memória alocada para a lista db
Desc * insertListDB(Desc *descritor, Music *MusicItem);
Node * criaNodo();

//Declaração das Funções PL
Descpl * createPlaylist(Desc *descritor); //cria uma playlist
Descpl * playlistpessoal(Descpl *descritorpl, Desc *descritor);
Descpl * playlitaleatoria(Descpl *descritorpl, Desc *descritor);
Descpl * insertListPL(Descpl *descritor, Musicpl *MusicItem);
void apagaPL(Descpl *descritor); //liibera a memória alocada para a lista db
Nodepl * criaNodoPL();

//ordenação
int compare(const void* a, const void* b);
