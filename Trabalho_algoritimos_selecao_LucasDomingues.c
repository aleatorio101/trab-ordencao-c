#include <stdio.h>
#include <locale.h>

// Algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
	int i = 0, j = 0, temporaria;
    // Loop externo percorre o array do início até o penúltimo elemento
    for (i = 0; i < n - 1; i++) {
        // Loop interno percorre os elementos não ordenados
        for (j = 0; j < n - i - 1; j++) {
            // Verifica se o elemento atual é maior que o próximo
            if (arr[j] > arr[j + 1]) {
                // Troca os dois elementos de lugar
                int temporaria = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temporaria;
            }
        }
        // Após cada iteração do loop externo, o maior elemento restante está na posição correta
    }
}

// Algoritmo Insertion Sort
void insertionSort(int arr[], int n) {
	int i = 0, j = 0, temporaria;
    // Começa do segundo elemento, já que o primeiro é considerado ordenado
    for ( i = 1; i < n; i++) {
        int temporaria = arr[i]; // Armazena o elemento atual em uma variável temporária
        int j = i - 1;

        // Move os elementos maiores que "temporaria" uma posição para frente
        while (j >= 0 && arr[j] > temporaria) {
            arr[j + 1] = arr[j]; // Desloca o elemento para a direita
            j--;
        }

        // Insere "key" na posição correta encontrada
        arr[j + 1] = temporaria;
    }
}

// Algoritmo Selection Sort
void selectionSort(int arr[], int n) {
	int i = 0, j = 0, IndexMinimo, temporaria;
    // Loop externo percorre o array do início até o penúltimo elemento
    for (i = 0; i < n - 1; i++) {
        int IndexMinimo = i; // Assume que o menor elemento está na posição atual

        // Loop interno encontra o índice do menor elemento no restante do array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[IndexMinimo]) { // Compara o elemento atual com o menor encontrado
                IndexMinimo = j; // Atualiza o índice do menor elemento
            }
        }

        // Troca o menor elemento encontrado com o elemento na posição atual
        int temporaria = arr[IndexMinimo];
        arr[IndexMinimo] = arr[i];
        arr[i] = temporaria;
    }
}

void printArray(int arr[], int n) {
	int i = 0;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
	setlocale(LC_ALL, "");
    int n, escolha, i = 0;

    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &n);

    int arr[n];
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEscolha o método de ordenação:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            bubbleSort(arr, n);
            printf("Vetor ordenado usando Bubble Sort: ");
            break;
        case 2:
            insertionSort(arr, n);
            printf("Vetor ordenado usando Insertion Sort: ");
            break;
        case 3:
            selectionSort(arr, n);
            printf("Vetor ordenado usando Selection Sort: ");
            break;
        default:
            printf("Escolha inválida.\n");
            return 0;
    }

    printArray(arr, n);
    return 0;
}
