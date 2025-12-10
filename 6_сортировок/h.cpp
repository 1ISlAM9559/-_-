#include<iostream>
using namespace std;

void print(int s);

void shet(int a);

int main() {
	setlocale(LC_ALL, "ru");
	int s, a;
	int n;
	cout << "Выберите действие сложение или умножение: (1)-сложение или (2)-умножение - ";
	cin >> n;
	
	switch (n) {
	case 1:
		cout << "Введите первый член: ";
		cin >> s;
		print(s);
		break;
	case 2:
		cout << "Введите первый множитель: "; cin >> a;
		shet(a);
		break;
	default:
		cout << "Выбранное действие отсутствует";
	}
	
	return 0;
}