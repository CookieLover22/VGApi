#include <main.h>
#include <LogicLayer.h>

/*! Deze functie genereert de Queue die gebruikt kan worden.
 *  Het aantal leden van deze Queue wordt meegegeven en de
 *  functie geeft het adres van de Queue terug.
 */
UART_Q_info * API_Qinit(int Qsize, int * error)
{
	if(Qsize < 1) {*error = 1; return QSIZEERROR;}
	UART_Q_info initQ;
	UART_command initCommand[Qlength];

	initQ.Q_size = Qlength;
	initQ.last_written_Q_member = 0;
	initQ.last_read_Q_member = 0;
	initQ.Q_address = &initCommand;

	*error = NOERROR;
	return &initQ;
}

/*!Deze functie schrijft een nieuw lid in de Q en returnt een errorcode.
 * Het adres van de Q (van API_Qinit()) wordt meegegeven aan de functie.
 * Ook wordt de UART_command struct die in de Q moet komen meegegeven
 */
int API_Qwriter(UART_Q_info * writeQ, UART_command * writeCommand)
{
	if (writeQ->last_written_Q_member < writeQ->Q_size - 1) writeQ->last_written_Q_member++;
	else writeQ->last_written_Q_member = 0;

	writeQ->Q_members[writeQ->last_written_Q_member] = *writeCommand;

	return NOERROR;

}

/*!Deze functie leest het oudste lid naar de Q en returnt een errorcode.
 * Het adres van de Q (van API_Qinit()) wordt meegegeven aan de functie.
 * Deze functie verwijderd het zojuist gelezen lid.
 */
int API_Qreader(UART_Q_info * readQ, UART_struct * readCommand)
{
	if (readQ->last_read_Q_member == readQ) return EMPTYQ;
	if (readQ->last_read_Q_member < readQ->Q_size - 1) readQ->last_read_Q_member++;
	else readQ->last_read_Q_member = 0;

	readCommand = readQ->Q_members[readQ->last_read_Q_member];

	return NOERROR;
}
/*!Deze functie leest het oudste lid naar de Q en returnt een errorcode.
 * Het adres van de Q (van API_Qinit()) wordt meegegeven aan de functie.
 * Deze functie verwijderd niet het zojuist gelezen lid.
 */
int API_Qreader_stealth(UART_Q_info * readQ, UART_struct * readCommand)
{
	if (readQ->last_read_Q_member == readQ) return EMPTYQ;

	readCommand = readQ->Q_members[readQ->last_read_Q_member+1];

	return NOERROR;
}

int API_functionpicker()
{

	switch(expression)
	{

	   case constant-expression  :
	      statement(s);
	      break; /* optional */

	   case constant-expression  :
	      statement(s);
	      break; /* optional */

	   /* you can have any number of case statements */
	   default : /* Optional */
	   statement(s);
	}
}
