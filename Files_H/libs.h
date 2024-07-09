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

typedef struct Nodo Nodo;
typedef struct music Music;
typedef struct desc Desc;

//Criação das structs db

struct music
{
    char Titulo[256];
    char Artista[256];
    char Letra[256];
    int Reproducoes;
    int id;
};


struct Nodo
{
    Music *info;
    Nodo *next;
};


struct desc
{
    int size;
    Nodo *first;
};


//Declaração das Funções DB

void importLista(Desc *descritor); //Importa a lista contendo as musicas
Desc * DataBase(); //cria a lista db
Desc * PreencherDataBase(int op, Desc *descritor);//preenche a lista DB
void printLista(); //exibe a lista completa de musicas
void apagaDB(Desc *descritor); //liibera a memória alocada para a lista db
Desc * insertListDB(Desc *descritor, Music *MusicItem);
Nodo * criaNodo();
void imprimir(Desc *descritor);

//Declarações Fila

typedef struct musicfila MusicaFIla;
typedef struct nodofila NodoFila;
typedef struct descfila DescFila;

struct musicfila{
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
};

struct nodofila{
    NodoFila *prox;
    MusicaFIla *info;
    NodoFila *ante;
};

struct descfila{
    NodoFila *head;
    NodoFila *tail;
    int tamanho;
};


DescFila * criaDescFila();
NodoFila * criaNodoFila();
DescFila * ENQUEUE(DescFila *descritor, NodoFila *elemento, MusicaFIla *MusicaFIla);
NodoFila * DEQUEUE(DescFila *descritor);
void ShowQueue(DescFila *descritor, Desc *desc);
void limpaQueue(DescFila *descritor);
void DELETE(DescFila *desc);

// Declarações Pilha

typedef struct musicpIlha MusicaPIlha;
typedef struct NodoPilha NodoPilha;
typedef struct DescPilha DescPilha;

struct musicpIlha{
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
};

struct NodoPilha{
    NodoPilha *prox;
    MusicaPIlha *info;
};

struct DescPilha{
    NodoPilha *pilha;
    int tamanho;
};


DescPilha * criaDescPilha();
NodoPilha * criaNodoPilha();
DescPilha * inserePilha(DescPilha *descritor, NodoPilha *elemento, MusicaPIlha *musica);
NodoPilha * POP(DescPilha *descritor);
void TOP(DescPilha *pilha);
void ImprimirPIlha(DescPilha *descritor, Desc *desc);
void removeElemento(DescPilha *descritor);
void limpaPilha(DescPilha *descritor);
void MakeNull(DescPilha *desc);

//funções complementares
int compare(const void* a, const void* b);
int jaPresente(int *vetor, int tamanho, int valor);
Music * searchMusic(Desc *descritor, char op);

//Cria Playlist
    //Aleatória
        DescFila * playlitaleatoria(Desc *descritor, DescFila *Fila);

    //Pessoal
        DescPilha * playlistpessoal(DescPilha *Pilha, Desc *descritor);
