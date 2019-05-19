#define ARGAMOUNT 10
#define ARGLENGTH 50

//==========================
//variabelen

union Argument
{
	char text[ARGLENGTH];
	int  num;
};

/*!Dit is de uart struct. De UART Queue die de front en de logic layer verbind
 * bevat structs van dit type
 */
typedef struct
{
	union Argument arg [ARGAMOUNT];
	//char arg[ARGAMOUNT][ARGLENGTH];

} COMMAND;

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

	COMMAND* Q_members;

} Q_INFO;


//==========================
//functieprototypes
int API_Qinit			(Q_INFO * initQ, int Qsize);
int API_Qwriter			(Q_INFO * writeQ, COMMAND * writeCommand);
int API_Qreader			(Q_INFO * readQ,  COMMAND * readCommand);
int API_Qreader_stealth	(Q_INFO * readQ,  COMMAND * readCommand);
int LOGIC_functionpicker(COMMAND * command_struct);
int API_perform			(Q_INFO * performQ);
