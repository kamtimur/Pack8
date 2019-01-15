#include "types.h"
#include "stdio.h"
#include <cmath>

#include "Pack.h"
#include "Pack8.h"
#include "PackAlg.h"
#include "Unpack8.h"
#include "Unpacker.h"


s32 Test(PackAlg* pack_alg, Unpacker* unpack, s32 num_unpack_funcs);
s32 signal[8];
s32 packed[8];
long unpacked[8];
s32 prev_signal[8];
s32 diff_signal[8];
int main()
{


	PackAlg pack8(8, pack8Funcs);
	Unpacker unpack8(8, unpack8Funcs);
	pack8.Reset();
	unpack8.Reset();

	if (Test(&pack8, &unpack8, 14))
	{
		printf("Test passed for %d channels", pack8.InnerChannelNumber);
	}

	return 0;
}


s32 Test(PackAlg* pack_alg, Unpacker* unpack, s32 num_unpack_funcs)
{

	s32 pack_used[20];
	s32 num_channels = pack_alg->InnerChannelNumber;
	s32 test_passed = 0;
	s32 cnt = 1;

	memset(signal, 0, num_channels);
	for (int i = 0; i < 20; i++)
	{
		pack_used[i] = 0;
	}

	while (true)
	{
		s32 ret_pack = pack_alg->Pack(signal, (EventMark)ECG, packed);
		s32 ret_unpack = unpack->Unpack((unsigned char*)packed, unpacked);

		for (int i = 0; i < num_channels; i++)
		{
			if (signal[i] != unpacked[i])
			{
				printf("error pack %d ", ret_pack);
				printf("error unpack %d", ret_unpack);
				return 0;
			}
		}
		pack_used[ret_pack-2]++;
		s32 count = 0;
		for (int i = 0; i < num_unpack_funcs; i++)
		{
			if (pack_used[i] != 0)
			{
				count++;
			}
		}
		if (count == num_unpack_funcs)
		{
			test_passed = 1;
			return 1;
		}
		for (int i = 0; i < 8; i++)
		{
			prev_signal[i] = signal[i];
			signal[i] = (sin(cnt)) * 0x7FFFF;
			diff_signal[i] = signal[i] - prev_signal[i];
		}
		cnt++;
	}
	return 0;
}