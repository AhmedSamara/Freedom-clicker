#ifndef TFT_LCD_H
#define TFT_LCD_H

#include <stdint.h>

#define TFT_WIDTH (240)
#define TFT_HEIGHT (320)

// TFT LCD Hardware Interface
// signals -- all on port C
#define TFT_DB8_POS (3)
#define TFT_DB15_POS (10)
#define TFT_D_NC_POS (12)
#define TFT_NWR_POS (13)
#define TFT_NRD_POS (16)
#define TFT_NRST_POS (17)
#define TFT_DATA_MASK (((unsigned )0x0ff) << TFT_DB8_POS)

// Backlight
#define TFT_BL_TPM (TPM1)
#define TFT_BL_TPM_CHANNEL (0)
#define TFT_BL_TPM_FREQ (20000)
#define TFT_BL_PERIOD ((SystemCoreClock)/(2*(TFT_BL_TPM_FREQ)))

// Touchscreen Hardware Interface
#define TFT_TS_YD_CHANNEL (0)
#define TFT_TS_YU_CHANNEL (3)
#define TFT_TS_XL_CHANNEL (4) 
#define TFT_TS_XR_CHANNEL (7)

#define TFT_TS_YD_BIT (20)
#define TFT_TS_XL_BIT (21)
#define TFT_TS_YU_BIT (22)
#define TFT_TS_XR_BIT (23)

// Touchscreen Configuration
#define TS_DELAY (1)
#define TS_CALIB_SAMPLES (10)

/**************************************************************/
#define	GPIO_ResetBit(pos)	(FPTC->PCOR = MASK(pos))
#define	GPIO_SetBit(pos) 		(FPTC->PSOR = MASK(pos))
#define GPIO_Write(cmd) 		FPTC->PDOR &= ~TFT_DATA_MASK; \
														FPTC->PDOR |= (cmd & 0xff) << TFT_DB8_POS;
/**************************************************************/

#define MIN(a,b) ((a)<(b)? a : b)
#define MAX(a,b) ((a)>(b)? a : b)

typedef struct {
	uint32_t X, Y;
} PT_T;

typedef struct {
	uint8_t R, G, B; // note: using 5-6-5 color mode for LCD. 
									 // Values are left aligned here
} COLOR_T;


 void TFT_Init(void);
 void TFT_Fill_Buffer(COLOR_T * color);
 void TFT_Fill_Rectangle(PT_T * p1, PT_T * p2, COLOR_T * color);
 uint32_t TFT_Start_Rectangle(PT_T * p1, PT_T * p2);
 void TFT_Write_Rectangle_Pixel(COLOR_T * color, unsigned int count);


 void TFT_Plot_Pixel(PT_T * pos, COLOR_T * color);
 void TFT_Set_BL(uint8_t on);
 void TFT_Set_Brightness(uint8_t brightness);
 void TFT_Set_Backlight_Brightness(uint16_t brightness_percent);
 void TFT_Set_Colors(COLOR_T * foreground, COLOR_T * background);

 void TFT_Erase(void);
 void TFT_Text_Init(uint8_t font_num);
 void TFT_Text_PrintChar(PT_T * pos, char ch);
 void TFT_Text_PrintStr(PT_T * pos, char * str);
 void TFT_Text_PrintStr_RC( uint8_t  row, uint8_t col, char *  str);

 void Graphics_Test(void);
 void TFT_Draw_Line(PT_T * p1, PT_T * p2, COLOR_T * color);


 void TFT_TS_Init(void);
 uint32_t TFT_TS_Read(PT_T * position);
 void TFT_TS_Test(void);
 void TFT_TS_Calibrate(void);

 extern uint8_t G_TFT_char_width, G_TFT_char_height;


  

#endif
