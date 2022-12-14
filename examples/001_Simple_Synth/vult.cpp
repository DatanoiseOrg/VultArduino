
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#include "vult.h"

void Util__ctx_type_3_init(Util__ctx_type_3 &_output_){
   Util__ctx_type_3 _ctx;
   _ctx.y1 = 0x0 /* 0.000000 */;
   _ctx.x1 = 0x0 /* 0.000000 */;
   _output_ = _ctx;
   return ;
}

fix16_t Util_dcblock(Util__ctx_type_3 &_ctx, fix16_t x0){
   fix16_t y0;
   y0 = (x0 + (- _ctx.x1) + fix_mul(0xfeb8 /* 0.995000 */,_ctx.y1));
   _ctx.x1 = x0;
   _ctx.y1 = y0;
   return y0;
}

void Adsr__ctx_type_0_init(Adsr__ctx_type_0 &_output_){
   Adsr__ctx_type_0 _ctx;
   _ctx.target = 0x0 /* 0.000000 */;
   _ctx.state = 0;
   _ctx.scale = 0x0 /* 0.000000 */;
   _ctx.rate = 0x0 /* 0.000000 */;
   _ctx.out = 0x0 /* 0.000000 */;
   Util__ctx_type_4_init(_ctx._inst955);
   Util__ctx_type_0_init(_ctx._inst251);
   _output_ = _ctx;
   return ;
}

fix16_t Adsr_do(Adsr__ctx_type_0 &_ctx, fix16_t gate, fix16_t a, fix16_t d, fix16_t s, fix16_t r){
   fix16_t a_rate;
   a_rate = fix_div(0x10000 /* 1.000000 */,(0x28f /* 0.010000 */ + fix_mul(0x640000 /* 100.000000 */,a)));
   fix16_t d_rate;
   d_rate = fix_div(0x10000 /* 1.000000 */,(0x28f /* 0.010000 */ + fix_mul(0x640000 /* 100.000000 */,d)));
   fix16_t r_rate;
   r_rate = fix_div(0x10000 /* 1.000000 */,(0x28f /* 0.010000 */ + fix_mul(0x640000 /* 100.000000 */,r)));
   _ctx.out = (_ctx.out + fix_mul(fix_mul(0x106 /* 0.004000 */,_ctx.rate),(_ctx.target + (- _ctx.out))));
   uint8_t bgate;
   bgate = (gate > 0x0 /* 0.000000 */);
   if(_ctx.state == 0){
      if(Util_edge(_ctx._inst251,bgate)){
         _ctx.state = 1;
         _ctx.scale = fix_mul(0x3333 /* 0.200000 */,gate);
      }
      _ctx.rate = r_rate;
      _ctx.target = 0x0 /* 0.000000 */;
   }
   if(_ctx.state == 1){
      if(bool_not(bgate)){
         _ctx.state = 0;
      }
      if(_ctx.out > 0x4000000 /* 1024.000000 */){
         _ctx.state = 2;
      }
      _ctx.rate = a_rate;
      _ctx.target = 0x4cccccc /* 1228.800000 */;
   }
   if(_ctx.state == 2){
      if(bool_not(bgate)){
         _ctx.state = 0;
      }
      _ctx.rate = d_rate;
      _ctx.target = (s << 10);
   }
   return fix_mul(Util_smooth(_ctx._inst955,_ctx.scale),fix_clip((_ctx.out >> 10),0x0 /* 0.000000 */,0x10000 /* 1.000000 */));
}

void Adsr__ctx_type_1_init(Adsr__ctx_type_1 &_output_){
   Adsr__ctx_type_1 _ctx;
   _ctx.knob4 = 0x0 /* 0.000000 */;
   _ctx.knob3 = 0x0 /* 0.000000 */;
   _ctx.knob2 = 0x0 /* 0.000000 */;
   _ctx.knob1 = 0x0 /* 0.000000 */;
   Adsr__ctx_type_0_init(_ctx._inst16);
   _output_ = _ctx;
   return ;
}

