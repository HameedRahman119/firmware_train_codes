#include <stdio.h>
#include <stdint.h>

volatile uint8_t GPIO_OUT = 0;

void set_pin(uint8_t pin)
{
    GPIO_OUT |= (uint8_t)(1U << pin);
}

void clear_pin(uint8_t pin)
{
    GPIO_OUT &= (uint8_t)~(1U << pin);
}

int main(void)
{
    set_pin(2);
    printf("GPIO = %u\n", GPIO_OUT);

    clear_pin(2);
    printf("GPIO = %u\n", GPIO_OUT);

    return 0;
}
