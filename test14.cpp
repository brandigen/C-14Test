
#include "stdafx.h"

#include <iostream>
#include <memory>
#include <string.h>

#include <set>
#include <string>
#include <tuple>
#include <utility>

using namespace std;


template<typename T>
constexpr T pi = T(3.141592653589793238462643383);

// Usual specialization rules apply:
template<>
constexpr const char* pi<const char*> = "pi";

class Phone {
public:
	char *name;
	double price;


	Phone()
	{
		this->name = new char[strlen("Default") + 1];
		strcpy(this->name, "Default");
		this->price = 0;
	}

	Phone(char *name, double price)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->price = price;
	}

	Phone(Phone& ph)
	{
		cout << "Copy ctor started" << endl;
		this->name = new char[strlen(ph.name) + 1];
		strcpy(this->name, ph.name);
		this->price = ph.price;
		cout << "Copy ctor ended" << endl;
	}


	Phone(Phone&& ph)
	{
		cout << "Move ctor started" << endl;
		this->name = new char[strlen(ph.name) + 1];
		strcpy(this->name, ph.name);
		delete[] ph.name;
		ph.name = nullptr;
		this->price = ph.price;
		ph.price = -1;
		cout << "Move ctor ended" << endl;
	}


	~Phone()
	{
		delete[] name;
	}

	Phone& operator=(const Phone& other)
	{

		if (this != &other) {
			delete[] name;  // Free the existing resource.
			price = other.price;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
		}
		return *this;
	}


};

constexpr auto test() {
	return 1;
}

void print(const Phone& p)
{
	cout << "name: " << p.name << " price: " << p.price << std::endl;
}

Phone createPhone(Phone phone)
{
	cout << "createPhone started" << endl;
	return phone;
}



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	int i = test();

	auto text = std::unique_ptr<char[]>(new char[5]);

	cout << i << endl;

	char *n1 = new char[strlen("Phone1") + 1];
	char *n2 = new char[strlen("Phone2") + 1];
	strcpy(n1, "Phone1");
	strcpy(n2, "Phone2");
	Phone p1(n1, 10);
	print(p1);
	Phone p2(n2, 20);
	print(p2);
	Phone p3(p2);
	print(p3);


	Phone p5 = createPhone(p3);

	auto integer_literal = 1'000'000;
	auto floating_point_literal = 0.000'015'3;
	auto binary_literal = 0b0100'1100'0110;
	auto silly_example = 1'0'0'000'00;

	cout << integer_literal << endl;
	cout << floating_point_literal << endl;
	cout << binary_literal << endl;
	cout << silly_example << endl;


	return 0;
}
