/*
Aluna Leticia Bail
*/

// incluido as bibliotecas (pacotes de funções uteis para o funcionamento do código)
#include <stdio.h>
#include <cstdlib>
#include <time.h>

/*
Imprimir array
*/
void imprimir_array(int* arr, int n){

    for (size_t j = 0; j < n; j++)
    {
        printf("%d\t", arr[j]);
    }
}


/*
Troca um valor pelo outro
*/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*
Algoritmo de ordenação por bubble Sort
*/
int *ordenacao_tipo_bolha(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return arr;
}

int *ordenacao_por_selecao(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    return arr;
}

/* Gera uma lista de valores sequenciais */
int *gera_lista_valores_sequenciais(int tamanho)
{
    // lista de valores a serem armazenados
    int *lista_gerado;
    lista_gerado = (int *)malloc(tamanho * sizeof(int));

    for (size_t i = 0; i < tamanho; i++)
    {
        // adiciona dentro da lista, os valores sequenciais
        lista_gerado[i] = i;
    }

    // retorna a lista dos valores sequenciais gerados
    return lista_gerado;
}

/* Gera uma lista de valores aleatorios com valores repetidos */
int *gera_lista_valores_aleatorios(int tamanho)
{
    int min_valor = 1;
    int max_valor = 100;

    int *lista_gerado = (int *)malloc(tamanho * sizeof(int));

    for (size_t i = 0; i < tamanho; i++)
    {
        lista_gerado[i] = (rand() % max_valor + min_valor);
    }

    return lista_gerado;
}

void demonstracao_ponteiros(){

    int* lista01; // criando um ponteiro, sem inicializar tamanho e memoria
    int lista02[] = {1, 2, 3}; // criando um array (ponteiro) inicializando com valores
    int lista03[3]; // criando array (ponteiro) inicializando o tamanho

    #pragma region ARMAZENANDO_VALORES
    // aloca memoria para uso
    lista01 = (int*)malloc(3 * sizeof(int));

    lista01[0] = 1;
    lista01[1] = 2;
    lista01[2] = 3;

    lista03[0] = 3;

    lista03[2] = 3;
    lista03[3] = 3;
    
    #pragma endregion
}

void teste_algoritmos_ordenacao()
{

#pragma region DADOS_ENTRADA

    int tamanho_da_lista[] = {10000, 100000, 500000, 1000000};

#pragma endregion

    time_t tempo_inicial;
    time_t tempo_final;
    double tempo_diferenca;

    // ponteiro, que armazenarao os valores (listas)
    int *lista;

    int *lista_ordenada;

    int qntd_tamanhos = sizeof(tamanho_da_lista) / sizeof(tamanho_da_lista[0]);

    for (
        int i = 0; // inicializa a variavel com valor x
        i < qntd_tamanhos; // condição de parada (quando sai do for)
        i = i + 1) // executa a cada ciclo
    {
        printf("___________________________________\n");
        printf("Tamanho da lista: %d \n\n", tamanho_da_lista[i]);

        // realoca memoria
        lista = (int *)malloc(tamanho_da_lista[i] * sizeof(int));
        lista_ordenada = (int *)malloc(tamanho_da_lista[i] * sizeof(int));

        lista = gera_lista_valores_aleatorios(tamanho_da_lista[i]); // gera valores

        //imprimir_array(lista, tamanho_da_lista[i]);

        #pragma region EXECUCAO_SELECTION_SORT
        
        printf("\n# Algoritmo de Selection Sort #\n");

        time(&tempo_inicial); // inicia contagem do tempo
        lista_ordenada = ordenacao_por_selecao(lista, tamanho_da_lista[i]);
        time(&tempo_final); // finaliza contagem do tempo

        tempo_diferenca = difftime(tempo_final, tempo_inicial); // calcula duracao do tempo de processamento
        printf("Tempo de processamento: %f segundos\n\n", tempo_diferenca);
        
        //imprimir_array(lista_ordenada, tamanho_da_lista[i]);

        #pragma endregion


        #pragma region EXECUCAO_BUBBLE_SORT

        printf("\n# Algoritmo de Bubble Sort #\n");

        time(&tempo_inicial); // inicia contagem do tempo
        lista_ordenada = ordenacao_tipo_bolha(lista, tamanho_da_lista[i]);
        time(&tempo_final); // finaliza contagem do tempo

        tempo_diferenca = difftime(tempo_final, tempo_inicial); // calcula duracao do tempo de processamento
        printf("Tempo de processamento: %f segundos\n\n", tempo_diferenca);

        //imprimir_array(lista_ordenada, tamanho_da_lista[i]);
        
        #pragma endregion
    }

#pragma region LIMPA_MEMORIA_DOS_PONTEIROS

    // limpa memoria
    free(lista);
    free(lista_ordenada);

#pragma endregion
}

/*
função main, corresponde a função principal, que é onde tudo começa
*/
int main(int argc, char const *argv[])
{
    teste_algoritmos_ordenacao();

    return 0;
}
