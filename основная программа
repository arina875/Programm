#include "../include/MilitaryEquipment.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>

const std::string FILENAME = "data/equipment.txt";

namespace Database {
    std::vector<MilitaryEquipment> loadFromFile() {
        std::vector<MilitaryEquipment> db;
        std::ifstream file(FILENAME);
        if (!file.is_open()) return db;

        while (file.peek() != EOF) {
            MilitaryEquipment eq;
            eq.loadFromFile(file);
            if (!eq.getName().empty()) {
                db.push_back(eq);
            }
        }
        file.close();
        return db;
    }

    void saveToFile(const std::vector<MilitaryEquipment>& db) {
        std::ofstream file(FILENAME);
        if (!file.is_open()) {
            std::cerr << "Ошибка открытия файла для сохранения!\n";
            return;
        }
        for (const auto& eq : db) {
            eq.saveToFile(file);
        }
        file.close();
        std::cout << "База данных сохранена в файл.\n";
    }

    void printAll(const std::vector<MilitaryEquipment>& db) {
        if (db.empty()) {
            std::cout << "База данных пуста.\n";
            return;
        }
        std::cout << "\n=== Содержимое базы данных ===\n";
        for (size_t i = 0; i < db.size(); ++i) {
            std::cout << i + 1 << ". " << db[i] << '\n';
        }
        std::cout << "================================\n\n";
    }

    void addEquipment(std::vector<MilitaryEquipment>& db) {
        MilitaryEquipment eq;
        std::cin >> eq;
        db.push_back(eq);
        std::cout << "Техника добавлена.\n";
    }

    void deleteEquipment(std::vector<MilitaryEquipment>& db) {
        if (db.empty()) {
            std::cout << "Нет элементов для удаления.\n";
            return;
        }
        printAll(db);
        int index;
        std::cout << "Введите номер техники для удаления: ";
        std::cin >> index;
        if (index >= 1 && index <= static_cast<int>(db.size())) {
            db.erase(db.begin() + index - 1);
            std::cout << "Элемент удалён.\n";
        } else {
            std::cout << "Неверный номер.\n";
        }
    }

    void editEquipment(std::vector<MilitaryEquipment>& db) {
        if (db.empty()) {
            std::cout << "Нет элементов для редактирования.\n";
            return;
        }
        printAll(db);
        int index;
        std::cout << "Введите номер техники для редактирования: ";
        std::cin >> index;
        if (index >= 1 && index <= static_cast<int>(db.size())) {
            MilitaryEquipment& eq = db[index - 1];
            std::cout << "Текущие данные: " << eq << '\n';
            std::cout << "Введите новые данные:\n";
            std::cin >> eq;
            std::cout << "Данные обновлены.\n";
        } else {
            std::cout << "Неверный номер.\n";
        }
    }

    void searchByType(const std::vector<MilitaryEquipment>& db) {
        if (db.empty()) {
            std::cout << "База пуста.\n";
            return;
        }
        std::string type;
        std::cout << "Введите тип для поиска (танк/самолёт/корабль/...): ";
        std::cin >> type;
        bool found = false;
        for (const auto& eq : db) {
            if (eq.getType() == type) {
                std::cout << eq << '\n';
                found = true;
            }
        }
        if (!found) {
            std::cout << "Техника данного типа не найдена.\n";
        }
    }

    void searchByYearRange(const std::vector<MilitaryEquipment>& db) {
        if (db.empty()) {
            std::cout << "База пуста.\n";
            return;
        }
        int fromYear, toYear;
        std::cout << "Введите диапазон лет (от и до): ";
        std::cin >> fromYear >> toYear;
        bool found = false;
        for (const auto& eq : db) {
            if (eq.getYear() >= fromYear && eq.getYear() <= toYear) {
                std::cout << eq << '\n';
                found = true;
            }
        }
        if (!found) {
            std::cout << "Техника в указанном диапазоне не найдена.\n";
        }
    }
}

int main() {
    std::vector<MilitaryEquipment> db = Database::loadFromFile();
    int choice;

    do {
        std::cout << "\n=== Меню управления базой данных военной техники ===\n";
        std::cout << "1. Вывести всю технику\n";
        std::cout << "2. Добавить новую технику\n";
        std::cout << "3. Удалить технику\n";
        std::cout << "4. Редактировать технику\n";
        std::cout << "5. Поиск по типу\n";
        std::cout << "6. Поиск по диапазону лет выпуска\n";
        std::cout << "7. Сохранить и выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                Database::printAll(db);
                break;
            case 2:
                Database::addEquipment(db);
                break;
            case 3:
                Database::deleteEquipment(db);
                break;
            case 4:
                Database::editEquipment(db);
                break;
            case 5:
                Database::searchByType(db);
                break;
            case 6:
                Database::searchByYearRange(db);
                break;
            case 7:
                Database::saveToFile(db);
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный ввод. Попробуйте снова.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    } while (choice != 7);

    return 0;
}
