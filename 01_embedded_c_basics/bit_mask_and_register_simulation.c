#include <stdio.h>
#include <stdint.h>

#define LED_BIT    3U
#define BUTTON_BIT 1U

void set_bit(uint8_t *reg, uint8_t bit)
{
    *reg |= (uint8_t)(1U << bit);
}

void clear_bit(uint8_t *reg, uint8_t bit)
{
    *reg &= (uint8_t)~(1U << bit);
}

uint8_t read_bit(uint8_t reg, uint8_t bit)
{
    return (uint8_t)((reg >> bit) & 1U);
}

int main(void)
{
    uint8_t gpio_output = 0U;
    uint8_t gpio_input = 0U;

    set_bit(&gpio_output, LED_BIT);
    printf("LED register: 0x%02X\n", gpio_output);

    set_bit(&gpio_input, BUTTON_BIT);

    if (read_bit(gpio_input, BUTTON_BIT) == 1U)
    {
        clear_bit(&gpio_output, LED_BIT);
    }

    printf("After button press: 0x%02X\n", gpio_output);

    return 0;
}
