#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


//Вывод массива в консоль
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

// Заполнение массива случайными числами
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
srand(time(NULL));
for (int i = 0; i < length; i++)
	arr[i] = rand() % (right - left) + left;

}

//если функция что то "выводит" то скорее всего эта функция - void
void type_of(int num)    { std::cout << "INT\n"; }
void type_of(char num)   { std::cout << "char\n"; }
void type_of(float num)  { std::cout << "float\n"; }
void type_of(double num) { std::cout << "double\n"; }


int sum_AB(int A, int B) {
	if (A > B) {
	std::swap(A, B);
	std::cout << "Ты дурачок :(\n";
	}
		
	if (A == B)
		return A;
	return  sum_AB(A, B - 1) + B;            // пишем return так как мы возвращаем что то - return -возвращение 

}

template <typename T>
void middle_sort(T arr[], const int length) {
	int first_index = 0, last_index = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			first_index = i; break;
		}
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] < 0) {
			last_index = i; break;
		}
	//Быстрая сортировка
	/*if (first_index != last_index)
		std::sort(arr + first_index + 1, arr + last_index);*/

	//Пузырьковая сортировка
	for (int i = last_index - 1; i > first_index + 1; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]); // swap  - aфункция позволяющая поменять значения местами, в данном случае arr[j] и arr[j+1]

}

template <typename T>
void move_arr(T arr[], const int length, int steps) {
	if (steps >= 0)
		for (int k = 0; k < steps; k++)
			for (int i = length - 1; i > 0; i--)
				std::swap(arr[i], arr[i - 1]);
	else
		for (int k = 0; k < -steps; k++) {
			T tmp = arr[0];
			for (int i = 0; i < length - 1; i++)
				arr[i] = arr[i + 1];
			arr[length - 1] = tmp;

		}

}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//Задача 1. Типы данных
	/*std::cout << "Задача 1.\n";
	std::cout << "105 - "; type_of(105);
	std::cout << "\'A\' - "; type_of('A');
	std::cout << "7.7F - "; type_of(7.7F);
	std::cout << "0.1 - "; type_of(0.1);
	std::cout << std::endl;*/

	//Задача 2. Рекурсивная сумма
	/*std::cout << "Задача 1.\nВведите первое число -> ";
	std::cin >> n;
	std::cout << "Введите второе число -> ";
	std::cin >> m;
	std::cout << "Сумма чисел от " << n << " до " << m << ": " << sum_AB(n, m) << "\n\n";*/

	//Задача 3. Сортировка середины
	/*std::cout << "Задача3. \nИзначальный массив:\n";
	const int size3 = 10; //size3 - потому что это задача 3
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21); // 21 - потому что по условия задачи от -20 до +20 "включительно"
	print_arr(arr3, size3);
	middle_sort(arr3, size3);

	std::cout << "Итоговый массив:\n";
	print_arr(arr3, size3);
	std::cout << std::endl;*/

	//Задача 4. Сдвиг массива
	std::cout << "Задача 4.\nИзначальный массив:\n";
	const int size4 = 5;
		int arr4[size4]{ 1, 2, 3, 4, 5 };
		print_arr(arr4, size4);
		std::cout << "Введите кол-во сдвигов -> ";
		std::cin >> n;
		move_arr(arr4, size4, n);
		std::cout << "Итоговый массив:\n";
		print_arr(arr4, size4);
		std::cout << std::endl;


	return 0;

}