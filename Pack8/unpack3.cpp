#include "unpack3.h"
//-------------------------------------------------------- -
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
s32 unpack3_0(unsigned char * _src, long * _dst)
{
	//1 / 0   : (0) xxxx'0000	
	return 0;
}
s32 unpack3_3(unsigned char * _src, long * _dst)
{
	//2 / 3   : (1) xxxx'100a	aabb'bccc
	WORD S = GETSRCSW(_src, 7);
	UNPACKPTN(S, 3);
	UNPACKPTN(S, 3);
	UNPACKPTN_END(S, 3);
	return 3;
}
s32 unpack3_5(unsigned char * _src, long * _dst)
{
	//3 / 5   : (8) xxxx'0001	aaaa'abbb	bbcc'ccc- 
	DWORD S = GETSRC(_src+1);
	UNPACKPTN(S, 5);
	UNPACKPTN(S, 5);
	UNPACKPTN_END(S, 5);
	return 5;
}
s32 unpack3_8(unsigned char * _src, long * _dst)
{
	//4 / 8   : (4) xxxx'0010	aaaa'aaaa	bbbb'bbbb   cccc'cccc
	DWORD S = GETSRC(_src+1);
	UNPACKPTN(S, 8);
	UNPACKPTN(S, 8);
	UNPACKPTN_END(S, 8);
	return 8;
}
s32 unpack3_11(unsigned char * _src, long * _dst)
{
	//5 / 11  : (5) xxxx'101a	aaaa'aaaa	aabb'bbbb   bbbb'bccc | cccc'cccc
	DWORD S = GETSRCS(_src,7);
	UNPACKPTN(S, 11);
	UNPACKPTN(S, 11);
	S = GETSRCS(_src + 3, 5);
	UNPACKPTN_END(S, 11);
	return 11;
}
s32 unpack3_13(unsigned char * _src, long * _dst)
{
	//6 / 13  : (6) xxxx'0011	aaaa'aaaa   aaaa'abbb   bbbb'bbbb | bbcc'cccc	cccc'ccc-
	DWORD S = GETSRC(_src+1);
	UNPACKPTN(S, 13);
	S = GETSRCS(_src + 2, 5);
	UNPACKPTN(S, 13);
	UNPACKPTN_END(S, 13);
	return 13;

}
s32 unpack3_16(unsigned char * _src, long * _dst)
{
	//7 / 16  : (2) xxxx'0100	aaaa'aaaa	aaaa'aaaa	bbbb'bbbb bbbb'bbbb	cccc'cccc cccc'cccc
	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 16);
	S = GETSRC(_src + 3);
	UNPACKPTN(S, 16);
	UNPACKPTN_END(S, 16);
	return 16;
}
s32 unpack3_19(unsigned char * _src, long * _dst)
{
	//8 / 19  : (3) xxxx'110a	aaaa'aaaa	aaaa'aaaa	aabb'bbbb bbbb'bbbb bbbb'bccc cccc'cccc cccc'cccc	
	DWORD S = GETSRCS(_src,7);
	UNPACKPTN(S, 19);
	S = GETSRCS(_src + 3,2);
	UNPACKPTN(S, 19);
	S = GETSRCS(_src + 5, 5);
	UNPACKPTN_END(S, 19);
	return 19;

}
s32 unpack3_21(unsigned char * _src, long * _dst)
{
	//9 / 21  : (6) xxxx'0110	aaaa'aaaa	aaaa'aaaa	aaaa'abbb bbbb'bbbb bbbb'bbbb bbcc'cccc cccc'cccc cccc'ccc-
	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 21);
	S = GETSRCS(_src + 3, 5);
	UNPACKPTN(S, 21);
	S = GETSRCS(_src + 6, 2);
	UNPACKPTN_END(S, 21);
	return 21;
}
s32 unpack3_24(unsigned char * _src, long * _dst)
{
	//10/ 24  : (E) xxxx'0111	aaaa'aaaa	aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'cccc
	DWORD S = GETSRC(_src + 1);
	UNPACKPTN(S, 24);
	S = GETSRC(_src + 4);
	UNPACKPTN(S, 24);
	S = GETSRC(_src + 7);
	UNPACKPTN_END(S, 24);
	return 24;
}