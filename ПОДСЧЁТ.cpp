#include<iostream>
using namespace std;

void podshet(int* arr, int n) {
    if (n <= 0) return;

    int max_val = arr[0];       // находим максимальный элемент
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int* count = new int[max_val + 1]();   // создаем массив для подсчета
    for (int i = 0; i < n; i++) {          // подсчитываем элементы
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_val; i++) {   // перезаписываем исходный массив отсортированными значениями
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }

    delete[] count;
}
void podshet_min(int* arr, int n) {
    if (n <= 0) return;

   
    int max_val = arr[0];                  
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int* count = new int[max_val + 1]();     

    for (int i = 0; i < n; i++) {            
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = max_val; i >= 0; i--) {     // заполняем в обратном порядке для сортировки по убыванию
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }

    delete[] count;
}