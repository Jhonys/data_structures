/*
Aluna Leticia Bail
Trabalho de Busca Sequencial e Binaria
*/


#include <iostream>
#include <stdlib.h>
#include <vector> // incluida para usar vector
#include <chrono> // includa para usar o tempo

// usado para mensurar o tempo de processamento com chronos
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using std::chrono::time_point;

/*
Algoritmo de ordenação por bubble Sort
*/
std::vector<int> ordenacao_tipo_bolha(std::vector<int> lista)
{
    bool swapped = true;
    int j = 0;
    int valor_temporario;

    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < lista.size() - j; ++i)
        {
            if (lista[i] > lista[i + 1])
            {
                valor_temporario = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = valor_temporario;
                swapped = true;
            }
        }
    }

    return lista;
}

/*
Algoritmo de ordenação por seleção
*/
std::vector<int> ordenacao_por_selecao(std::vector<int> lista)
{
    int valor_temporario;
    int valor_menor;

    for (int i = 0; i < lista.size(); ++i)
    {
        valor_menor = i;
        for (int j = i + 1; j < lista.size(); ++j)
        {
            if (lista[j] < lista[valor_menor])
                valor_menor = j;
        }
        if (valor_menor != i)
        {
            valor_temporario = lista[i];
            lista[i] = lista[valor_menor];
            lista[valor_menor] = valor_temporario;
        }
    }
    return lista;
}

/* Algoritmo de busca sequencial */
int busca_sequencial(std::vector<int> lista, int valor_procurado, int& output_qntd_iteracoes)
{
    // usado para contar a quantidade de iteracoes que foram executados, até achar o valor_procurado
    output_qntd_iteracoes = 0;
    
    for (size_t i = 0; i < lista.size(); i++)
    {
        output_qntd_iteracoes++;
        if(lista[i] == valor_procurado)
            return i;
    }
    
    // se nao achar o valor, retorna -1
    return -1;
}

/* Algoritmo de busca binaria */
int busca_binaria(std::vector<int> lista, int valor_procurado, int& output_qntd_iteracoes)
{
    int p = 0;
    int r = lista.size() - 1;
    int q = (r + p) / 2;

    // usado para contar a quantidade de iteracoes que foram executados, até achar o valor_procurado
    output_qntd_iteracoes = 0;

    while (p <= r)
    {
        output_qntd_iteracoes++;

        if (lista[q] == valor_procurado)
            return q;
        else
        {
            if (lista[q] < valor_procurado)
            {
                p = q + 1;
                q = (r + p) / 2;
            }
            else
            {
                r = q - 1;
                q = (r + p) / 2;
            }
        }
    }

    // se nao achar o valor, retorna -1
    return -1;
}

/* Busca binaria por recursividade */
int busca_binaria_recursiva(std::vector<int> lista, int valor_procurado, int p, int r)
{
    if (p > r)
        return -1;
    else
    {
        int q = (p + r) / 2;
        if (lista[q] == valor_procurado)
            return q;
        else
        {
            if (lista[q] < valor_procurado)
                return busca_binaria_recursiva(lista, valor_procurado, q + 1, r);

            else
                return busca_binaria_recursiva(lista, valor_procurado, p, q - 1);
        }
    }
}

/* Gera uma lista de valores sequenciais */
std::vector<int> gera_lista_valores_sequenciais(int tamanho)
{
    // lista de valores a serem armazenados
    std::vector<int> lista_gerado;

    for (size_t i = 0; i < tamanho; i++)
    {
        // adiciona dentro da lista, os valores sequenciais
        lista_gerado.push_back(i);
    }

    // retorna a lista dos valores sequenciais gerados
    return lista_gerado;
}

std::vector<int> gera_lista_valores_aleatorios(int tamanho, int min_valor = 1, int max_valor = 100){

    srand (time(NULL));

    std::vector<int> lista_gerado;

    for (size_t i = 0; i < tamanho; i++)
    {
        lista_gerado.push_back(rand() % max_valor + min_valor);
    }
    
    return lista_gerado;
}

