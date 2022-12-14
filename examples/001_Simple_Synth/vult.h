
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#ifndef VULT_H
#define VULT_H
#include <stdint.h>
#include <math.h>
#include "vultin.h"
#include "vult.tables.h"

typedef struct _tuple___bool_real__ {
   uint8_t field_0;
   fix16_t field_1;
} _tuple___bool_real__;

typedef struct _tuple___real_real__ {
   fix16_t field_0;
   fix16_t field_1;
} _tuple___real_real__;

typedef struct Util__ctx_type_0 {
   uint8_t pre;
} Util__ctx_type_0;

typedef Util__ctx_type_0 Util_edge_type;

static_inline void Util__ctx_type_0_init(Util__ctx_type_0 &_output_){
   Util__ctx_type_0 _ctx;
   _ctx.pre = false;
   _output_ = _ctx;
   return ;
}

static_inline void Util_edge_init(Util__ctx_type_0 &_output_){
   Util__ctx_type_0_init(_output_);
   return ;
}

static_inline uint8_t Util_edge(Util__ctx_type_0 &_ctx, uint8_t x){
   uint8_t ret;
   ret = (x && bool_not(_ctx.pre));
   _ctx.pre = x;
   return ret;
}

typedef struct Util__ctx_type_1 {
   fix16_t pre_x;
} Util__ctx_type_1;

typedef Util__ctx_type_1 Util_change_type;

static_inline void Util__ctx_type_1_init(Util__ctx_type_1 &_output_){
   Util__ctx_type_1 _ctx;
   _ctx.pre_x = 0x0 /* 0.000000 */;
   _output_ = _ctx;
   return ;
}

static_inline void Util_change_init(Util__ctx_type_1 &_output_){
   Util__ctx_type_1_init(_output_);
   return ;
}

static_inline uint8_t Util_change(Util__ctx_type_1 &_ctx, fix16_t x){
   uint8_t v;
   v = (_ctx.pre_x != x);
   _ctx.pre_x = x;
   return v;
}

static_inline fix16_t Util_map(fix16_t x, fix16_t x0, fix16_t x1, fix16_t y0, fix16_t y1){
   return (y0 + fix_div(fix_mul((x + (- x0)),(y1 + (- y0))),(x1 + (- x0))));
};

typedef struct Util__ctx_type_3 {
   fix16_t y1;
   fix16_t x1;
} Util__ctx_type_3;

typedef Util__ctx_type_3 Util_dcblock_type;

void Util__ctx_type_3_init(Util__ctx_type_3 &_output_);

static_inline void Util_dcblock_init(Util__ctx_type_3 &_output_){
   Util__ctx_type_3_init(_output_);
   return ;
}

fix16_t Util_dcblock(Util__ctx_type_3 &_ctx, fix16_t x0);

typedef struct Util__ctx_type_4 {
   fix16_t x;
} Util__ctx_type_4;

typedef Util__ctx_type_4 Util_smooth_type;

static_inline void Util__ctx_type_4_init(Util__ctx_type_4 &_output_){
   Util__ctx_type_4 _ctx;
   _ctx.x = 0x0 /* 0.000000 */;
   _output_ = _ctx;
   return ;
}

static_inline void Util_smooth_init(Util__ctx_type_4 &_output_){
   Util__ctx_type_4_init(_output_);
   return ;
}

static_inline fix16_t Util_smooth(Util__ctx_type_4 &_ctx, fix16_t input){
   _ctx.x = (_ctx.x + fix_mul(0x147 /* 0.005000 */,(input + (- _ctx.x))));
   return _ctx.x;
}

typedef struct Util__ctx_type_5 {
   fix16_t x0;
} Util__ctx_type_5;

typedef Util__ctx_type_5 Util_average2_type;

static_inline void Util__ctx_type_5_init(Util__ctx_type_5 &_output_){
   Util__ctx_type_5 _ctx;
   _ctx.x0 = 0x0 /* 0.000000 */;
   _output_ = _ctx;
   return ;
}

static_inline void Util_average2_init(Util__ctx_type_5 &_output_){
   Util__ctx_type_5_init(_output_);
   return ;
}

static_inline fix16_t Util_average2(Util__ctx_type_5 &_ctx, fix16_t x1){
   fix16_t result;
   result = ((_ctx.x0 + x1) >> 1);
   _ctx.x0 = x1;
   return result;
}

static_inline fix16_t Util_cubic_clipper(fix16_t x){
   if(x <= -0xaaaa /* -0.666667 */){
      return -0xaaaa /* -0.666667 */;
   }
   else
   {
      if(x >= 0xaaaa /* 0.666667 */){
         return 0xaaaa /* 0.666667 */;
      }
      else
      {
         return (x + fix_mul(fix_mul(fix_mul(-0x5555 /* -0.333333 */,x),x),x));
      }
   }
};

static_inline fix16_t Util_pitchToRate_1024_raw_c0(int index){
   return Util_pitchToRate_1024_c0[index];
};

static_inline fix16_t Util_pitchToRate_1024_raw_c1(int index){
   return Util_pitchToRate_1024_c1[index];
};

static_inline fix16_t Util_pitchToRate_1024_raw_c2(int index){
   return Util_pitchToRate_1024_c2[index];
};

