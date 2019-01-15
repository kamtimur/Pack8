#include "PackAlg.h"

s32 PackAlg::Pack(const s32 *RESTR in_diff, EventMark mark, s32 *RESTR out_pkcd)
{
	register s32 i, rg;
	register u32 frm;

	frm = 0;
	for (i = 0; i< InnerChannelNumber; i++)
	{
		Prev_Diff[i+8] = rg = in_diff[i] - Prev_Diff[i]; // ��������, ������� ��������� ����� �������
		Prev_Diff[i] = in_diff[i];
		rg = Size(rg);
		if (frm < rg) frm = rg;			//
	};
	frm &= 0x1F;
	return PackFuncs[frm](Prev_Diff+8, mark, frm, out_pkcd);	// 
}
void PackAlg::Reset()
{
	for (s32 i = 0; i < InnerChannelNumber; i++)
	{
		Prev_Diff[i] = 0;
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


s32 PackAlg::Size(s32 rg)// ���������� ������ ����� ������� 
{
		if (rg < 0) rg = ~rg;				//
		//__asm { clz rg ,rg};			// ����������� ������� ������� �������
		rg = clz(rg);					// ����������� �������� �������� �� ���
		rg = 33 - rg;							//	
		return rg;

}
