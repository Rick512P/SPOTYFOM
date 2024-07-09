#include "../Files_H/libs.h"

DescPilha * playlistpessoal(DescPilha *Pilha, Desc *descritor)
{
    int tamanho, cont=0, aviso;
    char musica, op;
    NodoPilha *nodo = NULL;
    Music * Musica = NULL;

    puts("Escolha a forma de busca");
    puts("C - Código");
    puts("T - Título");
    puts("A - Artista");
    getchar();
    scanf(" %c", &op);
    op=tolower(op);
    puts("Para Parar Digite um Valor Negativo (Para Busca Via Código), ou Escreva 'parar' (Para Demais Buscas)");
    do{
    
        Musica = searchMusic(descritor, op);

        if (Musica != NULL && Musica->id != -1 && Musica->id != -2){
            MusicaPIlha *MusicItem = (MusicaPIlha*)malloc(sizeof(MusicaPIlha));
            Nodo *auxiliar = descritor->first;
            NodoPilha *nodo = criaNodoPilha();
            cont++;
            aviso = 0;

            strcpy(MusicItem->artista,Musica->Artista);
            strcpy(MusicItem->titulo,Musica->Titulo);
            strcpy(MusicItem->letra,Musica->Letra);
            MusicItem->codigo = Musica->id;
            MusicItem->execucoes = Musica->Reproducoes;

            //puts(MusicItem->artista);
            Pilha = inserePilha(Pilha, nodo, MusicItem);
            //puts(Pilha->pilha->info->artista);
        }
        
    }while(Musica->id != -1 || Pilha->tamanho >= descritor->size);
    if (Pilha->tamanho == 0)
        Pilha = NULL;    
    else
        puts("Playlist Criada com Sucesso!");
    return Pilha;
}
