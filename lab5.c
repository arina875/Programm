int main() {
    SmartArray* arr = create_smart_array();
    int choice;
    char filename[100] = "military_vehicles.bin";

    do {
        print_menu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                Vehicle v;
                printf("Название: ");
                fgets(v.name, sizeof(v.name), stdin);
                v.name[strcspn(v.name, "\n")] = 0;
printf("Тип (танк, БМП, самолет и т.д.): ");

                fgets(v.type, sizeof(v.type), stdin);
                v.type[strcspn(v.type, "\n")] = 0;
                printf("Год выпуска: ");
                scanf("%d", &v.year);
                printf("Цена (млн руб.): ");
                scanf("%lf", &v.price);
                add_vehicle(arr, v);
                break;
            }
            case 2: {
                int index;
                printf("Введите номер для удаления: ");
                scanf("%d", &index);
                remove_vehicle(arr, index - 1);
                break;
            }
            case 3: {
                char name[100];
                printf("Введите название: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                Vehicle* found = find_vehicle(arr, name);
                if (found) {
                    printf("Найдено:\n");
                    print_vehicle(found);
                } else {
                    printf("Техника с названием \"%s\" не найдена.\n", name);
                }
                break;
            }
            case 4:
                print_all(arr);
                break;
            case 5:
                save_to_binary(arr, filename);
                break;
            case 6:
                free_smart_array(arr);
                arr = load_from_binary(filename);
                break;
            case 0:
                printf("Выход...\n");
                break;
            default:
                printf("Неверный выбор.\n");
        }
    } while (choice != 0);

    free_smart_array(arr);
    return 0;
}
