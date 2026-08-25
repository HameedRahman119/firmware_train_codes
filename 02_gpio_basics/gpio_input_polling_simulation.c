#include <stdio.h>
#include <stdint.h>

#define BUTTON_PIN 0
#define LED_PIN    1

volatile uint8_t GPIO_IN;
volatile uint8_t GPIO_OUT;

int main(void)
{
    int button;

    printf("Button state (0 or 1): ");
    scanf("%d", &button);

    if (button == 1)
        GPIO_IN |= (1u << BUTTON_PIN);

    if (GPIO_IN & (1u << BUTTON_PIN))
        GPIO_OUT |= (1u << LED_PIN);
    else
        GPIO_OUT &= ~(1u << LED_PIN);

    printf("GPIO_IN  = %u\n", GPIO_IN);
    printf("GPIO_OUT = %u\n", GPIO_OUT);

    return 0;
}
