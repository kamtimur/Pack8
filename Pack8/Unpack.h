#pragma once
#include "windows.h"
#include "types.h"


#define SIGNCH(a,m) if((a)&(m)){(a)|=(0xffffffff ^ ((m)-1));}
#define GETSRC(src) *(DWORD *)(src)
#define GETSRCS(src, shift) (*(DWORD *)(src))>>shift
#define UNPACKPTN_END(src, bits) *_dst = (src & ((1<<(bits))-1));SIGNCH((*(_dst)), (1 << ((bits)-1)))
#define UNPACKPTN(src, bits) UNPACKPTN_END(src, bits); _dst++; src>>=(bits)
#define GETSRCSW(src, shift) (*(WORD *)(src))>>shift

typedef s32(*type_unpack_funcs) (unsigned char * _src, long * _dst);

inline s32 unpack_NULL(unsigned char * _src, long * _dst) { return -1; };	//NULL