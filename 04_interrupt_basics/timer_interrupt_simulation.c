#include <stdio.h>
#include <stdint.h>

volatile uint8_t led_state = 0U;
volatile uint8_t timer_ticks = 0U;

void timer_interrupt(void)
{
    timer_ticks++;

    if (timer_ticks >= 3U)
    {
        led_state ^= 1U;
        timer_ticks = 0U;
    }
}

int main(void)
{
    for (int i = 0; i < 9; i++)
    {
        timer_interrupt();
        printf("Tick %d: LED = %u, timer ticks = %u\n",
               i + 1, led_state, timer_ticks);
    }

    return 0;
}
