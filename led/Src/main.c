#include <stdint.h>

// Địa chỉ các thanh ghi
#define RCC_BASE      0x40021000UL
#define GPIOA_BASE    0x40010800UL
#define GPIOC_BASE    0x40011000UL

#define RCC_APB2ENR   (*(volatile uint32_t *)(RCC_BASE + 0x18UL))

// Cấu hình LED (PC13)
#define GPIOC_CRH     (*(volatile uint32_t *)(GPIOC_BASE + 0x04UL))
#define GPIOC_ODR     (*(volatile uint32_t *)(GPIOC_BASE + 0x0CUL))

// Cấu hình Nút nhấn (PA0)
#define GPIOA_CRL     (*(volatile uint32_t *)(GPIOA_BASE + 0x00UL))
#define GPIOA_IDR     (*(volatile uint32_t *)(GPIOA_BASE + 0x08UL))
#define GPIOA_ODR     (*(volatile uint32_t *)(GPIOA_BASE + 0x0CUL))

void GPIO_Init(void) {
    // 1. Bật Clock cho Port A và Port C
    RCC_APB2ENR |= (1U << 2) | (1U << 4);

    // 2. Cấu hình PC13: Output Push-Pull (LED trên board)
    GPIOC_CRH &= ~(0xFU << 20);
    GPIOC_CRH |=  (0x2U << 20); // Mode Output 2MHz

    // 3. Cấu hình PA0: Input Pull-up (Nút nhấn)
    GPIOA_CRL &= ~(0xFU << 0);
    GPIOA_CRL |=  (0x8U << 0);  // Mode Input với Pull-up/down
    GPIOA_ODR |=  (1U << 0);    // Chọn Pull-up (kéo lên 3.3V)
}

// Hàm tạo trễ đơn giản để chống rung phím (Debounce)
void delay(int ms) {
    for (int i = 0; i < ms * 1000; i++) { __asm("nop"); }
}

int main(void) {
    GPIO_Init();

    while (1) {
        // Kiểm tra nếu nút nhấn PA0 được nhấn (nối xuống GND nên mức logic là 0)
        if (!(GPIOA_IDR & (1U << 0))) {

            // Đảo trạng thái LED PC13 (Toggle)
            GPIOC_ODR ^= (1U << 13);

            // Chờ cho đến khi thả nút ra để không bị nhảy loạn
            while (!(GPIOA_IDR & (1U << 0)));

            // Trễ một chút chống rung
            delay(20);
        }
    }
}
