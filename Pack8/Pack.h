#pragma once
#include "types.h"
enum EventMark //- EventMark
{
	NUL = 0,		
	ECG = 1, 	//- ECG
	REO,		//-	REO
	ACC_IN,		//-	ACC_IN
	ACC_EXT,	//-	ACC_EXT
	APT,		//-	APT
	PULSE,		//-	PULSE
	TON,		//-	TON
	SPO			//- SPO
};
enum PackType //- EventMark
{
	COMM = 0,
	BIND
};
#define RESTR __restrict 

using type_pack_funcs = s32(*) (const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
