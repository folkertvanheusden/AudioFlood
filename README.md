AudioFlood is like Pixelflut/Pixelflood for audio.

The goal is to make sure your audio-packet is the one in the server-buffer as soon as playing starts.
This requires timing and bandwidth.


It works as follows:
- the server waits for UDP packets and copy their contents (max 1500 bytes) into the play-buffer
- if it doesn't get overwritten by another client, that client wins
- the server plays audio at 44.1kHz, 16 bit unsigned stereo

This program is implemented for pipewire and requires libpipewire-0.3-dev.


(c) 2019-2023 by Folkert van Heusden <mail@vanheusden.com>
