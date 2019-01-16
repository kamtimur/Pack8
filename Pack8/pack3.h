#pragma once
#include "Pack.h"
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
s32 pack3_0(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_3(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_5(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_8(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_11(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_13(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_16(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_19(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_21(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_24(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
//--------------------------------------------------------
const type_pack_funcs pack3Funcs[] =
{
	pack3_0,		//0
	pack3_3,		//1
	pack3_3,		//2
	pack3_3,		//3
	pack3_5,		//4
	pack3_5,		//5
	pack3_8,		//6
	pack3_8,		//7
	pack3_8,		//8
	pack3_11,		//9
	pack3_11,		//10
	pack3_11,		//11
	pack3_13,		//12
	pack3_13,		//13
	pack3_16,		//14
	pack3_16,		//15
	pack3_16,		//16
	pack3_19,		//17
	pack3_19,		//18
	pack3_19,		//19
	pack3_21,		//20
	pack3_21,		//21
	pack3_24,		//22
	pack3_24,		//23
	pack3_24		//24
};