static_inline fix16_t Util_pitchToRate_1024(fix16_t pitch){
   int index;
   index = int_clip(fix_to_int(fix_mul(0x3e7c /* 0.244094 */,pitch)),0,31);
   return (fix_wrap_array(Util_pitchToRate_1024_c0)[index] + fix_mul(pitch,(fix_wrap_array(Util_pitchToRate_1024_c1)[index] + fix_mul(pitch,fix_wrap_array(Util_pitchToRate_1024_c2)[index]))));
}

static_inline fix16_t Util_pitchToRate_raw_c0(int index){
   return Util_pitchToRate_c0[index];
};

static_inline fix16_t Util_pitchToRate_raw_c1(int index){
   return Util_pitchToRate_c1[index];
};

static_inline fix16_t Util_pitchToRate_raw_c2(int index){
   return Util_pitchToRate_c2[index];
};

static_inline fix16_t Util_pitchToRate(fix16_t pitch){
   int index;
   index = int_clip(fix_to_int(fix_mul(0x3e7c /* 0.244094 */,pitch)),0,31);
   return (fix_wrap_array(Util_pitchToRate_c0)[index] + fix_mul(pitch,(fix_wrap_array(Util_pitchToRate_c1)[index] + fix_mul(pitch,fix_wrap_array(Util_pitchToRate_c2)[index]))));
}

static_inline fix16_t Util_cvToPitch(fix16_t cv){
   return (0x180000 /* 24.000000 */ + fix_mul(0x780000 /* 120.000000 */,cv));
};

static_inline fix16_t Util_cvToRate_1024_raw_c0(int index){
   return Util_cvToRate_1024_c0[index];
};

static_inline fix16_t Util_cvToRate_1024_raw_c1(int index){
   return Util_cvToRate_1024_c1[index];
};

static_inline fix16_t Util_cvToRate_1024_raw_c2(int index){
   return Util_cvToRate_1024_c2[index];
};

static_inline fix16_t Util_cvToRate_1024(fix16_t cv){
   int index;
   index = int_clip(fix_to_int(fix_mul(0x2271c7 /* 34.444444 */,cv)),0,31);
   return (fix_wrap_array(Util_cvToRate_1024_c0)[index] + fix_mul(cv,(fix_wrap_array(Util_cvToRate_1024_c1)[index] + fix_mul(cv,fix_wrap_array(Util_cvToRate_1024_c2)[index]))));
}

static_inline fix16_t Util_cvToRate_raw_c0(int index){
   return Util_cvToRate_c0[index];
};

static_inline fix16_t Util_cvToRate_raw_c1(int index){
   return Util_cvToRate_c1[index];
};

static_inline fix16_t Util_cvToRate_raw_c2(int index){
   return Util_cvToRate_c2[index];
};

static_inline fix16_t Util_cvToRate(fix16_t cv){
   int index;
   index = int_clip(fix_to_int(fix_mul(0x8d1c71 /* 141.111111 */,cv)),0,127);
   return (fix_wrap_array(Util_cvToRate_c0)[index] + fix_mul(cv,(fix_wrap_array(Util_cvToRate_c1)[index] + fix_mul(cv,fix_wrap_array(Util_cvToRate_c2)[index]))));
}

static_inline fix16_t Util_pitchToCv(fix16_t pitch){
   return fix_mul(0x222 /* 0.008333 */,(-0x180000 /* -24.000000 */ + pitch));
};

static_inline fix16_t Util_cvToperiod_raw_c0(int index){
   return Util_cvToperiod_c0[index];
};

static_inline fix16_t Util_cvToperiod_raw_c1(int index){
   return Util_cvToperiod_c1[index];
};

static_inline fix16_t Util_cvToperiod_raw_c2(int index){
   return Util_cvToperiod_c2[index];
};

static_inline fix16_t Util_cvToperiod(fix16_t cv){
   int index;
   index = int_clip(fix_to_int(fix_mul(0x1f0000 /* 31.000000 */,cv)),0,31);
   return (fix_wrap_array(Util_cvToperiod_c0)[index] + fix_mul(cv,(fix_wrap_array(Util_cvToperiod_c1)[index] + fix_mul(cv,fix_wrap_array(Util_cvToperiod_c2)[index]))));
}

static_inline fix16_t Util_cvTokHz_raw_c0(int index){
   return Util_cvTokHz_c0[index];
};

static_inline fix16_t Util_cvTokHz_raw_c1(int index){
   return Util_cvTokHz_c1[index];
};

static_inline fix16_t Util_cvTokHz_raw_c2(int index){
   return Util_cvTokHz_c2[index];
};

static_inline fix16_t Util_cvTokHz(fix16_t cv){
   int index;
   index = int_clip(fix_to_int(fix_mul(0x1f0000 /* 31.000000 */,cv)),0,31);
   return (fix_wrap_array(Util_cvTokHz_c0)[index] + fix_mul(cv,(fix_wrap_array(Util_cvTokHz_c1)[index] + fix_mul(cv,fix_wrap_array(Util_cvTokHz_c2)[index]))));
}

typedef struct Adsr__ctx_type_0 {
   fix16_t target;
   int state;
   fix16_t scale;
   fix16_t rate;
   fix16_t out;
   Util__ctx_type_4 _inst955;
   Util__ctx_type_0 _inst251;
} Adsr__ctx_type_0;

typedef Adsr__ctx_type_0 Adsr_do_type;

