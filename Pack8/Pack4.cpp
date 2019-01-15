#pragma once
#include "types.h"
#include "Pack.h"
//-------------------------------------------------------- -
//	Четырехканальная паковка - лучше не использовать
//	1/0  : xxxx'0000	
//	2/2  : xxxx'0001	aabb'сcdd
//	3/4  : xxxx'0010	aaaa'bbbb cccc'dddd
//	4/6  : xxxx'0011	aaaa'aabb bbbb'cccc ccdd'dddd
//	5/8  : xxxx'0100	aaaa'aaaa bbbb'bbbb cccc'cccc dddd'dddd
//	6/10 : xxxx'0101	aaaa'aaaa aabb'bbbb bbbb'cccc cccc'ccdd	dddd'dddd
//	7/12 : xxxx'0110	aaaa'aaaa aaaa'bbbb	bbbb'bbbb cccc'cccc	cccc'dddd dddd'dddd
//	8/14 : xxxx'0111	aaaa'aaaa aaaa'aabb	bbbb'bbbb bbbb'cccc cccc'cccc ccdd'dddd dddd'dddd
//	9/16 : xxxx'1000	aaaa'aaaa aaaa'aaaa	bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc dddd'dddd dddd'dddd
// 10/18 : xxxx'1001	aaaa'aaaa aaaa'aaaa	aabb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'ccdd dddd'dddd dddd'dddd
// 11/20 : xxxx'1010	aaaa'aaaa aaaa'aaaa	aaaa'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'dddd dddd'dddd dddd'dddd
// 12/22 : xxxx'1011	aaaa'aaaa aaaa'aaaa	aaaa'aabb bbbb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'cccc ccdd'dddd dddd'dddd dddd'dddd
// 13/24 : xxxx'1100	aaaa'aaaa aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'cccc dddd'dddd dddd'dddd dddd'dddd
////--------------------------------------------------------
#define RESTR __restrict 

