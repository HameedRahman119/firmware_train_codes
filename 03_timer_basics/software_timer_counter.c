#include <stdio.h>
#include <stdint.h>

volatile uint8_t timer_count = 0U;

void timer_tick(void)
{
    timer_count++;
}

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        timer_tick();
        printf("Tick %d: count = %u\n", i + 1, timer_count);
    }

    return 0;
}