void Adsr__ctx_type_0_init(Adsr__ctx_type_0 &_output_);

static_inline void Adsr_do_init(Adsr__ctx_type_0 &_output_){
   Adsr__ctx_type_0_init(_output_);
   return ;
}

fix16_t Adsr_do(Adsr__ctx_type_0 &_ctx, fix16_t gate, fix16_t a, fix16_t d, fix16_t s, fix16_t r);

typedef struct Adsr__ctx_type_1 {
   fix16_t knob4;
   fix16_t knob3;
   fix16_t knob2;
   fix16_t knob1;
   Adsr__ctx_type_0 _inst16;
} Adsr__ctx_type_1;

typedef Adsr__ctx_type_1 Adsr_process_type;

void Adsr__ctx_type_1_init(Adsr__ctx_type_1 &_output_);

static_inline void Adsr_process_init(Adsr__ctx_type_1 &_output_){
   Adsr__ctx_type_1_init(_output_);
   return ;
}

static_inline fix16_t Adsr_process(Adsr__ctx_type_1 &_ctx, fix16_t gate){
   return Adsr_do(_ctx._inst16,gate,_ctx.knob1,_ctx.knob2,_ctx.knob3,_ctx.knob4);
};

typedef Adsr__ctx_type_1 Adsr_noteOn_type;

static_inline void Adsr_noteOn_init(Adsr__ctx_type_1 &_output_){
   Adsr__ctx_type_1_init(_output_);
   return ;
}

static_inline void Adsr_noteOn(Adsr__ctx_type_1 &_ctx, int note, int velocity, int channel){
}

typedef Adsr__ctx_type_1 Adsr_noteOff_type;

static_inline void Adsr_noteOff_init(Adsr__ctx_type_1 &_output_){
   Adsr__ctx_type_1_init(_output_);
   return ;
}

static_inline void Adsr_noteOff(Adsr__ctx_type_1 &_ctx, int note, int channel){
}

typedef Adsr__ctx_type_1 Adsr_controlChange_type;

static_inline void Adsr_controlChange_init(Adsr__ctx_type_1 &_output_){
   Adsr__ctx_type_1_init(_output_);
   return ;
}

void Adsr_controlChange(Adsr__ctx_type_1 &_ctx, int control, int value, int channel);

typedef Adsr__ctx_type_1 Adsr_default_type;

static_inline void Adsr_default_init(Adsr__ctx_type_1 &_output_){
   Adsr__ctx_type_1_init(_output_);
   return ;
}

static_inline void Adsr_default(Adsr__ctx_type_1 &_ctx){
   _ctx.knob1 = 0x0 /* 0.000000 */;
   _ctx.knob2 = 0x8000 /* 0.500000 */;
   _ctx.knob3 = 0x10000 /* 1.000000 */;
   _ctx.knob4 = 0x8000 /* 0.500000 */;
}

static_inline fix16_t Saturate_soft_tanh_table_raw_c0(int index){
   return Saturate_soft_tanh_table_c0[index];
};

static_inline fix16_t Saturate_soft_tanh_table_raw_c1(int index){
   return Saturate_soft_tanh_table_c1[index];
};

static_inline fix16_t Saturate_soft_tanh_table_raw_c2(int index){
   return Saturate_soft_tanh_table_c2[index];
};

static_inline fix16_t Saturate_soft_tanh_table(fix16_t x){
   int index;
   index = int_clip(fix_to_int(fix_mul(0x50000 /* 5.000000 */,(0x180000 /* 24.000000 */ + x))),0,240);
   return (fix_wrap_array(Saturate_soft_tanh_table_c0)[index] + fix_mul(x,(fix_wrap_array(Saturate_soft_tanh_table_c1)[index] + fix_mul(x,fix_wrap_array(Saturate_soft_tanh_table_c2)[index]))));
}

static_inline fix16_t Saturate_soft_process(fix16_t x){
   return Saturate_soft_tanh_table(x);
};

static_inline void Saturate_soft_noteOn(int note, int velocity, int channel){
}

static_inline void Saturate_soft_noteOff(int note, int channel){
}

static_inline void Saturate_soft_controlChange(int control, int value, int channel){
}

static_inline void Saturate_soft_default(){
}

static_inline fix16_t Svf_calc_g_raw_c0(int index){
   return Svf_calc_g_c0[index];
};

static_inline fix16_t Svf_calc_g_raw_c1(int index){
   return Svf_calc_g_c1[index];
};

static_inline fix16_t Svf_calc_g_raw_c2(int index){
   return Svf_calc_g_c2[index];
};

static_inline fix16_t Svf_calc_g(fix16_t cv){
   int index;
   index = int_clip(fix_to_int(fix_mul(0x8d1c71 /* 141.111111 */,cv)),0,127);
   return (fix_wrap_array(Svf_calc_g_c0)[index] + fix_mul(cv,(fix_wrap_array(Svf_calc_g_c1)[index] + fix_mul(cv,fix_wrap_array(Svf_calc_g_c2)[index]))));
}

typedef struct Svf__ctx_type_4 {
   fix16_t z2;
   fix16_t z1;
   fix16_t inv_den;
   fix16_t g;
   Util__ctx_type_1 _inst23b;
   Util__ctx_type_1 _inst13b;
   fix16_t R;
} Svf__ctx_type_4;

typedef Svf__ctx_type_4 Svf_process_type;

