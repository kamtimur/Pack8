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