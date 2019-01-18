#include "pack3.h"
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

s32 pack3(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd) //TODO(romanm): поменять возвращаемое значение на знаковое во всей цепочке вызовов
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 mark_num = mark;
	mark_num &= 0xF;

	switch (num_bits)
	{
	case 0:
		//1 / 0  xxxx'0000	
		*out_pkcd = mark_num | (0x0 << 4);
		return 1;
	case 1:
	case 2:
	case 3:
		//2 / 3: xxxx'100a aabb'bccc
		ch0 &= 0x7; ch1 &= 0x7; ch2 &= 0x7;
		*out_pkcd = mark_num | (0b100 << 4) | (ch0 << 7) | (ch1 << 10) | (ch2 << 13);
		return 2;
	case 4:
	case 5:
		//3  / 5 xxxx'0001 aaaa'abbb bbcc'ccc-
		ch0 &= 0x1F; ch1 &= 0x1F; ch2 &= 0x1F;
		*out_pkcd = mark_num | (0b0001 << 4) | (ch0 << 8) | (ch1 << 13) | (ch2 << 18);
		return 3;
	case 6:
	case 7:
	case 8:
		//4 ����� / 8 ���: xxxx'0010 aaaa'aaaa bbbb'bbbb cccc'cccc
		ch0 &= 0xFF; ch1 &= 0xFF; ch2 &= 0xFF;
		*out_pkcd = mark_num | (0b0010 << 4) | (ch0 << 8) | (ch1 << 16) | (ch2 << 24);
		return 4;
	case 9:
	case 10:
	case 11:
		//5 ���� /11  ��� : xxxx'101a aaaa'aaaa	aabb'bbbb bbbb'bccc cccc'cccc
		ch0 &= 0x7FF; ch1 &= 0x7FF; ch2 &= 0x7FF;
		*out_pkcd++ = mark_num | (0b101 << 4) | (ch0 << 7) | (ch1 << 18) | (ch2 << 29);
		*out_pkcd = (ch2 >> 3);
		return 5;
	case 12:
	case 13:
		//6 ���� /13  ��� : xxxx'0011 aaaa'aaaa aaaa'abbb bbbb'bbbb bbcc'cccc cccc'ccc-
		ch0 &= 0x1FFF; ch1 &= 0x1FFF; ch2 &= 0x1FFF;
		*out_pkcd++ = mark_num | (0b0011 << 4) | (ch0 << 8) | (ch1 << 21);
		*out_pkcd = (ch1 >> 11) | (ch2 << 2);
		return 6;
	case 14:
	case 15:
	case 16:
		//7 ���� /16  ��� : xxxx'0100 aaaa'aaaa	aaaa'aaaa bbbb'bbbb	bbbb'bbbb cccc'cccc cccc'cccc
		ch0 &= 0xFFFF; ch1 &= 0xFFFF; ch2 &= 0xFFFF;
		*out_pkcd++ = mark_num | (0b0100 << 4) | (ch0 << 8) | (ch1 << 24);
		*out_pkcd = (ch1 >> 8) | (ch2 << 8);
		return 7;
	case 17:
	case 18:
	case 19:
		//8 ����/18 ���: xxxx'0101 aaaa'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb bbbb'bccc cccc'cccc cccc'cccc
		ch0 &= 0xFFFF; ch1 &= 0xFFFF; ch2 &= 0xFFFF;
		*out_pkcd++ = mark_num | (0b0101 << 4) | (ch0 << 8) | (ch1 << 24);
		*out_pkcd = (ch1 >> 8) | (ch2 << 8);
		return 8;
	case 20:
	case 21:
		//9/21 : xxxx'0110 aaaa'aaaa aaaa'aaaa aaaa'abbb bbbb'bbbb bbbb'bbbb bbcc'cccc cccc'cccc cccc'ccc-
		ch0 &= 0x1FFFFF; ch1 &= 0x1FFFFF; ch2 &= 0x1FFFFF;
		*out_pkcd++ = mark_num | (0b0110 << 4) | (ch0 << 8) | (ch1 << 29);
		*out_pkcd++ = (ch1 >> 3) | (ch2 << 18);
		*out_pkcd = (ch2 >> 14);
		return 9;
	default:
		//10 /24 xxxx'0111	aaaa'aaaa aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'cccc		
		ch0 &= 0xFFFFFF; ch1 &= 0xFFFFFF; ch2 &= 0xFFFFFF;
		*out_pkcd++ = mark_num | (0b0111 << 4) | (ch0 << 8);
		*out_pkcd++ = ch1 | (ch2 << 24);
		*out_pkcd = (ch2 >> 8);
		return 10;
	}
}

