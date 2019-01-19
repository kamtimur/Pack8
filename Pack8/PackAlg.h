#pragma once
#include "types.h"
#include "Pack.h"





class PackAlg
{
public:
	PackAlg(s32 _ChannelNum, const type_pack_funcs* _PackFuncs, s32* _Prev, s32* _Diff)
		: 
		InnerChannelNumber(_ChannelNum),
		PackFuncs(_PackFuncs),
		Prev(_Prev),
		Diff(_Diff)
	{};
	void Reset();
	s32  Pack(const s32* RESTR in_diff, EventMark mark, s32* RESTR out_pkcd);

protected:
	s32 Size(s32 rg);
public:
	s32 InnerChannelNumber;
protected:
	s32* Prev;
	s32* Diff;
	const type_pack_funcs* PackFuncs;
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