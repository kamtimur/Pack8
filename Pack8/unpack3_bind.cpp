#include "unpack3_bind.h"

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

s32 unpack3_2_bind(unsigned char * _src, long * _dst)
{
	//1 / 2  : (0) 00aa'bbcc
	WORD S = GETSRCSW(_src, 2);
	UNPACKPTN(S, 2);
	UNPACKPTN(S, 2);
	UNPACKPTN_END(S, 2);
	return 2;
}
s32 unpack3_4_bind(unsigned char * _src, long * _dst)
{
	//2 / 4  : (3) 1100'aaaa bbbb'cccc
	WORD S = GETSRCSW(_src, 4);
	UNPACKPTN(S, 4);
	UNPACKPTN(S, 4);
	UNPACKPTN_END(S, 4);
	return 4;
}
s32 unpack3_7_bind(unsigned char * _src, long * _dst)
{
	//3 / 7  : (5) 101a'aaaa aabb'bbbb bccc'cccc
	DWORD S = GETSRCS(_src,3);
	UNPACKPTN(S, 7);
	UNPACKPTN(S, 7);
	UNPACKPTN_END(S, 7);
	return 7;
}
s32 unpack3_10_bind(unsigned char * _src, long * _dst)
{
	//4 / 10 : (2) 01aa'aaaa aaaa'bbbb bbbb'bbcc cccc'cccc
	DWORD S = GETSRCS(_src, 2);
	UNPACKPTN(S, 10);
	UNPACKPTN(S, 10);
	UNPACKPTN_END(S, 10);
	return 10;
}
s32 unpack3_12_bind(unsigned char * _src, long * _dst)
{
	//5 / 12 : (B) 1101'aaaa aaaa'aaaa bbbb'bbbb bbbb'cccc cccc'cccc
	DWORD S = GETSRCS(_src, 4);
	UNPACKPTN(S, 12);
	UNPACKPTN(S, 12);
	S = GETSRCS(_src + 3, 4);
	UNPACKPTN_END(S, 12);
	return 12;
}
s32 unpack3_15_bind(unsigned char * _src, long * _dst)
{
	//6 / 15 : (1) 100a'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb bccc'cccc cccc'cccc
	DWORD S = GETSRCS(_src, 4);
	UNPACKPTN(S, 15);
	UNPACKPTN(S, 15);
	S = GETSRCS(_src + 4, 1);
	UNPACKPTN_END(S, 15);
	return 15;
}
s32 unpack3_17_bind(unsigned char * _src, long * _dst)
{
	//7 / 17 : (7) 1110'aaaa aaaa'aaaa aaaa'abbb bbbb'bbbb bbbb'bbcc cccc'cccc cccc'ccc-
	DWORD S = GETSRCS(_src, 4);
	UNPACKPTN(S, 17);
	UNPACKPTN(S, 17);
	S = GETSRCS(_src + 4, 6);
	UNPACKPTN_END(S, 17);
	return 17;
}
s32 unpack3_20_bind(unsigned char * _src, long * _dst)
{
	//8 / 20 : (F) 1111'aaaa aaaa'aaaa aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'cccc
	DWORD S = GETSRCS(_src, 4);
	UNPACKPTN(S, 20);
	UNPACKPTN(S, 20);
	S = GETSRCS(_src + 5, 4);
	UNPACKPTN_END(S, 20);
	return 20;
}