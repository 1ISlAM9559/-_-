#include <iostream>
using namespace std;

// cортировка вставками по возрастанию
void vstavka(int* arr, int n) {
    
    for (int i = 1; i < n; i++) {// начинаем со второго элемента 
        int tek_el = arr[i];  // текущий элемент дл€ вставки
        int j = i - 1;     // индекс предыдущего элемента

        
        while (j >= 0 && arr[j] > tek_el) { // сдвигаем элементы, которые ЅќЋ№Ў≈ текущего(tek_el), вправо
            arr[j + 1] = arr[j];  // сдвигаем элемент вправо
            j--;                   // переходим к следующему элементу слева
        }

        arr[j + 1] = tek_el;  // вставл€ем текуший элемент на правильное место
    }
}
void vstavka_min(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int tek_el = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < tek_el) { // влево
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tek_el;
    }
}