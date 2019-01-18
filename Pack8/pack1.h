#pragma once
#include "Pack.h"
//--------------------------------------------------------
//Одноканальная паковка
//1 / 2	 : (0) xxxx'00aa																																												
//2 / 10 : (2) xxxx'01aa	aaaa'aaaa
//3 / 18 : (1) xxxx'10aa	aaaa'aaaa aaaa'aaaa
//4 / 24 : (3) xxxx'11--	aaaa'aaaa aaaa'aaaa aaaa'aaaa
//--------------------------------------------------------
s32 pack1_0(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack1_10(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack1_18(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack1_24(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);

const type_pack_funcs pack1Funcs[] =
{
	pack1_0,		//0
	pack1_10,		//1
	pack1_10,		//2
	pack1_10,		//3
	pack1_10,		//4
	pack1_10,		//5
	pack1_10,		//6
	pack1_10,		//7
	pack1_10,		//8
	pack1_10,		//9
	pack1_10,		//10
	pack1_18,		//11
	pack1_18,		//12
	pack1_18,		//13
	pack1_18,		//14
	pack1_18,		//15
	pack1_18,		//16
	pack1_18,		//17
	pack1_18,		//18
	pack1_24,		//19
	pack1_24,		//20
	pack1_24,		//21
	pack1_24,		//22
	pack1_24,		//23
	pack1_24		//24
};