s32 pack3_0(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	//1 / 0   : (0) xxxx'0000	
	u32 mark_num = mark;
	mark_num &= 0xF;
	*out_pkcd = mark_num | (0x0 << 4);
	return 1;
}

s32 pack3_3(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//2 / 3   : (1) xxxx'100a	aabb'bccc
	ch0 &= 0x7; ch1 &= 0x7; ch2 &= 0x7;
	*out_pkcd = mark_num | (0b1 << 4) | (ch0 << 7) | (ch1 << 10) | (ch2 << 13);
	return 2;
}

s32 pack3_5(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//3 / 5   : (8) xxxx'0001	aaaa'abbb	bbcc'ccc-   
	ch0 &= 0x1F; ch1 &= 0x1F; ch2 &= 0x1F;
	*out_pkcd = mark_num | (0b1000 << 4) | (ch0 << 8) | (ch1 << 13) | (ch2 << 18);
	return 3;
}

s32 pack3_8(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//4 / 8   : (4) xxxx'0010	aaaa'aaaa	bbbb'bbbb   cccc'cccc
	ch0 &= 0xFF; ch1 &= 0xFF; ch2 &= 0xFF;
	*out_pkcd = mark_num | (0b0100 << 4) | (ch0 << 8) | (ch1 << 16) | (ch2 << 24);
	return 4;
}

s32 pack3_11(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//5 / 11  : (5) xxxx'101a	aaaa'aaaa	aabb'bbbb   bbbb'bccc cccc'cccc
	ch0 &= 0x7FF; ch1 &= 0x7FF; ch2 &= 0x7FF;
	*out_pkcd++ = mark_num | (0b101 << 4) | (ch0 << 7) | (ch1 << 18) | (ch2 << 29);
	*out_pkcd = (ch2 >> 3);
	return 5;
}

s32 pack3_13(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//6 / 13  : (6) xxxx'0011	aaaa'aaaa   aaaa'abbb   bbbb'bbbb bbcc'cccc	cccc'ccc-
	ch0 &= 0x1FFF; ch1 &= 0x1FFF; ch2 &= 0x1FFF;
	*out_pkcd++ = mark_num | (0b1100 << 4) | (ch0 << 8) | (ch1 << 21);
	*out_pkcd = (ch1 >> 11) | (ch2 << 2);
	return 6;
}

s32 pack3_16(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//7 / 16  : (2) xxxx'0100	aaaa'aaaa	aaaa'aaaa	bbbb'bbbb bbbb'bbbb	cccc'cccc cccc'cccc
	ch0 &= 0xFFFF; ch1 &= 0xFFFF; ch2 &= 0xFFFF;
	*out_pkcd++ = mark_num | (0b0010 << 4) | (ch0 << 8) | (ch1 << 24);
	*out_pkcd = (ch1 >> 8) | (ch2 << 8);
	return 7;
}

s32 pack3_19(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//8 / 19  : (3) xxxx'110a	aaaa'aaaa	aaaa'aaaa	aabb'bbbb bbbb'bbbb bbbb'bccc cccc'cccc cccc'cccc	
	ch0 &= 0x7FFFF; ch1 &= 0x7FFFF; ch2 &= 0x7FFFF;
	*out_pkcd++ = mark_num | (0b011 << 4) | (ch0 << 7) | (ch1 << 26);
	*out_pkcd = (ch1 >> 6) | (ch2 << 13);
	return 8;
}

s32 pack3_21(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//9 / 21  : (6) xxxx'0110	aaaa'aaaa	aaaa'aaaa	aaaa'abbb bbbb'bbbb bbbb'bbbb bbcc'cccc cccc'cccc cccc'ccc-
	ch0 &= 0x1FFFFF; ch1 &= 0x1FFFFF; ch2 &= 0x1FFFFF;
	*out_pkcd++ = mark_num | (0b0110 << 4) | (ch0 << 8) | (ch1 << 29);
	*out_pkcd++ = (ch1 >> 3) | (ch2 << 18);
	*out_pkcd = (ch2 >> 14);
	return 9;
}

s32 pack3_24(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd)
{
	u32 ch0 = in_diff[0];
	u32 ch1 = in_diff[1];
	u32 ch2 = in_diff[2];
	u32 mark_num = mark;
	mark_num &= 0xF;

	//10/ 24  : (E) xxxx'0111	aaaa'aaaa	aaaa'aaaa	aaaa'aaaa bbbb'bbbb bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc cccc'cccc
	ch0 &= 0xFFFFFF; ch1 &= 0xFFFFFF; ch2 &= 0xFFFFFF;
	*out_pkcd++ = mark_num | (0b1110 << 4) | (ch0 << 8);
	*out_pkcd++ = ch1 | (ch2 << 24);
	*out_pkcd = (ch2 >> 8);
	return 10;
}
