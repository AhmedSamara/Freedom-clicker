#include <stdint.h>
#include <stdio.h>
#include <math.h>

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

OS_TID t_Read_TS, t_Read_Accelerometer, t_Sound_Manager, t_US, t_Refill_Sound_Buffer,t_Update_Count;
OS_MUT LCD_mutex;
OS_MUT TS_mutex;

OS_MUT count_mutex;
OS_MUT increment_mutex;

os_mbx_declare(acc_mbx,16);

int rune_count=0;
int rune_increment = 0;

char menu_mode = FALSE;
//corners of rune ore.
PT_T rp1, rp2;


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



__task void Task_Increment_runes(void)
{
  char buffer[16];

  os_itv_set(TASK_INCREMENT_PERIOD_TICKS);
  
  

  //TFT_Fill_Rectangle
  while(1){
    os_itv_wait();
    rune_count += rune_increment;
    sprintf(buffer,"runes: %d",rune_count);
    
    os_mut_wait(&LCD_mutex, WAIT_FOREVER);
    TFT_Text_PrintStr_RC(0,0,buffer);
    os_mut_release(&LCD_mutex);

  }
}


__task void Task_Init(void) {
	os_mut_init(&LCD_mutex);

	t_Read_TS = os_tsk_create(Task_Read_TS, 4);
	t_Read_Accelerometer = os_tsk_create_user(Task_Read_Accelerometer, 3, RA_Stack, 512);
	t_Sound_Manager = os_tsk_create(Task_Sound_Manager, 2); // Should be lower priority than Refill Sound Buffer
	t_US = os_tsk_create(Task_Update_Screen, 5);
	t_Refill_Sound_Buffer = os_tsk_create(Task_Refill_Sound_Buffer, 1);
  
  t_Update_Count = os_tsk_create(Task_Increment_runes,6);
  
  os_tsk_delete_self ();
}

char tap_flg = TRUE;
char touch_flg = TRUE;

char first_touch = TRUE;

