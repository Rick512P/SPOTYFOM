#include "../Files_H/libs.h"

void searchMusic(Desc *descritor, char op){
    int code, code2, iaux = 0, verifica = 0;
    char titulo[256], tituloAux[256], artista[256], artistaAux[256];
    Nodo *auxiliar = descritor->first;
    switch (op)
    {
    case 'c'://Busca via Código
        puts("Entre com o código de busca");
        scanf("%d",&code);
        while (auxiliar != NULL)
        {
            if (code == auxiliar->info->id){
                verifica++;
                printf("Artista: %s\n", auxiliar->info->Artista);
                printf("Título: %s\n",auxiliar->info->Titulo);
                printf("Letra: %s\n", auxiliar->info->Letra);
                printf("Código: %d\n", auxiliar->info->id);
                printf("Execuções: %d\n", auxiliar->info->Reproducoes);
                puts(" ");
            }
            auxiliar = auxiliar->next;
        }
        
        if (verifica == 0)  
            puts("Nenhuma Música encontrada com este código!");

        break;
    
    case 't'://Busca via Título
        puts("Entre com o Título da Música");
        scanf(" %[^\n]", titulo);
        puts(" ");
        code = strlen(titulo);
        for (int i = 0; i<code; i++){
            if(titulo[i] == ' ' || titulo[i] == '-' || titulo[i] == '_' || titulo[i] == '(' || titulo[i] == ')'){
                if (iaux > 0)
                    iaux--;
                else
                    iaux = -1;
            }
            else if(titulo[i] == L'í' || titulo[i] == L'Í' || titulo[i] == L'Ì' || titulo[i] == L'ì' || titulo[i] == L'î' || titulo[i] == L'Î' || titulo[i] == L'ĩ' || titulo[i] == L'Ĩ')
                titulo[iaux] = 'i';
            else if(titulo[i] == L'á' || titulo[i] == L'Á' || titulo[i] == L'À' || titulo[i] == L'à' || titulo[i] == L'â' || titulo[i] == L'Â' || titulo[i] == L'ã' || titulo[i] == L'Ã')
                titulo[iaux] = 'a';
            else if(titulo[i] == L'é' || titulo[i] == L'É' || titulo[i] == L'È' || titulo[i] == L'è' || titulo[i] == L'ê' || titulo[i] == L'Ê' || titulo[i] == L'ẽ' || titulo[i] == L'Ẽ')
                titulo[iaux] = 'e';
            else if(titulo[i] == L'ó' || titulo[i] == L'Ó' || titulo[i] == L'Ò' || titulo[i] == L'ò' || titulo[i] == L'ô' || titulo[i] == L'Ô' || titulo[i] == L'õ' || titulo[i] == L'Õ')
                titulo[iaux] = 'o';
            else if(titulo[i] == L'ú' || titulo[i] == L'Ú' || titulo[i] == L'Ù' || titulo[i] == L'ù' || titulo[i] == L'û' || titulo[i] == L'Û' || titulo[i] == L'ũ' || titulo[i] == L'Ũ')
                titulo[iaux] = 'u';
            else if(titulo[i] == L'ç' || titulo[i] == L'Ç')
                titulo[iaux] = 'c';
            else
                titulo[iaux]=tolower(titulo[i]);
            iaux++;
        }
        titulo[iaux]='\0';
        puts(titulo);
        code = strlen(titulo);
        while (auxiliar != NULL){
            code2 = strlen(auxiliar->info->Titulo);
            iaux = 0;
            strcpy(tituloAux,auxiliar->info->Titulo);
            for (int i = 0; i<code2; i++){
                if(tituloAux[i] == ' ' || tituloAux[i] == '-' || tituloAux[i] == '_' || tituloAux[i] == '(' || tituloAux[i] == ')' ){
                    if (iaux > 0)
                       iaux--;
                    else
                        iaux = -1;
                }
                else if(tituloAux[i] == L'í' || tituloAux[i] == L'Í' || tituloAux[i] == L'Ì' || tituloAux[i] == L'ì' || tituloAux[i] == L'î' || tituloAux[i] == L'Î' || tituloAux[i] == L'ĩ' || tituloAux[i] == L'Ĩ')
                    tituloAux[iaux] = 'i';
                else if(tituloAux[i] == L'á' || tituloAux[i] == L'Á' || tituloAux[i] == L'À' || tituloAux[i] == L'à' || tituloAux[i] == L'â' || tituloAux[i] == L'Â' || tituloAux[i] == L'ã' || tituloAux[i] == L'Ã')
                    tituloAux[iaux] = 'a';
                else if(tituloAux[i] == L'é' || tituloAux[i] == L'É' || tituloAux[i] == L'È' || tituloAux[i] == L'è' || tituloAux[i] == L'ê' || tituloAux[i] == L'Ê' || tituloAux[i] == L'ẽ' || tituloAux[i] == L'Ẽ')
                    tituloAux[iaux] = 'e';
                else if(tituloAux[i] == L'ó' || tituloAux[i] == L'Ó' || tituloAux[i] == L'Ò' || tituloAux[i] == L'ò' || tituloAux[i] == L'ô' || tituloAux[i] == L'Ô' || tituloAux[i] == L'õ' || tituloAux[i] == L'Õ')
                    tituloAux[iaux] = 'o';
                else if(tituloAux[i] == L'ú' || tituloAux[i] == L'Ú' || tituloAux[i] == L'Ù' || tituloAux[i] == L'ù' || tituloAux[i] == L'û' || tituloAux[i] == L'Û' || tituloAux[i] == L'ũ' || tituloAux[i] == L'Ũ')
                    tituloAux[iaux] = 'u';
                else if(tituloAux[i] == L'ç' || tituloAux[i] == L'Ç')
                    tituloAux[iaux] = 'c';
                else
                    tituloAux[iaux]=tolower(tituloAux[i]);
                iaux++;
            }
            tituloAux[iaux]='\0';
            if (strcmp(titulo, tituloAux) == 0) //Verifica se é o mesmo titulo
            {
                verifica++;
                printf("Artista: %s\n", auxiliar->info->Artista);
                printf("Título: %s\n",auxiliar->info->Titulo);
                printf("Letra: %s\n", auxiliar->info->Letra);
                printf("Código: %d\n", auxiliar->info->id);
                printf("Execuções: %d\n", auxiliar->info->Reproducoes);
                puts(" ");
            }
                
            auxiliar = auxiliar->next;
        }
        if (verifica == 0)  
            puts("Titulo Não Encontrado!");
        break;
    
    case 'a'://Busca via Artista
        puts("Entre com o Artista ou Banda");
        scanf(" %[^\n]", artista);
        puts(" ");
        code = strlen(artista);
        for (int i = 0; i<code; i++){
            
            if(artista[i] == ' ' || artista[i] == '-' || artista[i] == '_' || artista[i] == '(' || artista[i] == ')'){
                if (iaux > 0)
                    iaux--;
                else
                    iaux = -1;
            }
            else if(artista[i] == L'í' || artista[i] == L'Í' || artista[i] == L'Ì' || artista[i] == L'ì' || artista[i] == L'î' || artista[i] == L'Î' || artista[i] == L'ĩ' || artista[i] == L'Ĩ')
                artista[iaux] = 'i';
            else if(artista[i] == L'á' || artista[i] == L'Á' || artista[i] == L'À' || artista[i] == L'à' || artista[i] == L'â' || artista[i] == L'Â' || artista[i] == L'ã' || artista[i] == L'Ã')
                artista[iaux] = 'a';
            else if(artista[i] == L'é' || artista[i] == L'É' || artista[i] == L'È' || artista[i] == L'è' || artista[i] == L'ê' || artista[i] == L'Ê' || artista[i] == L'ẽ' || artista[i] == L'Ẽ')
                artista[iaux] = 'e';
            else if(artista[i] == L'ó' || artista[i] == L'Ó' || artista[i] == L'Ò' || artista[i] == L'ò' || artista[i] == L'ô' || artista[i] == L'Ô' || artista[i] == L'õ' || artista[i] == L'Õ')
                artista[iaux] = 'o';
            else if(artista[i] == L'ú' || artista[i] == L'Ú' || artista[i] == L'Ù' || artista[i] == L'ù' || artista[i] == L'û' || artista[i] == L'Û' || artista[i] == L'ũ' || artista[i] == L'Ũ')
                artista[iaux] = 'u';
            else if(artista[i] == L'ç' || artista[i] == L'Ç')
                artista[iaux] = 'c';
            else
                artista[iaux]=tolower(artista[i]);
            iaux++;
        }
        artista[iaux]='\0';
        code = strlen(artista);
        while (auxiliar != NULL){
            code2 = strlen(auxiliar->info->Artista);
            iaux = 0;
            strcpy(artistaAux,auxiliar->info->Artista);
            for (int i = 0; i<code2; i++){
                if(artistaAux[i] == ' ' || artistaAux[i] == '-' || artistaAux[i] == '_' || artistaAux[i] == '(' || artistaAux[i] == ')' ){
                    if (iaux > 0)
                       iaux--;
                    else
                        iaux = -1;
                }
                else if(artistaAux[i] == L'í' || artistaAux[i] == L'Í' || artistaAux[i] == L'Ì' || artistaAux[i] == L'ì' || artistaAux[i] == L'î' || artistaAux[i] == L'Î' || artistaAux[i] == L'ĩ' || artistaAux[i] == L'Ĩ')
                    artistaAux[iaux] = 'i';
                else if(artistaAux[i] == L'á' || artistaAux[i] == L'Á' || artistaAux[i] == L'À' || artistaAux[i] == L'à' || artistaAux[i] == L'â' || artistaAux[i] == L'Â' || artistaAux[i] == L'ã' || artistaAux[i] == L'Ã')
                    artistaAux[iaux] = 'a';
                else if(artistaAux[i] == L'é' || artistaAux[i] == L'É' || artistaAux[i] == L'È' || artistaAux[i] == L'è' || artistaAux[i] == L'ê' || artistaAux[i] == L'Ê' || artistaAux[i] == L'ẽ' || artistaAux[i] == L'Ẽ')
                    artistaAux[iaux] = 'e';
                else if(artistaAux[i] == L'ó' || artistaAux[i] == L'Ó' || artistaAux[i] == L'Ò' || artistaAux[i] == L'ò' || artistaAux[i] == L'ô' || artistaAux[i] == L'Ô' || artistaAux[i] == L'õ' || artistaAux[i] == L'Õ')
                    artistaAux[iaux] = 'o';
                else if(artistaAux[i] == L'ú' || artistaAux[i] == L'Ú' || artistaAux[i] == L'Ù' || artistaAux[i] == L'ù' || artistaAux[i] == L'û' || artistaAux[i] == L'Û' || artistaAux[i] == L'ũ' || artistaAux[i] == L'Ũ')
                    artistaAux[iaux] = 'u';
                else if(artistaAux[i] == L'ç' || artistaAux[i] == L'Ç')
                    artistaAux[iaux] = 'c';
                else
                    artistaAux[iaux]=tolower(artistaAux[i]);
                iaux++;
            }
            artistaAux[iaux]='\0';
            if (strcmp(artista, artistaAux) == 0) //Verifica se é o mesmo artista
            {
                verifica++;
                printf("Artista: %s\n", auxiliar->info->Artista);
                printf("Título: %s\n",auxiliar->info->Titulo);
                printf("Letra: %s\n", auxiliar->info->Letra);
                printf("Código: %d\n", auxiliar->info->id);
                printf("Execuções: %d\n", auxiliar->info->Reproducoes);
                puts(" ");
            }
                
            auxiliar = auxiliar->next;
        }
        if (verifica == 0)  
            puts("Artista Não Encontrado!");
        break;

    default:
        break;
    }
}