u32 pack4_switch(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd) //TODO(romanm): поменять возвращаемое значение на знаковое во всей цепочке вызовов
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	switch (num_bits)
	{
	case 0:
		//1 байт/ 0 бит: xxxx'0000	
		*out_pkcd = mark_num | (0x0 << 4);
		return 1;
	case 1:
	case 2:
		//2 байта/ 2 бита: xxxx'0001 aabb'сcdd
		ch0 &= 0x3; ch1 &= 0x3; ch2 &= 0x3; ch3 &= 0x3;
		*out_pkcd = mark_num | (0b0001 << 4) | (ch0 << 8) | (ch1 << 10) | (ch2 << 12) | (ch3 << 14);
		return 2;
	case 3:
		//3 байта/ 4 бита: xxxx'0010 aaaa'bbbb cccc'dddd
		ch0 &= 0xF; ch1 &= 0xF; ch2 &= 0xF; ch3 &= 0xF;
		*out_pkcd = mark_num | (0b0010 << 4) | (ch0 << 8) | (ch1 << 12) | (ch2 << 16) | (ch3 << 20);
		return 3;
	case 4:
	case 5:
	case 6:
		//4 байта/ 6 бита: xxxx'0011 aaaa'aabb bbbb'cccc ccdd'dddd
		ch0 &= 0x3F; ch1 &= 0x3F; ch2 &= 0x3F; ch3 &= 0x3F;
		*out_pkcd = mark_num | (0b0011 << 4) | (ch0 << 8) | (ch1 << 14) | (ch2 << 20) | (ch3 << 26);
		return 4;
	case 7:
	case 8:
		//5 байт / 8 бит: xxxx'0100 aaaa'aaaa bbbb'bbbb cccc'cccc dddd'dddd
		ch0 &= 0xFF; ch1 &= 0xFF; ch2 &= 0xFF;  ch3 &= 0xFF;
		*out_pkcd = mark_num | (0b0100 << 4) | (ch0 << 8) | (ch1 << 16) | (ch2 << 24) | (ch3 << 30);;
		return 5;
	case 9:
	case 10:
		//6 байт / 10 бит: xxxx'0101 aaaa'aaaa aabb'bbbb bbbb'cccc cccc'ccdd dddd'dddd
		ch0 &= 0x3FF; ch1 &= 0x3FF; ch2 &= 0x3FF; ch3 &= 0x3FF;
		*out_pkcd++ = mark_num | (0b0101 << 4) | (ch0 << 8) | (ch1 << 18) | (ch2 << 26);
		*out_pkcd = (ch2 >> 6) | (ch3 << 4);
		return 6;
	case 11:
	case 12:
		//7 байт / 12 бит: xxxx'0110 aaaa'aaaa	aaaa'bbbb bbbb'bbbb	cccc'cccc cccc'dddd dddd'dddd
		ch0 &= 0xFFF; ch1 &= 0xFFF; ch2 &= 0xFFF; ch3 &= 0xFFF;
		*out_pkcd++ = mark_num | (0b0110 << 4) | (ch0 << 8) | (ch1 << 20);
		*out_pkcd = (ch2) | (ch3 << 12);
		return 7;
	case 13:
	case 14:
		//8 байт / 14 бит: xxxx'0111 aaaa'aaaa	aaaa'aabb bbbb'bbbb bbbb'cccc cccc'cccc ccdd'dddd dddd'dddd
		ch0 &= 0x3FFF; ch1 &= 0x3FFF; ch2 &= 0x3FFF; ch3 &= 0x3FFF;
		*out_pkcd++ = mark_num | (0b0111 << 4) | (ch0 << 8) | (ch1 << 22);
		*out_pkcd = (ch1 >> 10) | (ch2 << 4) | (ch3 << 18);
		return 8;
	case 15:
	case 16:
		//9 байт / 16 бит: xxxx'1000 aaaa'aaaa aaaa'aaaa bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc dddd'dddd dddd'dddd
		ch0 &= 0xFFFF; ch1 &= 0xFFFF; ch2 &= 0xFFFF; ch3 &= 0xFFFF;
		*out_pkcd++ = mark_num | (0b1000 << 4) | (ch0 << 8) | (ch1 << 24);
		*out_pkcd++ = (ch1 >> 8) | (ch2 << 8) | (ch3 << 24);
		*out_pkcd = (ch3 >> 8);
		return 9;
	case 17:
	case 18:
		//10 байт / 18 бит: xxxx'1001 aaaa'aaaa	aaaa'aaaa aabb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'ccdd dddd'dddd dddd'dddd
		ch0 &= 0x3FFFF; ch1 &= 0x3FFFF; ch2 &= 0x3FFFF; ch3 &= 0x3FFFF;
		*out_pkcd++ = mark_num | (0b1001 << 4) | (ch0 << 8) | (ch1 << 26);
		*out_pkcd++ = (ch1 >> 6) | (ch2 << 12) | (ch3 << 30);
		*out_pkcd = (ch3 >> 2);
		return 10;
	case 19:
	case 20:
		//11 байт / 20 бит: xxxx'1010 aaaa'aaaa	aaaa'aaaa aaaa'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'dddd dddd'dddd dddd'dddd
		ch0 &= 0xFFFFF; ch1 &= 0xFFFFF; ch2 &= 0xFFFFF; ch3 &= 0xFFFFF;
		*out_pkcd++ = mark_num | (0b1010 << 4) | (ch0 << 8) | (ch1 << 28);
		*out_pkcd++ = (ch1 >> 4) | (ch2 << 16);
		*out_pkcd = (ch2 >> 16) | (ch3 << 4);
		return 11;
	case 21:
	case 22:
		//12 байт / 22 бит: xxxx'1011 aaaa'aaaa	aaaa'aaaa aaaa'aabb bbbb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'cccc ccdd'dddd dddd'dddd dddd'dddd
		ch0 &= 0x3FFFFF; ch1 &= 0x3FFFFF; ch2 &= 0x3FFFFF; ch3 &= 0x3FFFFF;
		*out_pkcd++ = mark_num | (0b1011 << 4) | (ch0 << 8) | (ch1 << 30);
		*out_pkcd++ = (ch1 >> 2) | (ch2 << 20);
		*out_pkcd = (ch2 >> 12) | (ch3 << 8);
		return 12;
	default:
		//13 байт/24 бит: xxxx'1100	aaaa'aaaa aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'cccc dddd'dddd dddd'dddd dddd'dddd	
		ch0 &= 0xFFFFFF; ch1 &= 0xFFFFFF;
		*out_pkcd++ = mark_num | (0b1100 << 4) | (ch0 << 8);
		*out_pkcd++ = (ch1) | (ch2 << 24);
		*out_pkcd++ = (ch2 >> 8) | (ch3 << 16);
		*out_pkcd = (ch3 >> 16);
		return 13;
	}

}
//------------------------------------------------------------------------------------------------------
s32 pack4_0(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 mark_num = mark;
	mark_num &= 0xF;
	//1 байт/ 0 бит: 0000'xxxx	
	*out_pkcd = mark_num | (0x0 << 4);
	return 1;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_2(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//2 байта/ 2 бита: xxxx'0001 aabb'сcdd
	ch0 &= 0x3; ch1 &= 0x3; ch2 &= 0x3; ch3 &= 0x3;
	*out_pkcd = mark_num | (0b1000 << 4) | (ch0 << 8) | (ch1 << 10) | (ch2 << 12) | (ch3 << 14);
	return 2;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_3(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//3 байта/ 4 бита: xxxx'0010 aaaa'bbbb cccc'dddd
	ch0 &= 0xF; ch1 &= 0xF; ch2 &= 0xF; ch3 &= 0xF;
	*out_pkcd = mark_num | (0b0100 << 4) | (ch0 << 8) | (ch1 << 12) | (ch2 << 16) | (ch3 << 20);
	return 3;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_6(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//4 байта/ 6 бита: xxxx'0011 aaaa'aabb bbbb'cccc ccdd'dddd
	ch0 &= 0x3F; ch1 &= 0x3F; ch2 &= 0x3F; ch3 &= 0x3F;
	*out_pkcd = mark_num | (0b1100 << 4) | (ch0 << 8) | (ch1 << 14) | (ch2 << 20) | (ch3 << 26);
	return 4;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_8(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//5 байт / 8 бит: xxxx'0100 aaaa'aaaa bbbb'bbbb cccc'cccc dddd'dddd
	ch0 &= 0xFF; ch1 &= 0xFF; ch2 &= 0xFF;  ch3 &= 0xFF;
	*out_pkcd = mark_num | (0b0010 << 4) | (ch0 << 8) | (ch1 << 16) | (ch2 << 24) | (ch3 << 30);;
	return 5;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_10(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//6 байт / 10 бит: xxxx'0101 aaaa'aaaa aabb'bbbb bbbb'cccc cccc'ccdd dddd'dddd
	ch0 &= 0x3FF; ch1 &= 0x3FF; ch2 &= 0x3FF; ch3 &= 0x3FF;
	*out_pkcd++ = mark_num | (0b1010 << 4) | (ch0 << 8) | (ch1 << 18) | (ch2 << 26);
	*out_pkcd = (ch2 >> 6) | (ch3 << 4);
	return 6;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_12(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//7 байт / 12 бит: xxxx'0110 aaaa'aaaa	aaaa'bbbb bbbb'bbbb	cccc'cccc cccc'dddd dddd'dddd
	ch0 &= 0xFFF; ch1 &= 0xFFF; ch2 &= 0xFFF; ch3 &= 0xFFF;
	*out_pkcd++ = mark_num | (0b0110 << 4) | (ch0 << 8) | (ch1 << 20);
	*out_pkcd = (ch2) | (ch3 << 12);
	return 7;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_14(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//8 байт / 14 бит: xxxx'0111 aaaa'aaaa	aaaa'aabb bbbb'bbbb bbbb'cccc cccc'cccc ccdd'dddd dddd'dddd
	ch0 &= 0x3FFF; ch1 &= 0x3FFF; ch2 &= 0x3FFF; ch3 &= 0x3FFF;
	*out_pkcd++ = mark_num | (0b1110 << 4) | (ch0 << 8) | (ch1 << 22);
	*out_pkcd = (ch1 >> 10) | (ch2 << 4) | (ch3 << 18);
	return 8;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_16(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//9 байт / 16 бит: xxxx'1000 aaaa'aaaa aaaa'aaaa bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc dddd'dddd dddd'dddd
	ch0 &= 0xFFFF; ch1 &= 0xFFFF; ch2 &= 0xFFFF; ch3 &= 0xFFFF;
	*out_pkcd++ = mark_num | (0b0001 << 4) | (ch0 << 8) | (ch1 << 24);
	*out_pkcd++ = (ch1 >> 8) | (ch2 << 8) | (ch3 << 24);
	*out_pkcd = (ch3 >> 8);
	return 9;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_18(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//10 байт / 18 бит: xxxx'1001 aaaa'aaaa	aaaa'aaaa aabb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'ccdd dddd'dddd dddd'dddd
	ch0 &= 0x3FFFF; ch1 &= 0x3FFFF; ch2 &= 0x3FFFF; ch3 &= 0x3FFFF;
	*out_pkcd++ = mark_num | (0b1001 << 4) | (ch0 << 8) | (ch1 << 26);
	*out_pkcd++ = (ch1 >> 6) | (ch2 << 12) | (ch3 << 30);
	*out_pkcd = (ch3 >> 2);
	return 10;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_20(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//11 байт / 20 бит: xxxx'1010 aaaa'aaaa	aaaa'aaaa aaaa'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'dddd dddd'dddd dddd'dddd
	ch0 &= 0xFFFFF; ch1 &= 0xFFFFF; ch2 &= 0xFFFFF; ch3 &= 0xFFFFF;
	*out_pkcd++ = mark_num | (0b0101 << 4) | (ch0 << 8) | (ch1 << 28);
	*out_pkcd++ = (ch1 >> 4) | (ch2 << 16);
	*out_pkcd = (ch2 >> 16) | (ch3 << 4);
	return 11;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_22(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//12 байт / 22 бит: xxxx'1011 aaaa'aaaa	aaaa'aaaa aaaa'aabb bbbb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'cccc ccdd'dddd dddd'dddd dddd'dddd
	ch0 &= 0x3FFFFF; ch1 &= 0x3FFFFF; ch2 &= 0x3FFFFF; ch3 &= 0x3FFFFF;
	*out_pkcd++ = mark_num | (0b1101 << 4) | (ch0 << 8) | (ch1 << 30);
	*out_pkcd++ = (ch1 >> 2) | (ch2 << 20);
	*out_pkcd = (ch2 >> 12) | (ch3 << 8);
	return 12;
}
//------------------------------------------------------------------------------------------------------
s32 pack4_24(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//13 байт/24 бит: xxxx'1100	aaaa'aaaa aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'cccc dddd'dddd dddd'dddd dddd'dddd	
	ch0 &= 0xFFFFFF; ch1 &= 0xFFFFFF;
	*out_pkcd++ = mark_num | (0b0011 << 4) | (ch0 << 8);
	*out_pkcd++ = (ch1) | (ch2 << 24);
	*out_pkcd++ = (ch2 >> 8) | (ch3 << 16);
	*out_pkcd = (ch3 >> 16);
	return 13;
}
//------------------------------------------------------------------------------------------------------
