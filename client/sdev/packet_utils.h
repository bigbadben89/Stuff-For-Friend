

#ifndef PACKET_UTILS_H
#define PACKET_UTILS_H

typedef void (*IsSentPacketFunction)(void*, int);


void callIsSentPacket(void* address, int length, IsSentPacketFunction isSentPacketFunction);

#endif // PACKET_UTILS_H