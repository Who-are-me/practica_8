#include "perenthome.h"

PerentHome::PerentHome() {
    id = 0;
    number_house = 0;
    square = 0;
    floor = 0;
    count_room = 0;
    street = "";
    name_class = "PerentHome";
}

void PerentHome::where_home() {
    std::cout << "Street " << street
        << " home " << number_house
        << " floor " << floor << std::endl;
}

void PerentHome::saveToFile(std::string pathToFile) {
    std::cout << "\nsaveToFile\n";
}

void PerentHome::loadFromFile(std::string pathToFile) {
    std::cout << "\nloadFromFile\n";
}

std::istream& operator >>(std::istream& in, PerentHome& x) {
    in >> x.id >> x.number_house >> x.floor >> x.count_room >> x.street;
    return in;
}

std::ostream& operator <<(std::ostream& out, PerentHome& x) {

    out << "id\t\t" << x.id
        << "\nnumber room\t" << x.number_house
        << "\nsquare\t\t" << x.square
        << "\nfloor\t\t" << x.floor
        << "\ncount rooms\t" << x.count_room
        << "\nstreet\t\t" << x.street << "\n-----------\n";

    return out;
}

std::string PerentHome::what_class() {
    return name_class;
}