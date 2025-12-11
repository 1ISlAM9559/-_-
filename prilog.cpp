#include<iostream>
#include <cstdlib>
#include <ctime>
#include "h.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int ybiv_vozrast;

    while (true) {
        cout << "\nВыберите действие:\n";
        cout << "1. Сортировка массива по убыванию.\n";
        cout << "2. Сортировка массива по возрастанию.\n";
        cout << "3. Выход.\n";
        cout << "Ответ: ";
        cin >> ybiv_vozrast;

        switch (ybiv_vozrast) {
        case 1: // Сортировка по убыванию
        case 2: { // Сортировка по возрастанию
            int kol;
            cout << "Введите количество элементов массива: ";
            cin >> kol;

            int* arr = new int[kol];
            for (int i = 0; i < kol; i++) {
                arr[i] = rand() % 100;
            }

            cout << "Введенный массив:\n";
            for (int i = 0; i < kol; i++) {
                cout << arr[i] << "\t";
            }
            cout << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------\n";

            int metod_sort;

            while (true) {
                cout << "\nВыберите сортировку:\n";
                cout << "1. Сортировка Шелла\n";
                cout << "2. Сортировка вставкой\n";
                cout << "3. Пузырьковая сортировка\n";
                cout << "4. Сортировка выбором\n";
                cout << "5. Сортировка подсчётом\n";
                cout << "6. Сортировка парным обменом\n";
                cout << "7. Выход\n";
                cout << "Ответ: ";
                cin >> metod_sort;

                // Создаем копию массива для сортировки
                int* temparr = new int[kol];
                for (int i = 0; i < kol; i++) {
                    temparr[i] = arr[i];
                }

                bool sorted = false;

                switch (metod_sort) {
                case 1: // Сортировка Шелла
                    if (ybiv_vozrast == 1) { // по убыванию
                        shell_min(temparr, kol);
                    }
                    else { // по возрастанию
                        shell(temparr, kol);
                    }
                    sorted = true;
                    break;

                case 2: // Сортировка вставкой
                    if (ybiv_vozrast == 1) {
                        vstavka_min(temparr, kol);
                    }
                    else {
                        vstavka(temparr, kol);
                    }
                    sorted = true;
                    break;

                case 3: // Пузырьковая сортировка
                    if (ybiv_vozrast == 1) {
                        pyzir_min(temparr, kol);
                    }
                    else {
                        pyzir(temparr, kol);
                    }
                    sorted = true;
                    break;

                case 4: // Сортировка выбором
                    if (ybiv_vozrast == 1) {
                        vibor_min(temparr, kol);
                    }
                    else {
                        vibor(temparr, kol);
                    }
                    sorted = true;
                    break;

                case 5: // Сортировка подсчётом
                    if (ybiv_vozrast == 1) {
                        podshet_min(temparr, kol);
                    }
                    else {
                        podshet(temparr, kol);
                    }
                    sorted = true;
                    break;

                case 6: // Сортировка парным обменом
                    if (ybiv_vozrast == 1) {
                        parni_min(temparr, kol);
                    }
                    else {
                        parni(temparr, kol);
                    }
                    sorted = true;
                    break;

                case 7:
                    delete[] temparr;
                    delete[] arr;
                    goto exit_inner; // Выход из внутреннего цикла

                default:
                    cout << "Выбранной сортировки нет.\n";
                    delete[] temparr;
                    continue;
                }

                if (sorted) {
                    cout << "--------------------------------------------------------------------------------------------------------------------\n";
                    cout << "Отсортированный массив:\n";
                    for (int i = 0; i < kol; i++) {
                        cout << temparr[i] << "\t";
                    }
                    cout << endl;
                }

                delete[] temparr;
            }

        exit_inner:
            break;
        }
        case 3:
            cout << "Для продолжения нажмите любую клавишу ...\n";
            return 0;
        default:
            cout << "Выбранного действия нет.\n";
            cout << "--------------------------------------------------------------------------------------------------------------------\n";
            break;
        }
    }

    return 0;
}