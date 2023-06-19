#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "pipewire.h"
#include "pipewire-audio.h"


int main(int argc, char *argv[])
{
	constexpr int sample_rate = 44100;
	constexpr int n_channels  = 2;

	init_pipewire(&argc, &argv);

	sound_parameters sp_audio(sample_rate, n_channels);

	configure_pipewire_audio(&sp_audio);

	constexpr int port = 58231;

	int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

        sockaddr_in bind_addr { 0 };
        bind_addr.sin_family      = AF_INET;
        bind_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        bind_addr.sin_port        = htons(port);

        if ((bind(fd, reinterpret_cast<sockaddr *>(&bind_addr), sizeof bind_addr)) == -1) {
                perror("bind");
                return 1;
        }

	int flag_on = 1;
        if ((setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char *>(&flag_on), sizeof flag_on)) == -1) {
                perror("setsockopt(SO_REUSEADDR)");
		return 1;
	}

	for(;;) {
		if (recvfrom(fd, sp_audio.buffer, sizeof sp_audio.buffer, 0, nullptr, nullptr) == -1) {
			perror("recvfrom");
			break;
		}
	}

	return 0;
}
