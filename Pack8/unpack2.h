#pragma once
#include "windows.h"
#include "Unpack.h"
//--------------------------------------------------------
//Двухканальная паковка
//1 / 0  : (0) xxxx'0000	
//2 / 5  : (2) xxxx'01aa	aaab'bbbb
//3 / 9  : (1) xxxx'10aa	aaaa'aaab bbbb'bbbb
//4 / 11 : (3) xxxx'1100	aaaa'aaaa aaab'bbbb	bbbb'bbbb
//5 / 16 : (B) xxxx'1101	aaaa'aaaa aaaa'aaaa	bbbb'bbbb bbbb'bbbb
//6 / 20 : (7) xxxx'1110	aaaa'aaaa aaaa'aaaa	aaaa'bbbb bbbb'bbbb bbbb'bbbb
//7 / 24 : (F) xxxx'1111	aaaa'aaaa aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb
//--------------------------------------------------------
s32 unpack2_0(unsigned char * _src, long * _dst);
s32 unpack2_5(unsigned char * _src, long * _dst);
s32 unpack2_9(unsigned char * _src, long * _dst);
s32 unpack2_11(unsigned char * _src, long * _dst);
s32 unpack2_16(unsigned char * _src, long * _dst);
s32 unpack2_20(unsigned char * _src, long * _dst);
s32 unpack2_24(unsigned char * _src, long * _dst);
//--------------------------------------------------------
//для кодов паковки меньше 4 бит, например 100 в таблицу функций пишем в позиции 1000(1) и 1001(9) ту функцию, которая должна вызываться для кода 100
const type_unpack_funcs unpack2Funcs[] =
{
	unpack2_0,		//0
	unpack2_9,		//1
	unpack2_5,		//2
	unpack2_11,		//3
	unpack_NULL,	//4
	unpack2_9,		//5
	unpack2_5,		//6
	unpack2_20,		//7
	unpack_NULL,	//8
	unpack2_9,		//9
	unpack2_5,		//A
	unpack2_16,		//B
	unpack_NULL,	//C
	unpack2_9,		//D
	unpack2_5,		//E
	unpack2_24		//F
};