#include "types.h"
#include "Pack.h"
#include "stdio.h"

#define SIGNCH(a,m) if((a)&(m)){(a)|=(0xffffffff ^ ((m)-1));}




int main()
{
	s32 signal[8] = {6,4,2,5,7,-3,-5,-6};
	s32 packed[8];
	long unpacked[8];
	s32* tmp = packed;
	u32 ret=pack8(signal, ECG, 4, packed);
	UnPackB8_4((unsigned char*)packed, unpacked);
	for (int i = 0; i < 8; i++)
	{
		if (signal[i] != unpacked[i])
		{
			printf("error %d", ret);
			return 0;
		}
	}
	return 0;
}