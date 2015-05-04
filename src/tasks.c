#include <stdint.h>
#include <stdio.h>
#include <RTL.h>
#include <MKL25Z4.h>

#include "TFT_LCD.h"
#include "font.h"
#include "tasks.h"
#include "MMA8451.h"
#include "sound.h"
#include "DMA.h"
#include "gpio_defs.h"


U64 RA_Stack[64];

OS_TID t_Read_TS, t_Read_Accelerometer, t_Sound_Manager, t_US, t_Refill_Sound_Buffer;
OS_MUT LCD_mutex;
OS_MUT TS_mutex;
int rune_count=0;
int rune_increment = 1;

extern COLOR_T red,green,blue;

void Init_Debug_Signals(void) {
	// Enable clock to port B
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	
	// Make pins GPIO
	PORTB->PCR[DEBUG_T0_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DEBUG_T0_POS] |= PORT_PCR_MUX(1);          
	PORTB->PCR[DEBUG_T1_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DEBUG_T1_POS] |= PORT_PCR_MUX(1);          
	PORTB->PCR[DEBUG_T2_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DEBUG_T2_POS] |= PORT_PCR_MUX(1);          
	PORTB->PCR[DEBUG_T3_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DEBUG_T3_POS] |= PORT_PCR_MUX(1);          

	PORTB->PCR[DEBUG_I0_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DEBUG_I0_POS] |= PORT_PCR_MUX(1);          

	
	// Set ports to outputs
	PTB->PDDR |= MASK(DEBUG_T0_POS);
	PTB->PDDR |= MASK(DEBUG_T1_POS);
	PTB->PDDR |= MASK(DEBUG_T2_POS);
	PTB->PDDR |= MASK(DEBUG_T3_POS);
	PTB->PDDR |= MASK(DEBUG_I0_POS);
	
	// Initial values are 0
	PTB->PCOR = MASK(DEBUG_T0_POS);
	PTB->PCOR = MASK(DEBUG_T1_POS);
	PTB->PCOR = MASK(DEBUG_T2_POS);
	PTB->PCOR = MASK(DEBUG_T3_POS);
	PTB->PCOR = MASK(DEBUG_I0_POS);

}	


__task void Increment_runes(void)
{
  os_itv_set(TASK_INCREMENT_PERIOD_TICKS);
  
  while(1){
    
  }
}

__task void Task_Init(void) {
	os_mut_init(&LCD_mutex);

	t_Read_TS = os_tsk_create(Task_Read_TS, 4);
	t_Read_Accelerometer = os_tsk_create_user(Task_Read_Accelerometer, 3, RA_Stack, 512);
	t_Sound_Manager = os_tsk_create(Task_Sound_Manager, 2); // Should be lower priority than Refill Sound Buffer
	t_US = os_tsk_create(Task_Update_Screen, 5);
	t_Refill_Sound_Buffer = os_tsk_create(Task_Refill_Sound_Buffer, 1);

  os_tsk_delete_self ();
}

__task void Task_Read_TS(void) {
	PT_T p, pp;
	COLOR_T c;
	
	c.R = 150;
	c.G = 200;
	c.B = 255;
	
	os_itv_set(TASK_READ_TS_PERIOD_TICKS);

	TFT_Text_PrintStr_RC(TFT_MAX_ROWS-3, 0, "Mute");
	TFT_Text_PrintStr_RC(TFT_MAX_ROWS-3, 12, "Unmute");
	
	while (1) {
		os_itv_wait();
		PTB->PSOR = MASK(DEBUG_T1_POS);
		if (TFT_TS_Read(&p)) { 
			// Send message indicating screen was pressed
			// os_evt_set(EV_PLAYSOUND, t_Sound);

			if (p.Y > 240) { 
				if (p.X < TFT_WIDTH/2) {
					Sound_Disable_Amp();
				} else {
					Sound_Enable_Amp();
				}
			} else {
				// Now draw on screen
				if ((pp.X == 0) && (pp.Y == 0)) {
					pp = p;
				}
				os_mut_wait(&LCD_mutex, WAIT_FOREVER);
				TFT_Draw_Line(&p, &pp, &c);
				os_mut_release(&LCD_mutex);
				pp = p;
			} 
		} else {
			pp.X = 0;
			pp.Y = 0;
		}
		PTB->PCOR = MASK(DEBUG_T1_POS);
	}
}

