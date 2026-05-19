#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>

int main() {
    printf("=== Полные интерфейсные тесты CBLAS Level 1 ===\n");
    printf("ДЕМОНСТРАЦИОННЫЙ КОММИТ — ТЕСТ ДОЛЖЕН УПАСТЬ\n\n");

    float x[5] = {1,2,3,4,5};
    float y[5] = {0};

    cblas_saxpy(5, 2.0f, x, 1, y, 1);

    printf("saxpy выполнен: y[0] = %.1f\n", y[0]);

    // Намеренно ломаем тест
    printf("Проверка результата...\n");
    if (y[0] == 2.0f) {
        printf("FAIL: Ожидалось другое значение! (демонстрация падения CI)\n");
        return 1;        // <-- Возвращаем ошибку → CI упадёт
    }

    printf("Тест пройден\n");
    return 0;
}
