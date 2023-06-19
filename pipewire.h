#include <string.h>

#include "pipewire-audio.h"


class sound_parameters
{
public:
	sound_parameters(const int sample_rate, const int n_channels) :
       		sample_rate(sample_rate),
		n_channels(n_channels) {

		memset(buffer, 0x00, sizeof buffer);
	}

	virtual ~sound_parameters() {
	}

	int buffer_offset = 0;
	int16_t buffer[1500];

	int sample_rate     { 0 };
	int n_channels      { 0 };

	pipewire_data_audio pw;
};

void init_pipewire(int *argc, char **argv[]);
