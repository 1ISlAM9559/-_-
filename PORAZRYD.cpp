#include <iostream>
using namespace std;

void porazryd(int* arr, int n, int cif) {

    int xran[10][1000];  // 10 групп для цифр 0-9
    int shet[10] = { 0 }; // счетчики чисел в группах
    for (int i = 0; i < n; i++) {// Раскладываем по группам
        int razryd = (arr[i] / cif) % 10;  // цифра разряда
        xran[razryd][shet[razryd]] = arr[i];  // засовываем в гурппы
        shet[razryd]++;  // увеличиваем счетчик
    }
    int k = 0;  // индекс в arr
    // собираем обратно
    for (int d = 0; d < 10; d++) {  // по всем группам
        for (int i = 0; i < shet[d]; i++) {  // все числа из групп
            arr[k] = xran[d][i];  // копируем
            k++;
        }
    }
}

void porazryd_min(int* arr, int n, int cif) {
    int xran[10][1000];
    int shet[10] = { 0 }; 
    for (int i = 0; i < n; i++) {
        int razryd = (arr[i] / cif) % 10;
        xran[razryd][shet[razryd]] = arr[i];
        shet[razryd]++;
    }
    int k = 0;
    for (int d = 9; d >= 0; d--) { // меняем знак
        for (int i = 0; i < shet[d]; i++) {
            arr[k] = xran[d][i];
            k++;
        }
    }
}