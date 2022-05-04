#include <iostream>
#include "student.h"
#include "worker.h"

using namespace std;

int main()
{
	const int EGN[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	Student s2("Pesho", "Goshov", "Sashov", EGN,
		           "0MI0100001");
	s2.print();

	Worker w1("Pesho", "Goshov", "Sashov", EGN, "work1221", true);

	w1.print();

	return 0;
}