void teste_algoritmos_busca(){

#pragma region DADOS_ENTRADA

    // define o valor a ser buscado
    int valor_procurado = 1000000000-1;

    // tamanho da lista = 1 * 10^10
    int tamanho_da_lista = 1000000000;
    
    #pragma endregion

    #pragma region CHAMANDO_FUNCOES_DE_BUSCA

    std::vector<int> lista;
    
    // usado para contar a quantidade de iteracoes que foram executados, até achar o valor_procurado
    int qntd_iteracoes = 0;

    std::cout << "___________________________________\n";
    std::cout << "Tamanho da lista: " << tamanho_da_lista << "\nValor procurado: " << valor_procurado << "\n";

    // gera valores sequenciais
    lista = gera_lista_valores_sequenciais(tamanho_da_lista);
    
    auto t1 = high_resolution_clock::now(); // calcula tempo inicial
    std::cout << "___________________________________\n";
    std::cout << "# Algoritmo de Busca Sequencial #\n";
    std::cout << "Resultado encontrado: " << busca_sequencial(lista, valor_procurado, qntd_iteracoes) << "\n";
    // std::cout << "Quantidade de iteracoes ate achar o valor procurado: " << qntd_iteracoes << "\n";
    auto t2 = high_resolution_clock::now();
    int ms_int = duration_cast<milliseconds>(t2 - t1).count(); // calcual tempo final do processamento da funcao
    std::cout << "Tempo de processamento: " << ms_int << " milisegundos\n\n";


    auto t3 = high_resolution_clock::now();
    std::cout << "___________________________________\n";
    std::cout << "# Algoritmo de Busca Binaria #\n";
    std::cout << "Resultado encontrado: " << busca_binaria(lista, valor_procurado, qntd_iteracoes) << "\n";
    // std::cout << "Quantidade de iteracoes ate achar o valor procurado: " << qntd_iteracoes << "\n";
    auto t4 = high_resolution_clock::now();
    int ms_int2 = duration_cast<milliseconds>(t4 - t3).count();
    std::cout << "Tempo de processamento: " << ms_int2 << " milisegundos\n\n";

    #pragma endregion
}

void teste_algoritmos_ordenacao(){

#pragma region DADOS_ENTRADA

    int tamanho_da_lista[] = {10000, 100000, 500000, 1000000};

#pragma endregion

    std::vector<int> lista;
    std::vector<int> lista_ordenada;
    
    for (size_t i = 0; i < sizeof(tamanho_da_lista)/sizeof(tamanho_da_lista[0]); i++)
    {
        std::cout << "___________________________________\n";
        std::cout << "Tamanho da lista: " << tamanho_da_lista[i] << "\n\n";
        
        lista.clear();
        lista_ordenada.clear();

        lista = gera_lista_valores_aleatorios(tamanho_da_lista[i]); // gera valores

        auto t1 = high_resolution_clock::now(); // calcula tempo inicial

        //std::cout << "___________________________________\n";
        std::cout << "# Algoritmo de Selection Sort #\n";

        lista_ordenada = ordenacao_por_selecao(lista);

        auto t2 = high_resolution_clock::now();
        int ms_int = duration_cast<milliseconds>(t2 - t1).count(); // calcual tempo final do processamento da funcao
        std::cout << "Tempo de processamento: " << ms_int << " milisegundos\n\n";

        
        auto t3 = high_resolution_clock::now(); // calcula tempo inicial

        //std::cout << "___________________________________\n";
        std::cout << "# Algoritmo de Bubble Sort #\n";

        lista_ordenada = ordenacao_tipo_bolha(lista);

        auto t4 = high_resolution_clock::now();
        int ms_int2 = duration_cast<milliseconds>(t4 - t3).count(); // calcual tempo final do processamento da funcao
        std::cout << "Tempo de processamento: " << ms_int2 << " milisegundos\n\n";
    }
    
}

int main(int argc, char const *argv[])
{
    //teste_algoritmos_busca();

    teste_algoritmos_ordenacao();

    return 0;
}
