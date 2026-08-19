#include "stm32f4xx.h"
#include "signals.h"

extern float _5hz_signal[HZ_5_SIG_LEN];
float g_in_sig_samples;
static void plot_input_signal(void);
static void pseudo_dly(int dly);


int main(){
	/* Enable the Floating Point Unit: Enable CP10 and CP11 full access */
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));

    while(1) {
    	plot_input_signal();
    }
}

static void plot_input_signal(void) {
	int i;
	for(i = 0; i < HZ_5_SIG_LEN; i++) {
		g_in_sig_samples = _5hz_signal[i];
		pseudo_dly(9000);
	}
}

static void pseudo_dly(int dly) {	/*False delay - dly is not time parameter*/
	for(int i = 0; i < dly; i++) {}
}
