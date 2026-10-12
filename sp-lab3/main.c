#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Завдання 1: Функція Calculations
void Calculations(double *g, double *v, double *c) {
    double orig_g = *g;
    double orig_v = *v;
    double orig_c = *c;

    double sum = orig_g + orig_v + orig_c;
    double prod = orig_g * orig_v * orig_c;
    // Оскільки варіант 6 (парний), обчислюємо синус суми
    double trig = sin(sum);

    *g = sum;
    *v = prod;
    *c = trig;
}

// Завдання 2: Рекурсивна функція
int sum_of_digits(int n) {
    n = abs(n);
    
    if (n == 0) {
        return 0;
    }
    
    return (n % 10) + sum_of_digits(n / 10);
}

int main() {
    srand(time(NULL));

    printf("================ ЗАВДАННЯ 1 ================\n");
    double group = 80;
    double variant = 6;
    double course = 4;

    printf("Початкові значення: група = %.0f, варіант = %.0f, курс = %.0f\n", group, variant, course);
    
    Calculations(&group, &variant, &course);
    
    printf("Нові значення: група = %.0f, варіант = %.0f, курс = %f\n\n", group, variant, course);

    printf("================ ЗАВДАННЯ 2 ================\n");
    int num;
    printf("Введіть ціле число: ");
    scanf("%d", &num);
    
    int sum_digits = (num == 0) ? 0 : sum_of_digits(num);
    printf("Сума цифр числа %d дорівнює: %d\n\n", num, sum_digits);

    printf("================ ЗАВДАННЯ 3 ================\n");
    double arr[5] = {1, 2, group, variant, course};
    
    printf("Масив до змін: [");
    for(int i = 0; i < 5; i++) {
        printf("%g ", arr[i]);
    }
    printf("]\n");

    arr[0] = group;
    arr[1] = course;

    for(int i = 0; i < 5; i++) {
        arr[i] += variant;
    }

    printf("Масив після змін: [");
    for(int i = 0; i < 5; i++) {
        printf("%g ", arr[i]);
    }
    printf("]\n\n");

    printf("================ ЗАВДАННЯ 4 ================\n");
    int N;
    printf("Введіть розмір масиву N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Помилка: розмір масиву має бути більше 0.\n");
        return 1;
    }

    int *dyn_arr = (int*)malloc(N * sizeof(int));
    if (dyn_arr == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    printf("\n=== 1. Початковий масив ===\n");
    for(int i = 0; i < N; i++) {
        *(dyn_arr + i) = rand() % 100 + 1; // Випадкові числа від 1 до 100
        printf("Елемент %d: значення = %d | адреса = %p\n", i, *(dyn_arr + i), (void*)(dyn_arr + i));
    }

    int *min_ptr = dyn_arr;
    int *max_ptr = dyn_arr;

    for(int i = 1; i < N; i++) {
        if (*(dyn_arr + i) < *min_ptr) {
            min_ptr = (dyn_arr + i);
        }
        if (*(dyn_arr + i) > *max_ptr) {
            max_ptr = (dyn_arr + i);
        }
    }

    printf("\n=== 2. Результати пошуку ===\n");
    printf("Мінімальний елемент: значення = %d | адреса = %p\n", *min_ptr, (void*)min_ptr);
    printf("Максимальний елемент: значення = %d | адреса = %p\n", *max_ptr, (void*)max_ptr);

    int temp = *min_ptr;
    *min_ptr = *max_ptr;
    *max_ptr = temp;

    printf("\n=== 3. Результуючий масив після обміну ===\n");
    for(int i = 0; i < N; i++) {
        printf("Елемент %d: значення = %d | адреса = %p\n", i, *(dyn_arr + i), (void*)(dyn_arr + i));
    }

    free(dyn_arr);
    return 0;
}