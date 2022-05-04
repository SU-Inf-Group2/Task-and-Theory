#pragma once

class Worker
{
	static const int EGN_SIZE = 10;
	char* first_name;
	char* middle_name;
	char* last_name;
	int EGN[EGN_SIZE];
	char* work_id;
	bool is_hired;
public:
	Worker();
	Worker(const char* first_name, const char* middle_name, const char* last_name,
		    const int EGN[EGN_SIZE], const char* work_id, const bool is_hired);
	Worker(const Worker& other);
	~Worker();

	void set_names(const char* first_name, const char* middle_name, const char* last_name);
	
	void set_first_name(const char* first_name);
	void set_middle_name(const char* middle_name);
	void set_last_name(const char* last_name);
	void set_EGN(const int EGN[EGN_SIZE]);
	void set_work_id(const char* work_id);
	void change_employment_state(); //hire or fire

	void print_EGN() const;
	void print() const;
};