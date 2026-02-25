#include "spi.h"

void SPI_Master_Init(void) {
    /* Bật clock SPI1 và GPIOA */
    RCC->APB2ENR |= (1U << 12) | (1U << 2);

    /* Cấu hình PA5(SCK), PA6(MISO), PA7(MOSI) */
    GPIOA->CRL &= ~(0xFFF << 20);
    GPIOA->CRL |= (0xB << 20) | (0x4 << 24) | (0xB << 28);

    /* Cấu hình PA4 làm chân CS (Output) cho Master */
    GPIOA->CRL &= ~(0xF << 16);
    GPIOA->CRL |= (0x3 << 16);
    GPIOA->ODR |= (1U << 4); // Mặc định để mức Cao

    /* Cấu hình SPI: Master mode, Baudrate fPCLK/16, SPE=1 */
    SPI1->CR1 = (1U << 2) | (0x3 << 3) | (1U << 6);
}

void SPI_Slave_Init(void) {
    /* Bật clock SPI1 và GPIOA */
    RCC->APB2ENR |= (1U << 12) | (1U << 2);

    /* Cấu hình chân cho Slave: PA5, PA6, PA7 */
    GPIOA->CRL &= ~(0xFFF << 20);
    GPIOA->CRL |= (0x4 << 20) | (0xB << 24) | (0x4 << 28);

    /* PA4 (NSS) cấu hình làm Input Floating */
    GPIOA->CRL &= ~(0xF << 16);
    GPIOA->CRL |= (0x4 << 16);

    /* Cấu hình SPI: Slave mode, SPE=1 */
    SPI1->CR1 = (1U << 6);
}

void SPI_Transmit(uint8_t *data, uint32_t size) {
    for(uint32_t i = 0; i < size; i++) {
        /* Chờ thanh ghi truyền trống */
        while (!(SPI1->SR & (1U << 1))) {}
        SPI1->DR = data[i];
    }
    /* Chờ SPI hết bận */
    while (SPI1->SR & (1U << 7)) {}
}

void SPI_Recieve(uint8_t *data, uint32_t size) {
    for(uint32_t i = 0; i < size; i++) {
        /* Gửi Dummy byte để tạo xung Clock nhận dữ liệu */
        while (!(SPI1->SR & (1U << 1))) {}
        SPI1->DR = 0xFF;

        /* Chờ dữ liệu về */
        while (!(SPI1->SR & (1U << 0))) {}
        data[i] = (uint8_t)SPI1->DR;
    }
}

void cs_enable(void) {
    /* Kéo PA4 xuống Thấp để chọn Slave */
    GPIOA->ODR &= ~(1U << 4);
}

void cs_disable(void) {
    /* Kéo PA4 lên Cao để dừng giao tiếp */
    GPIOA->ODR |= (1U << 4);
}
