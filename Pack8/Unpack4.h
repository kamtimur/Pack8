#pragma once
#include "windows.h"
#include "Unpack.h"

//-------------------------------------------------------- -
//	„етырехканальна¤ паковка - лучше не использовать
//	1/0  : (0) xxxx'0000	
//	2/2  : (8) xxxx'0001	aabb'сcdd
//	3/4  : (4) xxxx'0010	aaaa'bbbb cccc'dddd
//	4/6  : (C) xxxx'0011	aaaa'aabb bbbb'cccc ccdd'dddd
//	5/8  : (2) xxxx'0100	aaaa'aaaa bbbb'bbbb cccc'cccc dddd'dddd
//	6/10 : (A) xxxx'0101	aaaa'aaaa aabb'bbbb bbbb'cccc cccc'ccdd	dddd'dddd
//	7/12 : (6) xxxx'0110	aaaa'aaaa aaaa'bbbb	bbbb'bbbb cccc'cccc	cccc'dddd dddd'dddd
//	8/14 : (E) xxxx'0111	aaaa'aaaa aaaa'aabb	bbbb'bbbb bbbb'cccc cccc'cccc ccdd'dddd dddd'dddd
//	9/16 : (1) xxxx'1000	aaaa'aaaa aaaa'aaaa	bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc dddd'dddd dddd'dddd
// 10/18 : (9) xxxx'1001	aaaa'aaaa aaaa'aaaa	aabb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'ccdd dddd'dddd dddd'dddd
// 11/20 : (5) xxxx'1010	aaaa'aaaa aaaa'aaaa	aaaa'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'dddd dddd'dddd dddd'dddd
// 12/22 : (D) xxxx'1011	aaaa'aaaa aaaa'aaaa	aaaa'aabb bbbb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'cccc ccdd'dddd dddd'dddd dddd'dddd
// 13/24 : (3) xxxx'1100	aaaa'aaaa aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'cccc dddd'dddd dddd'dddd dddd'dddd
////--------------------------------------------------------

s32 unpack4_0 (unsigned char * _src, long * _dst);	//0
s32 unpack4_16(unsigned char * _src, long * _dst);	//1
s32 unpack4_8 (unsigned char * _src, long * _dst);	//2
s32 unpack4_24(unsigned char * _src, long * _dst);	//3
s32 unpack4_4 (unsigned char * _src, long * _dst);	//4
s32 unpack4_20(unsigned char * _src, long * _dst);	//5
s32 unpack4_12(unsigned char * _src, long * _dst);	//6
													//7
s32 unpack4_2 (unsigned char * _src, long * _dst);	//8
s32 unpack4_18(unsigned char * _src, long * _dst);	//9
s32 unpack4_10(unsigned char * _src, long * _dst);	//A
													//B
s32 unpack4_6(unsigned char * _src, long * _dst);	//C
s32 unpack4_22(unsigned char * _src, long * _dst);	//D



const untype_pack_funcs unpack4Funcs[] =
{
	unpack4_0,		//0
	unpack4_16,		//1
	unpack4_8,		//2
	unpack4_24,		//3
	unpack4_4,		//4
	unpack4_20,		//5
	unpack4_12,		//6
	unpack_NULL,	//7
	unpack4_2,		//8
	unpack4_12,		//9
	unpack4_8,		//A
	unpack_NULL,	//B
	unpack4_6,		//C
	unpack4_22		//D
};