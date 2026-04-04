#include "../include/MilitaryEquipment.h"
#include <iomanip>

MilitaryEquipment::MilitaryEquipment() : name(""), type(""), year(0), caliber(0.0) {}

MilitaryEquipment::MilitaryEquipment(const std::string& n, const std::string& t, int y, double c)
    : name(n), type(t), year(y), caliber(c) {}

std::string MilitaryEquipment::getName() const { return name; }
std::string MilitaryEquipment::getType() const { return type; }
int MilitaryEquipment::getYear() const { return year; }
double MilitaryEquipment::getCaliber() const { return caliber; }

void MilitaryEquipment::setName(const std::string& n) { name = n; }
void MilitaryEquipment::setType(const std::string& t) { type = t; }
void MilitaryEquipment::setYear(int y) { year = y; }
void MilitaryEquipment::setCaliber(double c) { caliber = c; }

std::ostream& operator<<(std::ostream& os, const MilitaryEquipment& eq) {
    os << "Название: " << eq.name
       << ", Тип: " << eq.type
       << ", Год выпуска: " << eq.year
       << ", Калибр: " << std::fixed << std::setprecision(1) << eq.caliber << " мм";
    return os;
}

std::istream& operator>>(std::istream& is, MilitaryEquipment& eq) {
    std::cout << "Введите название: ";
    is.ignore();
    std::getline(is, eq.name);
    std::cout << "Введите тип (танк/самолёт/корабль/...): ";
    std::getline(is, eq.type);
    std::cout << "Введите год выпуска: ";
    is >> eq.year;
    std::cout << "Введите калибр (мм): ";
    is >> eq.caliber;
    return is;
}

void MilitaryEquipment::saveToFile(std::ofstream& ofs) const {
    ofs << name << '\n' << type << '\n' << year << '\n' << caliber << '\n';
}

void MilitaryEquipment::loadFromFile(std::ifstream& ifs) {
    std::getline(ifs, name);
    std::getline(ifs, type);
    ifs >> year;
    ifs.ignore();
    ifs >> caliber;
    ifs.ignore();
} 
