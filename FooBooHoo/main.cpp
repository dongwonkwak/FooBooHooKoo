#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void Hoo();

// Do not Touch
void Foo(string val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, int val9)
{
	cout << val1 << val2 << val3 << val4 << val5 << val6 << val7 << val8 << val9 << endl;
}

void Foo2(string val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, int val9)
{
	cout << val1 << val2 << val3 << val4 << val5 << val6 << val7 << val8 << val9 << endl;
	Hoo();
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
	Boo();
	DWORD dwBackup;

	VirtualProtect(&Foo, 12, PAGE_EXECUTE_READWRITE, &dwBackup);
	uint64_t offset = (uint64_t)&Boo - (int64_t)&Hoo;
	uint64_t h = (uint64_t)&Foo2;
	BYTE d[12] = { 0x48, 0xb8,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0xff, 0xe0 };
	memcpy(&d[2], &h, 8);
	memcpy((void*)&Foo, &d, 12);
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