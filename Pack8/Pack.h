#pragma once
enum EventMark
{
	ECG = 1, 	//- ECG
	REO,		//-	REO
	ACÑ_IN,		//-	ACÑ_IN
	ACÑ_EXT,	//-	ACÑ_EXT
	APT,		//-	APT
	PULSE,		//-	PULSE
	TON,		//-	TON
	SPO			//- SPO
};
#define RESTR __restrict 

typedef s32(*typepack8Funcs) (const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);


