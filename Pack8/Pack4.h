#pragma once
#include "Pack.h"

s32 pack4_0(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_2(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_3(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_6(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_8(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_10(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_12(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_14(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_16(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_18(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_20(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_22(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack4_24(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);



const type_pack_funcs pack4Funcs[] =
{
	pack4_0,		//0
	pack4_2,		//1
	pack4_2,		//2
	pack4_3,		//3
	pack4_6,		//4
	pack4_6,		//5
	pack4_6,		//6
	pack4_8,		//7
	pack4_8,		//8
	pack4_10,		//9
	pack4_10,		//10
	pack4_12,		//11
	pack4_12,		//12
	pack4_14,		//13
	pack4_14,		//14
	pack4_16,		//15
	pack4_16,		//16
	pack4_18,		//17
	pack4_18,		//18
	pack4_20,		//19
	pack4_20,		//20
	pack4_22,		//21
	pack4_22,		//22
	pack4_24,		//23
	pack4_24		//24
};
