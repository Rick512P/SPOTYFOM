#include "../Files_H/libs.h"

Descpl * playlistpessoal(Descpl *descritorpl, Desc *descritor){
    int tamanho, cont=0, aviso;
    char musica[256], musicaaux[256];
    Musicpl *MusicItem = (Musicpl*)malloc(sizeof(Musicpl));
    printf("Para encerrar a inserção de musicas digite 'parar'");
        do{
            Node *auxiliar = descritor->first;
            cont++;
            aviso = 0;
            printf("Entre com o nome da %d° musica!\n", cont);
            tamanho = strlen(musica);
            scanf(" %[^\n]", musica);

            for(int i; i<tamanho;i++)//converte o titulo dado para minusculo
            {
                musica[i]=tolower(musica[i]);
            }

            //verificação de parada
            if (tamanho==strlen("parar"))//confere se o valor de entrada possui o mesmo tamanho da condição de parada
            {
                if (strcmp(musica,"parar")==0)//compara se o valor de entrada é 'parar', se for, encerra o preenchimento da playlist
                {
                    printf("Playlist preenchida!\n");
                    aviso = 2;
                }                
            }

            //inserção
            while (aviso==0 || auxiliar->next != NULL){
                if (strlen(auxiliar->info->Titulo)==strlen(musica))
                {
                    for(int i; i<tamanho;i++)//converte o titulo dado para minusculo
                    {
                        musicaaux[i]=tolower(auxiliar->info->Titulo[i]);
                    }
                    if (strcmp(musica,musicaaux))
                    {
                        strcpy(MusicItem->Artista,auxiliar->info->Artista);
                        strcpy(MusicItem->Letra,auxiliar->info->Letra);
                        strcpy(MusicItem->Titulo,auxiliar->info->Titulo);
                        MusicItem->id=auxiliar->info->id;
                        MusicItem->Reproducoes = auxiliar->info->Reproducoes;
                        aviso++;
                    }
                }
                auxiliar = auxiliar->next;
            }
            if (aviso==0)
            {
                printf("Música não encontrada!");
            }
            else if (aviso=1) // insere na lista caso a musica tenha sido encontrada
                descritorpl = insertListPL(descritorpl, MusicItem);
            
        }while(aviso != 2);
    return descritorpl;
}