#include <stdio.h>
#pragma warning(disable : 4996)
//Вариант#9

int main()
{
	int a, x, y, y1, y2, z;
	scanf("%d", &x);
	scanf("%d", &a);
	_asm
	{
		mov eax, x
		mov ecx, a
		cmp a, eax 
		ja Higher 
		add ecx, 2
		mov y2, ecx 
		jmp End 
		Higher: sub ecx, eax
		mov y2, ecx
		End:

		mov eax, x
		mov edi, 3
		div edi
		cmp dl, 2
		je Equally
		mov eax, 9
		mov y1, eax
		jmp Endl
		Equally: mov eax, x
		mov ecx, a
		imul eax, ecx
		mov y1, eax
		Endl:

		mov eax, y1
		mov ecx, y2
		imul ecx, eax
		mov y, ecx
	}
	printf("%d", y);
	return 0;
}