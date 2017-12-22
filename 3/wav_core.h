#ifndef WAV_CORE_H
#define WAV_CORE_H

#include <vector>

#include "wav_header.h"
#include "Exceptions.h"


// TODO: Implement all this in the form of a class.
// TODO: Use an exception system to control errors.
// TODO: Make support for 8-bit PSM, not just 16-bit.
// TODO: Write a function to change the tone of the voice. (Interestingly, it's not too difficult?)


// ************************************************************************
// * Functions for working with WAV file
// ************************************************************************

class Wav
{
public:

	// Reads file 'filename' and puts header's data to 'header_ptr' address.
	// Also checks header validity, returns 'WAV_OK' on success.
	void read_header(const char* filename);

	// Reads file 'filename' and puts PCM data (raw sound data) to 'channels_data'.
	// Also checks header validity, returns 'WAV_OK' on success.
	void extract_data_int16(const char* filename);

	// Creates a new WAV file 'filename', using 'sample_rate' and PCM data from 'channels_data'.
	// Returns 'WAV_OK' on success.
	void make_wav_file(const char* filename);

	// ************************************************************************
	// * Functions for working with sound PCM data - Digital Signal Processing
	// ************************************************************************

	// Makes mono PCM data from stereo 'source'.
	// Returns 'WAV_OK' on success.
	void make_mono();
	
	// Adds a reverberation (it's like an echo).
	// Returns 'WAV_OK' on success.
	void make_reverb(double delay_seconds, float decay);

	// Prints header's data from 'header_ptr' address.
	void print_info();
	





private:

	// ************************************************************************
	// * Private functions
	// ************************************************************************

	// Fills header with zeroes.
	void null_header();

	void make_reverb(int sample_rate, double delay_seconds, float decay);

	void make_wav_file(const char* filename, int sample_rate);


	// Checks header validity.
	// Returns 'WAV_OK' on success.
	void check_header(size_t file_size_bytes);

	// Fills header information, using input parameters. This function calls prefill_header() itself.
	void fill_header(int chan_count, int bits_per_sample, int sample_rate, int samples_count_per_chan);

	// Fills 'header_ptr' with default values.
	void prefill_header();

	wav_header_s header;

	std::vector<std::vector<short>> channels_data;
};
#endif // WAV_CORE_H
