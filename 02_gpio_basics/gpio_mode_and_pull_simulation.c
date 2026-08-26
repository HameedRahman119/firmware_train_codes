#include <stdint.h>
#include <stdio.h>

volatile uint8_t GPIO_MODE = 0;
volatile uint8_t GPIO_PULL = 0;

void set_output_mode(uint8_t pin)
{
    GPIO_MODE |= (1U << pin);
}

void enable_pull_up(uint8_t pin)
{
    GPIO_PULL |= (1U << pin);
}

int main(void)
{
    uint8_t led_pin = 2;
    uint8_t button_pin = 5;

    set_output_mode(led_pin);
    enable_pull_up(button_pin);

    printf("GPIO_MODE = 0x%02X\n", GPIO_MODE);
    printf("GPIO_PULL = 0x%02X\n", GPIO_PULL);

    return 0;
}
