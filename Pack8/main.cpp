#include "types.h"
#include "stdio.h"
#include <cmath>

#include "Pack.h"
#include "Pack8.h"
#include "PackAlg.h"
#include "Unpack8.h"


s32 signal[8] = { 0,0,0,0,0,0,0,0 };
s32 prev_signal[8];
s32 diff_signal[8];
s32 packed[8];
s32 prev[8];
s32 current[8];
long unpacked[8];

s32 pack_used[15];

int main()
{


	PackAlg pack8(8, pack8Funcs);
	pack8.Reset();
	s32 cnt = 1;

	for (int i = 0; i < 8; i++)
	{
		prev[i] = signal[i];
	}

	memset(pack_used, 0, 15);
	while (true)
	{
		s32 ret_pack = pack8.Pack(signal, (EventMark)ECG, packed);
		s32 ret_unpack = unpack8((unsigned char*)packed, unpacked);

		for (int i = 0; i < 8; i++)
		{
			current[i] = unpacked[i] + prev[i];
			prev[i] = current[i];
		}

		for (int i = 0; i < 8; i++)
		{
			if (signal[i] != current[i])
			{
				printf("error pack %d ", ret_pack);
				printf("error unpack %d", ret_unpack);
				return 0;
			}
			else
			{
				printf("good pack %d", ret_pack);
				printf("good unpack %d\n", ret_unpack);
			}
		}
		pack_used[ret_pack - 1]++;
		for (int i = 0; i < 8; i++)
		{
			prev_signal[i] = signal[i];
			signal[i] = (sin(cnt))*0x7FFFF ;
			diff_signal[i] = signal[i] - prev_signal[i];
		}
		cnt++;
	}

	return 0;
}