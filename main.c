/*
 * ctc_mode_main.c
 *
 * Created: 04/10/2018 06:10:59 p.m.
 * Author : Laptop
 */ 
//LED FLASH EVERY 100 ms
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect){
	PORTD ^= (0xFF<<PORTD);
}

void timer1_config(){
	TCCR1A |= (0<<WGM10)|(0<<WGM11)|(0<<COM1A1)|(1<<COM1A0); //CTC MODE, TOGGLE OC1A PIN(14)
	TCCR1B |= (1<<CS10)|(1<<CS11)|(1<<WGM12)|(0<<WGM13); //CTC MODE, Prescaler = 64
	OCR1A = 24999;
	
	TIMSK1 |= (1<<OCIE1A);
	
	sei();
	
	TCNT1 = 0x0000;
}

void pin_config(){	
	DDRD = (0xFF<<PORTD);
	DDRB = (1<<PORTB1);
}

int main(void)
{
    pin_config();
	timer1_config();
	
    while (1) 
    {
    }
}

