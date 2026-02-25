#include <stdint.h>
#include "stm32f103xb.h"

void GPIO_Init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH &= ~(0xF << 20);
    GPIOC->CRH |=  (0x3 << 20); // PC13 Output 50MHz
}

void TIMER2_Init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    TIM2->PSC = 7999;
    TIM2->ARR = 999;

    TIM2->DIER |= TIM_DIER_UIE;
    NVIC_EnableIRQ(TIM2_IRQn);

    TIM2->CR1 |= TIM_CR1_CEN;
}

void TIM2_IRQHandler(void) {
    if (TIM2->SR & TIM_SR_UIF) {
        TIM2->SR &= ~TIM_SR_UIF;
        GPIOC->ODR ^= GPIO_ODR_ODR13;
    }
}

int main(void) {
    GPIO_Init();
    TIMER2_Init();

    while(1) {
        // Chip rảnh tay để làm việc khác ở đây
    }
}
