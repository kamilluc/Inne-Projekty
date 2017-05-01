section .text

global _start
_start:
finit

fld qword [zmA]
fld qword [zmB]
fld qword [zmC]
fldz

fadd st0,st2
fmul st0,st2

mov dword [temp],2
fild dword [temp]

fmul st4,st0
fmul st4
fmul st2

fsubp st1,st0

fldz
fcomip st1

jb wieksza
ja mniejsza


mov eax,4
mov ebx,1
mov ecx,rowneZ
mov edx,[rowneZ_dl]

int 80h

fldz
fsub st3
fdiv st4
fist dword [temp]

mov al,[temp]
add al,48
mov [znak+6],al

mov eax,4
mov ebx,1
mov ecx,znak+6
mov edx,2

int 80h

jmp koniec

wieksza:

mov eax,4
mov ebx,1
mov ecx,wiekszaD
mov edx,[wiekszaD_dl]
int 80h

fsqrt
fldz

fsub st3
fsub st1
fdiv st4
fistp dword [temp]

mov al,[temp]
add al,48
mov [znak],al

fldz
fsub st3
fadd st1
fdiv st4

fist dword [temp]

mov al,[temp]
add al,48
mov [znak+6],al

mov eax,4
mov ebx,1
mov ecx,znak
mov edx,8
int 80h


jmp koniec

mniejsza:

mov eax,4
mov ebx,1
mov ecx,mnieD
mov edx,[mnieD_dl]

int 80h


koniec:

mov eax,1
int 80h

section .data

mnieD	db "delta mniejsza od zera ",0ah
mnieD_dl dd $ - mnieD

rowneZ db "delta = 0, podwojny pierwiastek x0: "
rowneZ_dl dd $ - rowneZ

wiekszaD db "delta wieksza od 0, dwa pierwiastki x1: "
wiekszaD_dl dd $ - wiekszaD


zmA dq 1.0
zmB dq -3.0
zmC dq 4.0
znak db 0," x2: ",0,0ah
temp dd 0