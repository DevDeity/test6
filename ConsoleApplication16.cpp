#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Шаг 1
    std::cout << "Приветствую! Это программа умного поисковика.\n";

    // Шаг 2
    int number;
    std::cout << "Введите число, которое вы хотите найти: ";
    std::cin >> number;

    // Шаг 3
    int target_number = number;

    // Шаг 4
    srand(time(nullptr));
    int array_size = rand() % 100 + 1;

    // Шаг 5
    std::cout << "Размер массива сгенерирован: " << array_size << "\n";

    // Шаг 6
    std::vector<int> array(array_size);

    // Шаг 7
    for (int i = 0; i < array_size; ++i) {
        array[i] = rand() % 501;  // Генерируем случайное число от 0 до 500
    }

    // Шаг 8
    std::cout << "Массив сгенерирован:\n";
    for (int num : array) {
        std::cout << num << "\n";
    }

    // Шаг 9
    std::sort(array.begin(), array.end());

    // Шаг 10
    std::cout << "Массив отсортирован:\n";
    for (int num : array) {
        std::cout << num << "\n";
    }

    // Шаг 11
    std::cout << "Произвожу бинарный поиск числа " << target_number << ".\n";

    // Шаг 12
    int index = binarySearch(array, target_number);

    // Шаг 13
    std::cout << "Бинарный поиск завершен.\n";

    // Шаг 14
    if (index != -1) {
        std::cout << "Искомое число найдено в массиве по индексу " << index << "\n";
    }
    else {
        auto lower = std::lower_bound(array.begin(), array.end(), target_number);
        int closest_number = *lower;
        int closest_index = std::distance(array.begin(), lower);
        std::cout << "Искомое число не найдено в массиве. Ближайшее к запрошенному числу, существующее в массиве: "
            << closest_number << " находится по индексу: " << closest_index << "\n";
    }

    return 0;
}