__task void Task_Read_TS(void) {
	PT_T p, pp, tp1, tp2;
	COLOR_T c;
  char buffer[16];
	
	c.R = 150;
	c.G = 200;
	c.B = 255;
	
	os_itv_set(TASK_READ_TS_PERIOD_TICKS);

  os_mut_wait(&LCD_mutex, WAIT_FOREVER);

	TFT_Text_PrintStr_RC(TFT_MAX_ROWS, 0, "Mute");
	TFT_Text_PrintStr_RC(TFT_MAX_ROWS, 12, "Unmute");
	
  os_mbx_init(&acc_mbx,sizeof(acc_mbx));
  
  
  os_mut_release(&LCD_mutex);


	while (1) {
		os_itv_wait();
		PTB->PSOR = MASK(DEBUG_T1_POS);

		if (TFT_TS_Read(&p)) { 
			// Send message indicating screen was pressed
			// os_evt_set(EV_PLAYSOUND, t_Sound);
      
      //Check if buying item from the menu

      if(menu_mode && tap_flg)
      {
        /*
        tp1.X = 0;
        tp1.Y = ROW_TO_Y(IRON_POS);
        
        tp2.X = TFT_WIDTH-1;
        tp2.Y = ROW_TO_Y(IRON_POS)+CHAR_HEIGHT;
        
        TFT_Fill_Rectangle(&tp1,&tp2,&c);
        */
        
        if( p.Y > ROW_TO_Y(IRON_POS) && p.Y < ROW_TO_Y(IRON_POS)+ CHAR_HEIGHT && (rune_count  > IRON_COST))
        {
          os_mut_wait(&increment_mutex, WAIT_MEH);
          rune_count -= IRON_COST;
          rune_increment += IRON_BONUS;
          tap_flg=FALSE;
          os_mut_release(&increment_mutex);

        }
        if( p.Y > ROW_TO_Y(MITH_POS) && p.Y < ROW_TO_Y(MITH_POS)+ CHAR_HEIGHT && rune_count > MITH_COST)
        {
          os_mut_wait(&increment_mutex, WAIT_MEH);
          rune_count -= MITH_COST;
          rune_increment += MITH_BONUS;
          tap_flg=FALSE;
          os_mut_release(&increment_mutex);

        }
        if( p.Y > ROW_TO_Y(RUNE_POS) && p.Y < ROW_TO_Y(RUNE_POS)+ CHAR_HEIGHT && rune_count > RUNE_COST)
        {
          os_mut_wait(&increment_mutex, WAIT_MEH);
          rune_count -= RUNE_COST;
          rune_increment += IRON_BONUS;
          tap_flg=FALSE;
          os_mut_release(&increment_mutex);
        }
        
        sprintf(buffer,"speed: %d rps",rune_increment);
       
				os_mut_wait(&LCD_mutex, WAIT_MEH);
        TFT_Text_PrintStr_RC(1,0,buffer);
        os_mut_release(&LCD_mutex);
        
      }

      //Check if rune click
      if(p.X > rp1.X && p.Y > rp1.Y
        && p.X < rp2.X && p.Y < rp2.Y
        && !menu_mode)
      {
        if(tap_flg){
          rune_count++;
          sprintf(buffer,"runes: %d", rune_count);
          TFT_Text_PrintStr_RC(0,0,buffer);
          tap_flg=FALSE; //be sure to not update more than once.
        }
      } 
    
			if (p.Y > 270) { 
				if (p.X < TFT_WIDTH/2) {
					Sound_Disable_Amp();
				} else {
					Sound_Enable_Amp();
				}
			} 

		} else {
			pp.X = 0;
			pp.Y = 0;
      tap_flg=TRUE;
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
	//int16_t paddle_pos=TFT_WIDTH/2;
  //int16_t paddle_y_pos = TFT_HEIGHT-4-PADDLE_HEIGHT;
  
	COLOR_T rune_color, black;
  PT_T center;
  char clr_flg = FALSE;

	
  //build rune square.
  rp1.X = TFT_WIDTH * 1/4;
  rp1.Y = TFT_HEIGHT * 1/4;

  rp2.X = TFT_WIDTH * 3/4 ;
  rp2.Y = TFT_HEIGHT * 3/4;

  rune_color.R=10;
  rune_color.B=200;
  rune_color.G=200;

  TFT_Fill_Rectangle(&rp1,&rp2,&rune_color);
  
  center.X = TFT_WIDTH/2;
  center.Y = TFT_HEIGHT/2;
  
  draw_pick(&center);
	
	os_itv_set(TASK_UPDATE_SCREEN_PERIOD_TICKS);
  
  //flg used to ensure only clears screen once.
  

	while (1) {
		os_itv_wait();
		PTB->PSOR = MASK(DEBUG_T3_POS);

		if ((roll < -MENU_TILT) || (roll > MENU_TILT) 
        || (pitch < -MENU_TILT) || (pitch > MENU_TILT)) {

       menu_mode = TRUE;
       //bring up menu when screen is tilted.
       TFT_Text_PrintStr_RC(IRON_POS,0,"Iron pick.......10");
       TFT_Text_PrintStr_RC(MITH_POS,0,"Mithril pick....50");
       TFT_Text_PrintStr_RC(RUNE_POS,0,"Rune pick.......100");
       clr_flg = TRUE;

		}
    else if (clr_flg)
    {
       menu_mode=FALSE;
       clr_flg = FALSE;
       TFT_Text_PrintStr_RC(5,0,"                   ");
       TFT_Text_PrintStr_RC(7,0,"                   ");
       TFT_Text_PrintStr_RC(9,0,"                   ");
       TFT_Fill_Rectangle(&rp1,&rp2,&rune_color);
       draw_pick(&center);

    }  

		PTB->PCOR = MASK(DEBUG_T3_POS);

	}
}



