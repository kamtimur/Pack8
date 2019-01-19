#pragma once
#include "Unpack.h"
#include "Pack.h"
class Unpacker
{
public:
	Unpacker(s32 ChannelNumber, const type_unpack_funcs* _UnpackFuncs, PackType _Type) : 
		InnerChannelNumber(ChannelNumber), 
		UnpackFuncs(_UnpackFuncs),
		Type(_Type)
	{ PrevSz = ChannelNumber; }
	void Reset();
	s32  Unpack(unsigned char * _src, long * _dst);

protected:
	const s32 InnerChannelNumber;
	PackType Type;
	s32 pkPoint[8]; s32 pkPointSz;
	s32 Prev[8];    s32 PrevSz;
	s32 Diff[8];    s32 DiffSz;
	const type_unpack_funcs* UnpackFuncs;
};