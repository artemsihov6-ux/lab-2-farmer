#include <stdio.h>
#include <stdlib.h>

#define START_DAY 1
#define START_HOUR 8
#define HOURS_IN_DAY 24

#define MENU_EXIT 0
#define MENU_CLOCK 1
#define MENU_WORK 2
#define MENU_SHOW_INVENTORY 3
#define MENU_PUT_ITEM 4
#define MENU_DROP_ITEM 5
#define MENU_VARIANT 6

/* Читает целое число; при вводе букв просит повторить */
int read_int(void)
{
    int value;
    int c;

    while (scanf("%d", &value) != 1) {
        if (feof(stdin)) {
            exit(0);
        }
        printf("Ошибка! Введите целое число: ");
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }
    /* убираем из буфера всё, что осталось в строке после числа */
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    return value;
}

int main(void)
{
    int current_day = START_DAY;
    int current_hour = START_HOUR;
    int choice;
    int hours;

    while (1) {
        printf("\n[%d] Выход\n", MENU_EXIT);
        printf("[%d] Посмотреть на часы\n", MENU_CLOCK);
        printf("[%d] Промотать время (Поработать)\n", MENU_WORK);
        printf("[%d] Посмотреть инвентарь\n", MENU_SHOW_INVENTORY);
        printf("[%d] Положить предмет в слот\n", MENU_PUT_ITEM);
        printf("[%d] Выбросить предмет\n", MENU_DROP_ITEM);
        printf("[%d] Инверсия карманов\n", MENU_VARIANT);
        printf("Выберите пункт: ");
        choice = read_int();

        switch (choice) {
        case MENU_EXIT:
            return 0;
        case MENU_CLOCK:
            printf("Текущее время: День %d, %02d:00\n", current_day, current_hour);
            break;
        case MENU_WORK:
            printf("Сколько часов поработать? ");
            hours = read_int();
            if (hours < 0) {
                printf("Часы не могут быть отрицательными.\n");
                break;
            }
            current_day += hours / HOURS_IN_DAY;
            current_hour += hours % HOURS_IN_DAY;
            if (current_hour >= HOURS_IN_DAY) {
                current_hour -= HOURS_IN_DAY;
                current_day++;
            }
            printf("Текущее время: День %d, %02d:00\n", current_day, current_hour);
            break;
        default:
            printf("Такого пункта меню нет.\n");
            break;
        }
    }
}
