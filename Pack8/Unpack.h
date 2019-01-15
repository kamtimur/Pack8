#pragma once
#include "windows.h"
#include "types.h"


#define SIGNCH(a,m) if((a)&(m)){(a)|=(0xffffffff ^ ((m)-1));}
#define GETSRC(src) *(DWORD *)(src)
#define UNPACKPTN_END(src, bits) *_dst = (src & ((1<<(bits))-1)); SIGNCH((*(_dst)), (1 << ((bits)-1)))
#define UNPACKPTN(src, bits) UNPACKPTN_END(src, bits); _dst++; src>>=(bits)


typedef s32(*untype_pack_funcs) (unsigned char * _src, long * _dst);

inline s32 unpack_NULL(unsigned char * _src, long * _dst) { return 0; };	//NULL