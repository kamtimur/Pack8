#include "unpack1.h"
//--------------------------------------------------------
//Одноканальная паковка
//1 / 2	 : (0) xxxx'00aa																																												
//2 / 10 : (2) xxxx'01aa	aaaa'aaaa
//3 / 18 : (1) xxxx'10aa	aaaa'aaaa aaaa'aaaa
//4 / 24 : (3) xxxx'11--	aaaa'aaaa aaaa'aaaa aaaa'aaaa
//--------------------------------------------------------
s32 unpack1_2(unsigned char * _src, long * _dst)
{
	//1 / 2	 : (0) xxxx'00aa	
	DWORD S = GETSRCS(_src, 6);
	UNPACKPTN_END(S, 2);
	return 2;
}

s32 unpack1_10(unsigned char * _src, long * _dst)
{
	//2 / 10 : (2) xxxx'01aa	aaaa'aaaa
	DWORD S = GETSRCS(_src, 6);
	UNPACKPTN_END(S, 10);
	return 10;
}

s32 unpack1_18(unsigned char * _src, long * _dst)
{
	//3 / 18 : (1) xxxx'10aa	aaaa'aaaa aaaa'aaaa
	DWORD S = GETSRCS(_src, 6);
	UNPACKPTN_END(S, 18);
	return 18;
}

s32 unpack1_24(unsigned char * _src, long * _dst)
{
	//4 / 24 : (3) xxxx'11--	aaaa'aaaa aaaa'aaaa aaaa'aaaa
	DWORD S = GETSRC(_src+1);
	UNPACKPTN_END(S, 24);
	return 24;
}
