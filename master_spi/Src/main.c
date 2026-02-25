#include "stm32f103xb.h"
#include "spi.h"
#include "uart1.h"
#include <string.h>


void delay_ms(uint32_t ms) {
    for(uint32_t i = 0; i < ms * 4000; i++) {}
}

int main(void)
{

    uart1_init();
    uart1_write_string("--- STM32 MASTER: Ready ---\r\n");


    SPI_Master_Init();

    uint8_t tx_data[] = "Ping from Master!";
    uint32_t tx_size = sizeof(tx_data) - 1;

    uint8_t rx_buffer[100];
    uint32_t rx_size = tx_size;

    while(1)
    {
        uart1_write_string("\r\n[MASTER] Starting transaction...\r\n");


        cs_enable();


        uart1_write_string("[MASTER] Sending: ");
        uart1_write_string((const char*)tx_data);
        uart1_write_string("\r\n");


        SPI_Transmit(tx_data, tx_size);


        uart1_write_string("[MASTER] Receiving acknowledgement/data...\r\n");


        SPI_Recieve(rx_buffer, rx_size);
        rx_buffer[rx_size] = '\0';


        cs_disable();


        uart1_write_string("[MASTER] Received: ");
        uart1_write_string((const char*)rx_buffer);
        uart1_write_string("\r\n");

        delay_ms(2000);
    }
}
