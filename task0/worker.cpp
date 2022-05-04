#include "worker.h"
#include <cstring>
#include <iostream>

//в случая е тук за ваше удобство, иначе не се счита за добра практика 
using namespace std;

Worker::Worker()
: first_name(0), middle_name(0), last_name(0), EGN{1}, work_id(0), is_hired(false) {}

Worker::Worker(const char* first_name, const char* middle_name, const char* last_name,
		         const int EGN[EGN_SIZE], const char* work_id, const bool is_hired)
: first_name(0), middle_name(0), last_name(0), work_id(0), is_hired(is_hired)
{
	set_names(first_name, middle_name, last_name);
	set_EGN(EGN);
	set_work_id(work_id);
}

Worker::Worker(const Worker& other)
: first_name(0), middle_name(0), last_name(0), work_id(0), is_hired(is_hired)
{
	set_names(other.first_name, other.middle_name, other.last_name);
	set_EGN(other.EGN);
	set_work_id(other.work_id);
}
	
Worker::~Worker()
{
	delete[] first_name;
	delete[] middle_name;
	delete[] last_name;
	delete[] work_id;
}

void Worker::set_names(const char* first_name, const char* middle_name, const char* last_name)
{
	set_first_name(first_name);
	set_middle_name(middle_name);
	set_last_name(last_name);
}
	
void Worker::set_first_name(const char* first_name)
{
	if(first_name == nullptr)
		throw "Invalid first name";

	delete[] this->first_name;
	this->first_name = new char[strlen(first_name) + 1];
	strcpy(this->first_name, first_name);
}

void Worker::set_middle_name(const char* middle_name)
{
	if(middle_name == nullptr)
		throw "Invalid middle name";

	delete[] this->middle_name;
	this->middle_name = new char[strlen(middle_name) + 1];
	strcpy(this->middle_name, middle_name);
}

void Worker::set_last_name(const char* last_name)
{
	if(last_name == nullptr)
		throw "Invalid last name";

	delete[] this->last_name;
	this->last_name = new char[strlen(last_name) + 1];
	strcpy(this->last_name, last_name);
}
	
void Worker::set_EGN(const int EGN[EGN_SIZE])
{
	for(int i = 0; i < EGN_SIZE; i++)
	{
		this->EGN[i] = EGN[i];
	}
}

void Worker::set_work_id(const char* work_id)
{
	if(work_id == nullptr)
		throw "Invalid work id";

	delete[] this->work_id;
	this->work_id = new char[strlen(work_id) + 1];
	strcpy(this->work_id, work_id);
}

void Worker::change_employment_state()
{
	is_hired = !is_hired;
}

void Worker::print_EGN() const
{
	for(int i = 0; i < EGN_SIZE; i++)
	{
		cout << EGN[i];
	}
	cout << endl;
}

void Worker::print() const
{
	cout << "Worker is called: ";
	cout << first_name << " " << middle_name << " " << last_name << endl;
	cout << "Worker has the EGN: ";
	print_EGN();
	cout << "Worker has the work id: " << work_id << endl;
	cout << "Worker is hired?: " << boolalpha << is_hired << endl;

}