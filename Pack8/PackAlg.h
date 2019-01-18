#pragma once
#include "types.h"
#include "Pack.h"



template<s32 _ChannelNum, typename TFunc, TFunc* _PackFuncs>
class PackAlg
{
public:
	PackAlg() {}
	void Reset();
	void Test();
	s32  Pack(const s32* RESTR in_diff, EventMark mark, s32* RESTR out_pkcd);
	s32  Pack(const s32* RESTR in_diff, s32* RESTR out_pkcd);
protected:
	s32 Size(s32 rg);
public:
	static const s32 InnerChannelNumber = _ChannelNum;
protected:

	static TFunc* const PackFuncs;
	static const s32 ChannelNum = _ChannelNum;
	s32 Prev[ChannelNum];
	s32 Diff[ChannelNum];
};

#include "PackAlg.cpp"

template<s32 _ChannelNum, typename TFunc, TFunc* _PackFuncs>
TFunc* const PackAlg<_ChannelNum, TFunc, _PackFuncs>::PackFuncs = _PackFuncs;

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