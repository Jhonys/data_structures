/*
Letícia Bail de Almeida - S25 
Tarefa 01 More
*/

#include <stdio.h>
#include <conio.h>

int bufferLength = 255;
char buffer[255];

#pragma region FUNCOES

const char *leitura_de_parametro(int argc, char const *argv[]);
FILE* leitura_do_arquivo(const char *nome_arquivo);
void apresentar_linhas(FILE *filePointer, int qntd_linhas);
void aguardar_comando();

#pragma endregion

// entrada de texto a partir de parametros
const char *leitura_de_parametro(int argc, char const *argv[])
{
    printf("Argumentos de entrada:\n");
    for (size_t i = 0; i < argc; i++)
    {
        printf("[%d]: %s\n", i, argv[i]);
    }
    
    if(argc < 1)
        printf("Faltando parametro");

    return argv[1];
}

/*Leitura do arquivo
*/
FILE* leitura_do_arquivo(const char *nome_arquivo)
{
    FILE *filePointer;

    filePointer = fopen(nome_arquivo, "r");
    return filePointer;
}

/*
Mostrar linhas
*/
void apresentar_linhas(FILE *filePointer, int qntd_linhas)
{
    int contador = 0;

    while (fgets(buffer, bufferLength, filePointer))
    {
        printf("%s\n", buffer);

        // incrementa contador, indicando qauantas linhas foram lidas ate o momento
        contador = contador + 1;

        // foram lidas 20 linhas ou mais?
        if (contador >= qntd_linhas)
        {
            aguardar_comando();

            // reseta contador
            contador = 0;
        }
    }

    printf("\nLeitura finalizada");
    printf("\nAluna Letícia Bail de Almeida - S25");

    // fecha documento
    fclose(filePointer);
}

/*Aguardar comando do usuario
*/
void aguardar_comando()
{
    printf("[ aguardando comando para continuar... ]\n");
    getch();
}

int main(int argc, char const *argv[])
{
    int qntd_linhas_apresentadas_por_rodada = 20;

    const char *nome_arquivo = leitura_de_parametro(argc, argv);

    FILE *filePointer = leitura_do_arquivo(nome_arquivo);
    // FILE *filePointer = leitura_do_arquivo(argv[1]);

    apresentar_linhas(filePointer, qntd_linhas_apresentadas_por_rodada);

    return 0;
}
