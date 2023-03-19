// ex01.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	Vector v1(5, 15);
	v1.insert(8,3);
	 

	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << endl;
	return 0;
}
