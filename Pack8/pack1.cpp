#include "pack1.h"
//--------------------------------------------------------
//Одноканальная паковка
//1 / 2	 : (0) xxxx'00aa																																												
//2 / 10 : (2) xxxx'01aa	aaaa'aaaa
//3 / 18 : (1) xxxx'10aa	aaaa'aaaa aaaa'aaaa
//4 / 24 : (3) xxxx'11--	aaaa'aaaa aaaa'aaaa aaaa'aaaa
//--------------------------------------------------------
s32 pack1_0(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//1 / 2	 : (0) xxxx'00aa	
	ch0 &= 0x3;
	*out_pkcd = mark_num | (0b00 << 4) | (ch0 << 6);
	return 1;
}

s32 pack1_10(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//2 / 10 : (2) xxxx'01aa	aaaa'aaaa
	ch0 &= 0x3FF;
	*out_pkcd = mark_num | (0b10 << 4) | (ch0 << 6);
	return 2;
}

s32 pack1_18(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//3 / 18 : (1) xxxx'10aa	aaaa'aaaa aaaa'aaaa
	ch0 &= 0x3FFFF;
	*out_pkcd = mark_num | (0b01 << 4) | (ch0 << 6);
	return 3;
}

s32 pack1_24(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//4 / 24 : (3) xxxx'11--	aaaa'aaaa aaaa'aaaa aaaa'aaaa
	ch0 &= 0xFFFFFF;
	*out_pkcd = mark_num | (0b11 << 4) | (ch0 << 8);
	return 4;
}
