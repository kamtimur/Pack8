enum EventMark
{
	ECG = 1, 	//- ECG
	REO,		//-	REO
	AC�_IN,		//-	AC�_IN
	AC�_EXT,	//-	AC�_EXT
	APT,		//-	APT
	PULSE,		//-	PULSE
	TON,		//-	TON
	SPO			//- SPO
};
#define RESTR __restrict 
//s32 size(s32 rg)	// ���������� ������ ����� ������� 
//{
//	if (rg < 0) rg = ~rg;				//
//	__asm { CLZ rg, rg };			// ����������� ������� ������� �������
//	rg = 33 - rg;							//	
//	return rg;
//};
u32 pack8(const s32* RESTR in_diff, EventMark mark, s32 num_bits, s32* RESTR out_pkcd);
