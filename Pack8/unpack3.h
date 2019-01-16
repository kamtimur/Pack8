#pragma once
#include "windows.h"
#include "Unpack.h"
//--------------------------------------------------------
//Трехканальная паковка
//1 / 0   : (0) xxxx'0000	
//2 / 3   : (1) xxxx'100a	aabb'bccc
//3 / 5   : (8) xxxx'0001	aaaa'abbb	bbcc'ccc-   
//4 / 8   : (4) xxxx'0010	aaaa'aaaa	bbbb'bbbb   cccc'cccc
//5 / 11  : (5) xxxx'101a	aaaa'aaaa	aabb'bbbb   bbbb'bccc cccc'cccc
//6 / 13  : (6) xxxx'0011	aaaa'aaaa   aaaa'abbb   bbbb'bbbb bbcc'cccc	cccc'ccc-
//7 / 16  : (2) xxxx'0100	aaaa'aaaa	aaaa'aaaa	bbbb'bbbb bbbb'bbbb	cccc'cccc cccc'cccc
//8 / 19  : (3) xxxx'110a	aaaa'aaaa	aaaa'aaaa	aabb'bbbb bbbb'bbbb bbbb'bccc cccc'cccc cccc'cccc	
//9 / 21  : (6) xxxx'0110	aaaa'aaaa	aaaa'aaaa	aaaa'abbb bbbb'bbbb bbbb'bbbb bbcc'cccc cccc'cccc cccc'ccc-
//10/ 24  : (E) xxxx'0111	aaaa'aaaa	aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'cccc
//--------------------------------------------------------

s32 unpack3_0(unsigned char * _src, long * _dst);
s32 unpack3_3(unsigned char * _src, long * _dst);
s32 unpack3_5(unsigned char * _src, long * _dst);
s32 unpack3_8(unsigned char * _src, long * _dst);
s32 unpack3_11(unsigned char * _src, long * _dst);
s32 unpack3_13(unsigned char * _src, long * _dst);
s32 unpack3_16(unsigned char * _src, long * _dst);
s32 unpack3_19(unsigned char * _src, long * _dst);
s32 unpack3_21(unsigned char * _src, long * _dst);
s32 unpack3_24(unsigned char * _src, long * _dst);

//для кодов паковки меньше 4 бит, например 100 в таблицу функций пишем в позиции 1000(1) и 1001(9) ту функцию, которая должна вызываться для кода 100
const type_unpack_funcs unpack3Funcs[] =
{
	unpack3_0,		//0
	unpack3_3,		//1
	unpack3_16,		//2
	unpack3_19,		//3
	unpack3_8,		//4
	unpack3_11,		//5
	unpack3_21,		//6
	unpack_NULL,	//7
	unpack3_5,		//8
	unpack3_3,		//9
	unpack_NULL,	//A
	unpack3_19,		//B
	unpack3_13,		//C
	unpack3_11,		//D
	unpack3_24		//E
};