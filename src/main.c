/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
#include <MKL25Z4.H>
#include <stdio.h>
#include "gpio_defs.h"

#include "tft_lcd.h"
#include "font.h"

#include "LEDs.h"
#include "timers.h"
#include "sound.h"
#include "DMA.h"

#include "I2C.h"
#include "mma8451.h"
#include "delay.h"
#include "profile.h"
#include "math.h"

#include <RTL.h>
#include "tasks.h"

#define USE_GFX_LCD

int main (void) {

  PT_T tp1;
  COLOR_T black;
  
  Init_colors();
  
  black.R=0;
  black.G=0;
  black.B=0;
  
  tp1.X = 320;
  tp1.Y = 240;
  
	Init_Debug_Signals();
	Init_RGB_LEDs();
	Sound_Init();	
	// Sound_Disable_Amp();
	Play_Tone();
	
	TFT_Init();
	TFT_Text_Init(1);
	TFT_Erase();
	
//	TFT_TS_Calibrate();
//	TFT_TS_Test();

	TFT_Text_PrintStr_RC(1,0, "Accel...");

	i2c_init();											// init I2C peripheral
	if (!init_mma()) {							// init accelerometer
		Control_RGB_LEDs(1,0,0);			// accel initialization failed, so turn on red error light
		while (1)
			;
	}
	TFT_Text_PrintStr_RC(1,9, "Done");

	Delay(70);

	os_sys_init(&Task_Init);

  TFT_Plot_Pixel(&tp1,&black);
  
	while (1)
    ;
}

// *******************************ARM University Program Copyright © ARM Ltd 2013*************************************   
