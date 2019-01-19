#include "PackAlg.h"
#include "Pack.h"
#include <iostream>

//template<s32 _ChannelNum, typename TFunc, TFunc * _PackFuncs>
//s32 PackAlg<_ChannelNum, TFunc, _PackFuncs>::Pack(const s32 *RESTR in_diff, EventMark mark, s32 *RESTR out_pkcd);

//
//template<s32 _ChannelNum, typename TFunc, void * _PackFuncs>
//s32 PackAlg<_ChannelNum, TFunc, _PackFuncs>::Test();




s32 PackAlg::Pack(const s32 *RESTR in_diff, EventMark mark, s32 *RESTR out_pkcd)
{
	register s32 i, rg;
	register u32 frm;

	frm = 0;
	for (i = 0; i< InnerChannelNumber; i++)
	{
		Diff[i] = rg = in_diff[i] - Prev[i]; // внимание, порядок вычитания снова изменен
		Prev[i] = in_diff[i];
		rg = Size(rg);
		if (frm < rg) frm = rg;			//
	}
	frm &= 0x1F;
	return PackFuncs[frm](Diff, mark, frm, out_pkcd);	// 
}



void PackAlg::Reset()
{
	for (s32 i = 0; i < InnerChannelNumber; i++)
	{
		Prev[i] = 0;
		Diff[i] = 0;
	}
}

int clz(uint32_t x)
{
	static const char debruijn32[32] = {
		0, 31, 9, 30, 3, 8, 13, 29, 2, 5, 7, 21, 12, 24, 28, 19,
		1, 10, 4, 14, 6, 22, 25, 20, 11, 15, 23, 26, 16, 27, 17, 18
	};
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x++;
	return debruijn32[x * 0x076be629 >> 27];
}

s32 PackAlg::Size(s32 rg)// определяем размер точки сигнала 
{
		if (rg < 0) rg = ~rg;				//
		//__asm { clz rg ,rg};			// определение позиции старшей единицы
		rg = clz(rg);					// ассемлерная операция заменена на эту
		rg = 33 - rg;							//	
		return rg;

}

