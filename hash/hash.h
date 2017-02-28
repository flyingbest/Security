#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
using namespace std;

class hash{
private:
  static const int tableSize = 10;
  
  struct item{
    string name;
    string drink;
    item* next;
  };

  item* HashTable[tableSize];

public:
  hash();
  int Hash(string key);

  int NumberOfItemsInIndex(int index);
  //void PrintTable();
	void PrintAllTable();
	//void PrintItemsInIndex(int index);

  void AddItem(string name, string drink);
	void FindDrink(string name);
	void RemoveItem(string name);

};

#endif
