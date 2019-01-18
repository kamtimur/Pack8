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

#include "pack2.h"
#include "unpack2.h"

#include "pack1.h"
#include "unpack1.h"

//функция проверки паковки распаковки 
//num_unpack_funcs - кол-во функций распаковки 
//max_capacity - максимальная разрядность(кол -во значащих бит) сигнала проверки(sin)
template<typename Pack>
s32 Test(Pack* pack_alg, Unpacker* unpack, s32 num_unpack_funcs, s32 max_capacity);
s32 signal[8];
s32 packed[8];
long unpacked[8];
s32 prev_signal[8];
s32 diff_signal[8];
int main()
{


	//PackAlg pack8(8, pack8Funcs);
	//Unpacker unpack8(8, unpack8Funcs);
	//pack8.Reset();
	//unpack8.Reset();

	//PackAlg pack4(4, pack4Funcs);
	//Unpacker unpack4(4, unpack4Funcs);
	//pack4.Reset();
	//unpack4.Reset();

	//PackAlg pack3(3, pack3Funcs);
	//Unpacker unpack3(3, unpack3Funcs);
	//pack3.Reset();
	//unpack3.Reset();

	//PackAlg pack2(2, pack2Funcs);
	//Unpacker unpack2(2, unpack2Funcs);
	//pack2.Reset();
	//unpack2.Reset();

	//PackAlg pack1(1, pack1Funcs);
	//Unpacker unpack1(1, unpack1Funcs);
	//pack1.Reset();
	//unpack1.Reset();
	//PackAlg<8, type_pack_func*, &> packAlg;

	PackAlg<4, type_pack_funcs, (type_pack_funcs*)pack4Funcs> pack4;
	Unpacker unpack4(4, unpack4Funcs);
	pack4.Reset();
	unpack4.Reset();

	//if (Test(&pack8, &unpack8, 14,20))
	//{
	//	printf("Test passed for %d channels\n", pack8.InnerChannelNumber);
	//}

	if (Test(&pack4, &unpack4, 12, 24))
	{
		printf("Test passed for %d channels\n", pack4.InnerChannelNumber);
	}

	//if (Test(&pack3, &unpack3, 9, 24))
	//{
	//	printf("Test passed for %d channels\n", pack3.InnerChannelNumber);
	//}
	//if (Test(&pack2, &unpack2, 6, 24))
	//{
	//	printf("Test passed for %d channels\n", pack2.InnerChannelNumber);
	//}
	//if (Test(&pack4, &unpack4, 3, 24))
	//{
	//	printf("Test passed for %d channels\n", pack1.InnerChannelNumber);
	//}
	return 0;
}

//функция проверки паковки распаковки 
//num_unpack_funcs - кол-во функций распаковки 
//max_capacity - максимальная разрядность(кол -во значащих бит) сигнала проверки(sin)
template<typename Pack>
s32 Test(Pack* pack_alg, Unpacker* unpack, s32 num_unpack_funcs, s32 max_capacity)
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