__task void Task_Read_Accelerometer(void) {
	char buffer[16];
	
	os_itv_set(TASK_READ_ACCELEROMETER_PERIOD_TICKS);

	while (1) {
		os_itv_wait();
		PTB->PSOR = MASK(DEBUG_T0_POS);
		read_full_xyz();
		convert_xyz_to_roll_pitch();

		sprintf(buffer, "Roll: %6.2f", roll);
		os_mut_wait(&LCD_mutex, WAIT_FOREVER);
		TFT_Text_PrintStr_RC(2, 0, buffer);
		os_mut_release(&LCD_mutex);

		sprintf(buffer, "Pitch: %6.2f", pitch);
		os_mut_wait(&LCD_mutex, WAIT_FOREVER);
		TFT_Text_PrintStr_RC(3, 0, buffer);
		os_mut_release(&LCD_mutex);

		PTB->PCOR = MASK(DEBUG_T0_POS);
	}
}







__task void Task_Update_Screen(void) {
	int16_t paddle_pos=TFT_WIDTH/2;
  int16_t paddle_y_pos = TFT_HEIGHT-4-PADDLE_HEIGHT;
  
	PT_T p1, p2;
	COLOR_T paddle_color, black;
  char clr_flg = FALSE;

	
	paddle_color.R = 100;
	paddle_color.G = 200;
	paddle_color.B = 50;

	black.R = 0;
	black.G = 0;
	black.B = 0;
	
	os_itv_set(TASK_UPDATE_SCREEN_PERIOD_TICKS);
  
  //flg used to insure only clears screen once.

	while (1) {
		os_itv_wait();
		PTB->PSOR = MASK(DEBUG_T3_POS);
    
    
		
		if ((roll < -MENU_TILT) || (roll > MENU_TILT) 
        || (pitch < -MENU_TILT) || (pitch > MENU_TILT)) {

       //bring up menu when screen is tilted.
       TFT_Text_PrintStr_RC(5,0,"Iron pick.......10");
       TFT_Text_PrintStr_RC(7,0,"Mithril pick....50");
       TFT_Text_PrintStr_RC(9,0,"Rune pick.......100");
       clr_flg=TRUE;
		}
    else if (clr_flg)
    {
       clr_flg=FALSE;
       TFT_Text_PrintStr_RC(5,0,"                   ");
       TFT_Text_PrintStr_RC(7,0,"                   ");
       TFT_Text_PrintStr_RC(9,0,"                   ");
      
    }
      /*
      p1.X = 0;
      p1.Y = TFT_HEIGHT/4;
      
      p2.X = TFT_WIDTH-1;
      p2.Y = TFT_HEIGHT;
      
      TFT_Fill_Rectangle(&p1,&p2,&red);
    */
    /*
    if ((pitch < -2.0) || (pitch > 2.0))
    {
      //p1.X = paddle_pos;
			p1.Y = paddle_y_pos;
			p2.X = p1.X + PADDLE_WIDTH;
			p2.Y = p1.Y + PADDLE_HEIGHT;
			TFT_Fill_Rectangle(&p1, &p2, &black); 		
			
			paddle_y_pos += pitch;
			paddle_y_pos = MAX(0, paddle_y_pos);
			paddle_y_pos = MIN(paddle_y_pos, TFT_HEIGHT-1);
			
			//p1.X = paddle_pos;
			p1.Y = paddle_y_pos;
			p2.X = p1.X + PADDLE_WIDTH;
			p2.Y = p1.Y + PADDLE_HEIGHT;
			TFT_Fill_Rectangle(&p1, &p2, &red); 	
      
    }
    */
    
		
		PTB->PCOR = MASK(DEBUG_T3_POS);
	}
}
