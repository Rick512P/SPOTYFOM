#include "../Files_H/libs.h"

int main(){
    int opcode = 0, opa = 0;
    char implst;
    Nodo *MusicaDB = NULL;
    Desc *DescritorDB = NULL;
    NodoFila *MusicaFila = NULL;
    DescFila *DescritorFila = NULL;
    NodoPilha *MusicaPilha = NULL;
    DescPilha *DescritorPilha = NULL;


    DescritorDB = DataBase(DescritorDB);

    printf("Seja Bem vindo ao seu Gerenciador Pessoal de Músicas!\n");
    do
    {
        printf("---------------------\n");
        printf("1- EXECUÇÃO\n");
        printf("2- PLAYLIST\n");
        printf("3- Busca\n");
        printf("4- IMPRESSÃO\n");
        printf("5- RELATÓRIO\n");
        printf("6- OPÇÕES AVANÇADAS\n");
        printf("0- SAIR\n");
        printf("---------------------\n");
        scanf("%d", &opcode);
        puts(" ");

        switch (opcode)
        {
            case 1:
                //Execução
                if(DescritorDB == NULL)
                    puts("Banco de Dados Vazio!");
                else if (DescritorFila != NULL && DescritorPilha != NULL)
                {
                    puts("Deseja executar sua Playlista Pessoal ou Aleatória? p/a");
                    getchar();
                    scanf(" %c", &implst);
                    implst = tolower(implst);
                    switch (implst)
                    {
                    case 'p':
                        ImprimirPIlha(DescritorPilha, DescritorDB);
                        MakeNull(DescritorPilha);
                        DescritorPilha = NULL;
                        break;
                    case 'a':
                        ShowQueue(DescritorFila, DescritorDB);
                        DELETE(DescritorFila);
                        DescritorFila = NULL;
                    default:
                        break;
                    }
                }
                else if(DescritorFila != NULL){
                    ShowQueue(DescritorFila, DescritorDB);
                    DELETE(DescritorFila);
                    DescritorFila = NULL;
                }
                else if(DescritorPilha != NULL){
                    ImprimirPIlha(DescritorPilha, DescritorDB);
                    MakeNull(DescritorPilha);
                    DescritorPilha = NULL;
                }
                else
                    puts("Playlists Não Criadas!");
                
                puts(" ");
                break;

            case 2:
                char playlist;
                puts("Deseja criar uma playlist Personalizada ou Aleatória? p/a");
                scanf(" %c", &playlist);
                playlist=tolower(playlist);
                switch (playlist)
                {
                case 'p':
                    if(DescritorPilha != NULL){
                        printf("Aviso, a playlist anterior será deletada!\n");
                        printf("Deseja continuar? s/n\n");
                        scanf(" %c", &implst);
                        implst=tolower(implst);
                        switch (implst)
                        {
                        case 's':
                            MakeNull(DescritorPilha);
                            DescritorPilha = criaDescPilha();
                            DescritorPilha = playlistpessoal(DescritorPilha, DescritorDB);
                            //ImprimirPIlha(DescritorPilha, DescritorDB);
                            break;
                        default:
                            break;
                        }
                    }
                    else{
                        DescritorPilha = criaDescPilha();
                        DescritorPilha = playlistpessoal(DescritorPilha, DescritorDB);
                        //ImprimirPIlha(DescritorPilha, DescritorDB);
                    }                    
                    break;
                case 'a':
                    if(DescritorFila != NULL){
                        printf("Aviso, a playlist anterior será deletada!\n");
                        printf("Deseja continuar? s/n\n");
                        scanf(" %c", &implst);
                        implst=tolower(implst);
                        switch (implst)
                        {
                        case 's':
                            DELETE(DescritorFila);
                            DescritorFila = criaDescFila();
                            DescritorFila = playlitaleatoria(DescritorDB, DescritorFila);
                            //ShowQueue(DescritorFila, DescritorDB);
                            break;
                        default:
                            break;
                        }
                    }
                    else{
                        DescritorFila = criaDescFila();
                        DescritorFila = playlitaleatoria(DescritorDB, DescritorFila);
                        //ShowQueue(DescritorFila, DescritorDB);
                    }
                    break;
                default:
                    break;
                }
                break;
            case 3:            
                puts("Escolha a forma de busca");
                puts("C - Código");
                puts("T - Título");
                puts("A - Artista");
                scanf(" %c", &implst);
                implst = tolower(implst);
                searchMusic(DescritorDB, implst);
                break;
            case 4:
                puts("Deseja visualizar uma música em específico, ou todas? 1/n");
                getchar();
                scanf(" %d", &implst);
                switch (implst)
                {
                case '1':
                    puts("Escolha a forma de busca");
                    puts("C - Código");
                    puts("T - Título");
                    puts("A - Artista");
                    scanf(" %c", &implst);
                    implst = tolower(implst);
                    searchMusic(DescritorDB, implst);
                    break;
                case 'n':
                case 'N':
                    imprimir(DescritorDB);
                    break;
                }
                break;

            case 6:
                printf("1- Importar nova lista de musicas\n");//opcoes avancadas
                printf("0- Voltar\n");//opcoes avancadas
                scanf("%d", &opa);
                while(opa != 0){
                    switch (opa)
                        {
                        case 0:
                            puts("Debug");
                            break;
                        case 1: //encaminha para a função responsável por importar uma nova lista de musicas
                            printf("Aviso! A lista padrão já está importada, deseja importar uma nova?\nIsto sobreescreverá toda a lista existente! s/n\n");
                            scanf(" %c", &implst);
                            implst=tolower(implst);
                            switch (implst)
                                {
                                case 's':
                                    importLista(DescritorDB);
                                    opa = 0;
                                    break;
                                
                                default:
                                    printf("Importação cancelada!");
                                    break;
                                }
                            break;
                        default:
                            printf("Opção inválida");
                            break;
                        }
                    
                };
                break;
            case 0:
                if (DescritorDB != NULL)
                    apagaDB(DescritorDB);
                if (DescritorPilha != NULL)
                    //apagaPL(DescritorPilha);
                if (DescritorFila != NULL)
                    //apagaPL(DescritorFila);
                printf("Encerrando o Programa!\n");
                sleep(1.5);
                system("clear");
                break;

            default:
                printf("Opção Inválida!\n");
                break;
        }
    } while (opcode != 0);
    
    return 0;
}