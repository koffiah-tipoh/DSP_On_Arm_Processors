#include "uart.h"

void uart2_tx_init(void) {

	/*** Configure UART GPIO Pin***/
	/* Enable clock access to GPIOA */
	/* Set PA2 mode to Alternate Function mode*/
	/* Set PA2 alternate function type to UART_TX(AF7)*/

	/*** Configure UART ***/
	/* Enable clock access to UART2 */
	/* Configure baud rate */
	/* Configure the transfer direction */
	/* Enable UART module*/
}
