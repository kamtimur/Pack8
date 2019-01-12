#pragma once

#include "Pack8.h"

//-------------------------------------------------------- -
//1 / 0	  : (0) xxxx'0000	                              |											|										  |
//5 / 4   : (8) xxxx'0001	aaaa'bbbb cccc'dddd eeee'ffff | hhhh'gggg								|									      |											|										  |
//6 / 5   : (4) xxxx'0010	aaaa'abbb bbcc'cccd dddd'eeee | efff'ffhh hhhg'gggg						|										  |											|										  |
//7 / 6   : (C) xxxx'0011	aaaa'aabb bbbb'cccc ccdd'dddd | eeee'eeff ffff'hhhh hhgg'gggg			|					     				  |											|										  |
//8 / 7   : (2) xxxx'0100	aaaa'aaab bbbb'bbcc cccc'cddd | dddd'eeee eeef'ffff ffhh'hhhh hggg'gggg |										  |											|										  |
//9 / 8   : (A) xxxx'0101	aaaa'aaaa bbbb'bbbb cccc'cccc | dddd'dddd eeee'eeee ffff'ffff hhhh'hhhh | gggg'gggg								  |											|										  |
//10 / 9  : (6) xxxx'0110	aaaa'aaaa abbb'bbbb bbcc'cccc | cccd'dddd dddd'eeee eeee'efff ffff'ffhh | hhhh'hhhg gggg'gggg					  |											|										  |
//11 / 10 : (E) xxxx'0111	aaaa'aaaa aabb'bbbb bbbb'cccc | cccc'ccdd dddd'dddd eeee'eeee eeff'ffff | ffff'hhhh hhhh'hhgg gggg'gggg			  |											|										  |
//12 / 11 : (1) xxxx'1000	aaaa'aaaa aaab'bbbb bbbb'bbcc | cccc'cccc cddd'dddd dddd'eeee eeee'eeef | ffff'ffff ffhh'hhhh hhhh'hggg gggg'gggg |											|										  |
//13 / 12 : (9) xxxx'1001	aaaa'aaaa aaaa'bbbb bbbb'bbbb | cccc'cccc cccc'dddd dddd'dddd eeee'eeee | eeee'ffff ffff'ffff hhhh'hhhh hhhh'gggg | gggg'gggg								|										  |
//14 / 13 : (5) xxxx'1010	aaaa'aaaa aaaa'abbb bbbb'bbbb | bbcc'cccc cccc'cccd dddd'dddd dddd'eeee | eeee'eeee efff'ffff ffff'ffhh hhhh'hhhh | hhhg'gggg gggg'gggg						|										  |
//15 / 14 : (D) xxxx'1011	aaaa'aaaa aaaa'aabb bbbb'bbbb | bbbb'cccc cccc'cccc ccdd'dddd dddd'dddd | eeee'eeee eeee'eeff ffff'ffff ffff'hhhh | hhhh'hhhh hhgg'gggg gggg'gggg			|										  |
//16 / 15 : (3) xxxx'1100	aaaa'aaaa aaaa'aaab bbbb'bbbb | bbbb'bbcc cccc'cccc cccc'cddd dddd'dddd | dddd'eeee eeee'eeee eeef'ffff ffff'ffff | ffhh'hhhh hhhh'hhhh hggg'gggg gggg'gggg |										  |
//17 / 16 : (B) xxxx'1101   aaaa'aaaa aaaa'aaaa bbbb'bbbb | bbbb'bbbb cccc'cccc cccc'cccc dddd'dddd | dddd'dddd eeee'eeee eeee'eeee ffff'ffff | ffff'ffff hhhh'hhhh hhhh'hhhh gggg'gggg | gggg'gggg					 			  |
//21 / 20 : (7) xxxx'1110	aaaa'aaaa aaaa'aaaa aaaa'bbbb | bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc | cccc'dddd dddd'dddd dddd'dddd eeee'eeee | eeee'eeee eeee'ffff ffff'ffff ffff'ffff | hhhh'hhhh hhhh'hhhh hhhh'gggg gggg'gggg | gggg'gggg
////--------------------------------------------------------



