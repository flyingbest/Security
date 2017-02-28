#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

int main(int argc, char* argv[]){
  hash hashObj;
	string name = "";
  
  hashObj.AddItem("xodbs", "Locha");
  hashObj.AddItem("kim", "Mocha");
  hashObj.AddItem("emma", "Beer");
  hashObj.AddItem("sarah", "Water");
  hashObj.AddItem("mike", "Tea");
  hashObj.AddItem("bill", "Hot Choco");
  hashObj.AddItem("steve", "Iced Mocha");
  hashObj.AddItem("susan", "Apple Cider");
  hashObj.AddItem("annie", "Caramel Mocha");
  hashObj.AddItem("jason", "Green Tea");

  //hashObj.PrintTable();
	//hashObj.PrintItemsInIndex(9);

  hashObj.PrintAllTable();

	/*
	while(name != "exit"){
		cout << "searching for : ";
		cin >> name;
		if(name != "exit"){
			hashObj.FindDrink(name);
		}
	}
	*/

	while(name != "exit"){
		cout << "Remove : ";
		cin >> name;
		if(name != "exit"){
			hashObj.RemoveItem(name);
		}
	}
	
  return 0;
} 
