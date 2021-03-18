#pragma once
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <conio.h>
using namespace std;

enum {W = 87, w = 119, S = 83, s = 115, Z = 90, z = 122 , X = 88, x = 120, C = 67, c = 99, V = 86, v = 118, Esc = 27};
enum {Latin = 0, Cyrillic = 1, Punct  = 2, Digit = 3};

class Class
{
	vector<string> vec;
	int page = 1;
	bool filters[4];
	void(*mod[4])(string&) = { Class::DeleteLatin, Class::DeleteCyrillic, Class::DeletePunct, Class::DeleteDigit };

	void Menu();
	void LoadPage();
	void Modification(int key, string page);
	void Filters(int key);
	static void DeletePunct(string& copy);
	static void DeleteDigit(string& copy);
	static void DeleteLatin(string& copy);
	static void DeleteCyrillic(string& copy);
public:
	void PrintPage();
};


