/*
 * UartPrint.h
 *
 *  Created on: 30.05.2012
 *      Author: duenda
 */

#ifndef UARTPRINT_H_
#define UARTPRINT_H_

#define usePDCA
#ifndef usePDCA
#define use_USART_TxRdyInt
#endif

void init_err_printf();
void  err_printf ( char *emsg, ...);
void info_printf( char *emsg, ...);

#endif /* UARTPRINT_H_ */