#pragma once
#include "types.h"
#include "Pack.h"
class PackAlg
{
public:
	PackAlg(s32 ChannelNumber, const typepack8Funcs* _PackFuncs) : InnerChannelNumber(ChannelNumber), PackFuncs(_PackFuncs) { PrevSz = ChannelNumber; }
	void Reset();
	s32  Pack(const s32* RESTR in_diff, EventMark mark, s32* RESTR out_pkcd);
protected:
	s32 Size(s32 rg);

protected:
	const s32 InnerChannelNumber;

	u32* pkPoint; s32 pkPointSz;
	s32 Prev[8];    s32 PrevSz;
	s32 Diff[8];    s32 DiffSz;
	const typepack8Funcs* PackFuncs;
};