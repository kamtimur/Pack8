#include "pack2.h"
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
const type_pack_funcs pack2Funcs[] =
{
	pack2_0,		//0
	pack2_5,		//1
	pack2_5,		//2
	pack2_5,		//3
	pack2_5,		//4
	pack2_5,		//5
	pack2_9,		//6
	pack2_9,		//7
	pack2_9,		//8
	pack2_9,		//9
	pack2_11,		//10
	pack2_11,		//11
	pack2_16,		//12
	pack2_16,		//13
	pack2_16,		//14
	pack2_16,		//15
	pack2_16,		//16
	pack2_20,		//17
	pack2_20,		//18
	pack2_20,		//19
	pack2_20,		//20
	pack2_24,		//21
	pack2_24,		//22
	pack2_24,		//23
	pack2_24		//24
};
//--------------------------------------------------------
s32 pack2_0(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 mark_num = mark;
	mark_num &= 0xF;
	//1 / 0  : (0) xxxx'0000
	*out_pkcd = mark_num | (0x0 << 4);
	return 1;
}
//--------------------------------------------------------
s32 pack2_5(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//2 / 5  : (2) xxxx'01aa	aaab'bbbb
	ch0 &= 0x1F; ch1 &= 0x1F;
	*out_pkcd = mark_num | (0b10 << 4) | (ch0 << 6) | (ch1 << 11);
	return 2;
}
//--------------------------------------------------------
s32 pack2_9(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//3 / 9  : (1) xxxx'10aa	aaaa'aaab bbbb'bbbb
	ch0 &= 0x1FF; ch1 &= 0x1FF;
	*out_pkcd = mark_num | (0b01 << 4) | (ch0 << 6) | (ch1 << 15);
	return 3;
}
//--------------------------------------------------------
s32 pack2_11(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//4 / 11 : (3) xxxx'1100	aaaa'aaaa aaab'bbbb	bbbb'bbbb
	ch0 &= 0x7FF; ch1 &= 0x7FF;
	*out_pkcd = mark_num | (0b0011 << 4) | (ch0 << 8) | (ch1 << 19);
	return 4;
}
//--------------------------------------------------------
s32 pack2_16(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//5 / 16 : (B) xxxx'1101	aaaa'aaaa aaaa'aaaa	bbbb'bbbb bbbb'bbbb
	ch0 &= 0xFFFF; ch1 &= 0xFFFF;
	*out_pkcd++ = mark_num | (0b1011 << 4) | (ch0 << 8) | (ch1 << 24);
	*out_pkcd = (ch1 >> 8);
	return 5;
}
//--------------------------------------------------------
s32 pack2_20(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//6 / 20 : (7) xxxx'1110	aaaa'aaaa aaaa'aaaa	aaaa'bbbb bbbb'bbbb bbbb'bbbb
	ch0 &= 0xFFFFF; ch1 &= 0xFFFFF;
	*out_pkcd++ = mark_num | (0b0111 << 4) | (ch0 << 8) | (ch1 << 28);
	*out_pkcd = (ch1 >> 4);
	return 6;
}
//--------------------------------------------------------
s32 pack2_24(const s32 *RESTR in_diff, EventMark mark, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 mark_num = mark;
	mark_num &= 0xF;
	//7 / 24 : (F) xxxx'1111	aaaa'aaaa aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb
	ch0 &= 0xFFFFFF; ch1 &= 0xFFFFFF;
	*out_pkcd++ = mark_num | (0b1111 << 4) | (ch0 << 8);
	*out_pkcd = (ch1);
	return 7;
}
//--------------------------------------------------------

