#include <stdint.h>
#include "tm4c123gh6pm.h"

void config_led_rojo(void){
// activamos la señal de reloj del puerto F
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
// esperamos a que realmente se active
while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)==0) { }
GPIO_PORTF_DIR_R |= 0x02; // Configura el bit 1 del puerto F como salida
GPIO_PORTF_DR8R_R |=0x02; // se activa el driver de 8 mA en el pin 1.
GPIO_PORTF_DEN_R |=0x02; // se activa el pin 1, como salida digital.
}
void retardo(uint32_t freq){
    uint32_t n;
    for(n = 0; n < freq; n++);
}
void AmenazaIntensidad(uint8_t nivel){
    config_led_rojo();
    switch (nivel)
    {
    case 1:
    GPIO_PORTF_DATA_R |=0X02;
    retardo(600000);
    GPIO_PORTF_DATA_R &=~(0X02);
    retardo(600000);
    break;
    case 2:
    GPIO_PORTF_DATA_R |=0X02;
    retardo(300000);
    GPIO_PORTF_DATA_R &=~(0X02);
    retardo(200000);
    break;
    case 3:
    GPIO_PORTF_DATA_R |=0X02;
    retardo(50000);
    GPIO_PORTF_DATA_R &=~(0X02);
    retardo(100000);
    break;
    }

}

void main (void){
    while(1){
    AmenazaIntensidad(1);
    }
}

