#include "hotelroom.h"

HotelRoom::HotelRoom() {
    std::cin >> id >> number_house >> floor >> count_room >> street;
    name_class = "HotelRoom";
}

HotelRoom::HotelRoom(int id, int number_house, int floor, int count_room, std::string street) {
    this->id = id;
    this->number_house = number_house;
    this->floor = floor;
    this->count_room = count_room;
    this->street = street;

    name_class = "HotelRoom";
}

HotelRoom::HotelRoom(const HotelRoom& object) {
    id = object.id;
    number_house = object.number_house;
    floor = object.floor;
    count_room = object.count_room;
    street = object.street;
    name_class = "HotelRoom";
}

void HotelRoom::where_home() {
    std::cout << "Street " << street
        << " home " << number_house
        << " floor " << floor << std::endl;
}

void HotelRoom::saveToFile(std::string pathToFile) {
    
    std::ofstream fout;
    fout.open(pathToFile, std::ofstream::app);

    fout << "HotelRoom " << std::to_string(id)
        << ", " << std::to_string(number_house)
        << ", " << std::to_string(floor)
        << ", " << std::to_string(count_room)
        << ", " << street << ";\n";

    fout.close();
}

void HotelRoom::loadFromFile(std::string pathToFile) {
    std::ifstream fin;
    fin.open(pathToFile);

    std::string str;

    try {
        if (fin.is_open()) {
            std::string str;

            while (!fin.eof()) {
                str = "";
                getline(fin, str);

                if (!fin.eof()) {
                    if (str[2] == 't') {
                        char tmp_data = ' ';
                        int i;
                        std::string data = "";

                        for (i = 10; tmp_data != ','; i++) {
                            data = data + str[i];
                            tmp_data = str[i + 1];
                        }

                        id = std::stoi(data);
                        data = "";
                        tmp_data = ' ';

                        for (i = i + 1; tmp_data != ','; i++) {
                            data = data + str[i];
                            tmp_data = str[i + 1];
                        }

                        number_house = std::stoi(data);
                        data = "";
                        tmp_data = ' ';

                        for (i = i + 1; tmp_data != ','; i++) {
                            data = data + str[i];
                            tmp_data = str[i + 1];
                        }

                        floor = std::stoi(data);
                        data = "";
                        tmp_data = ' ';

                        for (i = i + 1; tmp_data != ','; i++) {
                            data = data + str[i];
                            tmp_data = str[i + 1];
                        }

                        count_room = std::stoi(data);
                        data = "";
                        tmp_data = ' ';

                        for (i = i + 1; tmp_data != ';'; i++) {
                            data = data + str[i];
                            tmp_data = str[i + 1];
                        }

                        street = data;
                    }
                }
            }
        }
        else {
            throw MyException("Error is open file: ", pathToFile);
        }
    }
    catch (MyException* ex) {
        std::cout << ex->what_is_path();
    }

    fin.close();
}

HotelRoom::~HotelRoom() {

}

std::istream& operator >>(std::istream& in, HotelRoom& x) {
    in >> x.id >> x.number_house >> x.floor >> x.count_room >> x.street;
    return in;
}

std::ostream& operator <<(std::ostream& out, HotelRoom& x) {

    out << "id\t\t" << x.id
        << "\nnumber room\t" << x.number_house
        << "\nfloor\t\t" << x.floor
        << "\ncount rooms\t" << x.count_room
        << "\nstreet\t\t" << x.street << "\n-----------\n";

    return out;
}

bool operator == (HotelRoom& l, HotelRoom& r) {
    bool res = false;

    if (l.id == r.id &&
        l.number_house == r.number_house &&
        l.floor == r.floor &&
        l.count_room == r.count_room &&
        l.street == r.street)
    {
        res = true;
    }

    return res;
}

std::string HotelRoom::what_class() {
    return name_class;
}