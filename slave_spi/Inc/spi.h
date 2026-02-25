#ifndef SPI_H_
#define SPI_H_

#include "stm32f103xb.h"

// Định nghĩa đúng tên để main.c không báo lỗi undeclared
#define SR_RXNE    (1U << 0)
#define SR_TXE     (1U << 1)
#define SR_BSY     (1U << 7)

void SPI_Master_Init(void);
void SPI_Slave_Init(void);
void SPI_Transmit(uint8_t *data, uint32_t size);
void SPI_Recieve(uint8_t *data, uint32_t size);
void cs_enable(void);
void cs_disable(void);

#endif
