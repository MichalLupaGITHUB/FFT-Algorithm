#pragma once
#include "fftw3.h"

class FFT
{
private:
	double *DataInForFFT; //dane wejściowe dla FFT
	double *DataInForIFFT;//dane wyjściowe dla IFFT - odwrotna FFT
	fftw_complex *DataOutFromFFT;//wyjście FFT
	fftw_plan MakeIFFT;//dla wykonania IFFT - odwrotna FFT
	fftw_plan MakeFFT;//dla wykonania FFT
	const int N = 10; // ilość próbek

	// Functions
	void MemoryAllocation();
	void FillDatabySamples();
	void FunctionMakeFFT();
	void DispalyFFTResults();
	void FunctionMakeIFFT();
	void DispalyIFFTResults();

public:
	FFT();
	void FFT_Run();
	void IFFT_Run();

protected:

};