u32 pack8_switch(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd) //TODO(romanm): поменять возвращаемое значение на знаковое во всей цепочке вызовов
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
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
	case 3:
	case 4:
		//  5 байт  /4  бита: 0001'xxxx	aaaa'bbbb cccc'dddd eeee'ffff | hhhh'gggg
		ch0 &= 0x0F; ch1 &= 0x0F;	ch2 &= 0x0F;	ch3 &= 0x0F; ch4 &= 0x0F;	ch5 &= 0x0F;	ch6 &= 0x0F;	ch7 &= 0x0F;
		*out_pkcd++ = mark_num | (0b1000<<4) | (ch0 << 8) | (ch1 << 12) | (ch2 << 16) | (ch3 << 20) | (ch4 << 24) | (ch5 << 28);
		*out_pkcd = ch6 | (ch7 << 4);
		return 2;
	case 5:
		//  6 байт  /5  бита: 0010'xxxx	aaaa'abbb bbcc'cccd dddd'eeee | efff'ffhh hhhg'gggg
		ch0 &= 0x1F; ch1 &= 0x1F;	ch2 &= 0x1F;	ch3 &= 0x1F; ch4 &= 0x1F;	ch5 &= 0x1F;	ch6 &= 0x1F;	ch7 &= 0x1F;
		*out_pkcd++ = mark_num | (0b0100) | (ch0 << 8) | (ch1 << 13) | (ch2 << 18) | (ch3 << 23) | (ch4 << 28);
		*out_pkcd = (ch5 >> 4) | (ch6 << 1) | (ch7 << 6);
		return 3;
	case 6:
		//  7 байт  /6  бита: 0011'xxxx	aaaa'aabb bbbb'cccc ccdd'dddd | eeee'eeff ffff'hhhh hhgg'gggg
		ch0 &= 0x3F; ch1 &= 0x3F;	ch2 &= 0x3F;	ch3 &= 0x3F; ch4 &= 0x3F;	ch5 &= 0x3F;	ch6 &= 0x3F;	ch7 &= 0x3F;
		*out_pkcd++ = mark_num | (0b1100) | (ch0 << 8) | (ch1 << 14) | (ch2 << 20) | (ch3 << 26);
		*out_pkcd = (ch4) | (ch5 << 6) | (ch6 << 12) | (ch7 << 18);
		return 4;
	case 7:
		//  8 байт  /7  бита: 0100'xxxx	aaaa'aaab bbbb'bbcc cccc'cddd | dddd'eeee eeef'ffff ffhh'hhhh hggg'gggg
		ch0 &= 0x7F; ch1 &= 0x7F;	ch2 &= 0x7F;	ch3 &= 0x7F; ch4 &= 0x7F;	ch5 &= 0x7F;	ch6 &= 0x7F;	ch7 &= 0x7F;
		*out_pkcd++ = mark_num | (0b0010) | (ch0 << 8) | (ch1 << 15) | (ch2 << 22) | (ch3 << 29);
		*out_pkcd = (ch3 >> 3) | (ch4 << 4) | (ch5 << 11) | (ch6 << 18) | (ch7 << 25);
		return 5;
	case 8:
		//  9 байт  /8  бита: 0101'xxxx	aaaa'aaaa bbbb'bbbb cccc'cccc | dddd'dddd eeee'eeee ffff'ffff hhhh'hhhh | gggg'gggg
		ch0 &= 0xFF; ch1 &= 0xFF;	ch2 &= 0xFF;	ch3 &= 0xFF; ch4 &= 0xFF;	ch5 &= 0xFF;	ch6 &= 0xFF;	ch7 &= 0xFF;
		*out_pkcd++ = mark_num | (0b1010) | (ch0 << 8) | (ch1 << 16) | (ch2 << 24) | (ch3 << 30);
		*out_pkcd++ = (ch3 >> 2) | (ch4 << 6) | (ch5 << 14) | (ch6 << 20) | (ch7 << 28);
		*out_pkcd = (ch7 >> 4);
		return 6;
	case 9:
		//  10 байт  /9  бита: 0110'xxxx aaaa'aaaa abbb'bbbb bbcc'cccc | cccd'dddd dddd'eeee eeee'efff ffff'ffhh | hhhh'hhhg gggg'gggg
		ch0 &= 0x1FF; ch1 &= 0x1FF;	ch2 &= 0x1FF;	ch3 &= 0x1FF; ch4 &= 0x1FF;	ch5 &= 0x1FF;	ch6 &= 0x1FF;	ch7 &= 0x1FF;
		*out_pkcd++ = mark_num | (0b0110) | (ch0 << 8) | (ch1 << 17) | (ch2 << 26);
		*out_pkcd++ = (ch2 >> 6) | (ch3 << 3) | (ch4 << 12) | (ch5 << 18) | (ch6 << 24) | (ch7 << 30);
		*out_pkcd = (ch7 >> 2);
		return 7;
	case 10:
		//  11 байт  /10  бита: 0111'xxxx	aaaa'aaaa aabb'bbbb bbbb'cccc | cccc'ccdd dddd'dddd eeee'eeee eeff'ffff | ffff'hhhh hhhh'hhgg gggg'gggg
		ch0 &= 0x3FF; ch1 &= 0x3FF;	ch2 &= 0x3FF;	ch3 &= 0x3FF; ch4 &= 0x3FF;	ch5 &= 0x3FF;	ch6 &= 0x3FF;	ch7 &= 0x3FF;
		*out_pkcd++ = mark_num | (0b1110) | (ch0 << 8) | (ch1 << 18) | (ch2 << 28);
		*out_pkcd++ = (ch2 >> 4) | (ch3 << 6) | (ch4 << 16) | (ch5 << 26);
		*out_pkcd = (ch5 >> 6) | (ch6 << 4) | (ch7 << 14);
		return 8;
	case 11:
		//  12 байт  /11  бита: 1000'xxxx	aaaa'aaaa aaab'bbbb bbbb'bbcc | cccc'cccc cddd'dddd dddd'eeee eeee'eeef | ffff'ffff ffhh'hhhh hhhh'hggg gggg'gggg
		ch0 &= 0x7FF; ch1 &= 0x7FF;	ch2 &= 0x7FF;	ch3 &= 0x7FF; ch4 &= 0x7FF;	ch5 &= 0x7FF;	ch6 &= 0x7FF;	ch7 &= 0x7FF;
		*out_pkcd++ = mark_num | (0b0001) | (ch0 << 8) | (ch1 << 19) | (ch2 << 30);
		*out_pkcd++ = (ch2 >> 2) | (ch3 << 9) | (ch4 << 20) | (ch5 << 31);
		*out_pkcd = (ch5 >> 1) | (ch6 << 10) | (ch7 << 21);
		return 9;
	case 12:
		//13 байт / 12 бит: xxxx'1001 aaaa'aaaa aaaa'bbbb bbbb'bbbb | cccc'cccc cccc'dddd dddd'dddd eeee'eeee | eeee'ffff ffff'ffff hhhh'hhhh hhhh'gggg | gggg'gggg
		ch0 &= 0xFFF; ch1 &= 0xFFF;	ch2 &= 0xFFF;	ch3 &= 0xFFF; ch4 &= 0xFFF;	ch5 &= 0xFFF;	ch6 &= 0xFFF;	ch7 &= 0xFFF;
		*out_pkcd++ = mark_num | (0b1001) | (ch0 << 8) | (ch1 << 20);
		*out_pkcd++ = (ch2) | (ch3 << 12) | (ch4 << 24);
		*out_pkcd++ = (ch4 >> 8) | (ch5 << 4) | (ch6 << 16) | (ch7 << 28);
		*out_pkcd = (ch7 >> 4);
		return 10;
	case 13:
		//14 байт / 13 бит: 1010'xxxx aaaa'aaaa aaaa'abbb bbbb'bbbb | bbcc'cccc cccc'cccd dddd'dddd dddd'eeee | eeee'eeee efff'ffff ffff'ffhh hhhh'hhhh | hhhg'gggg gggg'gggg
		ch0 &= 0x1FFF; ch1 &= 0x1FFF;	ch2 &= 0x1FFF;	ch3 &= 0x1FFF; ch4 &= 0x1FFF;	ch5 &= 0x1FFF;	ch6 &= 0x1FFF;	ch7 &= 0x1FFF;
		*out_pkcd++ = mark_num | (0b0101) | (ch0 << 8) | (ch1 << 21);
		*out_pkcd++ = (ch1 >> 11) | (ch2 << 2) | (ch3 << 15) | (ch4 << 28);
		*out_pkcd++ = (ch4 >> 4) | (ch5 << 9) | (ch6 << 22);
		*out_pkcd = (ch6 >> 10) | (ch7 << 3);
		return 11;
	case 14:
		//15 байт / 14 бит: 1011'xxxx aaaa'aaaa aaaa'aabb bbbb'bbbb | bbbb'cccc cccc'cccc ccdd'dddd dddd'dddd | eeee'eeee eeee'eeff ffff'ffff ffff'hhhh | hhhh'hhhh hhgg'gggg gggg'gggg
		ch0 &= 0x3FFF; ch1 &= 0x3FFF;	ch2 &= 0x3FFF;	ch3 &= 0x3FFF; ch4 &= 0x3FFF;	ch5 &= 0x3FFF;	ch6 &= 0x3FFF;	ch7 &= 0x3FFF;
		*out_pkcd++ = mark_num | (0b1101) | (ch0 << 8) | (ch1 << 22);
		*out_pkcd++ = (ch1 >> 10) | (ch2 << 4) | (ch3 << 18);
		*out_pkcd++ = (ch4) | (ch5 << 14) | (ch6 << 28);
		*out_pkcd = (ch6 >> 4) | (ch7 << 10);
		return 12;
	case 15:
		//16 байт / 15 бит: 1100'xxxx aaaa'aaaa aaaa'aaab bbbb'bbbb | bbbb'bbcc cccc'cccc cccc'cddd dddd'dddd | dddd'eeee eeee'eeee eeef'ffff ffff'ffff | ffhh'hhhh hhhh'hhhh hggg'gggg gggg'gggg
		ch0 &= 0x7FFF; ch1 &= 0x7FFF;	ch2 &= 0x7FFF;	ch3 &= 0x7FFF; ch4 &= 0x7FFF;	ch5 &= 0x7FFF;	ch6 &= 0x7FFF;	ch7 &= 0x7FFF;
		*out_pkcd++ = mark_num | (0b0011) | (ch0 << 8) | (ch1 << 23);
		*out_pkcd++ = (ch1 >> 9) | (ch2 << 6) | (ch3 << 21);
		*out_pkcd++ = (ch3 >> 11) | (ch4 << 4) | (ch5 << 19);
		*out_pkcd = (ch5 >> 13) | (ch6 << 2) | (ch7 << 17);
		return 13;
	case 16:
		//17 байт / 16 бит: 1101'xxxx  aaaa'aaaa aaaa'aaaa bbbb'bbbb | bbbb'bbbb cccc'cccc cccc'cccc dddd'dddd | dddd'dddd eeee'eeee eeee'eeee ffff'ffff | ffff'ffff hhhh'hhhh hhhh'hhhh gggg'gggg | gggg'gggg
		ch0 &= 0xFFFF; ch1 &= 0xFFFF;	ch2 &= 0xFFFF;	ch3 &= 0xFFFF; ch4 &= 0xFFFF;	ch5 &= 0xFFFF;	ch6 &= 0xFFFF;	ch7 &= 0xFFFF;
		*out_pkcd++ = mark_num | (0b1011) | (ch0 << 8) | (ch1 << 24);
		*out_pkcd++ = (ch1 >> 8) | (ch2 << 8) | (ch3 << 24);
		*out_pkcd++ = (ch3 >> 8) | (ch4 << 8) | (ch5 << 24);
		*out_pkcd++ = (ch5 >> 8) | (ch6 << 8) | (ch7 << 24);
		*out_pkcd = (ch7 >> 8);
		return 14;
	default:
		//21 байт/20 бит: 1110'xxxx	aaaa'aaaa aaaa'aaaa aaaa'bbbb | bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc | cccc'dddd dddd'dddd dddd'dddd eeee'eeee | eeee'eeee eeee'ffff ffff'ffff ffff'ffff | hhhh'hhhh hhhh'hhhh hhhh'gggg gggg'gggg	| gggg'gggg
		ch0 &= 0xFFFFF; ch1 &= 0xFFFFF;	ch2 &= 0xFFFFF;	ch3 &= 0xFFFFF; ch4 &= 0xFFFFF;	ch5 &= 0xFFFFF;	ch6 &= 0xFFFFF;	ch7 &= 0xFFFFF;
		*out_pkcd++ = mark_num | (0b0111) | (ch0 << 8) | (ch1 << 28);
		*out_pkcd++ = (ch1 >> 4) | (ch2 << 16);
		*out_pkcd++ = (ch2 >> 16) | (ch3 << 4) | (ch4 << 24);
		*out_pkcd++ = (ch4 >> 8) | (ch5 << 12);
		*out_pkcd++ = (ch6) | (ch7 << 20);
		*out_pkcd = (ch7 >> 12);
		return 15;
	}

}
//------------------------------------------------------------------------------------------------------
s32 pack8_0(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd) 
{
	u32 mark_num = mark;
	mark_num &= 0xF;
	//1 байт/ 0 бит: 0000'xxxx	
	*out_pkcd = mark_num | (0x0 << 4);
	return 1;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_4(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//  5 байт  /4  бита: xxxx'0001	aaaa'bbbb cccc'dddd eeee'ffff | hhhh'gggg
	ch0 &= 0x0F; ch1 &= 0x0F;	ch2 &= 0x0F;	ch3 &= 0x0F; ch4 &= 0x0F;	ch5 &= 0x0F;	ch6 &= 0x0F;	ch7 &= 0x0F;
	*out_pkcd++ = mark_num | (0b1000 << 4) | (ch0 << 8) | (ch1 << 12) | (ch2 << 16) | (ch3 << 20) | (ch4 << 24) | (ch5 << 28);
	*out_pkcd = ch6 | (ch7 << 4);
	return 2;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_5(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//  6 байт  /5  бит: xxxx'0010	aaaa'abbb bbcc'cccd dddd'eeee | efff'ffhh hhhg'gggg
	ch0 &= 0x1F; ch1 &= 0x1F;	ch2 &= 0x1F;	ch3 &= 0x1F; ch4 &= 0x1F;	ch5 &= 0x1F;	ch6 &= 0x1F;	ch7 &= 0x1F;
	*out_pkcd++ = mark_num | (0b0100<<4) | (ch0 << 8) | (ch1 << 13) | (ch2 << 18) | (ch3 << 23) | (ch4 << 28);
	*out_pkcd = (ch4 >> 4) | (ch5 << 1)	| (ch6 << 6) | (ch7 << 11);
	return 3;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_6(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//  7 байт  /6  бита: xxxx'0011	aaaa'aabb bbbb'cccc ccdd'dddd | eeee'eeff ffff'hhhh hhgg'gggg
	ch0 &= 0x3F; ch1 &= 0x3F;	ch2 &= 0x3F;	ch3 &= 0x3F; ch4 &= 0x3F;	ch5 &= 0x3F;	ch6 &= 0x3F;	ch7 &= 0x3F;
	*out_pkcd++ = mark_num | (0b1100<<4) | (ch0 << 8) | (ch1 << 14) | (ch2 << 20) | (ch3 << 26);
	*out_pkcd = (ch4) | (ch5 << 6) | (ch6 << 12) | (ch7 << 18);
	return 4;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_7(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//  8 байт  /7  бита: xxxx'0100	aaaa'aaab bbbb'bbcc cccc'cddd | dddd'eeee eeef'ffff ffhh'hhhh hggg'gggg
	ch0 &= 0x7F; ch1 &= 0x7F;	ch2 &= 0x7F;	ch3 &= 0x7F; ch4 &= 0x7F;	ch5 &= 0x7F;	ch6 &= 0x7F;	ch7 &= 0x7F;
	*out_pkcd++ = mark_num | (0b0010<<4) | (ch0 << 8) | (ch1 << 15) | (ch2 << 22) | (ch3 << 29);
	*out_pkcd = (ch3 >> 3) | (ch4 << 4) | (ch5 << 11) | (ch6 << 18) | (ch7 << 25);
	return 5;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_8(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//  9 байт  /8  бита: xxxx'0101	aaaa'aaaa bbbb'bbbb cccc'cccc | dddd'dddd eeee'eeee ffff'ffff hhhh'hhhh | gggg'gggg
	ch0 &= 0xFF; ch1 &= 0xFF;	ch2 &= 0xFF;	ch3 &= 0xFF; ch4 &= 0xFF;	ch5 &= 0xFF;	ch6 &= 0xFF;	ch7 &= 0xFF;
	*out_pkcd++ = mark_num | (0b1010<<4) | (ch0 << 8) | (ch1 << 16) | (ch2 << 24);
	*out_pkcd++ = (ch3) | (ch4 << 8) | (ch5 << 16) | (ch6 << 24);
	*out_pkcd	= (ch7);
	return 6;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_9(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//  10 байт  /9  бита: xxxx'0110 aaaa'aaaa abbb'bbbb bbcc'cccc | cccd'dddd dddd'eeee eeee'efff ffff'ffhh | hhhh'hhhg gggg'gggg
	ch0 &= 0x1FF; ch1 &= 0x1FF;	ch2 &= 0x1FF;	ch3 &= 0x1FF; ch4 &= 0x1FF;	ch5 &= 0x1FF;	ch6 &= 0x1FF;	ch7 &= 0x1FF;
	*out_pkcd++ = mark_num | (0b0110<<4) | (ch0 << 8) | (ch1 << 17) | (ch2 << 26);
	*out_pkcd++ = (ch2 >> 6) | (ch3 << 3) | (ch4 << 12) | (ch5 << 21) | (ch6 << 30) ;
	*out_pkcd = (ch6 >> 2) | (ch7 << 7);
	return 7;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_10(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//  11 байт  /10  бита: xxxx'0111	aaaa'aaaa aabb'bbbb bbbb'cccc | cccc'ccdd dddd'dddd eeee'eeee eeff'ffff | ffff'hhhh hhhh'hhgg gggg'gggg
	ch0 &= 0x3FF; ch1 &= 0x3FF;	ch2 &= 0x3FF;	ch3 &= 0x3FF; ch4 &= 0x3FF;	ch5 &= 0x3FF;	ch6 &= 0x3FF;	ch7 &= 0x3FF;
	*out_pkcd++ = mark_num | (0b1110<<4) | (ch0 << 8) | (ch1 << 18) | (ch2 << 28);
	*out_pkcd++ = (ch2 >> 4) | (ch3 << 6) | (ch4 << 16) | (ch5 << 26);
	*out_pkcd = (ch5 >> 6) | (ch6 << 4) | (ch7 << 14);
	return 8;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_11(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//  12 байт  /11  бита: xxxx'1000	aaaa'aaaa aaab'bbbb bbbb'bbcc | cccc'cccc cddd'dddd dddd'eeee eeee'eeef | ffff'ffff ffhh'hhhh hhhh'hggg gggg'gggg
	ch0 &= 0x7FF; ch1 &= 0x7FF;	ch2 &= 0x7FF;	ch3 &= 0x7FF; ch4 &= 0x7FF;	ch5 &= 0x7FF;	ch6 &= 0x7FF;	ch7 &= 0x7FF;
	*out_pkcd++ = mark_num | (0b0001<<4) | (ch0 << 8) | (ch1 << 19) | (ch2 << 30);
	*out_pkcd++ = (ch2 >> 2) | (ch3 << 9) | (ch4 << 20) | (ch5 << 31);
	*out_pkcd = (ch5 >> 1) | (ch6 << 10) | (ch7 << 21);
	return 9;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_12(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//13 байт / 12 бит: xxxx'1001 aaaa'aaaa aaaa'bbbb bbbb'bbbb | cccc'cccc cccc'dddd dddd'dddd eeee'eeee | eeee'ffff ffff'ffff hhhh'hhhh hhhh'gggg | gggg'gggg
	ch0 &= 0xFFF; ch1 &= 0xFFF;	ch2 &= 0xFFF;	ch3 &= 0xFFF; ch4 &= 0xFFF;	ch5 &= 0xFFF;	ch6 &= 0xFFF;	ch7 &= 0xFFF;
	*out_pkcd++ = mark_num | (0b1001<<4) | (ch0 << 8) | (ch1 << 20);
	*out_pkcd++ = (ch2) | (ch3 << 12) | (ch4 << 24);
	*out_pkcd++ = (ch4 >> 8) | (ch5 << 4) | (ch6 << 16) | (ch7 << 28);
	*out_pkcd = (ch7 >> 4);
	return 10;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_13(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//14 байт / 13 бит: xxxx'1010 aaaa'aaaa aaaa'abbb bbbb'bbbb | bbcc'cccc cccc'cccd dddd'dddd dddd'eeee | eeee'eeee efff'ffff ffff'ffhh hhhh'hhhh | hhhg'gggg gggg'gggg
	ch0 &= 0x1FFF; ch1 &= 0x1FFF;	ch2 &= 0x1FFF;	ch3 &= 0x1FFF; ch4 &= 0x1FFF;	ch5 &= 0x1FFF;	ch6 &= 0x1FFF;	ch7 &= 0x1FFF;
	*out_pkcd++ = mark_num | (0b0101<<4) | (ch0 << 8) | (ch1 << 21);
	*out_pkcd++ = (ch1 >> 11) | (ch2 << 2) | (ch3 << 15) | (ch4 << 28);
	*out_pkcd++ = (ch4 >> 4) | (ch5 << 9) | (ch6 << 22);
	*out_pkcd = (ch6 >> 10) | (ch7 << 3);
	return 11;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_14(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//15 байт / 14 бит: xxxx'1011 aaaa'aaaa aaaa'aabb bbbb'bbbb | bbbb'cccc cccc'cccc ccdd'dddd dddd'dddd | eeee'eeee eeee'eeff ffff'ffff ffff'hhhh | hhhh'hhhh hhgg'gggg gggg'gggg
	ch0 &= 0x3FFF; ch1 &= 0x3FFF;	ch2 &= 0x3FFF;	ch3 &= 0x3FFF; ch4 &= 0x3FFF;	ch5 &= 0x3FFF;	ch6 &= 0x3FFF;	ch7 &= 0x3FFF;
	*out_pkcd++ = mark_num | (0b1101<<4) | (ch0 << 8) | (ch1 << 22);
	*out_pkcd++ = (ch1 >> 10) | (ch2 << 4) | (ch3 << 18);
	*out_pkcd++ = (ch4) | (ch5 << 14) | (ch6 << 28);
	*out_pkcd = (ch6 >> 4) | (ch7 << 10);
	return 12;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_15(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//16 байт / 15 бит: xxxx'1100 aaaa'aaaa aaaa'aaab bbbb'bbbb | bbbb'bbcc cccc'cccc cccc'cddd dddd'dddd | dddd'eeee eeee'eeee eeef'ffff ffff'ffff | ffhh'hhhh hhhh'hhhh hggg'gggg gggg'gggg
	ch0 &= 0x7FFF; ch1 &= 0x7FFF;	ch2 &= 0x7FFF;	ch3 &= 0x7FFF; ch4 &= 0x7FFF;	ch5 &= 0x7FFF;	ch6 &= 0x7FFF;	ch7 &= 0x7FFF;
	*out_pkcd++ = mark_num | (0b0011<<4) | (ch0 << 8) | (ch1 << 23);
	*out_pkcd++ = (ch1 >> 9) | (ch2 << 6) | (ch3 << 21);
	*out_pkcd++ = (ch3 >> 11) | (ch4 << 4) | (ch5 << 19);
	*out_pkcd = (ch5 >> 13) | (ch6 << 2) | (ch7 << 17);
	return 13;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_16(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//17 байт / 16 бит: xxxx'1101  aaaa'aaaa aaaa'aaaa bbbb'bbbb | bbbb'bbbb cccc'cccc cccc'cccc dddd'dddd | dddd'dddd eeee'eeee eeee'eeee ffff'ffff | ffff'ffff hhhh'hhhh hhhh'hhhh gggg'gggg | gggg'gggg
	ch0 &= 0xFFFF; ch1 &= 0xFFFF;	ch2 &= 0xFFFF;	ch3 &= 0xFFFF; ch4 &= 0xFFFF;	ch5 &= 0xFFFF;	ch6 &= 0xFFFF;	ch7 &= 0xFFFF;
	*out_pkcd++ = mark_num | (0b1011<<4) | (ch0 << 8) | (ch1 << 24);
	*out_pkcd++ = (ch1 >> 8) | (ch2 << 8) | (ch3 << 24);
	*out_pkcd++ = (ch3 >> 8) | (ch4 << 8) | (ch5 << 24);
	*out_pkcd++ = (ch5 >> 8) | (ch6 << 8) | (ch7 << 24);
	*out_pkcd = (ch7 >> 8);
	return 14;
}
//------------------------------------------------------------------------------------------------------
s32 pack8_20(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 ch3 = in_diff[3];
	u32 ch4 = in_diff[4];
	u32 ch5 = in_diff[5];
	u32 ch6 = in_diff[6];
	u32 ch7 = in_diff[7];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//21 байт/20 бит: xxxx'1110	aaaa'aaaa aaaa'aaaa aaaa'bbbb | bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc | cccc'dddd dddd'dddd dddd'dddd eeee'eeee | eeee'eeee eeee'ffff ffff'ffff ffff'ffff | hhhh'hhhh hhhh'hhhh hhhh'gggg gggg'gggg	| gggg'gggg
	ch0 &= 0xFFFFF; ch1 &= 0xFFFFF;	ch2 &= 0xFFFFF;	ch3 &= 0xFFFFF; ch4 &= 0xFFFFF;	ch5 &= 0xFFFFF;	ch6 &= 0xFFFFF;	ch7 &= 0xFFFFF;
	*out_pkcd++ = mark_num | (0b0111<<4) | (ch0 << 8) | (ch1 << 28);
	*out_pkcd++ = (ch1 >> 4) | (ch2 << 16);
	*out_pkcd++ = (ch2 >> 16) | (ch3 << 4) | (ch4 << 24);
	*out_pkcd++ = (ch4 >> 8) | (ch5 << 12);
	*out_pkcd++ = (ch6) | (ch7 << 20);
	*out_pkcd = (ch7 >> 12);
	return 15;
}
