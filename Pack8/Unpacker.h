#pragma once
#include "Unpack.h"
class Unpacker
{
public:
	Unpacker(s32 ChannelNumber, const untype_pack_funcs* _UnpackFuncs) : InnerChannelNumber(ChannelNumber), UnpackFuncs(_UnpackFuncs) { PrevSz = ChannelNumber; }
	void Reset();
	s32  Unpack(unsigned char * _src, long * _dst);

protected:
	const s32 InnerChannelNumber;

	s32 pkPoint[8]; s32 pkPointSz;
	s32 Prev[8];    s32 PrevSz;
	s32 Diff[8];    s32 DiffSz;
	const untype_pack_funcs* UnpackFuncs;
};