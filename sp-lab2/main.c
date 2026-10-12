#include <stdio.h>
#include <math.h>
#include <string.h>

// 3. Оголошення глобальних змінних
int group_number;
int variant_number;

// 5. Функція перевірки квадратного кореня та довжини імені
void check_sqrt(int group_num, const char* name) {
    double sq = sqrt(group_num);
    size_t len = strlen(name);

    printf("\n--- Результат виконання функції check_sqrt ---\n");
    printf("sqrt(%d) = %.2f, довжина імені \"%s\" = %zu\n", group_num, sq, name, len);

    if (sq > len) {
        printf("Результат: %.2fs (Корінь більший за довжину імені, виведено суму)\n", sq + len);
    } else if (sq < len) {
        printf("Результат: %.2fn (Корінь менший за довжину імені, виведено добуток)\n", sq * len);
    } else {
        printf("Результат: Значення рівні! Корінь: %.2f, Довжина: %zu\n", sq, len);
    }
}

int main() {
    // Введення первинних даних користувачем
    printf("===== ВВЕДЕННЯ ДАНИХ КОРИСТУВАЧА =====\n");
    printf("Введіть ваш номер за журналом (варіант): ");
    scanf("%d", &variant_number);

    printf("Введіть номер вашої групи (наприклад, 92): ");
    scanf("%d", &group_number);

    // 3a. Оголошення та введення ім'я користувача
    char name[50];
    printf("Введіть ваше ім'я: ");
    scanf("%49s", name);

    printf("\n================ РЕЗУЛЬТАТИ ================\n");

    // 2. Обчислення sin або cos залежно від парності варіанта
    if (variant_number % 2 == 0) {
        printf("2. Мій номер за журналом %d (ПАРНИЙ). Його Sin = %f\n", 
               variant_number, sin(variant_number));
    } else {
        printf("2. Мій номер за журналом %d (НЕПАРНИЙ). Його Cos = %f\n", 
               variant_number, cos(variant_number));
    }

    // 3a. Виведення основних даних
    printf("3a. Група: %d, Варіант: %d, Ім'я: %s\n", group_number, variant_number, name);

    // 3b, 3c. Обчислення добутку та явне приведення типів
    double product = variant_number * 3.14;
    int converted_product = (int)product; // Явне приведення типів
    printf("3b,c. Добуток = %.2f, Конвертований у int = %d\n", product, converted_product);

    // 4. Оголошення константи довжини імені та обчислення суми в циклі
    const int NAME_NUMBER = strlen(name);
    int target_start = variant_number + NAME_NUMBER;
    int total_sum = 0;

    for (int i = target_start; i >= 1; i--) {
        total_sum += i;
    }

    printf("\n4. Кількість літер у повному імені (NAME_NUMBER): %d\n", NAME_NUMBER);
    printf("   Початковий лічильник (Варіант + NAME_NUMBER): %d\n", target_start);
    printf("   Сума усіх чисел від 1 до %d: %d\n", target_start, total_sum);

    // 5. Виклик функції check_sqrt
    check_sqrt(group_number, name);

    // 6. Множинний вибір switch для визначення курсу
    int input_group;
    printf("\n6. Введіть номер групи для перевірки курсу (або %d за замовчуванням): ", group_number);
    scanf("%d", &input_group);

    switch (input_group) {
        case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 99:
            printf("Група %d навчається на I курсі.\n", input_group);
            break;
        case 87: case 88: case 89: case 90: case 91:
            printf("Група %d навчається на II курсі.\n", input_group);
            break;
        case 81: case 82: case 83: case 84: case 85: case 86:
            printf("Група %d навчається на III курсі.\n", input_group);
            break;
        case 75: case 76: case 77: case 78: case 79: case 80:
            printf("Група %d навчається на IV курсі.\n", input_group);
            break;
        default:
            printf("Групу з номером %d не знайдено серед списку груп коледжу.\n", input_group);
            break;
    }

    return 0;
}
