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

void toggle_pin(uint8_t pin)
{
    GPIO_OUT ^= (uint8_t)(1U << pin);
}

int main(void)
{
    set_pin(1);
    printf("After set:    %u\n", GPIO_OUT);

    toggle_pin(1);
    printf("After toggle: %u\n", GPIO_OUT);

    clear_pin(1);
    printf("After clear:  %u\n", GPIO_OUT);

    return 0;
}
