#include "unpack2.h"
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

s32 unpack2_0(unsigned char * _src, long * _dst)
{
	//1 / 0  : (0) xxxx'0000	
	return 0;
}

s32 unpack2_5(unsigned char * _src, long * _dst)
{
	//2 / 5  : (2) xxxx'01aa	aaab'bbbb
	DWORD S = GETSRCS(_src, 6);
	UNPACKPTN(S, 5);
	UNPACKPTN_END(S, 5);
	return 5;
}

s32 unpack2_9(unsigned char * _src, long * _dst)
{
	//3 / 9  : (1) xxxx'10aa	aaaa'aaab bbbb'bbbb
	DWORD S = GETSRCS(_src, 6);
	UNPACKPTN(S, 9);
	UNPACKPTN_END(S, 9);
	return 9;
}

s32 unpack2_11(unsigned char * _src, long * _dst)
{
	//4 / 11 : (3) xxxx'1100	aaaa'aaaa aaab'bbbb	bbbb'bbbb
	DWORD S = GETSRC(_src+1);
	UNPACKPTN(S, 11);
	UNPACKPTN_END(S, 11);
	return 11;
}

s32 unpack2_16(unsigned char * _src, long * _dst)
{
	//5 / 16 : (B) xxxx'1101	aaaa'aaaa aaaa'aaaa	bbbb'bbbb bbbb'bbbb
	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 16);
	S = GETSRC(_src + 3);
	UNPACKPTN_END(S, 16);
	return 16;
}

s32 unpack2_20(unsigned char * _src, long * _dst)
{
	//6 / 20 : (7) xxxx'1110	aaaa'aaaa aaaa'aaaa	aaaa'bbbb bbbb'bbbb bbbb'bbbb
	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 20);
	S = GETSRCS(_src + 3,4);
	UNPACKPTN_END(S, 20);
	return 20;
}

s32 unpack2_24(unsigned char * _src, long * _dst)
{
	//7 / 24 : (F) xxxx'1111	aaaa'aaaa aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb
	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 24);
	S = GETSRC(_src + 4);
	UNPACKPTN_END(S, 24);
	return 24;
}
