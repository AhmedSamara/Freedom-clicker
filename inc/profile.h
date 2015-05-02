#ifndef PROFILE_H
#define PROFILE_H

#define RET_ADX_OFFSET (0x18)
#define CUR_FRAME_SIZE (8)  // 0 if var is initialized as first auto var 

#define DISABLE_PROFILING { profiling_enabled--;}
#define ENABLE_PROFILING { profiling_enabled++;}

extern volatile char profiling_enabled;

 void Init_Profiling(void);

 void Disable_Profiling(void);
 void Enable_Profiling(void);
 void Sort_Profile_Regions(void);

 void Display_Profile(void);

#endif
