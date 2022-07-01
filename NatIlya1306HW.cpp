/*
Задание: 
Написать функцию, принимающую в качестве параметров две строки и возвращающую копию первого
параметра, все вхождения второго параметра в которой
взяты в «()».
*/


#include <iostream>
#include "Windows.h"
using namespace std;

// Функция для поиска фрагмента. Принимает строку и фрагмента для поиска.
void findPeace(string buffer, string fragment)
{
    int sizeOfBuffer = buffer.size(); // Размер строки.
    int sizeOfPeace = fragment.size(); // Размер фрагмента.
    int startFrom = 0; // Указатель для поиска.
    int placeOfPeace; // Указатель в строке на место с фрагментом.
    bool over = false; // Переменная типа "bool" для окончания цикла(значение "true" означает, что в строке нет фрагментов).
    do 
    {
        placeOfPeace = buffer.find(fragment, startFrom); // Поиск фрагмента. Если фрагмента нет, то возвращает значение больше размера строки.
        if (placeOfPeace > sizeOfBuffer)
        {
            over = true;
        }
        else
        {
            buffer.insert(placeOfPeace, "("); // Вставляет перед фрагментом круглую скобку.
            buffer.insert(placeOfPeace + sizeOfPeace + 1, ")"); // Вставляет после фрагмента круглую скобку.
            startFrom = startFrom + placeOfPeace + sizeOfPeace; // Значению для начала поиска присваивается номер элемента после найденного фрагмента.
        }
    } while (!over);
    cout << buffer; // Вывод строки.
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string buffer;
    string fragment;
    cout << "Введите строку символов: ";
    cin >> buffer;
    cout << "Введите фрагмент для поиска: ";
    cin >> fragment;

    findPeace(buffer, fragment);
}