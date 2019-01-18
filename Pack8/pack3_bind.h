#pragma once
#include "Pack.h"
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


s32 pack3_2_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_4_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_7_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_10_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_12_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_15_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_17_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack3_20_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);

const type_pack_bind_funcs pack3_bind_Funcs[] =
{
	pack3_2_bind,		//0
	pack3_2_bind,		//1
	pack3_2_bind,		//2
	pack3_4_bind,		//3
	pack3_4_bind,		//4
	pack3_7_bind,		//5
	pack3_7_bind,		//6
	pack3_7_bind,		//7
	pack3_10_bind,		//8
	pack3_10_bind,		//9
	pack3_10_bind,		//10
	pack3_12_bind,		//11
	pack3_12_bind,		//12
	pack3_15_bind,		//13
	pack3_15_bind,		//14
	pack3_15_bind,		//15
	pack3_17_bind,		//16
	pack3_17_bind,		//17
	pack3_20_bind,		//18
	pack3_20_bind,		//19
	pack3_20_bind		//20
};

