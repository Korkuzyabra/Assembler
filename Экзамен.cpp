#include<stdio.h>
#include <iostream>

using namespace std;

int main()
{
	short b;
	char a, c;
	_asm
	{
		mov ax, 3
		mov dx, 16
		imul ax, dx
		mov b, ax
		mov ax, 9
		mov dx, 8
		imul ax, dx
		add ax, b
		mov b, ax
		mov ax, b
		mov bl, 32
		div bl
		mov a, al
		mov c, ah
	}
	cout << (int)a << endl;
	cout<< (int)c;
	return 0;
}
