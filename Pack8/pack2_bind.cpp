#include "pack2_bind.h"
//--------------------------------------------------------
//Двухканальная паковка связанная
//1 / 3	 : (0) 00aa'abbb
//2 / 7  : (2) 01aa'aaaa abbb'bbbb
//3 / 11 : (1) 10aa'aaaa aaaa'abbb bbbb'bbbb
//4 / 14 : (3) 1100'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb
//5 / 18 : (B) 1101'aaaa aaaa'aaaa aaaa'aabb bbbb'bbbb bbbb'bbbb
//6 / 22 : (7) 1110'aaaa aaaa'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb bbbb'bbbb
//-------------------------------------------------------- -
s32 pack2_3_bind(const s32 *RESTR in_diff, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	//1 / 3	 : (0) 00aa'abbb
	ch0 &= 0x07; ch1 &= 0x07;
	*out_pkcd = 0 | (ch0 << 2) | (ch1 << 5);
	return 1;
}
//--------------------------------------------------------
s32 pack2_7_bind(const s32 *RESTR in_diff, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	//2 / 7  : (2) 01aa'aaaa abbb'bbbb
	ch0 &= 0x7F; ch1 &= 0x7F;
	*out_pkcd = 0b01 | (ch0 << 2) | (ch1 << 9);
	return 2;
}
//--------------------------------------------------------
s32 pack2_11_bind(const s32 *RESTR in_diff, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	//3 / 11 : (1) 10aa'aaaa aaaa'abbb bbbb'bbbb
	ch0 &= 0x7FF; ch1 &= 0x7FF;
	*out_pkcd = 0b10 | (ch0 << 2) | (ch1 << 13);
	return 3;
}
//--------------------------------------------------------
s32 pack2_14_bind(const s32 *RESTR in_diff, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	//4 / 14 : (3) 1100'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb
	ch0 &= 0x3FFF; ch1 &= 0x3FFF;
	*out_pkcd = 0b1100 | (ch0 << 4) | (ch1 << 18);
	return 4;
}
//--------------------------------------------------------
s32 pack2_18_bind(const s32 *RESTR in_diff, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	//5 / 18 : (B) 1101'aaaa aaaa'aaaa aaaa'aabb bbbb'bbbb bbbb'bbbb
	ch0 &= 0x3FFFF; ch1 &= 0x3FFFF;
	*out_pkcd++ = 0b1110 | (ch0 << 4) | (ch1 << 22);
	*out_pkcd = (ch1 >> 10);
	return 5;
}
//--------------------------------------------------------
s32 pack2_22_bind(const s32 *RESTR in_diff, s32 num_bits, s32 *RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	//6 / 22 : (7) 1110'aaaa aaaa'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb bbbb'bbbb
	ch0 &= 0x3FFFFF; ch1 &= 0x3FFFFF;
	*out_pkcd++ = 0b1101 | (ch0 << 4) | (ch1 << 26);
	*out_pkcd = (ch1 >> 6);
	return 6;
}
//--------------------------------------------------------