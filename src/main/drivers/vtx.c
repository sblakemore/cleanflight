/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Author: Sean Blakemore (sean@impulserc.com)
 *
 * This source code is provided as is and can be used/modified so long
 * as this header is maintained with the file at all times.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "platform.h"

#ifdef VTX

#include "drivers/gpio.h"
#include "drivers/vtx_rtc6705.h"
#include "drivers/vtx.h"

void vtxDriverInit()
{

#ifdef USE_VTX_RTC6705
    rtc6705Init();
    vtx.setChannel = rtc6705SetChannel;
    vtx.setFreq = rtc6705SetFreq;
#endif

#ifdef VTX_POWER
    gpio_config_t cfg;
    cfg.pin = VTX_POWER_PIN;
    cfg.mode = Mode_Out_OD;
    cfg.speed = Speed_2MHz;

    RCC_AHBPeriphClockCmd(VTX_POWER_PERIPHERAL, ENABLE);
    
    gpioInit(VTX_POWER_GPIO, &cfg);
#endif
}

void vtxSetPower(uint8_t power)
{
#ifdef VTX_POWER
    if (power == 0) {
        digitalHi(VTX_POWER_GPIO, VTX_POWER_PIN);
    } else {
        digitalLo(VTX_POWER_GPIO, VTX_POWER_PIN);

    }
#endif
}

#endif

