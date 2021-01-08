#ifndef HOUSE_H
#define HOUSE_H

#include <fstream>

#include "perenthome.h"

class House : public PerentHome {
private:
    friend std::istream& operator >>(std::istream& in, House& x);
    friend std::ostream& operator <<(std::ostream& out, House& x);
    friend bool operator == (House& l, House& r);
public:
    House();
    House(int id, int number_house, int square, int floor, int count_room, std::string street);
    House(const House& object);

    void where_home() override;

    void saveToFile(std::string pathToFile) override;

    void loadFromFile(std::string pathToFile) override;

    std::string what_class() override;

    ~House();
};

#endif // HOUSE_H
