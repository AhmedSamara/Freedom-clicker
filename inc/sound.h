#ifndef SOUND_H
#define SOUND_H

#include <stdint.h>
#include <RTL.h>

// On Port E
#define AMP_ENABLE_POS (29)
#define DAC_POS (30)
#define MAX_DAC_CODE (4095)
#define NUM_STEPS (64)
#define NUM_WAVEFORM_SAMPLES (512)


#define AUDIO_SAMPLE_FREQ (22000.0)
#define AUDIO_SAMPLE_PERIOD_US (1000000/AUDIO_SAMPLE_FREQ)

#define FREQ_TO_PERIOD(f) (AUDIO_SAMPLE_FREQ/(f))

// Voice type definitions
typedef enum {VW_UNINIT, VW_NOISE, VW_SQUARE, VW_SINE} VW_E;

typedef struct {
	uint16_t Volume; // scaled by 65536
	int16_t Decay; // scaled by 65536. 0 means no decay in volume.
	uint32_t Duration; // measured in samples
	uint32_t Counter; // internal, measured in samples (for sine, is scaled by 256)
	uint32_t CounterIncrement; // for sine only: internal, samples scaled by 256 
	uint16_t Period; // measured in samples
	VW_E Type; // Sine, square, white noise
} VOICE_T;

#define NUM_VOICES (8)

typedef struct {
	uint32_t Volume, Frequency, Decay, Duration, Delay;
} NOTE_T;

void DAC_Init(void);
void Play_Tone(void);
void Sound_Init(void);

void Sound_Enable_Amp(void);
void Sound_Disable_Amp(void);

// void Play_Tone_with_DMA(unsigned int period, unsigned int num_cycles);
void Sound_Refill_Buffer(uint32_t samples);
void Play_Waveform_with_DMA(void);

 __task void Task_Sound_Manager(void);
 __task void Task_Refill_Sound_Buffer(void);

#endif // SOUND_H