void Svf__ctx_type_4_init(Svf__ctx_type_4 &_output_);

static_inline void Svf_process_init(Svf__ctx_type_4 &_output_){
   Svf__ctx_type_4_init(_output_);
   return ;
}

fix16_t Svf_process(Svf__ctx_type_4 &_ctx, fix16_t x, fix16_t cv, fix16_t q, int sel);

typedef Svf__ctx_type_4 Svf_noteOn_type;

static_inline void Svf_noteOn_init(Svf__ctx_type_4 &_output_){
   Svf__ctx_type_4_init(_output_);
   return ;
}

static_inline void Svf_noteOn(Svf__ctx_type_4 &_ctx, int note, int velocity, int channel){
}

typedef Svf__ctx_type_4 Svf_noteOff_type;

static_inline void Svf_noteOff_init(Svf__ctx_type_4 &_output_){
   Svf__ctx_type_4_init(_output_);
   return ;
}

static_inline void Svf_noteOff(Svf__ctx_type_4 &_ctx, int note, int channel){
}

typedef Svf__ctx_type_4 Svf_controlChange_type;

static_inline void Svf_controlChange_init(Svf__ctx_type_4 &_output_){
   Svf__ctx_type_4_init(_output_);
   return ;
}

static_inline void Svf_controlChange(Svf__ctx_type_4 &_ctx, int control, int value, int channel){
}

typedef Svf__ctx_type_4 Svf_default_type;

static_inline void Svf_default_init(Svf__ctx_type_4 &_output_){
   Svf__ctx_type_4_init(_output_);
   return ;
}

static_inline void Svf_default(Svf__ctx_type_4 &_ctx){
   _ctx.g = 0x98 /* 0.002330 */;
   _ctx.R = 0x10000 /* 1.000000 */;
   _ctx.inv_den = fix_div(0x10000 /* 1.000000 */,(0x10000 /* 1.000000 */ + fix_mul(_ctx.g,_ctx.g)));
}

typedef struct Sawcore__ctx_type_0 {
   fix16_t ptr_w2_ret_1;
   uint8_t ptr_w2_ret_0;
} Sawcore__ctx_type_0;

typedef Sawcore__ctx_type_0 Sawcore_ptr_w2_type;

void Sawcore__ctx_type_0_init(Sawcore__ctx_type_0 &_output_);

static_inline void Sawcore_ptr_w2_init(Sawcore__ctx_type_0 &_output_){
   Sawcore__ctx_type_0_init(_output_);
   return ;
}

void Sawcore_ptr_w2(Sawcore__ctx_type_0 &_ctx, fix16_t phase, fix16_t rate);

typedef Sawcore__ctx_type_0 Sawcore_ptr_w2_ret_0_type;

static_inline void Sawcore_ptr_w2_ret_0_init(Sawcore__ctx_type_0 &_output_){
   Sawcore__ctx_type_0_init(_output_);
   return ;
}

static_inline uint8_t Sawcore_ptr_w2_ret_0(Sawcore__ctx_type_0 &_ctx){
   return _ctx.ptr_w2_ret_0;
};

typedef Sawcore__ctx_type_0 Sawcore_ptr_w2_ret_1_type;

static_inline void Sawcore_ptr_w2_ret_1_init(Sawcore__ctx_type_0 &_output_){
   Sawcore__ctx_type_0_init(_output_);
   return ;
}

static_inline fix16_t Sawcore_ptr_w2_ret_1(Sawcore__ctx_type_0 &_ctx){
   return _ctx.ptr_w2_ret_1;
};

typedef struct Sawcore__ctx_type_1 {
   uint8_t reset_state;
   fix16_t reset_phase;
   fix16_t rate;
   fix16_t phase;
   Sawcore__ctx_type_0 _inst622;
   Util__ctx_type_0 _inst351;
   Util__ctx_type_1 _inst13b;
} Sawcore__ctx_type_1;

typedef Sawcore__ctx_type_1 Sawcore_process_type;

void Sawcore__ctx_type_1_init(Sawcore__ctx_type_1 &_output_);

static_inline void Sawcore_process_init(Sawcore__ctx_type_1 &_output_){
   Sawcore__ctx_type_1_init(_output_);
   return ;
}

fix16_t Sawcore_process(Sawcore__ctx_type_1 &_ctx, fix16_t cv, fix16_t reset);

typedef Sawcore__ctx_type_1 Sawcore_noteOn_type;

static_inline void Sawcore_noteOn_init(Sawcore__ctx_type_1 &_output_){
   Sawcore__ctx_type_1_init(_output_);
   return ;
}

static_inline void Sawcore_noteOn(Sawcore__ctx_type_1 &_ctx, int note, int velocity, int channel){
}

typedef Sawcore__ctx_type_1 Sawcore_noteOff_type;

static_inline void Sawcore_noteOff_init(Sawcore__ctx_type_1 &_output_){
   Sawcore__ctx_type_1_init(_output_);
   return ;
}

static_inline void Sawcore_noteOff(Sawcore__ctx_type_1 &_ctx, int note, int channel){
}

typedef Sawcore__ctx_type_1 Sawcore_controlChange_type;

static_inline void Sawcore_controlChange_init(Sawcore__ctx_type_1 &_output_){
   Sawcore__ctx_type_1_init(_output_);
   return ;
}

