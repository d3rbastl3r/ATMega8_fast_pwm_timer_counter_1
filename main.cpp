/**
 * A minimal example how to implement a Fast PWM with Timer/Counter1 on OC1A (PB1)
 *
 * @author Igor Martens
 * @since 12.10.2018
 */

#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>

void setup() {
    DDRB |= (1 << DDB1); // Setup the Output for PWM (OC1A)


    TCCR1B |=
        // Set Timer/Counter1 prescaler to clock/64.
        // At 16 MHz this is 250 kHz.
        (0 << CS12) |
        (1 << CS11) |
        (1 << CS10) |

        // Fast PWM, 8-bit
        (0 << WGM13) |
        (1 << WGM12);


    TCCR1A |=
        // Fast PWM, 8-bit
        (0 << WGM11) |
        (1 << WGM10) |

        // Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM, (non-inverting mode)
        (1 << COM1A1) |
        (0 << COM1A0);

    // If the value '128' is reached, the PWM signal will set to LOW
    OCR1A=80; // 50% duty cycle
}

int main(void) {
    setup();

    while(1) {
    }

    return 0;
}
