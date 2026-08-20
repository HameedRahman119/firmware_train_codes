#include <stdio.h>
#include <stdint.h>

static void set_bit(uint8_t *value, uint8_t position)
{
    *value |= (uint8_t)(1u << position);
}

static void clear_bit(uint8_t *value, uint8_t position)
{
    *value &= (uint8_t)~(1u << position);
}

static uint8_t read_bit(uint8_t value, uint8_t position)
{
    return (uint8_t)((value >> position) & 1u);
}

int main(void)
{
    uint8_t port = 0x00;

    set_bit(&port, 0);
    set_bit(&port, 3);
    printf("After setting bits 0 and 3: 0x%02X\n", port);

    printf("Bit 3: %u\n", read_bit(port, 3));

    clear_bit(&port, 0);
    printf("After clearing bit 0: 0x%02X\n", port);

    return 0;
}
