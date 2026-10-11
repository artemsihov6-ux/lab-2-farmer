#include <stdio.h>
#include <stdlib.h>

#define START_DAY 1
#define START_HOUR 8
#define HOURS_IN_DAY 24
#define INVENTORY_SIZE 10

#define ITEM_EMPTY 0
#define ITEM_WOOD 1
#define ITEM_STONE 2
#define ITEM_SEEDS 3
#define ITEM_WATERING_CAN 4
#define ITEM_HOE 5
#define ITEM_CARROT 6
#define ITEM_WHEAT 7
#define ITEM_EGG 8
#define ITEM_MILK 9

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
    int inventory[INVENTORY_SIZE] = {
        ITEM_WOOD, ITEM_STONE, ITEM_SEEDS, ITEM_WATERING_CAN, ITEM_HOE,
        ITEM_CARROT, ITEM_WHEAT, ITEM_EGG, ITEM_MILK, ITEM_EMPTY
    };
    int choice;
    int hours;
    int slot;
    int item;
    int i;

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
        case MENU_SHOW_INVENTORY:
            for (i = 0; i < INVENTORY_SIZE; i++) {
                printf("Слот %d: [%d]", i, inventory[i]);
                switch (inventory[i]) {
                case ITEM_WOOD:
                    printf(" (Дерево)");
                    break;
                case ITEM_STONE:
                    printf(" (Камень)");
                    break;
                case ITEM_SEEDS:
                    printf(" (Семена)");
                    break;
                case ITEM_WATERING_CAN:
                    printf(" (Лейка)");
                    break;
                case ITEM_HOE:
                    printf(" (Мотыга)");
                    break;
                case ITEM_CARROT:
                    printf(" (Морковь)");
                    break;
                case ITEM_WHEAT:
                    printf(" (Пшеница)");
                    break;
                case ITEM_EGG:
                    printf(" (Яйцо)");
                    break;
                case ITEM_MILK:
                    printf(" (Молоко)");
                    break;
                default:
                    break;
                }
                printf("\n");
            }
            break;
        case MENU_PUT_ITEM:
            printf("Введите индекс слота (от 0 до %d): ", INVENTORY_SIZE - 1);
            slot = read_int();
            if (slot < 0 || slot >= INVENTORY_SIZE) {
                printf("Такого слота нет.\n");
                break;
            }
            printf("Введите ID предмета (от %d до %d): ", ITEM_EMPTY, ITEM_MILK);
            item = read_int();
            if (item < ITEM_EMPTY || item > ITEM_MILK) {
                printf("Такого предмета нет.\n");
                break;
            }
            inventory[slot] = item;
            break;
        case MENU_DROP_ITEM:
            printf("Введите индекс слота (от 0 до %d): ", INVENTORY_SIZE - 1);
            slot = read_int();
            if (slot < 0 || slot >= INVENTORY_SIZE) {
                printf("Такого слота нет.\n");
                break;
            }
            inventory[slot] = ITEM_EMPTY;
            break;
        default:
            printf("Такого пункта меню нет.\n");
            break;
        }
    }
}
