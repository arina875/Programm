#ifndef MILITARY_EQUIPMENT_H
#define MILITARY_EQUIPMENT_H

#include <iostream>
#include <string>
#include <fstream>

class MilitaryEquipment {
private:
    std::string name;
    std::string type;     
    int year;
    double caliber;       

public:
    MilitaryEquipment();
    MilitaryEquipment(const std::string& n, const std::string& t, int y, double c);

    std::string getName() const;
    std::string getType() const;
    int getYear() const;
    double getCaliber() const;

    void setName(const std::string& n);
    void setType(const std::string& t);
    void setYear(int y);
    void setCaliber(double c);

    friend std::ostream& operator<<(std::ostream& os, const MilitaryEquipment& eq);
    friend std::istream& operator>>(std::istream& is, MilitaryEquipment& eq);

    void saveToFile(std::ofstream& ofs) const;
    void loadFromFile(std::ifstream& ifs);
};

#endif
