/*
 * robomaster_utils.h
 *
 *  Created on: Dec 10, 2024
 *      Author: motii
 */

#ifndef INC_ROBOMASTER_UTILS_H_
#define INC_ROBOMASTER_UTILS_H_

#include <array>

namespace robomaster
{
	enum RoboMasterType
	{
		M3508,
		M2006
	};

	class RoboMasterHandler
	{
		public:
		RoboMasterHandler()
		{
			for(int i = 0; i < 8; i++)
			{
				txBuf1[i] = 0x00;
				txBuf2[i] = 0x00;
			}
		}

		void setCurrent(int id, RoboMasterType type, int16_t current)
		{
			int16_t target_current = 0;
			if(type == RoboMasterType::M2006)
			{
				if(current > m2006_max_current)
				{
					target_current = m2006_max_current;
				}
				else if(current < -1.0*m2006_max_current)
				{
					target_current = -1.0 * m2006_max_current;
				}
				else
				{
					target_current = current;
				}
			}
			else if(type == RoboMasterType::M3508)
			{
				if(current > m3508_max_current)
				{
					target_current = m3508_max_current;
				}
				else if(current < -1.0*m3508_max_current)
				{
					target_current = -1.0 * m3508_max_current;
				}
				else
				{
					target_current = current;
				}
			}

			if(id < 5)
			{
				txBuf1[2*id-2] = (target_current >> 8) & 0xFF;
				txBuf1[2*id-1] = target_current & 0xFF;
			}
		}

		std::array<uint8_t, 8> getTxBuf()
		{

		}

		private:
		uint8_t txBuf1[8];
		uint8_t txBuf2[8];
		const int16_t m3508_max_current = 16384;
		const int16_t m2006_max_current = 10000;
	};
}


#endif /* INC_ROBOMASTER_UTILS_H_ */
