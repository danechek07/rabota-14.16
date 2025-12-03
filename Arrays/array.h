#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

double* full_elements(double* ptr_array, int n); // заполнение массива (по func или другому правилу)

double func(double x); // функция для заполнения

int put_elements(double* ptr_array, int n); // вывод массива

double* calc_elements(double* ptr_array, int n); // преобразование массива (умножение на -1)

double sum_elements(double* ptr_array, int begin, int end); // сумма элементов в диапазоне

int find_max_from_k(double* ptr_array, int n, int ka); // индекс максимального элемента с позиции ka

double* full_elements_rand(double* ptr_array, int n); // заполнение случайными числами [-1,1]

int delete_less_than_avg(double* ptr_array, int n); // удалить элементы < среднего, вернуть новое n

#endif // ARRAY_H
