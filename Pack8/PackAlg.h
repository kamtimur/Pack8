#pragma once
#include "types.h"
#include "Pack.h"
class PackAlg
{
public:
	PackAlg(s32 ChannelNumber, const type_pack_funcs* _PackFuncs) : InnerChannelNumber(ChannelNumber), PackFuncs(_PackFuncs) 
	{
		stide_sz= ChannelNumber*2; 
	}
	void Reset();
	s32  Pack(const s32* RESTR in_diff, EventMark mark, s32* RESTR out_pkcd);
protected:
	s32 Size(s32 rg);
public:
	const s32 InnerChannelNumber;
protected:

	const type_pack_funcs* PackFuncs;
	s32 stide_sz;
	s32 Prev_Diff[];
};

//struct PackAlgConf {
//	const type_pack_funcs* PackFuncs;
//	s32 stide_sz;
//	s32 Prev_Diff[];  
//};

//struct FrameEcg
//{
//	s32 p[8];
//};
//
//class BlockPacker
//{
//public:
//	PackAlg packAlgEcg(8,tbl1);
//	PackAlg packAlgPress(3,tbl2);
//
//	void Exe(FrameEcg & ecg, FramePress & press)
//	{
//		packAlgEcg.Pack(ecg);
//		packAlgPress.Pack(press);
//
//
//	}
//
//	void ChangeChPack(int num)
//	{
//		case 3:
//			packAlg.SetPackFunc(table3);
//		case 8:
//			packAlg.SetPackFunc(table8);
//	}
//
//};