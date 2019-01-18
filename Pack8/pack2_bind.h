#pragma once
#include "Pack.h"
//--------------------------------------------------------
//Двухканальная паковка связанная
//1 / 3	 : (0) 00aa'abbb
//2 / 7  : (2) 01aa'aaaa abbb'bbbb
//3 / 11 : (1) 10aa'aaaa aaaa'abbb bbbb'bbbb
//4 / 14 : (3) 1100'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb
//5 / 18 : (B) 1101'aaaa aaaa'aaaa aaaa'aabb bbbb'bbbb bbbb'bbbb
//6 / 22 : (7) 1110'aaaa aaaa'aaaa aaaa'aaaa aabb'bbbb bbbb'bbbb bbbb'bbbb
//-------------------------------------------------------- -


s32 pack2_3_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_7_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_11_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_14_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_18_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_22_bind(const s32* RESTR in_diff, s32 num_bits, s32* RESTR out_pkcd);

const type_pack_bind_funcs pack2_bind_Funcs[] =
{
	pack2_3_bind,		//0
	pack2_3_bind,		//1
	pack2_3_bind,		//2
	pack2_3_bind,		//3
	pack2_7_bind,		//4
	pack2_7_bind,		//5
	pack2_7_bind,		//6
	pack2_7_bind,		//7
	pack2_11_bind,		//8
	pack2_11_bind,		//9
	pack2_11_bind,		//10
	pack2_11_bind,		//11
	pack2_14_bind,		//12
	pack2_14_bind,		//13
	pack2_14_bind,		//14
	pack2_18_bind,		//15
	pack2_18_bind,		//16
	pack2_18_bind,		//17
	pack2_18_bind,		//18
	pack2_22_bind,		//19
	pack2_22_bind,		//20
	pack2_22_bind,		//21
	pack2_22_bind		//22
};

