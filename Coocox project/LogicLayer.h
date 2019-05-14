
//==========================
//variabelen

/*!Dit is de uart struct. De UART Queue die de front en de logic layer verbind
 * bevat structs van dit type
 */
typedef struct
{
	char arg[ARGAMOUNT][ARGLENGTH];

} UART_command;

/*!Dit is de struct met info over de Queue. Deze wordt teruggegeven door de API_Qinit functie
 *
 */
typedef struct
{
	//! deze variabele geeft aan hoe lang de Q is.
	int Q_size;
	//! dit is de variabele die aan geeft waar in de Q het nieuwste lid zit (++ bij schrijven Q)
	int last_written_Q_member;
	/*! dit is de variabele die aan geeft waar in de Q het laatst gelezen lid zit (++ bij lezen Q).
	 *  Als deze gelijk is aan first_in_Q_member is de Q leeg.
	 */
	int last_read_Q_member;

	UART_command* Q_members;

} UART_Q_info;


//==========================
//functieprototypes
int API_Qinit			(UART_Q_info * initQ, int Qsize);
int API_Qwriter			(UART_Q_info * writeQ, UART_command * writeCommand);
int API_Qreader			(UART_Q_info * readQ,  UART_command * readCommand);
int API_Qreader_stealth	(UART_Q_info * readQ,  UART_command * readCommand);
