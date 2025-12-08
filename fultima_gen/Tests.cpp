#define test //triger na testy. Zakomentowaæ po zakoñczeniu testów

#include <iostream>
#include <fstream>
#include "Generator.h"
#include "Player.h"

#ifdef test
//TODO: dodaæ testy jednostkowe
void testJSON_open();
void testCreatePlayer();

int main() {
	std::cout << "Starting tests..." << std::endl;
	testJSON_open();
	testCreatePlayer();
	std::cout << "Tests finished." << std::endl;
	return 0;
}

void testJSON_open() {
	Generator gen;
	try {
	
	}
	catch (const std::exception& e) {
		std::cerr << "ERR: Json file could not be opened" << e.what() << std::endl;
	}
	std::cerr << "JSON open test passed." << std::endl;
}

void testCreatePlayer() {

}
#endif // test
