#include "Unpack8.h"

s32 unpack8_0(unsigned char * _src, long * _dst)
{
	return 0;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_4(unsigned char * _src, long * _dst)
{
	// 4	байта : 0001'xxxx	aaaa'bbbb cccc'dddd eeee'ffff | hhhh'gggg					
	//CString sbin = ToBin(_src, 5);
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
	_dst++;

	//4 e
	*_dst = ((DW >> 16) & 0x0f);
	SIGNCH((*_dst), (1 << 3));
	_dst++;

	//5 f
	*_dst = ((DW >> 20) & 0x0f);
	SIGNCH((*_dst), (1 << 3));
	_dst++;

	//6 h
	*_dst = ((DW >> 24) & 0x0f);
	SIGNCH((*_dst), (1 << 3));
	_dst++;

	//7 g
	*_dst = ((DW >> 28) & 0x0f);
	SIGNCH((*_dst), (1 << 3));
	return 4;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_5(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 6);
	// 5	байт  : 0010'xxxx	aaaa'abbb bbcc'cccd dddd'eeee | efff'ffhh hhhg'gggg	
//  6 байт  /5  бит:xxxx'0010	aaaa'abbb bbcc'cccd dddd'eeee | efff'ffhh hhhg'gggg
	DWORD DW = *(DWORD*)(_src + 1);
	//0 a

	*_dst = (DW & 0x1f);
	SIGNCH((*_dst), (1 << 4));
	_dst++;

	//1 b
	*_dst = ((DW >> 5) & 0x1f);
	SIGNCH((*_dst), (1 << 4));
	_dst++;


	DW = *(DWORD*)(_src + 2);
	//2 c
	*_dst = ((DW >> 2) & 0x1f);
	SIGNCH((*_dst), (1 << 4));
	_dst++;

	//3 d
	*_dst = ((DW >> 7) & 0x1f);
	SIGNCH((*_dst), (1 << 4));
	_dst++;

	//4 e
	*_dst = ((DW >> 12) & 0x1f);
	SIGNCH((*_dst), (1 << 4));
	_dst++;

	//5 f
	*_dst = ((DW >> 17) & 0x1f);
	SIGNCH((*_dst), (1 << 4));
	_dst++;

	//6 h
	*_dst = ((DW >> 22) & 0x1f);
	SIGNCH((*_dst), (1 << 4));
	_dst++;

	//7 g
	*_dst = ((DW >> 27) & 0x1f);
	SIGNCH((*_dst), (1 << 4));
	return 5;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_6(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 7);
	// 6	байт  : 0011'xxxx	aaaa'aabb bbbb'cccc ccdd'dddd | eeee'eeff ffff'hhhh hhgg'gggg	
	DWORD DW = *(DWORD*)(_src + 1);
	//0 a
	*_dst = (DW & 0x3f);
	SIGNCH((*_dst), (1 << 5));
	_dst++;

	//1 b
	*_dst = ((DW >> 6) & 0x3f);
	SIGNCH((*_dst), (1 << 5));
	_dst++;

	//2 c
	*_dst = ((DW >> 12) & 0x3f);
	SIGNCH((*_dst), (1 << 5));
	_dst++;

	DW = *(DWORD*)(_src + 3);
	//3 d
	*_dst = ((DW >> 2) & 0x3f);
	SIGNCH((*_dst), (1 << 5));
	_dst++;

	//4 e
	*_dst = ((DW >> 8) & 0x3f);
	SIGNCH((*_dst), (1 << 5));
	_dst++;

	//5 f
	*_dst = ((DW >> 14) & 0x3f);
	SIGNCH((*_dst), (1 << 5));
	_dst++;

	//6 h
	*_dst = ((DW >> 20) & 0x3f);
	SIGNCH((*_dst), (1 << 5));
	_dst++;

	//7 g
	*_dst = ((DW >> 26) & 0x3f);
	SIGNCH((*_dst), (1 << 5));
	return 6;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_7(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 8);
	// 7	байт  : 0100'xxxx	aaaa'aaab bbbb'bbcc cccc'cddd | dddd'eeee eeef'ffff ffhh'hhhh hggg'gggg								
	DWORD DW = *(DWORD*)(_src + 1);
	//0 a
	*_dst = (DW & 0x7f);
	SIGNCH((*_dst), (1 << 6));
	_dst++;

	//1 b
	*_dst = ((DW >> 7) & 0x7f);
	SIGNCH((*_dst), (1 << 6));
	_dst++;

	//2 c
	*_dst = ((DW >> 14) & 0x7f);
	SIGNCH((*_dst), (1 << 6));
	_dst++;

	//3 d
	*_dst = ((DW >> 21) & 0x7f);
	SIGNCH((*_dst), (1 << 6));
	_dst++;

	DW = *(DWORD*)(_src + 4);
	//4 e
	*_dst = ((DW >> 4) & 0x7f);
	SIGNCH((*_dst), (1 << 6));
	_dst++;

	//5 f
	*_dst = ((DW >> 11) & 0x7f);
	SIGNCH((*_dst), (1 << 6));
	_dst++;

	//6 h
	*_dst = ((DW >> 18) & 0x7f);
	SIGNCH((*_dst), (1 << 6));
	_dst++;

	//7 g
	*_dst = ((DW >> 25) & 0x7f);
	SIGNCH((*_dst), (1 << 6));
	return 7;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_8(unsigned char * _src, long * _dst)
{

	//CString sbin = ToBin(_src, 9);

	// 8	байт  : 0101'xxxx	aaaa'aaaa bbbb'bbbb cccc'cccc | dddd'dddd eeee'eeee ffff'ffff hhhh'hhhh | gggg'gggg		
	//0 a
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
//------------------------------------------------------------------------------------------------------
s32 unpack8_9(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 10);
	// 9	байт  : 0110'xxxx	aaaa'aaaa abbb'bbbb bbcc'cccc | cccd'dddd dddd'eeee eeee'efff ffff'ffhh | hhhh'hhhg gggg'gggg					
	DWORD DW = *(DWORD*)(_src + 1);
	//0 a
	*_dst = (DW & 0x1ff);
	SIGNCH((*_dst), (1 << 8));
	_dst++;

	//1 b
	*_dst = ((DW >> 9) & 0x1ff);
	SIGNCH((*_dst), (1 << 8));
	_dst++;

	//2 c
	*_dst = ((DW >> 18) & 0x1ff);
	SIGNCH((*_dst), (1 << 8));
	_dst++;

	DW = *(DWORD*)(_src + 4);
	//3 d
	*_dst = ((DW >> 3) & 0x1ff);
	SIGNCH((*_dst), (1 << 8));
	_dst++;

	//4 e
	*_dst = ((DW >> 12) & 0x1ff);
	SIGNCH((*_dst), (1 << 8));
	_dst++;

	//5 f
	*_dst = ((DW >> 21) & 0x1ff);
	SIGNCH((*_dst), (1 << 8));
	_dst++;

	DW = *(DWORD*)(_src + 6);
	//6 h
	*_dst = ((DW >> 14) & 0x1ff);
	SIGNCH((*_dst), (1 << 8));
	_dst++;

	//7 g
	*_dst = ((DW >> 23) & 0x1ff);
	SIGNCH((*_dst), (1 << 8));
	return 9;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_10(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 11);
	// 10	байт  : 0111'xxxx	aaaa'aaaa aabb'bbbb bbbb'cccc | cccc'ccdd dddd'dddd eeee'eeee eeff'ffff | ffff'hhhh hhhh'hhgg gggg'gggg			
	DWORD DW = *(DWORD*)(_src + 1);
	//0 a
	*_dst = (DW & 0x3ff);
	SIGNCH((*_dst), (1 << 9));
	_dst++;

	//1 b
	*_dst = ((DW >> 10) & 0x3ff);
	SIGNCH((*_dst), (1 << 9));
	_dst++;

	//2 c
	*_dst = ((DW >> 20) & 0x3ff);
	SIGNCH((*_dst), (1 << 9));
	_dst++;

	DW = *(DWORD*)(_src + 4);
	//3 d
	*_dst = ((DW >> 6) & 0x3ff);
	SIGNCH((*_dst), (1 << 9));
	_dst++;

	//4 e
	*_dst = ((DW >> 16) & 0x3ff);
	SIGNCH((*_dst), (1 << 9));
	_dst++;

	DW = *(DWORD*)(_src + 7);
	//5 f
	*_dst = ((DW >> 2) & 0x3ff);
	SIGNCH((*_dst), (1 << 9));
	_dst++;

	DW = *(DWORD*)(_src + 8);
	//6 h
	*_dst = ((DW >> 4) & 0x3ff);
	SIGNCH((*_dst), (1 << 9));
	_dst++;

	//7 g
	*_dst = ((DW >> 14) & 0x3ff);
	SIGNCH((*_dst), (1 << 9));
	return 10;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_11(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 12);
	// 11	байт  : 1000'xxxx	aaaa'aaaa aaab'bbbb bbbb'bbcc | cccc'cccc cddd'dddd dddd'eeee eeee'eeef | ffff'ffff ffhh'hhhh hhhh'hggg gggg'gggg	|								
	DWORD DW = *(DWORD*)(_src + 1);

	//0 a
	*_dst = (DW & 0x7ff);
	SIGNCH((*_dst), (1 << 10));

	//a=((a)&(m))?((0xffffffff ^ (m-1))|a):(a)  



	_dst++;

	//1 b
	*_dst = ((DW >> 11) & 0x7ff);
	SIGNCH((*_dst), (1 << 10));
	_dst++;


	DW = *(DWORD*)(_src + 3);
	//2 c
	*_dst = ((DW >> 6) & 0x7ff);
	SIGNCH((*_dst), (1 << 10));
	_dst++;

	//3 d
	*_dst = ((DW >> 17) & 0x7ff);
	SIGNCH((*_dst), (1 << 10));
	_dst++;

	DW = *(DWORD*)(_src + 6);
	//4 e
	*_dst = ((DW >> 4) & 0x7ff);
	SIGNCH((*_dst), (1 << 10));
	_dst++;

	DW = *(DWORD*)(_src + 7);
	//5 f
	*_dst = ((DW >> 7) & 0x7ff);
	SIGNCH((*_dst), (1 << 10));
	_dst++;

	//6 h
	*_dst = ((DW >> 18) & 0x7ff);
	SIGNCH((*_dst), (1 << 10));
	_dst++;

	DW = *(DWORD*)(_src + 9);
	//7 g
	*_dst = ((DW >> 13) & 0x7ff);
	SIGNCH((*_dst), (1 << 10));
	return 11;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_12(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 13);
	// 12	байт  : 1001'xxxx	aaaa'aaaa aaaa'bbbb bbbb'bbbb | cccc'cccc cccc'dddd dddd'dddd eeee'eeee | eeee'ffff ffff'ffff hhhh'hhhh hhhh'gggg	| gggg'gggg			
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
	_dst++;

	DW = *(DWORD*)(_src + 7);
	//4 e
	*_dst = (DW & 0xfff);
	SIGNCH((*_dst), (1 << 11));
	_dst++;

	//5 f
	*_dst = ((DW >> 12) & 0xfff);
	SIGNCH((*_dst), (1 << 11));
	_dst++;

	DW = *(DWORD*)(_src + 9);
	//6 h
	*_dst = ((DW >> 8) & 0xfff);
	SIGNCH((*_dst), (1 << 11));
	_dst++;

	//7 g
	*_dst = ((DW >> 20) & 0xfff);
	SIGNCH((*_dst), (1 << 11));
	return 12;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_13(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 14);
	// 13	байт  : 1010'xxxx	aaaa'aaaa aaaa'abbb bbbb'bbbb | bbcc'cccc cccc'cccd dddd'dddd dddd'eeee | eeee'eeee efff'ffff ffff'ffhh hhhh'hhhh	| hhhg'gggg gggg'gggg					
	DWORD DW = *(DWORD*)(_src + 1);
	//0 a
	*_dst = (DW & 0x1fff);
	SIGNCH((*_dst), (1 << 12));
	_dst++;

	//1 b
	*_dst = ((DW >> 13) & 0x1fff);
	SIGNCH((*_dst), (1 << 12));
	_dst++;

	DW = *(DWORD*)(_src + 4);
	//2 c
	*_dst = ((DW >> 2) & 0x1fff);
	SIGNCH((*_dst), (1 << 12));
	_dst++;

	//3 d
	*_dst = ((DW >> 15) & 0x1fff);
	SIGNCH((*_dst), (1 << 12));
	_dst++;

	DW = *(DWORD*)(_src + 7);
	//4 e
	*_dst = ((DW >> 4) & 0x1fff);
	SIGNCH((*_dst), (1 << 12));
	_dst++;

	//5 f
	*_dst = ((DW >> 17) & 0x1fff);
	SIGNCH((*_dst), (1 << 12));
	_dst++;

	DW = *(DWORD*)(_src + 10);
	//6 h
	*_dst = ((DW >> 6) & 0x1fff);
	SIGNCH((*_dst), (1 << 12));
	_dst++;

	//7 g
	*_dst = ((DW >> 19) & 0x1fff);
	SIGNCH((*_dst), (1 << 12));
	return 13;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_14(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 15);
	// 14	байт  : 1011'xxxx	aaaa'aaaa aaaa'aabb bbbb'bbbb | bbbb'cccc cccc'cccc ccdd'dddd dddd'dddd | eeee'eeee eeee'eeff ffff'ffff ffff'hhhh | hhhh'hhhh hhgg'gggg gggg'gggg			
	DWORD DW = *(DWORD*)(_src + 1);
	//0 a
	*_dst = (DW & 0x3fff);
	SIGNCH((*_dst), (1 << 13));
	_dst++;

	//1 b
	*_dst = ((DW >> 14) & 0x3fff);
	SIGNCH((*_dst), (1 << 13));
	_dst++;

	DW = *(DWORD*)(_src + 4);
	//2 c
	*_dst = ((DW >> 4) & 0x3fff);
	SIGNCH((*_dst), (1 << 13));
	_dst++;

	//3 d
	*_dst = ((DW >> 18) & 0x3fff);
	SIGNCH((*_dst), (1 << 13));
	_dst++;

	DW = *(DWORD*)(_src + 8);
	//4 e
	*_dst = (DW & 0x3fff);
	SIGNCH((*_dst), (1 << 13));
	_dst++;

	//5 f
	*_dst = ((DW >> 14) & 0x3fff);
	SIGNCH((*_dst), (1 << 13));
	_dst++;

	DW = *(DWORD*)(_src + 11);
	//6 h
	*_dst = ((DW >> 4) & 0x3fff);
	SIGNCH((*_dst), (1 << 13));
	_dst++;

	//7 g
	*_dst = ((DW >> 18) & 0x3fff);
	SIGNCH((*_dst), (1 << 13));
	return 14;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_15(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 16);
	// 15	байт  : 1100'xxxx	aaaa'aaaa aaaa'aaab bbbb'bbbb | bbbb'bbcc cccc'cccc cccc'cddd dddd'dddd | dddd'eeee eeee'eeee eeef'ffff ffff'ffff | ffhh'hhhh hhhh'hhhh hggg'gggg gggg'gggg	|
	DWORD DW = *(DWORD*)(_src + 1);
	//0 a
	*_dst = (DW & 0x7fff);
	SIGNCH((*_dst), (1 << 14));
	_dst++;

	//1 b
	*_dst = ((DW >> 15) & 0x7fff);
	SIGNCH((*_dst), (1 << 14));
	_dst++;

	DW = *(DWORD*)(_src + 4);
	//2 c
	*_dst = ((DW >> 6) & 0x7fff);
	SIGNCH((*_dst), (1 << 14));
	_dst++;

	DW = *(DWORD*)(_src + 6);
	//3 d
	*_dst = ((DW >> 5) & 0x7fff);
	SIGNCH((*_dst), (1 << 14));
	_dst++;

	DW = *(DWORD*)(_src + 8);
	//4 e
	*_dst = ((DW >> 4) & 0x7fff);
	SIGNCH((*_dst), (1 << 14));
	_dst++;

	DW = *(DWORD*)(_src + 10);
	//5 f
	*_dst = ((DW >> 3) & 0x7fff);
	SIGNCH((*_dst), (1 << 14));
	_dst++;

	DW = *(DWORD*)(_src + 12);
	//6 h
	*_dst = ((DW >> 2) & 0x7fff);
	SIGNCH((*_dst), (1 << 14));
	_dst++;

	//7 g
	*_dst = ((DW >> 17) & 0x7fff);
	SIGNCH((*_dst), (1 << 14));
	return 15;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_16(unsigned char * _src, long * _dst)
{
	//CString sbin = ToBin(_src, 17);
	// 16	байт  : 1101'xxxx aaaa'aaaa aaaa'aaaa bbbb'bbbb | bbbb'bbbb cccc'cccc cccc'cccc dddd'dddd | dddd'dddd eeee'eeee eeee'eeee ffff'ffff | ffff'ffff hhhh'hhhh hhhh'hhhh gggg'gggg	| gggg'gggg							
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

	//4 e
	*_dst = (long)*pW;
	SIGNCH((*_dst), (1 << 15));
	_dst++;
	pW++;

	//5 f
	*_dst = (long)*pW;
	SIGNCH((*_dst), (1 << 15));
	_dst++;
	pW++;

	//6 h
	*_dst = (long)*pW;
	SIGNCH((*_dst), (1 << 15));
	_dst++;
	pW++;

	//7 g
	*_dst = (long)*pW;
	SIGNCH((*_dst), (1 << 15));
	return 16;
}
//------------------------------------------------------------------------------------------------------
s32 unpack8_20(unsigned char * _src, long * _dst)
{
	// 21	байт  : 
	// 1110'xxxx 
	// aaaa'aaaa aaaa'aaaa aaaa'bbbb | bbbb'bbbb bbbb'bbbb cccc'cccc | cccc'cccc cccc'dddd dddd'dddd |
	// dddd'dddd eeee'eeee eeee'eeee | eeee'ffff ffff'ffff ffff'ffff | hhhh'hhhh hhhh'hhhh hhhh'gggg |
	// gggg'gggg | gggg gggg

	//21 байт/20 бит: xxxx'1110	aaaa'aaaa aaaa'aaaa aaaa'bbbb | bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc | cccc'dddd dddd'dddd dddd'dddd eeee'eeee | eeee'eeee eeee'ffff ffff'ffff ffff'ffff | hhhh'hhhh hhhh'hhhh hhhh'gggg gggg'gggg	| gggg'gggg
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
	_dst++;

	DW = *(DWORD*)(_src + 11);
	//4 e
	*_dst = (DW & 0xfffff);
	SIGNCH((*_dst), (1 << 19));
	_dst++;

	DW = *(DWORD*)(_src + 13);
	//5 f
	*_dst = ((DW >> 4) & 0xfffff);
	SIGNCH((*_dst), (1 << 19));
	_dst++;

	DW = *(DWORD*)(_src + 16);
	//6 h
	*_dst = (DW & 0xfffff);
	SIGNCH((*_dst), (1 << 19));
	_dst++;

	DW = *(DWORD*)(_src + 18);
	//7 g
	*_dst = ((DW >> 4) & 0xfffff);
	SIGNCH((*_dst), (1 << 19));
	return 20;
}


s32 unpack8(unsigned char * _src, long * _dst)
{
	BYTE id = ((*_src>>4) & 0x0F);
	s32 ret;
	if (id < 0x0F)
	{
		//untype_pack_funcs * pUp = &unpack8Funcs[id];
		ret=unpack8Funcs[id](_src, _dst);
	}
	return ret;
}