#include "fir.h"

void __attribute__ ( ( section ( ".mprjram" ) ) ) initfir() {
	//initial your fir
	int i;
	for(i=0;i<N;i++)
	{
		outputsignal[i] = 0;
	}
}

int* __attribute__ ( ( section ( ".mprjram" ) ) ) fir(){
	initfir();
	int i,j;
	//write down your fir
	for(i=0;i<N;i++)
	{
		for(j=0;j<(i+1);j++)
		{
			outputsignal[i] = outputsignal[i] + inputsignal[i-j]*taps[j];
		}
	}
	return outputsignal;
}
		
