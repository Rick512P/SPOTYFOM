#include "../Files_H/libs.h"

Descpl* createPlaylist(Desc *descritor){
    int op, verifica;
    Descpl *descpl = (Descpl*)malloc(sizeof(Descpl));
    system("clear");
    printf("Bem vindo a sala de criação de playlist!\n");
    printf("Oferecemos dois tipos de Plailists! Escolha entre:\n");

    while (verifica == 0)
    {     
        printf("1- Playlist Aleatória\n");
        printf("2- Playlist Pessoal\n");
        printf("0- Voltar");
        scanf("%d",&op);
        switch (op)
        {
        case 0:
            break;
        case 1:
            descpl->first = NULL;
            descpl->size = 0;
            descpl = playlitaleatoria(descpl, descritor);
            verifica = 1;
            break;
        
        case 2:
            descpl->last = NULL;
            descpl->size = 0;
            descpl = playlistpessoal(descpl, descritor);
            verifica = 1;
            break;
        
        default:
            verifica = 0;
            system("clear");
            puts("Opção Inválida! Tente Novamente!");
            break;
        }
    }

    return descpl;
}