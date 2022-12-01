#include "vult.h"

Dsp_process_type ctx;

void setup()
{
    Serial.begin(115200);
    Dsp_process_init(ctx);
    Dsp_default_init(ctx);
    Dsp_default(ctx);
}

void loop()
{
    // put your main code here, to run repeatedly:
    int32_t sample = Dsp_process(ctx, 0);
    Serial.println(sample);
}