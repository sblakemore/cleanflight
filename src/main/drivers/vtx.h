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

#pragma once

typedef void (*vtxSetChannelFuncPtr)(uint8_t band, uint8_t channel);
typedef void (*vtxSetFreqFuncPtr)(uint16_t freq);

typedef struct vtx_s {
    vtxSetChannelFuncPtr setChannel;
    vtxSetFreqFuncPtr setFreq;
} vtx_t;

vtx_t vtx;

void vtxDriverInit();
void vtxSetPower(uint8_t power);