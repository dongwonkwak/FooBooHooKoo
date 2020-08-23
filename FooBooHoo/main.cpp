#include <iostream>
#include <string>

using namespace std;

// Do not Touch
void Foo(string val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, int val9)
{
	cout << val1 << val2 << val3 << val4 << val5 << val6 << val7 << val8 << val9 << endl;
}

// Do Not Touch
void Boo()
{
	cout << "Boo" << endl;
}

// Do Not touch
void Hoo()
{
	cout << "Hoo" << endl;
}

void Koo()
{

}

// x64, Windows
int wmain()
{
	Koo();
	Foo("Test", 1, 2, 3, 4, 5, 6, 7, 8);
	/*
		Boo
		Test12345678
		Hoo
	*/
}