void Adsr_controlChange(Adsr__ctx_type_1 &_ctx, int control, int value, int channel){
   if(control == 1){
      _ctx.knob1 = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 2){
      _ctx.knob2 = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 3){
      _ctx.knob3 = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 4){
      _ctx.knob4 = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
}

void Svf__ctx_type_4_init(Svf__ctx_type_4 &_output_){
   Svf__ctx_type_4 _ctx;
   _ctx.z2 = 0x0 /* 0.000000 */;
   _ctx.z1 = 0x0 /* 0.000000 */;
   _ctx.inv_den = 0x0 /* 0.000000 */;
   _ctx.g = 0x0 /* 0.000000 */;
   Util__ctx_type_1_init(_ctx._inst23b);
   Util__ctx_type_1_init(_ctx._inst13b);
   _ctx.R = 0x0 /* 0.000000 */;
   Svf_default(_ctx);
   _output_ = _ctx;
   return ;
}

fix16_t Svf_process(Svf__ctx_type_4 &_ctx, fix16_t x, fix16_t cv, fix16_t q, int sel){
   q = (0x8000 /* 0.500000 */ + q);
   if(Util_change(_ctx._inst13b,cv) || Util_change(_ctx._inst23b,q)){
      _ctx.g = Svf_calc_g(cv);
      _ctx.R = fix_div(0x10000 /* 1.000000 */,((0x0 /* 0.000000 */ + q) << 1));
      _ctx.inv_den = fix_div(0x10000 /* 1.000000 */,(0x10000 /* 1.000000 */ + fix_mul(_ctx.g,_ctx.g) + (fix_mul(_ctx.R,_ctx.g) << 1)));
   }
   fix16_t high;
   high = fix_mul(_ctx.inv_den,(x + (- _ctx.z2) + (- fix_mul(_ctx.z1,(_ctx.g + (_ctx.R << 1))))));
   fix16_t band;
   band = (_ctx.z1 + fix_mul(_ctx.g,high));
   fix16_t low;
   low = (_ctx.z2 + fix_mul(_ctx.g,band));
   fix16_t notch;
   notch = (high + low);
   _ctx.z1 = (band + fix_mul(_ctx.g,high));
   _ctx.z2 = (low + fix_mul(_ctx.g,band));
   fix16_t output;
   switch(sel) {
      case 0:
         output = low;
      break;
      case 1:
         output = high;
      break;
      case 2:
         output = band;
      break;
    default: 
      output = notch;
   }
   return Saturate_soft_process(output);
}

void Sawcore__ctx_type_0_init(Sawcore__ctx_type_0 &_output_){
   Sawcore__ctx_type_0 _ctx;
   _ctx.ptr_w2_ret_1 = 0x0 /* 0.000000 */;
   _ctx.ptr_w2_ret_0 = false;
   _output_ = _ctx;
   return ;
}

void Sawcore_ptr_w2(Sawcore__ctx_type_0 &_ctx, fix16_t phase, fix16_t rate){
   _tuple___bool_real__ out;
   fix16_t s1;
   s1 = rate;
   fix16_t s2;
   s2 = (rate + s1);
   if(phase < s1){
      fix16_t d;
      d = fix_div(phase,rate);
      fix16_t t2;
      t2 = (s2 >> 10);
      {
         out.field_0 = false;
         out.field_1 = (0x10000 /* 1.000000 */ + fix_mul(d,(t2 + (- d))));
      }
   }
   else
   {
      if(phase < s2){
         fix16_t d;
         d = fix_div(phase,rate);
         fix16_t t2;
         t2 = (s2 >> 10);
         {
            out.field_0 = false;
            out.field_1 = (0x30000 /* 3.000000 */ + fix_mul(d,(-0x40000 /* -4.000000 */ + d + t2)));
         }
      }
      else
      {
         out.field_0 = true;
         out.field_1 = 0x0 /* 0.000000 */;
      }
   }
   _ctx.ptr_w2_ret_0 = out.field_0;_ctx.ptr_w2_ret_1 = out.field_1;
   return ;
}

void Sawcore__ctx_type_1_init(Sawcore__ctx_type_1 &_output_){
   Sawcore__ctx_type_1 _ctx;
   _ctx.reset_state = false;
   _ctx.reset_phase = 0x0 /* 0.000000 */;
   _ctx.rate = 0x0 /* 0.000000 */;
   _ctx.phase = 0x0 /* 0.000000 */;
   Sawcore__ctx_type_0_init(_ctx._inst622);
   Util__ctx_type_0_init(_ctx._inst351);
   Util__ctx_type_1_init(_ctx._inst13b);
   Sawcore_default(_ctx);
   _output_ = _ctx;
   return ;
}

fix16_t Sawcore_process(Sawcore__ctx_type_1 &_ctx, fix16_t cv, fix16_t reset){
   fix16_t transition;
   transition = 0x0 /* 0.000000 */;
   fix16_t out;
   out = 0x0 /* 0.000000 */;
   if(Util_change(_ctx._inst13b,cv)){
      _ctx.rate = Util_cvToRate_1024(cv);
   }
   fix16_t new_phase;
   new_phase = (_ctx.phase + _ctx.rate);
   uint8_t do_reset;
   do_reset = Util_edge(_ctx._inst351,(reset > 0x0 /* 0.000000 */));
   uint8_t do_wrap;
   do_wrap = (new_phase > 0x4000000 /* 1024.000000 */);
   if(do_reset || do_wrap){
      _ctx.reset_phase = _ctx.phase;
      if(do_wrap){
         new_phase = (-0x4000000 /* -1024.000000 */ + new_phase);
      }
      else
      {
         new_phase = 0x0 /* 0.000000 */;
      }
      _ctx.reset_state = true;
   }
   _ctx.phase = new_phase;
   out = _ctx.phase;
   if(_ctx.reset_state){
      uint8_t done;
      fix16_t ptr;
      Sawcore_ptr_w2(_ctx._inst622,_ctx.phase,_ctx.rate);
      done = Sawcore_ptr_w2_ret_0(_ctx._inst622);
      ptr = Sawcore_ptr_w2_ret_1(_ctx._inst622);
      transition = (fix_mul(_ctx.reset_phase,(0x10000 /* 1.000000 */ + ptr)) >> 1);
      if(done){
         _ctx.reset_state = false;
      }
      else
      {
         out = transition;
      }
   }
   return (-0x10000 /* -1.000000 */ + (out >> 9));
}

void Dsp__ctx_type_6_init(Dsp__ctx_type_6 &_output_){
   Dsp__ctx_type_6 _ctx;
   _ctx.rate = 0x0 /* 0.000000 */;
   _ctx.phase = 0x0 /* 0.000000 */;
   Dsp__ctx_type_2_init(_ctx._inst1e0);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_phasor(Dsp__ctx_type_6 &_ctx, fix16_t pitch, uint8_t reset){
   if(Dsp_change(_ctx._inst1e0,pitch)){
      _ctx.rate = Dsp_pitchToRate(pitch);
   }
   if(reset){
      _ctx.phase = 0x0 /* 0.000000 */;
   }
   else
   {
      _ctx.phase = ((_ctx.phase + _ctx.rate) % 0x10000 /* 1.000000 */);
   }
   return _ctx.phase;
}

void Dsp__ctx_type_7_init(Dsp__ctx_type_7 &_output_){
   Dsp__ctx_type_7 _ctx;
   _ctx.phase = 0x0 /* 0.000000 */;
   Dsp__ctx_type_3_init(_ctx._inst1aa);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_lfo(Dsp__ctx_type_7 &_ctx, fix16_t f, uint8_t gate){
   fix16_t rate;
   rate = fix_mul(0xe /* 0.000227 */,f);
   if(Dsp_edge(_ctx._inst1aa,gate)){
      _ctx.phase = 0x0 /* 0.000000 */;
   }
   _ctx.phase = (_ctx.phase + rate);
   if(_ctx.phase > 0x10000 /* 1.000000 */){
      _ctx.phase = (-0x10000 /* -1.000000 */ + _ctx.phase);
   }
   return (-0x8000 /* -0.500000 */ + fix_sin(fix_mul(0x6487e /* 6.283185 */,_ctx.phase)));
}

void Dsp__ctx_type_8_init(Dsp__ctx_type_8 &_output_){
   Dsp__ctx_type_8 _ctx;
   _ctx.pre_phase1 = 0x0 /* 0.000000 */;
   Dsp__ctx_type_6_init(_ctx._inst36f);
   Dsp__ctx_type_0_init(_ctx._inst228);
   Dsp__ctx_type_6_init(_ctx._inst16f);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_phd_osc(Dsp__ctx_type_8 &_ctx, fix16_t pitch, fix16_t detune){
   fix16_t phase1;
   phase1 = Dsp_phasor(_ctx._inst16f,pitch,false);
   fix16_t comp;
   comp = (0x10000 /* 1.000000 */ + (- phase1));
   uint8_t reset;
   reset = ((_ctx.pre_phase1 + (- phase1)) > 0x8000 /* 0.500000 */);
   _ctx.pre_phase1 = phase1;
   fix16_t phase2;
   phase2 = Dsp_phasor(_ctx._inst36f,(pitch + (Dsp_smooth(_ctx._inst228,detune) << 5)),reset);
   fix16_t sine;
   sine = fix_sin(fix_mul(0x6487e /* 6.283185 */,phase2));
   return fix_mul(comp,sine);
}

void Dsp__ctx_type_9_init(Dsp__ctx_type_9 &_output_){
   Dsp__ctx_type_9 _ctx;
   _ctx.write_pos = 0;
   ;
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_delay(Dsp__ctx_type_9 &_ctx, fix16_t x, fix16_t time, fix16_t feedback){
   time = fix_clip(time,0x0 /* 0.000000 */,0x10000 /* 1.000000 */);
   feedback = fix_clip(feedback,0x0 /* 0.000000 */,0x10000 /* 1.000000 */);
   fix16_t index_r;
   index_r = fix_mul(0x7d000000 /* 32000.000000 */,time);
   int index_i;
   index_i = fix_to_int(fix_floor(index_r));
   int delta;
   delta = (_ctx.write_pos + (- index_i));
   int read_pos;
   if(delta < 0){
      read_pos = (32000 + delta);
   }
   else
   {
      read_pos = delta;
   }
   fix16_t decimal;
   decimal = (index_r + (- int_to_fix(index_i)));
   fix16_t x1;
   x1 = fix_get(_ctx.buffer,read_pos);
   fix16_t x2;
   x2 = fix_get(_ctx.buffer,((1 + read_pos) % 32000));
   fix16_t ret;
   ret = (x1 + fix_mul(decimal,(x2 + (- x1))));
   _ctx.write_pos = ((1 + _ctx.write_pos) % 32000);
   fix_set(_ctx.buffer,_ctx.write_pos,fix_clip((x + fix_mul(feedback,ret)),-0x10000 /* -1.000000 */,0x10000 /* 1.000000 */));
   return ret;
}

void Dsp__ctx_type_10_init(Dsp__ctx_type_10 &_output_){
   Dsp__ctx_type_10 _ctx;
   _ctx.write_pos = 0;
   fix_init_array(256,0x0 /* 0.000000 */,_ctx.buffer);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_combFilter(Dsp__ctx_type_10 &_ctx, fix16_t x, fix16_t time){
   time = fix_clip(time,0x0 /* 0.000000 */,0x10000 /* 1.000000 */);
   fix16_t index_r;
   index_r = (time << 8);
   int index_i;
   index_i = fix_to_int(fix_floor(index_r));
   int delta;
   delta = (_ctx.write_pos + (- index_i));
   int read_pos;
   if(delta < 0){
      read_pos = (256 + delta);
   }
   else
   {
      read_pos = delta;
   }
   fix16_t decimal;
   decimal = (index_r + (- int_to_fix(index_i)));
   fix16_t x1;
   x1 = fix_get(_ctx.buffer,read_pos);
   fix16_t x2;
   x2 = fix_get(_ctx.buffer,((1 + read_pos) % 256));
   fix16_t y;
   y = (x1 + fix_mul(decimal,(x2 + (- x1))));
   _ctx.write_pos = ((1 + _ctx.write_pos) % 256);
   fix_set(_ctx.buffer,_ctx.write_pos,x);
   return (x + fix_mul(-0x10000 /* -1.000000 */,y));
}

void Dsp__ctx_type_11_init(Dsp__ctx_type_11 &_output_){
   Dsp__ctx_type_11 _ctx;
   _ctx.pre = 0;
   int_init_array(4,0,_ctx.notes);
   _ctx.count = 0;
   _output_ = _ctx;
   return ;
}

int Dsp_mono_noteOn(Dsp__ctx_type_11 &_ctx, int n){
   if(_ctx.count < 4){
      int_set(_ctx.notes,_ctx.count,n);
      _ctx.pre = n;
      if(_ctx.count < 4){
         _ctx.count = (1 + _ctx.count);
      }
   }
   return _ctx.pre;
}

int Dsp_mono_noteOff(Dsp__ctx_type_11 &_ctx, int n){
   uint8_t found;
   found = false;
   int pos;
   int i;
   i = 0;
   if(_ctx.count == 0){
      return _ctx.pre;
   }
   while((i < 4) && bool_not(found)){
      if(int_get(_ctx.notes,i) == n){
         pos = i;
         found = true;
      }
      i = (1 + i);
   }
   if(found){
      int k;
      k = (1 + pos);
      while(k < 4){
         int_set(_ctx.notes,((-1) + k),int_get(_ctx.notes,k));
         k = (1 + k);
      }
      if(found && (_ctx.count > 0)){
         _ctx.count = ((-1) + _ctx.count);
         _ctx.pre = int_get(_ctx.notes,((-1) + _ctx.count));
      }
   }
   return _ctx.pre;
}

void Dsp__ctx_type_12_init(Dsp__ctx_type_12 &_output_){
   Dsp__ctx_type_12 _ctx;
   _ctx.target = 0x0 /* 0.000000 */;
   _ctx.state = 0;
   _ctx.rate = 0x0 /* 0.000000 */;
   _ctx.out = 0x0 /* 0.000000 */;
   _ctx.hold_phase = 0x0 /* 0.000000 */;
   _ctx.env_drum_ret_1 = 0x0 /* 0.000000 */;
   _ctx.env_drum_ret_0 = 0x0 /* 0.000000 */;
   Util__ctx_type_0_init(_ctx._inst351);
   Util__ctx_type_0_init(_ctx._inst151);
   _output_ = _ctx;
   return ;
}

void Dsp_env_drum(Dsp__ctx_type_12 &_ctx, fix16_t gate, fix16_t a, fix16_t h, fix16_t d){
   int release;
   release = 0;
   int attack;
   attack = 1;
   int hold;
   hold = 2;
   int reset;
   reset = 3;
   uint8_t bgate;
   bgate = (gate > 0x0 /* 0.000000 */);
   if(Util_edge(_ctx._inst151,bgate)){
      _ctx.state = reset;
   }
   fix16_t resetting;
   if(_ctx.state == reset){
      resetting = 0x10000 /* 1.000000 */;
   }
   else
   {
      resetting = 0x0 /* 0.000000 */;
   }
   if(Util_edge(_ctx._inst351,(_ctx.out > 0x4000000 /* 1024.000000 */))){
      _ctx.hold_phase = 0x0 /* 0.000000 */;
      _ctx.state = hold;
   }
   if((_ctx.out < 0xa0000 /* 10.000000 */) && (_ctx.state == reset)){
      _ctx.state = attack;
   }
   if((_ctx.hold_phase > 0x640000 /* 100.000000 */) && (_ctx.state == hold)){
      _ctx.state = release;
   }
   if(_ctx.state == reset){
      _ctx.rate = 0xfd77 /* 0.990099 */;
      _ctx.target = 0x0 /* 0.000000 */;
   }
   if(_ctx.state == attack){
      _ctx.rate = fix_div(0x10000 /* 1.000000 */,(0x28f /* 0.010000 */ + fix_mul(0x640000 /* 100.000000 */,a)));
      _ctx.target = 0x4cccccc /* 1228.800000 */;
   }
   if(_ctx.state == hold){
      fix16_t hrate;
      hrate = fix_div(0x10000 /* 1.000000 */,(0x28f /* 0.010000 */ + fix_mul(0x640000 /* 100.000000 */,h)));
      _ctx.hold_phase = (_ctx.hold_phase + hrate);
   }
   if(_ctx.state == release){
      _ctx.rate = fix_div(0x10000 /* 1.000000 */,(0x28f /* 0.010000 */ + fix_mul(0x640000 /* 100.000000 */,d)));
      _ctx.target = 0x0 /* 0.000000 */;
   }
   _ctx.out = (_ctx.out + fix_mul(fix_mul(0x147 /* 0.005000 */,_ctx.rate),(_ctx.target + (- _ctx.out))));
   _ctx.env_drum_ret_0 = fix_clip((_ctx.out >> 10),0x0 /* 0.000000 */,0x10000 /* 1.000000 */);
   _ctx.env_drum_ret_1 = resetting;
   return ;
}

void Dsp__ctx_type_13_init(Dsp__ctx_type_13 &_output_){
   Dsp__ctx_type_13 _ctx;
   _ctx.out = 0x0 /* 0.000000 */;
   Util__ctx_type_0_init(_ctx._inst151);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_env_swept(Dsp__ctx_type_13 &_ctx, fix16_t gate, fix16_t start, fix16_t end, fix16_t rate){
   fix16_t a_rate;
   a_rate = fix_div(0x10000 /* 1.000000 */,(0x28f /* 0.010000 */ + fix_mul(0x640000 /* 100.000000 */,rate)));
   uint8_t bgate;
   bgate = (gate > 0x0 /* 0.000000 */);
   _ctx.out = (_ctx.out + fix_mul(fix_mul(0x106 /* 0.004000 */,rate),((- _ctx.out) + (end << 10))));
   if(Util_edge(_ctx._inst151,bgate)){
      _ctx.out = (start << 10);
   }
   return (_ctx.out >> 10);
}

void Dsp__ctx_type_14_init(Dsp__ctx_type_14 &_output_){
   Dsp__ctx_type_14 _ctx;
   _ctx.reset_state = false;
   _ctx.reset_phase = 0x0 /* 0.000000 */;
   _ctx.rate = 0x0 /* 0.000000 */;
   _ctx.phase = 0x0 /* 0.000000 */;
   _ctx.direction = false;
   Util__ctx_type_0_init(_ctx._inst451);
   Util__ctx_type_0_init(_ctx._inst351);
   Util__ctx_type_1_init(_ctx._inst13b);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_tricore(Dsp__ctx_type_14 &_ctx, fix16_t cv, fix16_t reset, fix16_t disable){
   fix16_t out;
   out = 0x0 /* 0.000000 */;
   if(Util_change(_ctx._inst13b,cv)){
      _ctx.rate = (Util_cvToRate(cv) << 2);
   }
   fix16_t new_phase;
   fix16_t _if_13;
   if(_ctx.direction){
      _if_13 = _ctx.rate;
   }
   else
   {
      _if_13 = (- _ctx.rate);
   }
   new_phase = (_ctx.phase + _if_13);
   uint8_t bdisable;
   bdisable = (disable > 0x8000 /* 0.500000 */);
   if(Util_edge(_ctx._inst351,(reset > 0x0 /* 0.000000 */)) || Util_edge(_ctx._inst451,bdisable)){
      _ctx.reset_phase = _ctx.phase;
      _ctx.reset_state = true;
      new_phase = 0x0 /* 0.000000 */;
   }
   if(new_phase > 0x4000000 /* 1024.000000 */){
      new_phase = (0x4000000 /* 1024.000000 */ + (- (-0x4000000 /* -1024.000000 */ + new_phase)));
      _ctx.direction = false;
   }
   else
   {
      if(new_phase < -0x4000000 /* -1024.000000 */){
         _ctx.direction = true;
      }
   }
   if(bdisable){
      _ctx.phase = 0x0 /* 0.000000 */;
   }
   else
   {
      _ctx.phase = new_phase;
   }
   if(_ctx.reset_state){
      if((fix_abs(_ctx.reset_phase) > 0xa0000 /* 10.000000 */) || bdisable){
         fix16_t reset_speed;
         if(bdisable){
            reset_speed = 0x28f /* 0.010000 */;
         }
         else
         {
            reset_speed = 0x8000 /* 0.500000 */;
         }
         _ctx.reset_phase = (_ctx.reset_phase + (- fix_mul(_ctx.reset_phase,reset_speed)));
      }
      else
      {
         uint8_t _cond_17;
         _cond_17 = (_ctx.reset_phase > 0xa0000 /* 10.000000 */);
         if(bool_not(_cond_17)){
            _ctx.reset_phase = 0x0 /* 0.000000 */;
         }
         _ctx.reset_state = false;
         _ctx.direction = true;
      }
      out = _ctx.reset_phase;
   }
   out = (_ctx.phase + out);
   return (out >> 10);
}

fix16_t Dsp_saturate(fix16_t x){
   if(x == 0x0 /* 0.000000 */){
      return 0x0 /* 0.000000 */;
   }
   fix16_t fixed;
   uint8_t sign;
   if(x > 0x0 /* 0.000000 */){
      fixed = x;
      sign = false;
   }
   else
   {
      fixed = (- x);
      sign = true;
   }
   fix16_t out;
   out = 0x0 /* 0.000000 */;
   if(fixed > 0x60000 /* 6.000000 */){
      out = 0x10000 /* 1.000000 */;
   }
   else
   {
      out = Dsp_saturate_table(fixed);
   }
   if(sign){
      out = (- out);
   }
   return out;
}

fix16_t Dsp_pinker(Dsp__ctx_type_20 &_ctx, fix16_t x){
   fix16_t b0;
   b0 = 0x718 /* 0.027713 */;
   fix16_t b1;
   b1 = 0x718 /* 0.027713 */;
   fix16_t a1;
   a1 = -0xf1cf /* -0.944574 */;
   fix16_t w0;
   w0 = (x + (- fix_mul(_ctx.w1,a1)));
   fix16_t y0;
   y0 = (fix_mul(_ctx.w1,b1) + fix_mul(b0,w0));
   _ctx.w1 = w0;
   return y0;
}

void Dsp__ctx_type_21_init(Dsp__ctx_type_21 &_output_){
   Dsp__ctx_type_21 _ctx;
   _ctx.x2 = 0;
   _ctx.x1 = 0;
   Dsp__ctx_type_20_init(_ctx._inst123);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_osc_noisef(Dsp__ctx_type_21 &_ctx, uint8_t color){
   _ctx.x1 = ((7919 + (17389 * _ctx.x1)) % 32768);
   fix16_t y1;
   y1 = fix_mul(0x2 /* 0.000031 */,int_to_fix(_ctx.x1));
   _ctx.x2 = ((12553 + (27449 * _ctx.x2)) % 32768);
   fix16_t y2;
   y2 = fix_mul(0x2 /* 0.000031 */,int_to_fix(_ctx.x2));
   fix16_t out;
   if(color){
      out = Dsp_pinker(_ctx._inst123,(y1 + (- y2)));
   }
   else
   {
      out = (y1 + (- y2));
   }
   return (out << 1);
}

void Dsp__ctx_type_22_init(Dsp__ctx_type_22 &_output_){
   Dsp__ctx_type_22 _ctx;
   Dsp__ctx_type_21_init(_ctx._inst53d);
   Dsp__ctx_type_12_init(_ctx._inst41f);
   Dsp__ctx_type_14_init(_ctx._inst37);
   Dsp__ctx_type_13_init(_ctx._inst2e8);
   Dsp__ctx_type_12_init(_ctx._inst11f);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_unit_drum(Dsp__ctx_type_22 &_ctx, fix16_t gate, fix16_t odecay, fix16_t pitch, fix16_t swept, fix16_t noise){
   fix16_t osc_env;
   fix16_t env_reset;
   Dsp_env_drum(_ctx._inst11f,gate,0x147 /* 0.005000 */,(0x1999 /* 0.100000 */ + odecay),(0x28f /* 0.010000 */ + odecay));
   osc_env = Dsp_env_drum_ret_0(_ctx._inst11f);
   env_reset = Dsp_env_drum_ret_1(_ctx._inst11f);
   fix16_t cv;
   cv = Dsp_env_swept(_ctx._inst2e8,(0x10000 /* 1.000000 */ + (- env_reset)),(pitch + fix_mul(0x6666 /* 0.400000 */,swept)),pitch,0x1999 /* 0.100000 */);
   fix16_t osc;
   osc = Dsp_tricore(_ctx._inst37,cv,0x0 /* 0.000000 */,env_reset);
   fix16_t osc_sat;
   osc_sat = Dsp_saturate(fix_mul(0x18000 /* 1.500000 */,osc));
   fix16_t noise_env;
   Dsp_env_drum(_ctx._inst41f,gate,0x41 /* 0.001000 */,0x28f /* 0.010000 */,(0x41 /* 0.001000 */ + fix_mul(0x28f /* 0.010000 */,noise)));
   noise_env = Dsp_env_drum_ret_0(_ctx._inst41f);
   Dsp_env_drum_ret_1(_ctx._inst41f);
   fix16_t noise_osc;
   noise_osc = fix_mul(fix_mul(0x5555 /* 0.333333 */,noise),Dsp_osc_noisef(_ctx._inst53d,true));
   return (fix_mul(noise_env,noise_osc) + fix_mul(osc_env,osc_sat));
}

void Dsp__ctx_type_23_init(Dsp__ctx_type_23 &_output_){
   Dsp__ctx_type_23 _ctx;
   _ctx.i = 0;
   ;
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_delay_600(Dsp__ctx_type_23 &_ctx, fix16_t x, int n){
   int d;
   d = (_ctx.i + (- n));
   int r;
   if(d < 0){
      r = (2400 + d);
   }
   else
   {
      r = d;
   }
   _ctx.i = ((1 + _ctx.i) % 2400);
   fix16_t y;
   y = fix_get(_ctx.buffer,r);
   fix_set(_ctx.buffer,_ctx.i,x);
   return y;
}

void Dsp__ctx_type_24_init(Dsp__ctx_type_24 &_output_){
   Dsp__ctx_type_24 _ctx;
   _ctx.pre_y = 0x0 /* 0.000000 */;
   _ctx.pre_x = 0x0 /* 0.000000 */;
   Dsp__ctx_type_23_init(_ctx._inst28);
   Dsp__ctx_type_23_init(_ctx._inst18);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_ap(Dsp__ctx_type_24 &_ctx, fix16_t x, fix16_t g, int n){
   fix16_t y;
   y = ((- x) + fix_mul(_ctx.pre_x,(0x10000 /* 1.000000 */ + g)) + fix_mul(_ctx.pre_y,g));
   _ctx.pre_x = Dsp_delay_600(_ctx._inst18,x,n);
   _ctx.pre_y = Dsp_delay_600(_ctx._inst28,y,n);
   return y;
}

void Dsp__ctx_type_25_init(Dsp__ctx_type_25 &_output_){
   Dsp__ctx_type_25 _ctx;
   Dsp__ctx_type_24_init(_ctx._inst4a9);
   Dsp__ctx_type_24_init(_ctx._inst3a9);
   Dsp__ctx_type_24_init(_ctx._inst2a9);
   Dsp__ctx_type_24_init(_ctx._inst1a9);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_reverb(Dsp__ctx_type_25 &_ctx, fix16_t x){
   fix16_t y;
   y = Dsp_ap(_ctx._inst1a9,x,0x8000 /* 0.500000 */,255);
   y = Dsp_ap(_ctx._inst2a9,y,0x8000 /* 0.500000 */,556);
   y = Dsp_ap(_ctx._inst3a9,y,0x8000 /* 0.500000 */,441);
   y = Dsp_ap(_ctx._inst4a9,y,0x8000 /* 0.500000 */,341);
   return y;
}

void Dsp__ctx_type_26_init(Dsp__ctx_type_26 &_output_){
   Dsp__ctx_type_26 _ctx;
   _ctx.wetdry = 0x0 /* 0.000000 */;
   _ctx.volume = 0x0 /* 0.000000 */;
   _ctx.vca_sustain = 0x0 /* 0.000000 */;
   _ctx.vca_release = 0x0 /* 0.000000 */;
   _ctx.vca_decay = 0x0 /* 0.000000 */;
   _ctx.vca_attack = 0x0 /* 0.000000 */;
   _ctx.time = 0x0 /* 0.000000 */;
   _ctx.pitchBend = 0x0 /* 0.000000 */;
   _ctx.pitch = 0x0 /* 0.000000 */;
   Dsp__ctx_type_11_init(_ctx.notes);
   _ctx.mute = false;
   _ctx.lfo_rate = 0x0 /* 0.000000 */;
   _ctx.lfo_amt = 0x0 /* 0.000000 */;
   _ctx.filter_sustain = 0x0 /* 0.000000 */;
   _ctx.filter_resonance = 0x0 /* 0.000000 */;
   _ctx.filter_release = 0x0 /* 0.000000 */;
   _ctx.filter_env_amt = 0x0 /* 0.000000 */;
   _ctx.filter_decay = 0x0 /* 0.000000 */;
   _ctx.filter_cutoff = 0x0 /* 0.000000 */;
   _ctx.filter_attack = 0x0 /* 0.000000 */;
   _ctx.feedback = 0x0 /* 0.000000 */;
   _ctx.detune = 0x0 /* 0.000000 */;
   Dsp__ctx_type_0_init(_ctx._inst928);
   Dsp__ctx_type_0_init(_ctx._inst828);
   Svf__ctx_type_4_init(_ctx._inst712);
   Adsr__ctx_type_0_init(_ctx._inst66);
   Adsr__ctx_type_0_init(_ctx._inst56);
   Dsp__ctx_type_0_init(_ctx._inst428);
   Sawcore__ctx_type_1_init(_ctx._inst31b);
   Sawcore__ctx_type_1_init(_ctx._inst21b);
   Dsp__ctx_type_7_init(_ctx._inst15a);
   Dsp__ctx_type_9_init(_ctx._inst10c7);
   _output_ = _ctx;
   return ;
}

fix16_t Dsp_process(Dsp__ctx_type_26 &_ctx, fix16_t input){
   uint8_t gate;
   gate = Dsp_mono_isGateOn(_ctx.notes);
   fix16_t lfo_val;
   lfo_val = fix_mul(_ctx.lfo_amt,Dsp_lfo(_ctx._inst15a,_ctx.lfo_rate,gate));
   fix16_t o1;
   o1 = (Sawcore_process(_ctx._inst21b,Util_pitchToCv((_ctx.pitch + _ctx.pitchBend + lfo_val)),0x0 /* 0.000000 */) >> 1);
   fix16_t o2;
   o2 = (Sawcore_process(_ctx._inst31b,(-0x1999 /* -0.100000 */ + Util_pitchToCv((_ctx.detune + _ctx.pitch + _ctx.pitchBend + lfo_val))),0x0 /* 0.000000 */) >> 1);
   fix16_t osc_mix;
   osc_mix = (o1 + o2);
   fix16_t amp;
   fix16_t _if_11;
   if(gate){
      _if_11 = 0x10000 /* 1.000000 */;
   }
   else
   {
      _if_11 = 0x0 /* 0.000000 */;
   }
   amp = Dsp_smooth(_ctx._inst428,_if_11);
   fix16_t osc_out;
   osc_out = fix_mul(amp,osc_mix);
   fix16_t gate_real;
   if(gate){
      gate_real = 0x10000 /* 1.000000 */;
   }
   else
   {
      gate_real = 0x0 /* 0.000000 */;
   }
   fix16_t env_vcf;
   env_vcf = (Adsr_do(_ctx._inst56,gate_real,_ctx.filter_attack,_ctx.filter_decay,_ctx.filter_sustain,_ctx.filter_release) << 2);
   fix16_t env_vca;
   env_vca = (Adsr_do(_ctx._inst66,gate_real,_ctx.vca_attack,_ctx.vca_decay,_ctx.vca_sustain,_ctx.vca_release) << 2);
   fix16_t filter_frequency;
   filter_frequency = fix_clip((_ctx.filter_cutoff + fix_mul(_ctx.filter_env_amt,env_vcf)),0x0 /* 0.000000 */,0x10000 /* 1.000000 */);
   fix16_t filter_out;
   filter_out = Svf_process(_ctx._inst712,osc_out,filter_frequency,_ctx.filter_resonance,0);
   fix16_t delay_out;
   delay_out = Dsp_delay(_ctx._inst10c7,filter_out,Dsp_smooth(_ctx._inst828,_ctx.time),Dsp_smooth(_ctx._inst928,_ctx.feedback));
   return (((delay_out >> 1) + (filter_out >> 1)) >> 2);
}

void Dsp_controlChange(Dsp__ctx_type_26 &_ctx, int control, int value, int channel){
   if(control == 30){
      _ctx.volume = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 31){
      _ctx.detune = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 32){
      _ctx.lfo_rate = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 33){
      _ctx.lfo_amt = ((-0x8000 /* -0.500000 */ + fix_mul(0x204 /* 0.007874 */,int_to_fix(value))) << 1);
   }
   if(control == 34){
      _ctx.time = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 35){
      _ctx.feedback = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 36){
      _ctx.wetdry = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 37){
      _ctx.filter_attack = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 38){
      _ctx.filter_decay = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 39){
      _ctx.filter_sustain = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 40){
      _ctx.filter_release = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 41){
      _ctx.filter_env_amt = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 42){
      _ctx.filter_cutoff = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 43){
      _ctx.filter_resonance = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 44){
      _ctx.vca_attack = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 45){
      _ctx.vca_decay = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 46){
      _ctx.vca_sustain = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 47){
      _ctx.vca_release = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 2){
      _ctx.lfo_amt = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
   if(control == 1){
      _ctx.lfo_rate = fix_mul(0x204 /* 0.007874 */,int_to_fix(value));
   }
}

void Dsp_default(Dsp__ctx_type_26 &_ctx){
   _ctx.volume = 0x10000 /* 1.000000 */;
   _ctx.pitch = 0x2d0000 /* 45.000000 */;
   _ctx.detune = 0xccc /* 0.050000 */;
   _ctx.lfo_rate = 0x11eb /* 0.070000 */;
   _ctx.lfo_amt = 0x1999 /* 0.100000 */;
   _ctx.time = 0x9999 /* 0.600000 */;
   _ctx.feedback = 0x4ccc /* 0.300000 */;
   _ctx.wetdry = 0x4ccc /* 0.300000 */;
   _ctx.mute = true;
   _ctx.filter_attack = 0x0 /* 0.000000 */;
   _ctx.filter_decay = 0x3333 /* 0.200000 */;
   _ctx.filter_sustain = 0x9999 /* 0.600000 */;
   _ctx.filter_release = 0xcccc /* 0.800000 */;
   _ctx.filter_env_amt = 0xcccc /* 0.800000 */;
   _ctx.filter_cutoff = 0x3333 /* 0.200000 */;
   _ctx.filter_resonance = 0x8000 /* 0.500000 */;
   _ctx.vca_attack = 0x0 /* 0.000000 */;
   _ctx.vca_decay = 0x6666 /* 0.400000 */;
   _ctx.vca_sustain = 0xb333 /* 0.700000 */;
   _ctx.vca_release = 0xe666 /* 0.900000 */;
   _ctx.pitchBend = 0x0 /* 0.000000 */;
}


