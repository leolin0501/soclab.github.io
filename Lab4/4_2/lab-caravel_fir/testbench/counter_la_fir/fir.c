#include "fir.h"
#include <defs.h>

void __attribute__ ( ( section ( ".mprjram" ) ) ) initfir() {
	//initial your fir
	// {0,-10,-9,23,56,63,56,23,-9,-10,0};
	tap_1 = 0;
	tap_2 = -10;
	tap_3 = -9;
	tap_4 = 23;
	tap_5 = 56;
	tap_6 = 63;
	tap_7 = 56;
	tap_8 = 23;
	tap_9 = -9;
	tap_10= -10;
	tap_11= 0;

	datalength = 64;

	reg_mprj_datal = 0x00A50000;
	status = 0x00000001;

}

int* __attribute__ ( ( section ( ".mprjram" ) ) ) fir(int method){
	initfir();
	//write down your fir

	int x[64];
	int s;
	for (int i = 0; i < 64; i++) {
		if(method == 1)
			x[i] = i;
		else if(method == 2) 
			x[i] = 64 - i;
		else if(method == 3)
			x[i] = 1;
	}

	s = status;
	for (int i = 0; i < 64; i++) {
		while (!((s >> 4) & 1) && i != 0)
			s = status;
		inputsignal = x[i];

		while (!((s >> 5) & 1))
			s = status;
		ans[i] = outputsignal;
	}

	s = status;
	reg_mprj_datal = ((0x000000FF & ans[63]) << 24) | 0x005A0000;

	return ans;
}
		
