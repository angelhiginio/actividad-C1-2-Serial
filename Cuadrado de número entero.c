#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"

#define UART_PORT_NUM      UART_NUM_0
#define UART_BAUD_RATE     115200
#define BUF_SIZE           1024

void configurar_uart() {
    uart_config_t uart_config = {
        .baud_rate = UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT, 
    };
    uart_param_config(UART_PORT_NUM, &uart_config);
    uart_driver_install(UART_PORT_NUM, BUF_SIZE * 2, 0, 0, NULL, 0);
}


void app_main(void) {
    configurar_uart();
    char input[BUF_SIZE];

    printf("\n--- ESP32 Serial Monitor (PuTTY) ---\n");
    
    while (1) {
        printf("Ingrese un numero entero positivo:\n");
        
        int len = uart_read_bytes(UART_PORT_NUM, (uint8_t*)input, BUF_SIZE - 1, portMAX_DELAY);
        
        if (len > 0) {
            input[len] = '\0';
            char *pos;
            if ((pos=strchr(input, '\n')) != NULL) *pos = '\0';
            if ((pos=strchr(input, '\r')) != NULL) *pos = '\0';

           
        }
        vTaskDelay(pdMS_TO_TICKS(100)); 
    }
}
