#include <stdio.h>
#include <stdint.h>

#define BUTTON1 (1U << 0)
#define BUTTON2 (1U << 1)
#define LED1    (1U << 4)
#define LED2    (1U << 5)

int main(void)
{
    volatile uint8_t input_register = BUTTON1 | BUTTON2;
    volatile uint8_t output_register = 0;

    if (input_register & BUTTON1)
        output_register |= LED1;
    else
        output_register &= (uint8_t)~LED1;

    if (input_register & BUTTON2)
        output_register |= LED2;
    else
        output_register &= (uint8_t)~LED2;

    printf("GPIO output: 0x%02X\n", output_register);

    return 0;
}
