#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;


// Заполнение массива случайными числами

template <typename T>
void fill_arr(T arr[], const int lenght, int begin, int end) {
	srand(time(0));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (end - begin) + begin;
}

// Вывод массива в консоль
template <typename T>
void show_arr(T arr[], const int lenght) {
	cout << "[";
	for (int i = 0; i < lenght; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

// Задача 1
void type_of(int num) {
	cout << "Int\n";
}
void type_of(double num) {
	cout << "Double\n";
}
void type_of(char num) {
	cout << "Char\n";
}

// Задача 2
int sumAB(int a, int b) {
	if (b == a + 1)
		return a + b;
	return sumAB(a, b - 1) + b;
}

// Задача 3
template <typename T>
void sort_range(T arr[], const int lenght) {
	int first_index = 0, last_index = 0;
	for (int i = 0; i < lenght; i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	for (int i = lenght - 1; i >= 0; i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
		// Пузырьковая сортировка
	/*for (int i = last_index - 1; i > 0; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);*/

		// Быстрая сортировка
	sort(arr + first_index + 1, arr + last_index);
}

// Задача 4
template <typename T>
void move_arr(T arr[],const int lenght, int moves) {
	for (int j = 0; j < moves; j++)
		for (int i = lenght - 2; i >= 0; i--)
			swap(arr[i], arr[i + 1]);
	//show_arr(arr, lenght);
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Задача 1. Тип данных
	/*cout << "Задача 1.\n";
	cout << "15 - ";
	type_of(15);
	cout << "\'A\' - ";
	type_of('A');
	cout << "1.5 - ";
	type_of(1.5);
	cout << endl;*/

	// Задача 2. Сумма чисел в диапазоне от А до В с помощью рекурсии
	/*cout << "Задача2.\nВведите начало диапазона: ";
	cin >> n;
	cout << "Введите конец диапазона: ";
	cin >> m;
	cout << "Сумма чисел от " << n << " до " << m << " = " << sumAB(n,m) << "\n\n";*/

	// Задача 3. Сортировка внутри
	/*cout << "Задача 3.\nИзначальный массив:\n";
	const int size1 = 20;
	int arr1[size1];
	fill_arr(arr1, size1, -20, +20 + 1);
	show_arr(arr1, size1);
	cout << "Итоговый массив:\n";
	sort_range(arr1, size1);
	show_arr(arr1, size1);*/

	// Задача 4. Сдвиг массива
	cout << "Задача 4.\nИзначальный массив:\n";
	const int size2 = 5;
	int arr2[size2]{ 1, 2, 3, 4, 5 };
	show_arr(arr2, size2);
	cout << "Введите количество сдвигов: ";
	cin >> n;
	move_arr(arr2,size2,n);
	cout << "Итоговый массив:\n";
	show_arr(arr2, size2);

	return 0;
}