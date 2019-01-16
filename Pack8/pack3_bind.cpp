#include "pack3_bind.h"
//--------------------------------------------------------
//Трехканальная паковка связанная
//1 / 2  : (0) 00aa'bbcc
//2 / 4  : (3) 1100'aaaa bbbb'cccc
//3 / 7  : (5) 101a'aaaa aabb'bbbb bccc'cccc
//4 / 10 : (2) 01aa'aaaa aaaa'bbbb bbbb'bbcc cccc'cccc
//5 / 12 : (B)1101'aaaa aaaa'aaaa bbbb'bbbb bbbb'cccc cccc'cccc
//6 / 15 : (1) 100a'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb bccc'cccc cccc'cccc
//7 / 17 : (7) 1110'aaaa aaaa'aaaa aaaa'abbb bbbb'bbbb bbbb'bbcc cccc'cccc cccc'ccc-
//8 / 20 : (F)1111'aaaa aaaa'aaaa aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'cccc
//-------------------------------------------------------- -


//s32 pack3_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd) //TODO(romanm): �������� ������������ �������� �� �������� �� ���� ������� �������
//{
//	u32 ch0 = in_diff[0];
//	u32 ch1 = in_diff[1];
//	u32 ch2 = in_diff[2];
//
//	switch (num_bits)
//	{
//	case 0:
//	case 1:
//		//  1 ����� /2  ����: 00aa'bbcc
//		ch0 &= 0x03; ch1 &= 0x03; ch2 &= 0x03;
//		*out_pkcd = 0 | (ch0 << 2) | (ch1 << 4) | (ch2 << 6);
//		return 1;
//	case 2:
//	case 3:
//	case 4:
//		//  2 ����� /4  ����: 1100'aaaa bbbb'cccc
//		ch0 &= 0xF; ch1 &= 0xF; ch2 &= 0xF;
//		*out_pkcd = 0b1100 | (ch0 << 4) | (ch1 << 8) | (ch2 << 12);
//		return 2;
//	case 5:
//	case 6:
//	case 7:
//		//  3 ����� /7  ��� : 101a'aaaa aabb'bbbb bccc'cccc
//		ch0 &= 0x7F; ch1 &= 0x7F; ch2 &= 0x7F;
//		*out_pkcd = 0b101 | (ch0 << 3) | (ch1 << 10) | (ch2 << 17);
//		return 3;
//	case 8:
//	case 9:
//	case 10:
//		//  4 ����� /10  ��� : 01aa'aaaa aaaa'bbbb bbbb'bbcc cccc'cccc
//		ch0 &= 0x3FF; ch1 &= 0x3FF; ch2 &= 0x3FF;
//		*out_pkcd = 0b01 | (ch0 << 2) | (ch1 << 12) | (ch2 << 22);
//		return 4;
//	case 11:
//	case 12:
//		//  5 ����� /12  ��� : 1101'aaaa aaaa'aaaa bbbb'bbbb bbbb'cccc cccc'cccc
//		ch0 &= 0xFFF; ch1 &= 0xFFF; ch2 &= 0xFFF;
//		*out_pkcd++ = 0b1101 | (ch0 << 4) | (ch1 << 16) | (ch2 << 28);
//		*out_pkcd = (ch2 >> 4);
//		return 5;
//	case 13:
//	case 14:
//	case 15:
//		//  6 ����� /15  ��� : 100a'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb bccc'cccc cccc'cccc
//		ch0 &= 0x7FFF; ch1 &= 0x7FFF; ch2 &= 0x7FFF;
//		*out_pkcd++ = 0b100 | (ch0 << 3) | (ch1 << 18);
//		*out_pkcd = (ch1 >> 14) | (ch2 << 1);
//		return 6;
//	case 16:
//	case 17:
//		//  7 ����� /17  ��� : 1110'aaaa aaaa'aaaa aaaa'abbb bbbb'bbbb bbbb'bbcc cccc'cccc cccc'ccc-
//		ch0 &= 0x1FFFF; ch1 &= 0x1FFFF; ch2 &= 0x1FFFF;
//		*out_pkcd++ = 0b1110 | (ch0 << 4) | (ch1 << 21);
//		*out_pkcd = (ch1 >> 11) | (ch2 << 6);
//		return 7;
//	default:
//		//  8 ����  /20 ����: 1111'aaaa aaaa'aaaa aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'cccc		
//		ch0 &= 0xFFFFF; ch1 &= 0x3FFFFF;
//		*out_pkcd++ = 0b1111 | (ch0 << 4) | (ch1 << 24);
//		*out_pkcd = (ch1 >> 8) | (ch2 << 12);
//		return 8;
//	}
//
//}

