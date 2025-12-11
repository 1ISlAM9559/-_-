#include <iostream>
using namespace std;

void shell(int* arr, int n) {
    // Начинаем с большого промежутка, затем уменьшаем его
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Выполняем сортировку вставками для этого промежутка
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // Сдвигаем элементы, пока не найдем правильную позицию
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shell_min(int* arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}