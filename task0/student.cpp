#include "student.h"
#include <cstring>
#include <iostream>

//в случая е тук за ваше удобство, иначе не се счита за добра практика 
using namespace std;

Student::Student()
: first_name(0), middle_name(0), last_name(0), EGN{1}, faculty_number(0) {}

Student::Student(const char* first_name, const char* middle_name, const char* last_name,
		         const int EGN[EGN_SIZE], const char* faculty_number)
: first_name(0), middle_name(0), last_name(0), faculty_number(0) 
{
	set_names(first_name, middle_name, last_name);
	set_EGN(EGN);
	set_faculty_number(faculty_number);
}

Student::Student(const Student& other)
: first_name(0), middle_name(0), last_name(0), faculty_number(0)
{
	set_names(other.first_name, other.middle_name, other.last_name);
	set_EGN(other.EGN);
	set_faculty_number(other.faculty_number);
}
	
Student::~Student()
{
	delete[] first_name;
	delete[] middle_name;
	delete[] last_name;
	delete[] faculty_number;
}

void Student::set_names(const char* first_name, const char* middle_name, const char* last_name)
{
	set_first_name(first_name);
	set_middle_name(middle_name);
	set_last_name(last_name);
}
	
void Student::set_first_name(const char* first_name)
{
	if(first_name == nullptr)
		throw "Invalid first name";

	delete[] this->first_name;
	this->first_name = new char[strlen(first_name) + 1];
	strcpy(this->first_name, first_name);
}

void Student::set_middle_name(const char* middle_name)
{
	if(middle_name == nullptr)
		throw "Invalid middle name";

	delete[] this->middle_name;
	this->middle_name = new char[strlen(middle_name) + 1];
	strcpy(this->middle_name, middle_name);
}

void Student::set_last_name(const char* last_name)
{
	if(last_name == nullptr)
		throw "Invalid last name";

	delete[] this->last_name;
	this->last_name = new char[strlen(last_name) + 1];
	strcpy(this->last_name, last_name);
}
	
void Student::set_EGN(const int EGN[EGN_SIZE])
{
	for(int i = 0; i < EGN_SIZE; i++)
	{
		this->EGN[i] = EGN[i];
	}
}

void Student::set_faculty_number(const char* faculty_number)
{
	if(faculty_number == nullptr)
		throw "Invalid faculty number";

	delete[] this->faculty_number;
	this->faculty_number = new char[strlen(faculty_number) + 1];
	strcpy(this->faculty_number, faculty_number);
}

void Student::print_EGN() const
{
	for(int i = 0; i < EGN_SIZE; i++)
	{
		cout << EGN[i];
	}
	cout << endl;
}

void Student::print() const
{
	cout << "Student is called: ";
	cout << first_name << " " << middle_name << " " << last_name << endl;
	cout << "Student has the EGN: ";
	print_EGN();
	cout << "Student has the faculty number: " << faculty_number << endl;
}