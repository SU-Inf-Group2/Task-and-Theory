#pragma once

class Student
{
	static const int EGN_SIZE = 10;
	char* first_name;
	char* middle_name;
	char* last_name;
	int EGN[EGN_SIZE];
	char* faculty_number;
public:
	Student();
	Student(const char* first_name, const char* middle_name, const char* last_name,
		    const int EGN[EGN_SIZE], const char* faculty_number);
	Student(const Student& other);
	~Student();

	void set_names(const char* first_name, const char* middle_name, const char* last_name);
	
	void set_first_name(const char* first_name);
	void set_middle_name(const char* middle_name);
	void set_last_name(const char* last_name);
	void set_EGN(const int EGN[EGN_SIZE]);
	void set_faculty_number(const char* faculty_number);

	void print_EGN() const;
	void print() const;
};