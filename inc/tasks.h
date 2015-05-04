#ifndef TASKS_H
#define TASKS_H

#include <RTL.h>
#include "TFT_LCD.h"

#define TASK_READ_TS_PERIOD_TICKS (20)  // 1 tick/ms
#define TASK_READ_ACCELEROMETER_PERIOD_TICKS (100)  // 1 tick/ms
#define TASK_SOUND_PERIOD_TICKS (100)  // 1 tick/ms
#define TASK_INCREMENT_PERIOD_TICKS (1000) 
#define TASK_UPDATE_SCREEN_PERIOD_TICKS (100)

// Debug outputs on Port B
#define DEBUG_T0_POS 	0		// J10 pin 2
#define DEBUG_T1_POS 	1 	// J10 pin 4
#define DEBUG_T2_POS 2 	// J10 pin 6
#define DEBUG_T3_POS 	3		// J10 pin 8
#define DEBUG_I0_POS 8 // J9 Pin 1

 void	Init_Debug_Signals(void);

#define EV_PLAYSOUND (1) 
#define EV_SOUND_ON (2)
#define EV_SOUND_OFF (4)

#define EV_REFILL_SOUND (1)

#define WAIT_FOREVER (0xffff)

 __task void Task_Init(void);
 __task void Task_Read_TS(void);
 __task void Task_Read_Accelerometer(void);
 __task void Task_Update_Screen(void);
 
extern OS_TID t_Read_TS, t_Read_Accelerometer, t_Sound_Manager, t_US, t_Refill_Sound_Buffer;

 
// Game Constants
#define PADDLE_WIDTH (40)
#define PADDLE_HEIGHT (15)
#define PADDLE_Y_POS (TFT_HEIGHT-4-PADDLE_HEIGHT)

#define MENU_TILT   (33.0)

#define FALSE (0x00)
#define TRUE  (0x11)
 
#endif // TASKS_H
