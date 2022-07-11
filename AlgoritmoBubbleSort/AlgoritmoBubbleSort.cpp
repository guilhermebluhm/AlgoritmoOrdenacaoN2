#include <iostream>
#include <time.h>
#include <random>

#define n 15

void imprimirVetor(int* v) {
    for (int i = 0; i < n; i += 1) {
        std::cout << " [ " << *(v + i) << " ] ";
    }
}

void insertion(int v[]) {
    int aux = 0;
    int j = 0;
    //parte da posição 1 do vetor pois se admite 0 como o elemento
    //previamente ordenado
    for (int i = 1; i < n; i += 1) {
        aux = v[i];
        //se faz o laço ir de frente para tras
        //se verificando constantemente se a posição j analisada
        //e maior que o elemento arbitrario setado em i para aux
        for (j = (i - 1); (v[j] > aux) && (j >= 0); j -= 1) {
            //caso seja verdade e feito o deslocamento para
            //reposicionamento do elemento na ordenação
            v[j + 1] = v[j];
        }
        //reinserindo em posição nao nula o elemento
        //de referencia para i em um espaço vago gerado pelo laço de j
        v[j + 1] = aux;
    }
}

void selection(int v[]) {
    int menor = 0;
    int aux = 0;
    for (int i = 0; i < n - 1; i += 1) {
        //admitindo i como o elemento de menor valor
        //para aquela iteração inicial nao tendo havido
        //nenhuma troca
        menor = i;
        for (int j = (i + 1); j < n; j += 1) {
            //(i+1) ate n pois precisa ler da posição subsquente
            //ate o fim do que se quer trocar
            if (v[j] < v[menor]) {
                //se o j que e sempre (i+1) ate n for
                //menor que o suposto menor arbitrario = troca
                menor = j;
            }
        }
        //o menor arbitrario vai para flag aux
        aux = v[i];
        //o novo menor vai para a primeira posição de troca
        v[i] = v[menor];
        //e o primeiro elemento sera trocado na suposta posição (i+1) ate n
        v[menor] = aux;
    }
}

void bubble(int v[]) {
    //flag para fazer as trocas da flutuação
    int aux = 0;
    //laço mais externo para iterar no conjunto de dados
    for (int i = 0; i < n; i += 1) {
        //se usa n - 1 - i (pois se considera n - 1 para a
        //primeira hipotese de troca e - i para desconsiderar
        //os elementos ja passados na troca
        for (int j = 0; j < n - 1 - i; j += 1) {
            if (v[j] > v[j+1]) {
                //admite que v[j] e o elemento maior desordenado
                //armazenado em flag
                aux = v[j];
                //o menor passa para o elemento v[j]
                v[j] = v[j + 1];
                //o maior que estava em flag vai para v[j+1]
                v[j + 1] = aux;
            }
        }
    }
}

int main()
{
    srand((unsigned)time(0));
    int vet[n];
    for (int i = 0; i < n; i += 1) {
        int rnd = 1 + rand() % 100;
        vet[i] = rnd;
    }
    std::cout << "vetor desordenado: " << std::endl;
    imprimirVetor(vet);
    //bubble(vet);
    //selection(vet);
    insertion(vet);
    std::cout << std::endl;
    std::cout << "vetor ordenado: " << std::endl;
    imprimirVetor(vet);
    return 0;
}
