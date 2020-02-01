#pragma once

unsigned char uart_isdata(void);
unsigned char uart_recv(void);
void uart_send(unsigned char val);
void uart_init(void);
uint8_t uart_peek(void);
void uart_wait_txdone(void);
#define BAUD 9600
#define RECEIVE() uart_recv()
#define SEND(n) uart_send(n)
#define PEEK() uart_peek()
#define UART_BUFLEN 16
#define UARTTX_BUFLEN 16

