#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
int main()
{
	std::ifstream gile("MagicNumbers.txt");
	std::ifstream in("drago.png");
	bool fallo = false;
	int magic[8];

	in.read(reinterpret_cast<char*>(magic), 16);


	char check[8] = { 0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A };

	if (!gile.is_open())
		std::cout << "No se abrio" << "\n";
	else
		std::cout << " Se abrio." << "\n";

	std::string hexxx;

	getline(gile, hexxx);

	int d = 233;
	std::cout << std::hex << magic;
	


	_getch();
}