.386
.MODEL flat, stdcall
includelib kernel32.lib

STD_INPUT_HANDLE EQU -10
STD_OUTPUT_HANDLE EQU -11
WriteConsole EQU <WriteConsoleA>
ReadConsole EQU <ReadConsoleA>
WriteConsoleOutputCharacter EQU <WriteConsoleOutputCharacterA>

BufSize = 100
COORD struc
x word ?
y word ?
COORD ends


GetStdHandle PROTO, nStdHandle:DWORD
ExitProcess PROTO :DWORD

ReadConsole PROTO,
handle: DWORD,
pBuffer: PTR BYTE,
maxBytes: DWORD,
pBytesRead: PTR DWORD,
notUsed: DWORD

WriteConsole PROTO,
handle: DWORD,
pBuffer: PTR BYTE,
bufsize: DWORD,
pCount: PTR DWORD,
lpReserved: DWORD

WriteConsoleOutputAttribute PROTO,
handle: DWORD,
pAttribute: PTR WORD,
nLength: DWORD,
xyCoord: COORD,
lpCount: PTR DWORD

SetConsoleTextAttribute PROTO,
outHandle:DWORD,
NCOLOR:DWORD

WriteConsoleOutputCharacter PROTO,
outHAndle:DWORD,
pBuffer:DWORD,
bufSize:DWORD,
xyCoord:COORD,
lpCount:PTR DWORD

.data

inputHandle DWORD ?
buffer BYTE BufSize DUP(?),0,0
bytesRead dd ?
attributes WORD 0Fh, 0Eh,0Dh,0Ch, 0Bh, 0Ah, 6,1,4,3
WORD 0Fh, 0Eh,0Dh,0Ch, 0Bh, 0Ah, 3, 4, 9, 2
WORD 0Fh, 0Eh,0Dh,0Ch, 0Bh, 0Ah, 2,1,6,8
WORD 0Fh, 0Eh,0Dh,0Ch, 0Bh, 0Ah, 3, 4, 9, 2
WORD 0Fh, 0Eh,0Dh,0Ch, 0Bh, 0Ah, 3, 4, 9, 2
WORD 0Fh, 0Eh,0Dh,0Ch, 0Bh, 0Ah, 8,3,5,1
WORD 0Fh, 0Eh,0Dh,0Ch, 0Bh, 0Ah, 3, 4, 9, 2
WORD 0Fh, 0Eh,0Dh,0Ch, 0Bh, 0Ah, 0,2,8,9
WORD 0Fh, 0Eh,0Dh,0Ch, 0Bh, 0Ah, 3, 4, 9, 2
WORD 0Fh, 0Eh,0Dh,0Ch, 0Bh, 0Ah, 1,0,2,3
xyPos COORD <1,2>

.code
main PROC

INVOKE GetStdHandle, STD_INPUT_HANDLE
mov inputHandle, eax
INVOKE ReadConsole,
inputHandle,
ADDR buffer,
BufSize-2,
ADDR bytesRead,
0

INVOKE GetStdHandle, STD_OUTPUT_HANDLE
mov inputHandle, eax
INVOKE WriteConsole,
inputHandle,
ADDR buffer,
BufSize-2,
ADDR bytesRead,
0

INVOKE WriteConsoleOutputAttribute,
inputHandle,
ADDR attributes,
bufSize-2,
xyPos,
ADDR bytesRead

INVOKE WriteConsoleOutputCharacter,
inputHandle,
ADDR buffer,
BufSize - 2,
xyPos,
ADDR bytesRead

call ExitProcess
main ENDP
end main