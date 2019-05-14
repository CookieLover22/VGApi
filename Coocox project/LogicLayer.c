#include <main.h>
#include <string.h>



void LOGIC_errorhandler(int error)
{

}


/*! Deze functie genereert de Queue die gebruikt kan worden.
 *  Het aantal leden van deze Queue wordt meegegeven en de
 *  functie geeft het adres van de Queue terug.
 */
int API_Qinit(UART_Q_info * initQ, int Qsize)
{
	if(Qsize < 1) return QSIZEERROR;
	UART_command initCommand[Qsize];

	initQ->Q_size = Qsize;
	initQ->last_written_Q_member = 0;
	initQ->last_read_Q_member = 0;
	initQ->Q_members = initCommand;

	return NOERROR;
}

/*!Deze functie schrijft een nieuw lid in de Q en returnt een errorcode.
 * Het adres van de Q (van API_Qinit()) wordt meegegeven aan de functie.
 * Ook wordt de UART_command struct die in de Q moet komen meegegeven
 */
int API_Qwriter(UART_Q_info * writeQ, UART_command * writeCommand)
{


	if (writeQ->last_written_Q_member < writeQ->Q_size - 1)
	{
		if (writeQ->last_read_Q_member == writeQ->last_written_Q_member+1) return FULLQ;
		writeQ->last_written_Q_member++;
	}
	else
	{
		if (writeQ->last_read_Q_member == 0) return FULLQ;
		writeQ->last_written_Q_member = 0;
	}

	writeQ->Q_members[writeQ->last_written_Q_member] = *writeCommand;

	return NOERROR;

}

/*!Deze functie leest het oudste lid naar de Q en returnt een errorcode.
 * Het adres van de Q (van API_Qinit()) wordt meegegeven aan de functie.
 * Deze functie verwijderd het zojuist gelezen lid.
 */
int API_Qreader(UART_Q_info * readQ, UART_command * readCommand)
{
	if (readQ->last_read_Q_member == readQ->last_written_Q_member) return EMPTYQ;
	if (readQ->last_read_Q_member < readQ->Q_size - 1) readQ->last_read_Q_member++;
	else readQ->last_read_Q_member = 0;

	*readCommand = readQ->Q_members[readQ->last_read_Q_member];

	return NOERROR;
}
/*!Deze functie leest het oudste lid naar de Q en returnt een errorcode.
 * Het adres van de Q (van API_Qinit()) wordt meegegeven aan de functie.
 * Deze functie verwijderd niet het zojuist gelezen lid.
 */
int API_Qreader_stealth(UART_Q_info * readQ, UART_command * readCommand)
{
	if (readQ->last_read_Q_member == readQ->last_written_Q_member) return EMPTYQ;

	*readCommand = readQ->Q_members[readQ->last_read_Q_member+1];

	return NOERROR;
}

int LOGIC_functionpicker()
{
	int error = 0;
	UART_command command_struct;

	error = API_Qreader(&front_to_logic_Q, &command_struct);
	if (error) LOGIC_errorhandler(error);

	int i;
	for (i = 0; i < ARGAMOUNT; i++)
	{
		// de volgende if checkt of het eerste character van het commando een getal is (of - voor negatief).
		// als dat zo is wordt hij omgezet
		if (command_struct.arg[i].text[0] == 45 || command_struct.arg[i].text[0] >= 48 || command_struct.arg[i].text[0] <= 57)
		{
			//het argument is een union tussen num en text (een int en een string)
			//deze lijn zet de string om in een int en plaatst het terug in het zelfde geheugen!
			command_struct.arg[i].num = atoi(command_struct.arg[i].text);
		}
	}

	if (!strcmp(command_struct.arg[0].text, "bitmap"))
	{

	}

	if (!strcmp(command_struct.arg[0].text, "clearscherm"))
	{

	}

	if (!strcmp(command_struct.arg[0].text, "driehoek"))
	{

	}

	if (!strcmp(command_struct.arg[0].text, "ellips"))
	{

	}

	if (!strcmp(command_struct.arg[0].text, "lijn"))
	{

	}

	if (!strcmp(command_struct.arg[0].text, "rechthoek"))
	{

	}

	if (!strcmp(command_struct.arg[0].text, "tekst"))
	{
		API_draw_text(	command_struct.arg[1],
						command_struct.arg[2],
						command_struct.arg[3],
						command_struct.arg[4],
						command_struct.arg[5],
						command_struct.arg[6],
						command_struct.arg[7],
						command_struct.arg[8]);
	}

	if (!strcmp(command_struct.arg[0].text, "wacht"))
	{

	}

	//als dit deel van de functie bereikt wordt is het commando niet herkend
	return COMMANDERROR;
}

