#include <iostream>
using namespace std;

void bistro(int* arr, int n) {
    if (n <= 1) return;

    int razd = arr[n - 1];  // берем последний элемент как опорный
    int i = 0;  // индекс для элементов меньше razd

    for (int j = 0; j < n - 1; j++) {
        if (arr[j] <= razd) {
            // меняем местами arr[i] и arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    // ставим razd на правильное место
    int temp = arr[i];
    arr[i] = arr[n - 1];
    arr[n - 1] = temp;

    // сортируем левую и правую части
    bistro(arr, i);  // левая частьдо razd
    bistro(arr + i + 1, n - i - 1);  // правая часть после razd
}


void bistro_min(int* arr, int n) {
    if (n <= 1) return;

    int razd = arr[n - 1]; 
    int i = 0; 

    for (int j = 0; j < n - 1; j++) {
        if (arr[j] >= razd) {  // изменяем знак сравнения
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[n - 1];
    arr[n - 1] = temp;
    
    bistro_min(arr, i);  
    bistro_min(arr + i + 1, n - i - 1); 
}