s32 pack3_2_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	//1 / 2  : (0) 00aa'bbcc
	ch0 &= 0x03; ch1 &= 0x03; ch2 &= 0x03;
	*out_pkcd = 0 | (ch0 << 2) | (ch1 << 4) | (ch2 << 6);
	return 1;
}
s32 pack3_4_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	//2 / 4  : (3) 1100'aaaa bbbb'cccc
	ch0 &= 0xF; ch1 &= 0xF; ch2 &= 0xF;
	*out_pkcd = 0b1100 | (ch0 << 4) | (ch1 << 8) | (ch2 << 12);
	return 2;
}
s32 pack3_7_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	//3 / 7  : (5) 101a'aaaa aabb'bbbb bccc'cccc
	ch0 &= 0x7F; ch1 &= 0x7F; ch2 &= 0x7F;
	*out_pkcd = 0b101 | (ch0 << 3) | (ch1 << 10) | (ch2 << 17);
	return 3;
}
s32 pack3_10_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	//4 / 10 : (2) 01aa'aaaa aaaa'bbbb bbbb'bbcc cccc'cccc
	ch0 &= 0x3FF; ch1 &= 0x3FF; ch2 &= 0x3FF;
	*out_pkcd = 0b01 | (ch0 << 2) | (ch1 << 12) | (ch2 << 22);
	return 4;
}
s32 pack3_12_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	//5 / 12 : (B)1101'aaaa aaaa'aaaa bbbb'bbbb bbbb'cccc cccc'cccc
	ch0 &= 0xFFF; ch1 &= 0xFFF; ch2 &= 0xFFF;
	*out_pkcd++ = 0b1101 | (ch0 << 4) | (ch1 << 16) | (ch2 << 28);
	*out_pkcd = (ch2 >> 4);
	return 5;
}
s32 pack3_15_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	//6 / 15 : (1) 100a'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb bccc'cccc cccc'cccc
	ch0 &= 0x7FFF; ch1 &= 0x7FFF; ch2 &= 0x7FFF;
	*out_pkcd++ = 0b100 | (ch0 << 3) | (ch1 << 18);
	*out_pkcd = (ch1 >> 14) | (ch2 << 1);
	return 6;
}
s32 pack3_17_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	//7 / 17 : (7) 1110'aaaa aaaa'aaaa aaaa'abbb bbbb'bbbb bbbb'bbcc cccc'cccc cccc'ccc-
	ch0 &= 0x1FFFF; ch1 &= 0x1FFFF; ch2 &= 0x1FFFF;
	*out_pkcd++ = 0b1110 | (ch0 << 4) | (ch1 << 21);
	*out_pkcd = (ch1 >> 11) | (ch2 << 6);
	return 7;
}
s32 pack3_20_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	//8 / 20 : (F)1111'aaaa aaaa'aaaa aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'cccc cccc'cccc cccc'cccc
	ch0 &= 0xFFFFF; ch1 &= 0x3FFFFF;
	*out_pkcd++ = 0b1111 | (ch0 << 4) | (ch1 << 24);
	*out_pkcd = (ch1 >> 8) | (ch2 << 12);
	return 8;
}
