//==========================
//functieprototypes
int API_Qinit(int Qsize);
int API_Qwriter(UART_Q_info * writeQ, UART_command * writeCommand);
int API_Qreader(UART_Q_info * readQ, UART_struct * readCommand);


//==========================
//variabelen

/*!Dit is de struct met info over de Queue. Deze wordt teruggegeven door de API_Qinit functie
 *
 */
typedef struct Qinfo
{
	//! deze variabele geeft aan hoe lang de Q is.
	int Q_size = 0;
	//! dit is de variabele die aan geeft waar in de Q het nieuwste lid zit (++ bij schrijven Q)
	int last_written_Q_member = 0;
	/*! dit is de variabele die aan geeft waar in de Q het laatst gelezen lid zit (++ bij lezen Q).
	 *  Als deze gelijk is aan first_in_Q_member is de Q leeg.
	 */
	int last_read_Q_member = 0;

	UART_command* Q_members;

} UART_Q_info;

/*!Dit is de uart struct. De UART Queue die de front en de logic layer verbind
 * bevat structs van dit type
 */
typedef struct command
{
	char arg[8][20];

} UART_command;

