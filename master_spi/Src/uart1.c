#include "uart1.h"

void uart1_init(void) {
    /* 1. Bật clock cho GPIOA và USART1 */
    RCC->APB2ENR |= (1U << 2) | (1U << 14);

    /* 2. Cấu hình PA9 (TX) là AF Push-pull và PA10 (RX) là Input Floating */
    GPIOA->CRH &= ~(0xFF << 4);
    GPIOA->CRH |=  (0xB << 4);     // PA9
    GPIOA->CRH |=  (0x4 << 8);     // PA10

    /* 3. Thiết lập Baudrate 9600 với PCLK = 8MHz */
    USART1->BRR = 0x341;

    /* 4. Cho phép UART, TX và RX hoạt động */
    USART1->CR1 = (1U << 13) | (1U << 3) | (1U << 2);
}

void uart1_write(int ch) {
    /* Chờ cho đến khi thanh ghi truyền trống (TXE) */
    while (!(USART1->SR & (1U << 7))) {}
    USART1->DR = (ch & 0xFF);
}

void uart1_write_string(const char *str) {
    /* Lặp qua từng ký tự trong chuỗi để gửi */
    while (*str) {
        uart1_write(*str++);
    }
}
