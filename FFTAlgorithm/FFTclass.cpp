#include "pch.h"
#include "FFTclass.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

// Konstruktor
FFT::FFT()
{

}

// Alokacja pamięci
void FFT::MemoryAllocation()
{
	DataInForFFT = (double*)malloc(sizeof(double) * FFT::N);
	DataOutFromFFT = (fftw_complex *)malloc(sizeof(fftw_complex) * FFT::N);
	DataInForIFFT = (double *)malloc(sizeof(double) * FFT::N);
}

// Wypelnienie bufora próbkami
void FFT::FillDatabySamples()
{
	for (int iterator = 0; iterator < FFT::N; iterator++)
	{
		DataInForFFT[iterator] = (iterator + 1) / 3;
	}

}

// Wykoannaie FFT
void FFT::FunctionMakeFFT()
{
	MakeFFT = fftw_plan_dft_r2c_1d(FFT::N, DataInForFFT, DataOutFromFFT, FFTW_ESTIMATE);
	fftw_execute(MakeFFT);
}

// Wyniki FFT
void FFT::DispalyFFTResults()
{
	printf("Re: %f Im: %f\n", DataOutFromFFT[0][0], DataOutFromFFT[1][1]);
}

// Wykonanie programu FFT
void FFT::FFT_Run()
{
	FFT::MemoryAllocation();
	FFT::FillDatabySamples();
	FFT::FunctionMakeFFT();
	FFT::DispalyFFTResults();
}

// Wykonanie odwrotnej FFT
void FFT::FunctionMakeIFFT()
{
	MakeIFFT = fftw_plan_dft_c2r_1d(N, DataOutFromFFT, DataInForIFFT, FFTW_ESTIMATE);
	fftw_execute(MakeIFFT);
}

// Wyniki IFFT
void FFT::DispalyIFFTResults()
{
	printf("Odwrotna FFT: \n");

	for (int iterator = 0; iterator < N; iterator++)
	{
		printf("%f\n", DataInForIFFT[iterator] / (double)(N));
	}
}

// Wykonanie programu IFFT
void FFT::IFFT_Run()
{
	FFT::FunctionMakeIFFT();
	FFT::DispalyIFFTResults();
}

