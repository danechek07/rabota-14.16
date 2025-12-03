#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

double func(double x)
{
    return pow(x, 3) - 4 * pow(x, 2) + 2;
}

double* full_elements(double* ptr_array, int n)
{
    if (!ptr_array) return NULL;
    for (int i = 0; i < n; i++) {
        ptr_array[i] = func(i);
    }
    return ptr_array;
}

int put_elements(double* ptr_array, int n)
{
    if (!ptr_array || n <= 0) {
        printf("(массив пуст или недопустим)\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%2d: %.3lf\n", i, ptr_array[i]);
    }
    return n;
}

double* calc_elements(double* ptr_array, int n)
{
    if (!ptr_array) return NULL;
    for (int i = 0; i < n; i++) {
        ptr_array[i] = -ptr_array[i];
    }
    return ptr_array;
}

double sum_elements(double* ptr_array, int begin, int end)
{
    if (!ptr_array || begin > end || begin < 0) return 0.0;
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

int find_max_from_k(double* ptr_array, int n, int ka)
{
    if (!ptr_array || n <= 0 || ka < 0 || ka >= n) return -1;
    int idx_max = ka;
    double maxv = ptr_array[ka];
    for (int i = ka + 1; i < n; i++) {
        if (ptr_array[i] > maxv) {
            maxv = ptr_array[i];
            idx_max = i;
        }
    }
    return idx_max;
}

double* full_elements_rand(double* ptr_array, int n)
{
    if (!ptr_array) return NULL;
    for (int i = 0; i < n; i++) {
        double r = (double)rand() / (double)RAND_MAX;
        ptr_array[i] = -1.0 + 2.0 * r;
    }
    return ptr_array;
}

int delete_less_than_avg(double* ptr_array, int n)
{
    if (!ptr_array || n <= 0) return 0;

    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += ptr_array[i];
    double avg = sum / n;

    int write = 0;
    for (int read = 0; read < n; read++) {
        if (ptr_array[read] >= avg) {
            ptr_array[write++] = ptr_array[read];
        }
    }
    return write;
}