static_inline void Sawcore_controlChange(Sawcore__ctx_type_1 &_ctx, int control, int value, int channel){
}

typedef Sawcore__ctx_type_1 Sawcore_default_type;

static_inline void Sawcore_default_init(Sawcore__ctx_type_1 &_output_){
   Sawcore__ctx_type_1_init(_output_);
   return ;
}

static_inline void Sawcore_default(Sawcore__ctx_type_1 &_ctx){
   _ctx.rate = 0xc265 /* 0.759367 */;
};

typedef struct Dsp__ctx_type_0 {
   fix16_t x;
} Dsp__ctx_type_0;

typedef Dsp__ctx_type_0 Dsp_smooth_type;

static_inline void Dsp__ctx_type_0_init(Dsp__ctx_type_0 &_output_){
   Dsp__ctx_type_0 _ctx;
   _ctx.x = 0x0 /* 0.000000 */;
   _output_ = _ctx;
   return ;
}

static_inline void Dsp_smooth_init(Dsp__ctx_type_0 &_output_){
   Dsp__ctx_type_0_init(_output_);
   return ;
}

static_inline fix16_t Dsp_smooth(Dsp__ctx_type_0 &_ctx, fix16_t input){
   _ctx.x = (_ctx.x + fix_mul(0x147 /* 0.005000 */,(input + (- _ctx.x))));
   return _ctx.x;
}

typedef struct Dsp__ctx_type_1 {
   fix16_t x;
} Dsp__ctx_type_1;

typedef Dsp__ctx_type_1 Dsp_smooth2_type;

static_inline void Dsp__ctx_type_1_init(Dsp__ctx_type_1 &_output_){
   Dsp__ctx_type_1 _ctx;
   _ctx.x = 0x0 /* 0.000000 */;
   _output_ = _ctx;
   return ;
}

static_inline void Dsp_smooth2_init(Dsp__ctx_type_1 &_output_){
   Dsp__ctx_type_1_init(_output_);
   return ;
}

static_inline fix16_t Dsp_smooth2(Dsp__ctx_type_1 &_ctx, fix16_t input){
   _ctx.x = (_ctx.x + fix_mul(0x6 /* 0.000100 */,(input + (- _ctx.x))));
   return _ctx.x;
}

typedef struct Dsp__ctx_type_2 {
   fix16_t pre_x;
} Dsp__ctx_type_2;

typedef Dsp__ctx_type_2 Dsp_change_type;

static_inline void Dsp__ctx_type_2_init(Dsp__ctx_type_2 &_output_){
   Dsp__ctx_type_2 _ctx;
   _ctx.pre_x = 0x0 /* 0.000000 */;
   _output_ = _ctx;
   return ;
}

static_inline void Dsp_change_init(Dsp__ctx_type_2 &_output_){
   Dsp__ctx_type_2_init(_output_);
   return ;
}

static_inline uint8_t Dsp_change(Dsp__ctx_type_2 &_ctx, fix16_t x){
   uint8_t v;
   v = (_ctx.pre_x != x);
   _ctx.pre_x = x;
   return v;
}

typedef struct Dsp__ctx_type_3 {
   uint8_t pre_x;
} Dsp__ctx_type_3;

typedef Dsp__ctx_type_3 Dsp_edge_type;

static_inline void Dsp__ctx_type_3_init(Dsp__ctx_type_3 &_output_){
   Dsp__ctx_type_3 _ctx;
   _ctx.pre_x = false;
   _output_ = _ctx;
   return ;
}

static_inline void Dsp_edge_init(Dsp__ctx_type_3 &_output_){
   Dsp__ctx_type_3_init(_output_);
   return ;
}

static_inline uint8_t Dsp_edge(Dsp__ctx_type_3 &_ctx, uint8_t x){
   uint8_t v;
   v = ((_ctx.pre_x != x) && (_ctx.pre_x == false));
   _ctx.pre_x = x;
   return v;
}

typedef struct Dsp__ctx_type_4 {
   int count;
} Dsp__ctx_type_4;

typedef Dsp__ctx_type_4 Dsp_each_type;

static_inline void Dsp__ctx_type_4_init(Dsp__ctx_type_4 &_output_){
   Dsp__ctx_type_4 _ctx;
   _ctx.count = 0;
   _output_ = _ctx;
   return ;
}

static_inline void Dsp_each_init(Dsp__ctx_type_4 &_output_){
   Dsp__ctx_type_4_init(_output_);
   return ;
}

static_inline uint8_t Dsp_each(Dsp__ctx_type_4 &_ctx, int n){
   uint8_t ret;
   ret = (_ctx.count == 0);
   _ctx.count = ((1 + _ctx.count) % n);
   return ret;
}

static_inline fix16_t Dsp_pitchToRate(fix16_t d){
   return fix_mul(0xc /* 0.000185 */,fix_exp(fix_mul(0xec9 /* 0.057762 */,d)));
};

typedef struct Dsp__ctx_type_6 {
   fix16_t rate;
   fix16_t phase;
   Dsp__ctx_type_2 _inst1e0;
} Dsp__ctx_type_6;

typedef Dsp__ctx_type_6 Dsp_phasor_type;

void Dsp__ctx_type_6_init(Dsp__ctx_type_6 &_output_);

