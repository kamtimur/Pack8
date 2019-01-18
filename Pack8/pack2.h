#pragma once
#include "Pack.h"
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
s32 pack2_0(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_5(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_9(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_11(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_16(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_20(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
s32 pack2_24(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
//--------------------------------------------------------
extern const type_pack_funcs pack2Funcs[];
