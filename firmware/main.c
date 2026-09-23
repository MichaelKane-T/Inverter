/*
 * BYU Racing - Inverter Controller
 *
 * Main firmware entry point
 */

#include <stdint.h>

int main(void)
{
    /* Hardware initialization */

    /* ADC initialization */

    /* PWM initialization */

    /* Resolver initialization */

    /* CAN initialization */

    while (1)
    {
        /*
         * Background tasks.
         *
         * The fast FOC control loop should NOT
         * execute here. It will eventually be
         * synchronized with PWM/ADC timing.
         */
    }

    return 0;
}
