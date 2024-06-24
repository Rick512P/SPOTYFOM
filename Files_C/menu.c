#include "../Files_H/libs.h"

int main(){
    int opcode = 0, opa = 0;
    char implst;
    Node *MusicaDB;
    Desc *descritorDB;
    Nodepl *MusicaPL;
    Descpl *descritorPL;

    descritorDB = DataBase(descritorDB);

    printf("Seja Bem vindo ao seu Gerenciador Pessoal de Músicas!\n");
    do
    {
        printf("---------------------\n");
        printf("1- EXECUÇÃO\n");
        printf("2- PLAYLIST\n");
        printf("3- IMPRESSÃO\n");
        printf("4- RELATÓRIO\n");
        printf("5- OPÇÕES AVANÇADAS\n");
        printf("0- SAIR\n");
        printf("---------------------\n");
        scanf("%d", &opcode);

        switch (opcode)
        {
            case 1:
                //Execução
                break;

            case 2:
                if(descritorPL->first != NULL){
                    printf("Aviso, a playlist anterior será deletada!\n");
                    printf("Deseja continuar? s/n");
                    scanf(" %c", &implst);
                    implst=tolower(implst);
                    switch (implst)
                    {
                    case 's':
                        apagaPL(descritorPL);
                        descritorPL = createPlaylist(descritorDB);
                        break;
                    default:
                        break;
                    }
                }
                else{
                    descritorPL = createPlaylist(descritorDB);
                }
                break;
            case 3:            
                //printLista();
                break;
            case 4:

                break;

            case 5:
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
                                    importLista(descritorDB);
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
            case 0:
                apagaDB(descritorDB);
                apagaPL(descritorPL);
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