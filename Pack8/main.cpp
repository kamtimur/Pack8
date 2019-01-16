#include "types.h"
#include "stdio.h"
#include <cmath>

#include "Pack.h"
#include "PackAlg.h"
#include "Unpacker.h"

#include "Pack8.h"
#include "Unpack8.h"

#include "Pack4.h"
#include "Unpack4.h"

#include "pack3.h"
#include "unpack3.h"

//функция проверки паковки распаковки 
//num_unpack_funcs - кол-во функций распаковки 
//max_capacity - максимальная разрядность(кол -во значащих бит) сигнала проверки(sin)
s32 Test(PackAlg* pack_alg, Unpacker* unpack, s32 num_unpack_funcs, s32 max_capacity);
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

	PackAlg pack4(4, pack4Funcs);
	Unpacker unpack4(4, unpack4Funcs);
	pack4.Reset();
	unpack4.Reset();

	PackAlg pack3(3, pack3Funcs);
	Unpacker unpack3(4, unpack3Funcs);
	pack3.Reset();
	unpack3.Reset();

	if (Test(&pack8, &unpack8, 14,20))
	{
		printf("Test passed for %d channels\n", pack8.InnerChannelNumber);
	}

	if (Test(&pack4, &unpack4, 12, 24))
	{
		printf("Test passed for %d channels\n", pack4.InnerChannelNumber);
	}

	if (Test(&pack3, &unpack3, 9, 24))
	{
		printf("Test passed for %d channels\n", pack3.InnerChannelNumber);
	}
	return 0;
}

//функция проверки паковки распаковки 
//num_unpack_funcs - кол-во функций распаковки 
//max_capacity - максимальная разрядность(кол -во значащих бит) сигнала проверки(sin)
s32 Test(PackAlg* pack_alg, Unpacker* unpack, s32 num_unpack_funcs, s32 max_capacity)
{

	s32 pack_used[20];
	s32 num_channels = pack_alg->InnerChannelNumber;
	s32 cnt = 1;
	s32 amplitude = pow(2, max_capacity - 1);
	memset(signal, 0, num_channels*4);
	memset(pack_used, 0, 20 * 4);
	while (true)
	{
		s32 ret_pack = pack_alg->Pack(signal, (EventMark)ECG, packed);
		s32 ret_unpack = unpack->Unpack((unsigned char*)packed, unpacked);

		for (int i = 0; i < num_channels; i++)
		{
			if (signal[i] != unpacked[i])
			{
				printf("error pack %d ", ret_pack);
				printf("error unpack %d\n", ret_unpack);
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
			return 1;
		}
		for (int i = 0; i < num_channels; i++)
		{
			prev_signal[i] = signal[i];
			signal[i] = sin(cnt) * amplitude;
			diff_signal[i] = signal[i] - prev_signal[i];
		}
		cnt++;
	}
	return 0;
}