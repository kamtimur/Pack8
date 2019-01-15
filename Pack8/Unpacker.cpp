#include "Unpacker.h"

void Unpacker::Reset()
{
	for (s32 i = 0; i < PrevSz; i++)
	{
		Prev[i] = 0;
	}
}

s32 Unpacker::Unpack(unsigned char * _src, long * _dst)
{
	BYTE id = ((*_src >> 4) & 0x0F);
	s32 ret;
	if (id < 0x0F)
	{
		//untype_pack_funcs * pUp = &unpack8Funcs[id];
		ret = UnpackFuncs[id](_src, _dst);
		for (s32 i = 0; i < PrevSz; i++)
		{
			Diff[i] = *_dst;
			*_dst = Prev[i]+ Diff[i];
			Prev[i] = *_dst;
			_dst++;
		}
	}
	return ret;
}
