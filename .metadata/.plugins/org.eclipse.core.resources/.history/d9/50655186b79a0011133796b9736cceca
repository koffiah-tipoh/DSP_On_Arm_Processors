#include "stm32f4xx.h"

#define GPIOBEN    (1U<<1)
#define PIN0       (1U<<0)
#define LED_PIN    PIN0

int main() {
    RCC->AHB1ENR |= GPIOBEN;

    GPIOB->MODER |= (1U<<0);
    GPIOB->MODER &= ~(1U<<1);

    while(1){
        GPIOB->ODR ^= LED_PIN;
        for(int i = 0; i < 100000; i++) {}
    }
}
