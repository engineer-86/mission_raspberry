#include "../lib/bit_functions.h"

u_int32_t generate_bitmask()
{
	u_int32_t bitmask = (rand() % 2);
	time_t t;
	srand((unsigned)time(&t));

	for (int i = 0; i < 8; i++)
	{
		bitmask = bitmask * 10;
		int r = (rand() % 2);
		bitmask = (bitmask + r);
	}
	return bitmask;
}