static_inline void Dsp_phasor_init(Dsp__ctx_type_6 &_output_){
   Dsp__ctx_type_6_init(_output_);
   return ;
}

fix16_t Dsp_phasor(Dsp__ctx_type_6 &_ctx, fix16_t pitch, uint8_t reset);

typedef struct Dsp__ctx_type_7 {
   fix16_t phase;
   Dsp__ctx_type_3 _inst1aa;
} Dsp__ctx_type_7;

typedef Dsp__ctx_type_7 Dsp_lfo_type;

void Dsp__ctx_type_7_init(Dsp__ctx_type_7 &_output_);

static_inline void Dsp_lfo_init(Dsp__ctx_type_7 &_output_){
   Dsp__ctx_type_7_init(_output_);
   return ;
}

fix16_t Dsp_lfo(Dsp__ctx_type_7 &_ctx, fix16_t f, uint8_t gate);

typedef struct Dsp__ctx_type_8 {
   fix16_t pre_phase1;
   Dsp__ctx_type_6 _inst36f;
   Dsp__ctx_type_0 _inst228;
   Dsp__ctx_type_6 _inst16f;
} Dsp__ctx_type_8;

typedef Dsp__ctx_type_8 Dsp_phd_osc_type;

void Dsp__ctx_type_8_init(Dsp__ctx_type_8 &_output_);

static_inline void Dsp_phd_osc_init(Dsp__ctx_type_8 &_output_){
   Dsp__ctx_type_8_init(_output_);
   return ;
}

fix16_t Dsp_phd_osc(Dsp__ctx_type_8 &_ctx, fix16_t pitch, fix16_t detune);

typedef struct Dsp__ctx_type_9 {
   int write_pos;
   fix16_t buffer[32000];
} Dsp__ctx_type_9;

typedef Dsp__ctx_type_9 Dsp_delay_type;

void Dsp__ctx_type_9_init(Dsp__ctx_type_9 &_output_);

static_inline void Dsp_delay_init(Dsp__ctx_type_9 &_output_){
   Dsp__ctx_type_9_init(_output_);
   return ;
}

fix16_t Dsp_delay(Dsp__ctx_type_9 &_ctx, fix16_t x, fix16_t time, fix16_t feedback);

typedef struct Dsp__ctx_type_10 {
   int write_pos;
   fix16_t buffer[256];
} Dsp__ctx_type_10;

typedef Dsp__ctx_type_10 Dsp_combFilter_type;

void Dsp__ctx_type_10_init(Dsp__ctx_type_10 &_output_);

static_inline void Dsp_combFilter_init(Dsp__ctx_type_10 &_output_){
   Dsp__ctx_type_10_init(_output_);
   return ;
}

fix16_t Dsp_combFilter(Dsp__ctx_type_10 &_ctx, fix16_t x, fix16_t time);

typedef struct Dsp__ctx_type_11 {
   int pre;
   int notes[4];
   int count;
} Dsp__ctx_type_11;

typedef Dsp__ctx_type_11 Dsp_mono_noteOn_type;

void Dsp__ctx_type_11_init(Dsp__ctx_type_11 &_output_);

static_inline void Dsp_mono_noteOn_init(Dsp__ctx_type_11 &_output_){
   Dsp__ctx_type_11_init(_output_);
   return ;
}

int Dsp_mono_noteOn(Dsp__ctx_type_11 &_ctx, int n);

typedef Dsp__ctx_type_11 Dsp_mono_noteOff_type;

static_inline void Dsp_mono_noteOff_init(Dsp__ctx_type_11 &_output_){
   Dsp__ctx_type_11_init(_output_);
   return ;
}

int Dsp_mono_noteOff(Dsp__ctx_type_11 &_ctx, int n);

typedef Dsp__ctx_type_11 Dsp_mono_isGateOn_type;

static_inline void Dsp_mono_isGateOn_init(Dsp__ctx_type_11 &_output_){
   Dsp__ctx_type_11_init(_output_);
   return ;
}

static_inline uint8_t Dsp_mono_isGateOn(Dsp__ctx_type_11 &_ctx){
   return (_ctx.count > 0);
};

typedef struct Dsp__ctx_type_12 {
   fix16_t target;
   int state;
   fix16_t rate;
   fix16_t out;
   fix16_t hold_phase;
   fix16_t env_drum_ret_1;
   fix16_t env_drum_ret_0;
   Util__ctx_type_0 _inst351;
   Util__ctx_type_0 _inst151;
} Dsp__ctx_type_12;

typedef Dsp__ctx_type_12 Dsp_env_drum_type;

void Dsp__ctx_type_12_init(Dsp__ctx_type_12 &_output_);

static_inline void Dsp_env_drum_init(Dsp__ctx_type_12 &_output_){
   Dsp__ctx_type_12_init(_output_);
   return ;
}

void Dsp_env_drum(Dsp__ctx_type_12 &_ctx, fix16_t gate, fix16_t a, fix16_t h, fix16_t d);

typedef Dsp__ctx_type_12 Dsp_env_drum_ret_0_type;

static_inline void Dsp_env_drum_ret_0_init(Dsp__ctx_type_12 &_output_){
   Dsp__ctx_type_12_init(_output_);
   return ;
}

static_inline fix16_t Dsp_env_drum_ret_0(Dsp__ctx_type_12 &_ctx){
   return _ctx.env_drum_ret_0;
};

