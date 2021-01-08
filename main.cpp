#include "house.h"
#include "hotelroom.h"
#include "perenthome.h"
#include "abstracthome.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {

	std::vector<int> vec_f(10);
	std::vector<int> vec_s(10);
	std::vector<int> vec_merge(20);

	for (int i = 0; i < 10;) {

		int tmp = rand() % 100;

		if (tmp % 2 != 0) {
			vec_f[i] = tmp;
			i++;
		}
	}

	for (std::vector<int>::iterator i = vec_s.begin(); i != vec_s.end();) {

		int tmp = rand() % 100;

		if (tmp % 2 == 0) {
			*i = tmp;
			i++;
		}
	}

	std::sort(vec_f.begin(), vec_f.end());
	std::sort(vec_s.begin(), vec_s.end());

	std::merge(vec_f.begin(), vec_f.end(), vec_s.begin(), vec_s.end(), vec_merge.begin());

	for (std::vector<int>::iterator i = vec_merge.begin(); i != vec_merge.end(); i++) {
		std::cout << *i << " ";
	}

	std::cout << std::endl;

	std::vector<PerentHome*> vec_PerentHome;

	PerentHome* pPerentHome;

	for (int i = 0; i < 2; i++) {
		pPerentHome = new House(i, 2, 3, 4, 5, "House");
		vec_PerentHome.push_back(pPerentHome);

		pPerentHome = new HotelRoom(i, 2, 3, 4, "HotelRoom");
		vec_PerentHome.push_back(pPerentHome);
	}

	std::vector<PerentHome*> vec_PerentHome_two = vec_PerentHome;

	for (unsigned int i = 0; i < vec_PerentHome.size(); i++) {

		if (vec_PerentHome[i]->what_class() == "House") {
			vec_PerentHome.erase(vec_PerentHome.begin() + i);
		}
	}

	for (unsigned int i = 0; i < vec_PerentHome_two.size(); i++) {

		if (vec_PerentHome_two[i]->what_class() == "HotelRoom") {
			vec_PerentHome_two.erase(vec_PerentHome_two.begin() + i);
		}
	}

	for (unsigned int i = 0; i < vec_PerentHome.size(); i++) {

		std::cout << *vec_PerentHome[i];
	}

	for (unsigned int i = 0; i < vec_PerentHome_two.size(); i++) {

		std::cout << *vec_PerentHome_two[i];
	}

	for (std::vector<PerentHome*>::iterator pObj = vec_PerentHome.begin(); pObj != vec_PerentHome.end(); ++pObj) {

		delete* pObj;
	}

	for (std::vector<PerentHome*>::iterator pObj = vec_PerentHome_two.begin(); pObj != vec_PerentHome_two.end(); ++pObj) {

		delete* pObj;
	}

	vec_PerentHome.clear();
	vec_PerentHome_two.clear();

	return 0;
}