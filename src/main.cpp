// ex01.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	//tests:
	Vector v1(7, 6);
	Vector v2(5, 15);
	
	Vector v3(v2);

	if (v1 != v2)
		cout << "is not equal" << endl;
	else if(v1 > v2)
		cout << "v1 > v2" << endl;
	else if (v1 < v2)
		cout << "v1 < v2" << endl;
	
	


	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << endl;
	return 0;
}
