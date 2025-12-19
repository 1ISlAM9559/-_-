#include <iostream>
using namespace std;

// Сортировка Шелла по возрастанию
void shell(int* arr, int n) {
    // gap - расстояние между сравниваемыми элементами
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {        // Для каждого элемента, начиная с gap
            int temp = arr[i];  // Сохраняем текущий элемент
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {  // Сдвигаем элементы, которые больше temp
                arr[j] = arr[j - gap];  // Сдвигаем больший элемент вправо
            }
            arr[j] = temp;  // Вставляем temp на правильное место
        }
    }
}

// Сортировка Шелла по убыванию
void shell_min(int* arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // Сдвигаем элементы, которые МЕНЬШЕ temp (для убывания)
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}