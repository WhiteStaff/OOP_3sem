#include <iostream>

#include "wav_core.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "************** | WavCore | **************" << endl;


    // ################  Tests for WavCore  ################

    const char* input_fname  = "c:\\temp\\0.wav";
    const char* output_fname = "c:\\temp\\out.wav";

	Wav myClass, Class1;

	try {
		
		// #### Opening WAV file, checking header.
		myClass.read_header(input_fname);


		// #### Printing header.
		myClass.print_info();


		// #### Reading PCM data from file.
		myClass.extract_data_int16(input_fname);
		cout << endl << "********************" << endl;


		// #### Make several changes to PCM data.

		// # Making signal mono from stereo.
		myClass.make_mono();

		// # Add a reverberation
		myClass.make_reverb(0.5, 0.6f);


		// #### Making new WAV file using edited PCM data.
		myClass.make_wav_file(output_fname);

		// #### Reading the file just created to check its header corectness.
		Class1.read_header(output_fname);

		Class1.print_info();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}



    return 0;
}
