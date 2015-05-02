#ifndef FONT_H
#define FONT_H
#include <stdint.h>

typedef struct {
	uint8_t FontID;
	uint8_t Orientation;
	uint16_t FirstChar;
	uint16_t LastChar;
	uint8_t Height;
	uint8_t Reserved;
} FONT_HEADER_T;

typedef struct {
	uint32_t Width:8; // pixels
	uint32_t Offset:24; // Offset from start of table
} GLYPH_INDEX_T;

extern const uint8_t Lucida_Console8x13[];
extern const uint8_t Lucida_Console12x19[];
extern const uint8_t Lucida_Console20x31[];

#define CHAR_WIDTH G_TFT_char_width 
#define CHAR_HEIGHT G_TFT_char_height 

#define ROW_TO_Y(r) ((r)*G_TFT_char_height)
#define COL_TO_X(c) ((c)*G_TFT_char_width)

#define TFT_MAX_COLS (TFT_WIDTH/G_TFT_char_width)
#define TFT_MAX_ROWS (TFT_HEIGHT/G_TFT_char_height)


#endif // #ifndef FONT_H
