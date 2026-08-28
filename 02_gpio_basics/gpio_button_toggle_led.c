#include <stdint.h>
#include <stdio.h>

volatile uint8_t GPIO_INPUT = 0;
volatile uint8_t GPIO_OUTPUT = 0;

#define BUTTON_PIN (1U << 0)
#define LED_PIN    (1U << 1)

int main(void)
{
    GPIO_INPUT = BUTTON_PIN;

    if (GPIO_INPUT & BUTTON_PIN)
    {
        GPIO_OUTPUT ^= LED_PIN;
    }

    printf("GPIO_OUTPUT = 0x%02X\n", GPIO_OUTPUT);

    return 0;
}
