#include <stdio.h>
#include <iostream>


int main() 
{
	char x, y, z;
	_asm 
	{
		mov al, 01010111b //al = 01010111 (87)
		mov y, al //y = 01010111 (87)

		shr al, 7 //al = 00000000 (0)
		mov x, al

		mov al, y //al = 01010111 (87)
		shr al, 5 //al = 00000010 (2)
		and al, 100b //al = 00000000 (0)
		shr al, 1 // al = 00000000(0)
		or al, x //al = 00000000 (0)

		mov al, y //al = 01010111 (87)
		and al, 0001000b //al = 00000000 (0)
		shr al, 1 //al = 00000000 (0)
		or al, x //al = 00000000(0)

		mov al, y //al = 01010111 (87) 
		and al, 0000010b //al = 00000010 (2)
		shl al, 2 //al = 00001000 (8)
		or al, x //al = 00001000 (8)
		mov x, al
		//==================================================================
		mov al, 01010111b //al = 01010111 (87)
		mov y, al //y = 01010111 (87)

		shr al, 6 //al = 00000001 (1)
		mov z, al

		mov al, y //al = 01010111 (87)
		shr al, 4 //al = 00000101 (5)
		and al, 100b //al = 00000100 (4)
		shr al, 1 //al = 00000010 (2)
		or al, z //al = 00000011 (3)

		mov al, y //al = 01010111 (87)
		and al, 0001000b //al = 00000000(0)
		shr al, 2 //al = 00000000 (0)
		or al, z //al = 00000001 (1)

		mov al, y //al = 01010111 (87)
		and al, 0001111b //al = 00000111 (7)
		shl al, 1 //al = 00001110 (14)
		or al, z //al = 00001111 (15)

		or al, x //al = 00001111 (15) + x = 00001000 (8) => al = 00010111 (23)
		shr al, 3 //al = 00000010 (2)
		mov x, al
	}
	x = 2;
	printf("%x",x);
	return 0;
}