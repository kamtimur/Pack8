#include "Unpack4.h"

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

s32 unpack4_0(unsigned char * _src, long * _dst)
{
	//	1/0  : xxxx'0000
	return 0;
}

s32 unpack4_2(unsigned char * _src, long * _dst)
{
	//	2/2  : (8) xxxx'0001	aabb'сcdd
	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 2);
	UNPACKPTN(S, 2);
	UNPACKPTN(S, 2);
	UNPACKPTN_END(S, 2);
	return 2;
}

s32 unpack4_4(unsigned char * _src, long * _dst)
{
	//	3/4	  : (4) xxxx'0010	aaaa'bbbb cccc'dddd|

	DWORD DW = *(DWORD*)(_src + 1);
	//0 a
	*_dst = (DW & 0x0f);

	SIGNCH((*_dst), (1 << 3));
	_dst++;

	//1 b
	*_dst = ((DW >> 4) & 0x0f);
	SIGNCH((*_dst), (1 << 3));
	_dst++;

	//2 c
	*_dst = ((DW >> 8) & 0x0f);
	SIGNCH((*_dst), (1 << 3));
	_dst++;

	//3 d
	*_dst = ((DW >> 12) & 0x0f);
	SIGNCH((*_dst), (1 << 3));

	return 4;
}

s32 unpack4_6(unsigned char * _src, long * _dst)
{
	//	4/6  : (C) xxxx'0011	aaaa'aabb bbbb'cccc ccdd'dddd

	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 6);
	UNPACKPTN(S, 6);
	UNPACKPTN(S, 6);
	UNPACKPTN_END(S, 6);
	return 6;
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
	return 8;
}

s32 unpack4_10(unsigned char * _src, long * _dst)
{
	//	6/10 : (A) xxxx'0101	aaaa'aaaa aabb'bbbb bbbb'cccc cccc'ccdd	dddd'dddd

	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 10);
	UNPACKPTN(S, 10);
	UNPACKPTN(S, 10);
	S = GETSRCS(_src + 4, 6);
	UNPACKPTN_END(S, 10);
	return 10;
}

s32 unpack4_12(unsigned char * _src, long * _dst)
{
	//	7/12 : (6) xxxx'0110	aaaa'aaaa aaaa'bbbb	bbbb'bbbb cccc'cccc	cccc'dddd dddd'dddd

	DWORD DW = *(DWORD*)(_src + 1);
	//0 a
	*_dst = (DW & 0xfff);
	SIGNCH((*_dst), (1 << 11));
	_dst++;

	//1 b
	*_dst = ((DW >> 12) & 0xfff);
	SIGNCH((*_dst), (1 << 11));
	_dst++;

	DW = *(DWORD*)(_src + 4);
	//2 c
	*_dst = (DW & 0xfff);
	SIGNCH((*_dst), (1 << 11));
	_dst++;

	//3 d
	*_dst = ((DW >> 12) & 0xfff);
	SIGNCH((*_dst), (1 << 11));

	return 12;
}

s32 unpack4_14(unsigned char * _src, long * _dst)
{
	//	8/14 : (E) xxxx'0111	aaaa'aaaa aaaa'aabb	bbbb'bbbb | bbbb'cccc cccc'cccc | ccdd'dddd dddd'dddd

	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 14);
	UNPACKPTN(S, 14);

	S = GETSRCS(_src + 4, 4);
	UNPACKPTN(S, 14);
	UNPACKPTN_END(S, 14);

	return 14;
}

s32 unpack4_16(unsigned char * _src, long * _dst)
{
	//	9/16 : xxxx'1000 aaaa'aaaa aaaa'aaaa	bbbb'bbbb | bbbb'bbbb cccc'cccc | cccc'cccc dddd'dddd | dddd'dddd
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

s32 unpack4_18(unsigned char * _src, long * _dst)
{
	// 10/18 : (9) xxxx'1001 aaaa'aaaa aaaa'aaaa aabb'bbbb | bbbb'bbbb bbbb'cccc cccc'cccc cccc'ccdd | dddd'dddd dddd'dddd
	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 18);

	S = GETSRCS(_src + 3, 2);
	UNPACKPTN(S, 18);

	S = GETSRCS(_src + 5, 4);
	UNPACKPTN(S, 18);

	S = GETSRCS(_src + 7, 6);
	UNPACKPTN_END(S, 18);
	return 18;
}

s32 unpack4_20(unsigned char * _src, long * _dst)
{
	// 11/20 : (5) xxxx'1010	aaaa'aaaa aaaa'aaaa	aaaa'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'dddd dddd'dddd dddd'dddd
	DWORD DW = *(DWORD*)(_src + 1);
	//0 a
	*_dst = (DW & 0xfffff);
	SIGNCH((*_dst), (1 << 19));
	_dst++;

	DW = *(DWORD*)(_src + 3);
	//1 b
	*_dst = ((DW >> 4) & 0xfffff);
	SIGNCH((*_dst), (1 << 19));
	_dst++;

	DW = *(DWORD*)(_src + 6);
	//2 c
	*_dst = (DW & 0xfffff);
	SIGNCH((*_dst), (1 << 19));
	_dst++;

	DW = *(DWORD*)(_src + 8);
	//3 d
	*_dst = ((DW >> 4) & 0xfffff);
	SIGNCH((*_dst), (1 << 19));
	
	return 20;
}

s32 unpack4_22(unsigned char * _src, long * _dst)
{
	// 12/22 : (D) xxxx'1011	aaaa'aaaa aaaa'aaaa	aaaa'aabb bbbb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'cccc ccdd'dddd dddd'dddd dddd'dddd

	//a
	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 22);

	//b
	S = GETSRCS(_src + 3, 6);
	UNPACKPTN(S, 22);

	//c
	S = GETSRCS(_src + 6, 4);
	UNPACKPTN(S, 22);

	//d
	S = GETSRCS(_src + 9, 2);
	UNPACKPTN_END(S, 22);

	return 22;
}

s32 unpack4_24(unsigned char * _src, long * _dst)
{
	// 13/24 : (3) xxxx'1100	aaaa'aaaa aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'cccc dddd'dddd dddd'dddd dddd'dddd
	DWORD DW = *(DWORD*)(_src + 1);

	//0 a
	*_dst = (DW & 0xFFFFFF);
	SIGNCH((*_dst), (1 << 23));
	_dst++;

	DW = *(DWORD*)(_src + 4);

	//1 b
	*_dst = (DW & 0xFFFFFF);
	SIGNCH((*_dst), (1 << 23));
	_dst++;

	DW = *(DWORD*)(_src + 7);

	//2 c
	*_dst = (DW & 0xFFFFFF);
	SIGNCH((*_dst), (1 << 23));
	_dst++;

	DW = *(DWORD*)(_src + 10);

	//3 d
	*_dst = (DW & 0xFFFFFF);
	SIGNCH((*_dst), (1 << 23));
	_dst++;

	return 24;
}
