#pragma once
#include "types.h"
#include "Pack.h"

s32 pack8_0(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_4(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_5(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_6(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_7(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_8(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_9(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_10(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_11(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_12(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_13(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_14(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_15(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_16(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack8_20(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);


const type_pack_funcs pack8Funcs[] =
{
	pack8_0,		//0
	pack8_4,		//1
	pack8_4,		//2
	pack8_4,		//3
	pack8_4,		//4
	pack8_5,		//5
	pack8_6,		//6
	pack8_7,		//7
	pack8_8,		//8
	pack8_9,		//9
	pack8_10,		//10
	pack8_11,		//11
	pack8_12,		//12
	pack8_13,		//13
	pack8_14,		//14
	pack8_15,		//15
	pack8_16,		//16
	pack8_20,		//17
	pack8_20,		//18
	pack8_20,		//19
	pack8_20,		//20
};