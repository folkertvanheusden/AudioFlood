AudioFlood is like Pixelflut/Pixelflood for audio.

The idea is that clients try make their audio sample to played as much as possible.

It works as follows:
- the server waits for UDP packets and copy their contents (max 1500 bytes) into the play-buffer
- if it doesn't get overwritten by another client, that client wins
- the server plays audio at 44.1kHz, 16 bit unsigned stereo


(c) 2019 by Folkert van Heusden <mail@vanheusden.com>
