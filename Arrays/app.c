#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

#define N 200

int task14(void);
int task16(void);

int main(void)
{
    system("chcp 1251");
    srand((unsigned)time(NULL));

    printf("=== Лабораторная 14 ===\n");
    task14();

    printf("\n\n=== Лабораторная 16 ===\n");
    task16();

    return 0;
}

int task14(void)
{
    int size;
    double array[N];

    printf("Введите размер массива > ");
    if (scanf("%d", &size) != 1) return 1;
    if (size <= 0 || size > N) {
        printf("Недопустимый размер (1..%d)\n", N);
        return 1;
    }

    int begin, end;
    printf("Введите начало и конец диапазона: ");
    scanf("%d %d", &begin, &end);
    if (begin < 0) begin = 0;
    if (end >= size) end = size - 1;
    if (begin > end) {
        printf("Неверный диапазон\n");
        return 1;
    }

    int ka; // поиск порядкового номера максимального значения начиная с ka
    printf("Введите индекс ka (начало поиска максимума): ");
    scanf("%d", &ka);
    if (ka < 0) ka = 0;
    if (ka >= size) ka = size - 1;

    full_elements(array, size);

    // печать исходного
    printf("\nИсходный массив:\n");
    put_elements(array, size);

    // обработка (инверсия знака)
    double temp1[N];
    for (int i = 0; i < size; i++) temp1[i] = array[i];
    calc_elements(temp1, size);
    printf("\nПреобразованный массив (умножение на -1):\n");
    put_elements(temp1, size);

    // сумма в диапазоне
    double sum = sum_elements(array, begin, end);
    printf("\nСумма элементов в диапазоне [%d..%d]: %.3lf\n", begin, end, sum);

    // поиск индекса максимума, начиная с ka
    int idx = find_max_from_k(array, size, ka);
    printf("Индекс максимального элемента, начиная с %d: %d\n", ka, idx);

    return 0;
}

int task16(void)
{
    int size;
    printf("Введите размер массива > ");
    if (scanf("%d", &size) != 1) return 1;
    if (size <= 0) { printf("Неверный размер\n"); return 1; }

    double* ptr_array = (double*)malloc(size * sizeof(double));
    if (!ptr_array) { puts("Ошибка выделения памяти!"); return 1; }

    full_elements_rand(ptr_array, size);

    printf("\nВведённый (случайный) массив:\n");
    put_elements(ptr_array, size);

    printf("\nУдаление всех элементов, меньших среднего арифметического...\n");
    int new_size = delete_less_than_avg(ptr_array, size);
    if (new_size <= 0) {
        puts("Все элементы удалены — массив пуст.");
        free(ptr_array);
        return 1;
    }

    printf("Массив после удаления элементов < avg:\n");
    put_elements(ptr_array, new_size);

    free(ptr_array);
    return 0;
}