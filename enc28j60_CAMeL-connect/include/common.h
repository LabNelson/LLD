#pragma once

#include <stdint.h>
#include <stdbool.h>

void init_network(void);
void arp_test(void);

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef volatile u32 reg32;