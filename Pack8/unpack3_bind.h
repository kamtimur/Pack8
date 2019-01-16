#pragma once
#include "windows.h"
#include "Unpack.h"
//--------------------------------------------------------
//Трехканальная паковка связанная
//1 / 2  : (0) 00aa'bbcc
//2 / 4  : (3) 1100'aaaa bbbb'cccc
//3 / 7  : (5) 101a'aaaa aabb'bbbb bccc'cccc
//4 / 10 : (2) 01aa'aaaa aaaa'bbbb bbbb'bbcc cccc'cccc
//5 / 12 : (B) 1101'aaaa aaaa'aaaa bbbb'bbbb bbbb'cccc cccc'cccc
//6 / 15 : (1) 100a'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb bccc'cccc cccc'cccc
//7 / 17 : (7) 1110'aaaa aaaa'aaaa aaaa'abbb bbbb'bbbb bbbb'bbcc cccc'cccc cccc'ccc-
//8 / 20 : (F) 1111'aaaa aaaa'aaaa aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'cccc
//-------------------------------------------------------- -

s32 unpack3_2_bind(unsigned char * _src, long * _dst);
s32 unpack3_4_bind(unsigned char * _src, long * _dst);
s32 unpack3_7_bind(unsigned char * _src, long * _dst);
s32 unpack3_10_bind(unsigned char * _src, long * _dst);
s32 unpack3_12_bind(unsigned char * _src, long * _dst);
s32 unpack3_15_bind(unsigned char * _src, long * _dst);
s32 unpack3_17_bind(unsigned char * _src, long * _dst);
s32 unpack3_20_bind(unsigned char * _src, long * _dst);

//для кодов паковки меньше 4 бит, например 100 в таблицу функций пишем в позиции 1000(1) и 1001(9) ту функцию, которая должна вызываться для кода 100
const type_unpack_funcs unpack3Funcs_bind[] =
{
	unpack3_2_bind,		//0
	unpack3_15_bind,	//1
	unpack3_10_bind,	//2
	unpack3_4_bind,		//3
	unpack3_2_bind,		//4
	unpack3_7_bind,		//5
	unpack3_10_bind,	//6
	unpack3_17_bind,	//7
	unpack3_2_bind,		//8
	unpack3_15_bind,	//9
	unpack3_10_bind,	//A
	unpack3_12_bind,	//B
	unpack3_2_bind,		//C
	unpack3_7_bind,		//D
	unpack3_10_bind,	//E
	unpack3_20_bind		//F
};