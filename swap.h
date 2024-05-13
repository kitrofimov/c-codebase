#pragma once

#define SWAP(a, b) \
	do \
	{ \
		unsigned char temp[(sizeof(a) == sizeof(b)) ? (int) sizeof(a) : -1]; \
		memcpy(temp, &a, sizeof(a)); \
		memcpy(&a, &b, sizeof(a)); \
		memcpy(&b, temp, sizeof(a)); \
	} while (false)

