#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	_asm {
		mov eax, 49
		mov ecx, 7
		mov edx, 0
		cdq
		idiv ecx
		mov a, eax
		mov eax, 42
		mov ecx, 6
		cdq
		idiv ecx
		mov b, eax
		add a, eax
		mov ecx, 6
		imul ecx, 2
		add a, ecx
		mov ecx, 8
		imul ecx, 5
		mov b, ecx
		mov eax, b
		mov ecx, 9
		mov edx, 0
		cdq
		idiv ecx
		mov c, eax
		mov ecx, 4
		imul ecx, 6
		mov b, ecx
		mov ecx, c
		sub ecx, b
		mov eax, a
		mov edx, 0
		cdq
		idiv ecx
		mov c, eax
		mov eax, 23
		mov ecx, 12
		add eax, ecx
		imul eax, 5
		mov ecx, 26
		mov a, 4
		sub ecx, a
		mov edx, 0
		cdq
		idiv ecx
		mov a, eax
		mov eax, c
		add eax, a
		mov b, eax
	}
	cout <<(int) b;

	return 0;
}