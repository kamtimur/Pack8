#pragma once
#include "windows.h"
#include "Unpack.h"
//--------------------------------------------------------
//Одноканальная паковка
//1 / 2	 : (0) xxxx'00aa																																												
//2 / 10 : (2) xxxx'01aa	aaaa'aaaa
//3 / 18 : (1) xxxx'10aa	aaaa'aaaa aaaa'aaaa
//4 / 24 : (3) xxxx'11--	aaaa'aaaa aaaa'aaaa aaaa'aaaa
//--------------------------------------------------------
s32 unpack1_2(unsigned char * _src, long * _dst);
s32 unpack1_10(unsigned char * _src, long * _dst);
s32 unpack1_18(unsigned char * _src, long * _dst);
s32 unpack1_24(unsigned char * _src, long * _dst);
//--------------------------------------------------------
//для кодов паковки меньше 4 бит, например 100 в таблицу функций пишем в позиции 1000(1) и 1001(9) ту функцию, которая должна вызываться для кода 100
const type_unpack_funcs unpack1Funcs[] =
{
	unpack1_2,		//0
	unpack1_18,		//1
	unpack1_10,		//2
	unpack1_24,		//3
	unpack_NULL,	//4
	unpack1_18,		//5
	unpack1_10,		//6
	unpack1_24,		//7
	unpack_NULL,	//8
	unpack1_18,		//9
	unpack1_10,		//A
	unpack1_24,		//B
	unpack_NULL,	//C
	unpack1_18,		//D
	unpack1_10,		//E
	unpack1_24		//F
};