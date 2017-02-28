#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

hash::hash(){
	for(int i=0; i<tableSize; ++i){
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}

int hash::NumberOfItemsInIndex(int index){
	int cnt = 0;
	
	if(HashTable[index]->name == "empty"){
		return cnt;
	}	else {
		cnt++;
		item* ptr = HashTable[index];
		while(ptr->next != NULL){
			cnt++;
			ptr = ptr->next;
		}
	}
	return cnt;
}

/*
void hash::PrintTable(){
	int number;
	
	for(int i=0; i<tableSize; ++i){
		number = NumberOfItemsInIndex(i);
		cout << "--------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
		cout << "--------------------\n";
	}
}
*/

void hash::PrintAllTable(){
	int number;
	
	for(int i=0; i<tableSize; ++i){
		number = NumberOfItemsInIndex(i);

		item* ptr = HashTable[i];
		if(ptr->name == "empty"){
			cout << "--------------------\n";
			cout << "index = " << i << " is empty." << endl;
			cout << ptr->name << endl;
			cout << ptr->drink << endl;
			cout << "# of items = " << number << endl;
		} else {
			cout << "--------------------\n";
			cout << "index = " << i << " contains the following items." << endl;
			while(ptr != NULL){
				cout << "+-" << endl;
				cout << ptr->name << endl;
				cout << ptr->drink << endl;
				ptr = ptr->next;
			}
			cout << "# of items = " << number << endl;
		}
		cout << "--------------------\n";
	}
}

/*
void hash::PrintItemsInIndex(int index){
	item* ptr = HashTable[index];
	
	if(ptr->name == "empty"){
		cout << "index = " << index << " is empty." << endl;
	} else {
		cout << "index = " << index << " contains the following item.\n";
		while(ptr != NULL){
			cout << "--------------------\n";
			cout << ptr->name << endl;
			cout << ptr->drink << endl;
			cout << "--------------------\n";
			ptr = ptr->next;
		}
	}
}
*/

int hash::Hash(string key){
	int hash = 0;
	int index;

	for(int i=0; i<key.length(); ++i){
		hash = (hash + (int)key[i]) * 17;
		//cout << "hash = " << hash << endl;
		//cout << "key[" << i << "] = " << (int)key[i] << endl;
		//cout << endl;
	}
	
	index = hash % tableSize;

	return index;
}

void hash::AddItem(string name, string drink){
	int index = Hash(name);
	
	if(HashTable[index]->name == "empty"){
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}	else {
		item* ptr = HashTable[index];
		item* nptr = new item;
		nptr->name = name;
		nptr->drink = drink;
		nptr->next = NULL;

		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = nptr;
	}
}

void hash::FindDrink(string name){
	int index = Hash(name);
	bool foundName = false;
	string drink;

	item* ptr = HashTable[index];
	while(ptr != NULL){
		if(ptr->name == name){
			foundName = true;
			drink = ptr->drink;
		}
		ptr = ptr->next;
	}
	
	if(foundName == true){
		cout << "Favorite drink = " << drink << endl;
	} else {
		cout << name << "'s info was Not Found in the hash table." << endl;
	}
}

void hash::RemoveItem(string name){
	int index = Hash(name);
	
	item* delptr;
	item* p1;
	item* p2;

	// case 1. table is empty. 
	if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty"){
		cout << name << " was not found in the hash table." << endl;
	}

	// case 2. only 1 item contained in table and that item has matching name
	else if(HashTable[index]->name == name && HashTable[index]->next == NULL){
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";

		cout << name << " was removed from the hash table." << endl;
	}
	
	// case 3. match is located in the first item in the table but there are more items in the table.
	else if(HashTable[index]->name == name){
		delptr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delptr;

		cout << name << " was removed from the hash table." << endl;
	}

	// case 4. table contains items but first item is not a match
	else {
		p1 = HashTable[index]->next;
		p2 = HashTable[index];
		
		while(p1 != NULL && p1->name != name){
			p2 = p1;
			p1 = p1->next;
		}
		// case 4.1 no match
		if(p1 == NULL){
			cout << name << " was not found in the hash table." << endl;
		} 
		// case 4.2 match is found
		else {
			delptr = p1;
			p1 = p1->next;
			p2->next = p1;

			delete delptr;

			cout << name << " was removed from the hash table." << endl;
		}
	}
}
