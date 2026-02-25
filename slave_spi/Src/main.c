#include "stm32f103xb.h"
#include "spi.h"
#include "uart1.h"
#include <string.h>

uint8_t rx_buffer[100];
uint8_t tx_buffer[100];

// Đưa hàm delay ra ngoài hàm main
void delay_ms(uint32_t ms) {
    for(uint32_t i = 0; i < ms * 4000; i++) {}
}

int main(void)
{
    uart1_init();
    uart1_write_string("--- STM32 SLAVE: Ready ---\r\n");

    SPI_Slave_Init();

    // In TEST UART 5 lần
    for(int i = 0; i < 5; i++) {
        uart1_write_string("TEST: Slave UART is working!\r\n");
        delay_ms(500);
    }

    memset(tx_buffer, 0, sizeof(tx_buffer));

    while(1)
    {
        uint32_t i = 0;
        uint8_t data_received;
        memset(rx_buffer, 0, sizeof(rx_buffer));

        uart1_write_string("\r\n[SLAVE] Waiting for Master data...\r\n");

        // Đợi byte đầu tiên
        while (!(SPI1->SR & SR_RXNE)) {}

        uint32_t expected_size = 17; // Khớp với "Ping from Master!"

        for (i = 0; i < expected_size && i < sizeof(rx_buffer); i++)
        {
            if (i > 0) {
                 while (!(SPI1->SR & SR_RXNE)) {}
            }
            data_received = (uint8_t)(SPI1->DR & 0xFF);
            rx_buffer[i] = data_received;

            while (!(SPI1->SR & SR_TXE)) {}
            SPI1->DR = 0xFF; // Gửi Dummy byte
        }
        rx_buffer[i] = '\0';

        uart1_write_string("[SLAVE] Received: ");
        uart1_write_string((const char*)rx_buffer);
        uart1_write_string("\r\n");

        while (SPI1->SR & SR_BSY) {}

        // Copy dữ liệu vừa nhận sang buffer truyền
        strncpy((char*)tx_buffer, (const char*)rx_buffer, sizeof(tx_buffer) - 1);

        uint32_t current_byte_to_send = 0;
        uart1_write_string("[SLAVE] Ready to send back: ");
        uart1_write_string((const char*)tx_buffer);
        uart1_write_string("\r\n");

        while(current_byte_to_send < expected_size)
        {
            while (!(SPI1->SR & SR_RXNE)) {} // Chờ Master gửi Clock (Dummy byte)
            data_received = (uint8_t)(SPI1->DR & 0xFF); // Đọc bỏ byte Master gửi

            while (!(SPI1->SR & SR_TXE)) {}
            SPI1->DR = tx_buffer[current_byte_to_send++];
        }

        while (SPI1->SR & SR_BSY) {}
    }
}
