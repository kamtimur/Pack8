#include "Unpack4.h"

//-------------------------------------------------------- -
//	���������������� ������� - ����� �� ������������
//	1/0  : (0) xxxx'0000	
//	2/2  : (8) xxxx'0001	aabb'�cdd
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

s32 unpack4_0(unsigned char * _src, long * _dst)
{
	//	1/0  : xxxx'0000
	return 0;
}

s32 unpack4_16(unsigned char * _src, long * _dst)
{
	//	9/16 : xxxx'1000	aaaa'aaaa aaaa'aaaa	bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc dddd'dddd dddd'dddd
	WORD *pW = (WORD*)(_src + 1);
	//0 a
	*_dst = (long)*pW;
	SIGNCH((*_dst), (1 << 15));
	_dst++;
	pW++;

	//1 b
	*_dst = (long)*pW;
	SIGNCH((*_dst), (1 << 15));
	_dst++;
	pW++;

	//2 c
	*_dst = (long)*pW;
	SIGNCH((*_dst), (1 << 15));
	_dst++;
	pW++;

	//3 d
	*_dst = (long)*pW;
	SIGNCH((*_dst), (1 << 15));
	_dst++;
	pW++;

	return 16;
}

s32 unpack4_8(unsigned char * _src, long * _dst)
{
	//	5/8  : (2) xxxx'0100	aaaa'aaaa bbbb'bbbb cccc'cccc dddd'dddd
	_src++;
	*_dst = (long)(*_src);
	SIGNCH((*_dst), (1 << 7));
	_dst++;
	_src++;

	//1 b
	*_dst = (long)(*_src);
	SIGNCH((*_dst), (1 << 7));
	_dst++;
	_src++;

	//2 c
	*_dst = (long)(*_src);
	SIGNCH((*_dst), (1 << 7));
	_dst++;
	_src++;

	//3 d
	*_dst = (long)(*_src);
	SIGNCH((*_dst), (1 << 7));
	_dst++;
	_src++;

	//4 e
	*_dst = (long)(*_src);
	SIGNCH((*_dst), (1 << 7));
	_dst++;
	_src++;

	//5 f
	*_dst = (long)(*_src);
	SIGNCH((*_dst), (1 << 7));
	_dst++;
	_src++;

	//6 h
	*_dst = (long)(*_src);
	SIGNCH((*_dst), (1 << 7));
	_dst++;
	_src++;

	//7 g
	*_dst = (long)(*_src);
	SIGNCH((*_dst), (1 << 7));
	return 8;
}

s32 unpack4_24(unsigned char * _src, long * _dst)
{
	return 24;
}

s32 unpack4_4(unsigned char * _src, long * _dst)
{
	return 4;
}

s32 unpack4_20(unsigned char * _src, long * _dst)
{
	return 20;
}

s32 unpack4_12(unsigned char * _src, long * _dst)
{
	return 12;
}

s32 unpack4_2(unsigned char * _src, long * _dst)
{
	return 2;
}

s32 unpack4_18(unsigned char * _src, long * _dst)
{
	return 18;
}

s32 unpack4_10(unsigned char * _src, long * _dst)
{
	return 10;
}

s32 unpack4_6(unsigned char * _src, long * _dst)
{
	return 6;
}

s32 unpack4_22(unsigned char * _src, long * _dst)
{
	return 22;
}