typedef Dsp__ctx_type_12 Dsp_env_drum_ret_1_type;

static_inline void Dsp_env_drum_ret_1_init(Dsp__ctx_type_12 &_output_){
   Dsp__ctx_type_12_init(_output_);
   return ;
}

static_inline fix16_t Dsp_env_drum_ret_1(Dsp__ctx_type_12 &_ctx){
   return _ctx.env_drum_ret_1;
};

typedef struct Dsp__ctx_type_13 {
   fix16_t out;
   Util__ctx_type_0 _inst151;
} Dsp__ctx_type_13;

typedef Dsp__ctx_type_13 Dsp_env_swept_type;

void Dsp__ctx_type_13_init(Dsp__ctx_type_13 &_output_);

static_inline void Dsp_env_swept_init(Dsp__ctx_type_13 &_output_){
   Dsp__ctx_type_13_init(_output_);
   return ;
}

fix16_t Dsp_env_swept(Dsp__ctx_type_13 &_ctx, fix16_t gate, fix16_t start, fix16_t end, fix16_t rate);

typedef struct Dsp__ctx_type_14 {
   uint8_t reset_state;
   fix16_t reset_phase;
   fix16_t rate;
   fix16_t phase;
   uint8_t direction;
   Util__ctx_type_0 _inst451;
   Util__ctx_type_0 _inst351;
   Util__ctx_type_1 _inst13b;
} Dsp__ctx_type_14;

typedef Dsp__ctx_type_14 Dsp_tricore_type;

void Dsp__ctx_type_14_init(Dsp__ctx_type_14 &_output_);

static_inline void Dsp_tricore_init(Dsp__ctx_type_14 &_output_){
   Dsp__ctx_type_14_init(_output_);
   return ;
}

fix16_t Dsp_tricore(Dsp__ctx_type_14 &_ctx, fix16_t cv, fix16_t reset, fix16_t disable);

static_inline fix16_t Dsp_saturate_table_raw_c0(int index){
   return Dsp_saturate_table_c0[index];
};

static_inline fix16_t Dsp_saturate_table_raw_c1(int index){
   return Dsp_saturate_table_c1[index];
};

static_inline fix16_t Dsp_saturate_table_raw_c2(int index){
   return Dsp_saturate_table_c2[index];
};

static_inline fix16_t Dsp_saturate_table(fix16_t x){
   int index;
   index = int_clip(fix_to_int(fix_mul(0x18000 /* 1.500000 */,x)),0,9);
   return (fix_wrap_array(Dsp_saturate_table_c0)[index] + fix_mul(x,(fix_wrap_array(Dsp_saturate_table_c1)[index] + fix_mul(x,fix_wrap_array(Dsp_saturate_table_c2)[index]))));
}

fix16_t Dsp_saturate(fix16_t x);

typedef struct Dsp__ctx_type_20 {
   fix16_t w1;
} Dsp__ctx_type_20;

typedef Dsp__ctx_type_20 Dsp_pinker_type;

static_inline void Dsp__ctx_type_20_init(Dsp__ctx_type_20 &_output_){
   Dsp__ctx_type_20 _ctx;
   _ctx.w1 = 0x0 /* 0.000000 */;
   _output_ = _ctx;
   return ;
}

static_inline void Dsp_pinker_init(Dsp__ctx_type_20 &_output_){
   Dsp__ctx_type_20_init(_output_);
   return ;
}

fix16_t Dsp_pinker(Dsp__ctx_type_20 &_ctx, fix16_t x);

typedef struct Dsp__ctx_type_21 {
   int x2;
   int x1;
   Dsp__ctx_type_20 _inst123;
} Dsp__ctx_type_21;

typedef Dsp__ctx_type_21 Dsp_osc_noisef_type;

void Dsp__ctx_type_21_init(Dsp__ctx_type_21 &_output_);

static_inline void Dsp_osc_noisef_init(Dsp__ctx_type_21 &_output_){
   Dsp__ctx_type_21_init(_output_);
   return ;
}

fix16_t Dsp_osc_noisef(Dsp__ctx_type_21 &_ctx, uint8_t color);

typedef struct Dsp__ctx_type_22 {
   Dsp__ctx_type_21 _inst53d;
   Dsp__ctx_type_12 _inst41f;
   Dsp__ctx_type_14 _inst37;
   Dsp__ctx_type_13 _inst2e8;
   Dsp__ctx_type_12 _inst11f;
} Dsp__ctx_type_22;

typedef Dsp__ctx_type_22 Dsp_unit_drum_type;

void Dsp__ctx_type_22_init(Dsp__ctx_type_22 &_output_);

static_inline void Dsp_unit_drum_init(Dsp__ctx_type_22 &_output_){
   Dsp__ctx_type_22_init(_output_);
   return ;
}

fix16_t Dsp_unit_drum(Dsp__ctx_type_22 &_ctx, fix16_t gate, fix16_t odecay, fix16_t pitch, fix16_t swept, fix16_t noise);

typedef struct Dsp__ctx_type_23 {
   int i;
   fix16_t buffer[2400];
} Dsp__ctx_type_23;

typedef Dsp__ctx_type_23 Dsp_delay_600_type;

void Dsp__ctx_type_23_init(Dsp__ctx_type_23 &_output_);

static_inline void Dsp_delay_600_init(Dsp__ctx_type_23 &_output_){
   Dsp__ctx_type_23_init(_output_);
   return ;
}

