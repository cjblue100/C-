#include <iostream>
#include <list>
#include <string>
#include <conio.h>
using namespace std;

class HashTable
{
private:
	static const int hashGroups = 10;
	list<pair<int, int>> table[hashGroups]; 

public:
	bool isEmpty()const;
	int hashFunciont(int key);
	void insertItem(int key, int value);
	void removeItem(int key);

	void printTable();
	
};

bool HashTable::isEmpty()const
{
	int sum{};
	for (int i{};i < hashGroups;i++)
	{
		sum += table[i].size();
	}

	if (!sum)
	{
		return true;
	}
	return false;
}

int HashTable::hashFunciont(int key)
{
	return key % hashGroups; 
}

void HashTable::insertItem(int key, int value)
{
	int hashValue = hashFunciont(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	for (;bItr != end(cell);bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr->second = value;
			
			break;
		}
	}

	if (!keyExists)
	{
		cell.emplace_back(key, value);
	}

	value;
}

void HashTable::removeItem(int key)
{
	int hashValue = hashFunciont(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	for (;bItr != end(cell);bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr=cell.erase(bItr);
			
			break;
		}
	}

	if (!keyExists)
	{
		cout << "No se encontro" << endl;
	}
}

void HashTable::printTable()
{
	for (int i{};i < hashGroups;i++)
	{
		if (table[i].size() == 0) continue;
		auto bItr = table[i].begin();
		for (;bItr != table[i].end();bItr++)
		{
			cout << "Key: " << bItr->first << " Valor: " << bItr->second << endl;
		}
	}
}

int main()
{
	HashTable HT;

	

	HT.insertItem(905, 2);
	HT.insertItem(201, 3);
	HT.insertItem(102, 4);
	HT.insertItem(504, 7);
	HT.insertItem(606, 6);
	HT.insertItem(771, 1);
	HT.insertItem(771, 9);

	HT.printTable();

	
	
	_getch();
}