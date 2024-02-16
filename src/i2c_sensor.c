#include "../lib/i2c_sensor.h"

#define rMAX 10

u_int16_t init_sensor()
{
	m_date = 10;
	// does nothing :)
	// would do something if there actually would be a sensor
	printf("Radiation Sensor ready\n \n");
	return 0;
}

int16_t get_radiation_data()
{
	// deviation in uSv

	if (rand() % 2 == 1)
	{
		m_date = m_date + (rand() % rMAX);
	}
	else
	{
		m_date = m_date - (rand() % rMAX);
	}

		return abs(m_date);
}