fix16_t Dsp_delay_600(Dsp__ctx_type_23 &_ctx, fix16_t x, int n);

typedef struct Dsp__ctx_type_24 {
   fix16_t pre_y;
   fix16_t pre_x;
   Dsp__ctx_type_23 _inst28;
   Dsp__ctx_type_23 _inst18;
} Dsp__ctx_type_24;

typedef Dsp__ctx_type_24 Dsp_ap_type;

void Dsp__ctx_type_24_init(Dsp__ctx_type_24 &_output_);

static_inline void Dsp_ap_init(Dsp__ctx_type_24 &_output_){
   Dsp__ctx_type_24_init(_output_);
   return ;
}

fix16_t Dsp_ap(Dsp__ctx_type_24 &_ctx, fix16_t x, fix16_t g, int n);

typedef struct Dsp__ctx_type_25 {
   Dsp__ctx_type_24 _inst4a9;
   Dsp__ctx_type_24 _inst3a9;
   Dsp__ctx_type_24 _inst2a9;
   Dsp__ctx_type_24 _inst1a9;
} Dsp__ctx_type_25;

typedef Dsp__ctx_type_25 Dsp_reverb_type;

void Dsp__ctx_type_25_init(Dsp__ctx_type_25 &_output_);

static_inline void Dsp_reverb_init(Dsp__ctx_type_25 &_output_){
   Dsp__ctx_type_25_init(_output_);
   return ;
}

fix16_t Dsp_reverb(Dsp__ctx_type_25 &_ctx, fix16_t x);

typedef struct Dsp__ctx_type_26 {
   fix16_t wetdry;
   fix16_t volume;
   fix16_t vca_sustain;
   fix16_t vca_release;
   fix16_t vca_decay;
   fix16_t vca_attack;
   fix16_t time;
   fix16_t pitchBend;
   fix16_t pitch;
   Dsp__ctx_type_11 notes;
   uint8_t mute;
   fix16_t lfo_rate;
   fix16_t lfo_amt;
   fix16_t filter_sustain;
   fix16_t filter_resonance;
   fix16_t filter_release;
   fix16_t filter_env_amt;
   fix16_t filter_decay;
   fix16_t filter_cutoff;
   fix16_t filter_attack;
   fix16_t feedback;
   fix16_t detune;
   Dsp__ctx_type_0 _inst928;
   Dsp__ctx_type_0 _inst828;
   Svf__ctx_type_4 _inst712;
   Adsr__ctx_type_0 _inst66;
   Adsr__ctx_type_0 _inst56;
   Dsp__ctx_type_0 _inst428;
   Sawcore__ctx_type_1 _inst31b;
   Sawcore__ctx_type_1 _inst21b;
   Dsp__ctx_type_7 _inst15a;
   Dsp__ctx_type_9 _inst10c7;
} Dsp__ctx_type_26;

typedef Dsp__ctx_type_26 Dsp_process_type;

void Dsp__ctx_type_26_init(Dsp__ctx_type_26 &_output_);

static_inline void Dsp_process_init(Dsp__ctx_type_26 &_output_){
   Dsp__ctx_type_26_init(_output_);
   return ;
}

fix16_t Dsp_process(Dsp__ctx_type_26 &_ctx, fix16_t input);

typedef Dsp__ctx_type_26 Dsp_noteOn_type;

static_inline void Dsp_noteOn_init(Dsp__ctx_type_26 &_output_){
   Dsp__ctx_type_26_init(_output_);
   return ;
}

static_inline void Dsp_noteOn(Dsp__ctx_type_26 &_ctx, int note, int velocity, int channel){
   _ctx.mute = false;
   _ctx.pitch = int_to_fix(Dsp_mono_noteOn(_ctx.notes,note));
}

typedef Dsp__ctx_type_26 Dsp_noteOff_type;

static_inline void Dsp_noteOff_init(Dsp__ctx_type_26 &_output_){
   Dsp__ctx_type_26_init(_output_);
   return ;
}

static_inline void Dsp_noteOff(Dsp__ctx_type_26 &_ctx, int note, int channel){
   _ctx.pitch = int_to_fix(Dsp_mono_noteOff(_ctx.notes,note));
};

typedef Dsp__ctx_type_26 Dsp_controlChange_type;

static_inline void Dsp_controlChange_init(Dsp__ctx_type_26 &_output_){
   Dsp__ctx_type_26_init(_output_);
   return ;
}

void Dsp_controlChange(Dsp__ctx_type_26 &_ctx, int control, int value, int channel);

typedef Dsp__ctx_type_26 Dsp_pitchBend_type;

static_inline void Dsp_pitchBend_init(Dsp__ctx_type_26 &_output_){
   Dsp__ctx_type_26_init(_output_);
   return ;
}

static_inline void Dsp_pitchBend(Dsp__ctx_type_26 &_ctx, int value){
   _ctx.pitchBend = fix_mul(0x10 /* 0.000244 */,int_to_fix(value));
};

typedef Dsp__ctx_type_26 Dsp_default_type;

static_inline void Dsp_default_init(Dsp__ctx_type_26 &_output_){
   Dsp__ctx_type_26_init(_output_);
   return ;
}

void Dsp_default(Dsp__ctx_type_26 &_ctx);



#endif // VULT_H
