#ifndef VEHICLE_H
#define VEHICLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INIT_CAPACITY 2

typedef struct {
    char name[100];
    char type[50];
    int year;
    double price;
} Vehicle;

typedef struct {
    Vehicle* data;
    int size;
    int capacity;
} SmartArray;

//Создание массива
SmartArray* create_smart_array() {
    SmartArray* arr = (SmartArray*)malloc(sizeof(SmartArray));
    arr->data = (Vehicle*)malloc(INIT_CAPACITY * sizeof(Vehicle));
    arr->size = 0;
    arr->capacity = INIT_CAPACITY;
    return arr;
}

void resize_smart_array(SmartArray* arr) {
    arr->capacity *= 2;
    arr->data = (Vehicle*)realloc(arr->data, arr->capacity * sizeof(Vehicle));
}

void add_vehicle(SmartArray* arr, Vehicle v) {
    if (arr->size >= arr->capacity) {
        resize_smart_array(arr);
    }
    arr->data[arr->size++] = v;
}

void remove_vehicle(SmartArray* arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Неверный индекс!\n");
        return;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

Vehicle* find_vehicle(SmartArray* arr, const char* name) {
    for (int i = 0; i < arr->size; i++) {
        if (strcmp(arr->data[i].name, name) == 0) {
            return &arr->data[i];
        }
    }
    return NULL;
}

void print_vehicle(Vehicle* v) {
    printf("Название: %s\n", v->name);
    printf("Тип: %s\n", v->type);
    printf("Год выпуска: %d\n", v->year);
    printf("Цена: %.2f млн руб.\n", v->price);
}

void print_all(SmartArray* arr) {
    if (arr->size == 0) {
        printf("Список пуст.\n");
        return;
    }
    printf("=== Военная техника (%d единиц) ===\n", arr->size);
    for (int i = 0; i < arr->size; i++) {
        printf("%d. ", i + 1);
        print_vehicle(&arr->data[i]);
        printf("---\n");
    }
}

void free_smart_array(SmartArray* arr) {
    free(arr->data);
    free(arr);
}

// Работа с бинарным файлом
void save_to_binary(SmartArray* arr, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка открытия файла для записи");
        return;
    }
    fwrite(&arr->size, sizeof(int), 1, file);
    fwrite(arr->data, sizeof(Vehicle), arr->size, file);
    fclose(file);
    printf("Данные сохранены в бинарный файл: %s\n", filename);
}

SmartArray* load_from_binary(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Файл не найден, создан новый список.\n");
        return create_smart_array();
    }
    
    SmartArray* arr = create_smart_array();
    int size;
    fread(&size, sizeof(int), 1, file);
    
    for (int i = 0; i < size; i++) {
        Vehicle v;
        fread(&v, sizeof(Vehicle), 1, file);
        add_vehicle(arr, v);
    }
    
    fclose(file);
    printf("Данные загружены из бинарного файла: %s\n", filename);
    return arr;
}

//Меню
void print_menu() {
    printf("\n=== Система учета военной техники ===\n");
    printf("1. Добавить технику\n");
    printf("2. Удалить технику\n");
    printf("3. Найти технику по названию\n");
    printf("4. Показать всю технику\n");
    printf("5. Сохранить в файл\n");
    printf("6. Загрузить из файла\n");
    printf("0. Выход\n");
    printf("Выбор: ");
}
