#include <main.h>


void LOGIC_errorhandler(int error)
{

}


/*! Deze functie genereert de Queue die gebruikt kan worden.
 *  Het aantal leden van deze Queue wordt meegegeven en de
 *  functie geeft het adres van de Queue terug.
 */
int API_Qinit(Q_INFO * initQ, int Qsize)
{
	if(Qsize < 1) return QSIZEERROR;

	COMMAND initCommand[Qsize];
	//LCD_putint(sizeof(initCommand));
	void * command_pointer = malloc(sizeof(initCommand));

	initQ->Q_size = Qsize;
	initQ->last_written_Q_member = 0;
	initQ->last_read_Q_member = 0;
	initQ->Q_members = command_pointer;

	return NOERROR;
}

/*!Deze functie schrijft een nieuw lid in de Q en returnt een errorcode.
 * Het adres van de Q (van API_Qinit()) wordt meegegeven aan de functie.
 * Ook wordt de COMMAND struct die in de Q moet komen meegegeven
 */
int API_Qwriter(Q_INFO * writeQ, COMMAND * writeCommand)
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
int API_Qreader(Q_INFO * readQ, COMMAND * readCommand)
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
int API_Qreader_stealth(Q_INFO * readQ, COMMAND * readCommand)
{
	if (readQ->last_read_Q_member == readQ->last_written_Q_member) return EMPTYQ;

	*readCommand = readQ->Q_members[readQ->last_read_Q_member+1];

	return NOERROR;
}



/*!Deze functie zet het argument dat meegegeven om in een kleur.
 * Als de kleur niet bestaat of als het argument geen kleur is
 * wordt UNDEFINEDCOLOR gereturnt.
 */
int LOGIC_colorpicker(char * color_string, int *color_num)
{
	int test1 = strcmp(color_string, "zwart");
	int test2 = strcmp(color_string, "blauw");
	if (0==strcmp(color_string, "zwart"))  {*color_num = VGA_COL_BLACK;  return NOERROR; }
	if (0==strcmp(color_string, "blauw"))  {
		*color_num = VGA_COL_BLUE;
	return NOERROR; }
	if (0==strcmp(color_string, "groen"))  {*color_num = VGA_COL_GREEN;  return NOERROR; }
	if (0==strcmp(color_string, "rood"))   {*color_num = VGA_COL_RED; 	 return NOERROR; }
	if (0==strcmp(color_string, "wit"))    {*color_num = VGA_COL_WHITE;  return NOERROR; }
	if (0==strcmp(color_string, "cyaan"))  {*color_num = VGA_COL_CYAN; 	 return NOERROR; }
	if (0==strcmp(color_string, "magenta")){*color_num = VGA_COL_MAGENTA;return NOERROR; }
	if (0==strcmp(color_string, "geel"))   {*color_num = VGA_COL_YELLOW; return NOERROR; }

	return UNDEFINEDCOLOR;
}

int LOGIC_functionpicker(COMMAND *command_struct)
{
	int error = 0;

	//error = API_Qreader(&front_to_logic_Q, &command_struct);
	if (error) return error;

	int i;
	for (i = 0; i < ARGAMOUNT; i++)
	{
		// de volgende if checkt of het eerste character van het commando een getal is (of - voor negatief).
		// als dat zo is wordt hij omgezet
		if (command_struct->arg[i].text[0] == 45 || command_struct->arg[i].text[0] >= 48 || command_struct->arg[i].text[0] <= 57)
		{
			//het argument is een union tussen num en text (een int en een string)
			//deze lijn zet de string om in een int en plaatst het terug in het zelfde geheugen!
			command_struct->arg[i].num = atoi(command_struct->arg[i].text);
		}
	}



	if (!strcmp(command_struct->arg[0].text, "bitmap"))
	{
		API_draw_bitmap(command_struct->arg[1].num,
						command_struct->arg[2].num,
						command_struct->arg[3].num);
	}

	if (!strcmp(command_struct->arg[0].text, "clearscherm"))
	{
		error = LOGIC_colorpicker(command_struct->arg[1].text, &command_struct->arg[1].num);
		API_clearscreen(command_struct->arg[1].num);

		return error;
	}

	if (!strcmp(command_struct->arg[0].text, "driehoek"))
	{
		return COMMANDERROR;
	}

	if (!strcmp(command_struct->arg[0].text, "ellips"))
	{
		return COMMANDERROR;
	}

	if (!strcmp(command_struct->arg[0].text, "lijn"))
	{
		error = LOGIC_colorpicker(command_struct->arg[7].text, &command_struct->arg[7].num);
		API_draw_line(	command_struct->arg[1].num,
						command_struct->arg[2].num,
						command_struct->arg[3].num,
						command_struct->arg[4].num,
						command_struct->arg[5].num,
						command_struct->arg[6].num,
						command_struct->arg[7].num);
		return error;
	}

	if (strcmp(command_struct->arg[0].text, "rechthoek"))
	{
		//char * stringcol = command_struct->arg[5].text;
		char stringtest [] = "blauw";
		error = LOGIC_colorpicker(stringtest,&command_struct->arg[5].num);
		API_draw_rectangle(	command_struct->arg[1].num,
							command_struct->arg[2].num,
							command_struct->arg[3].num,
							command_struct->arg[4].num,
							command_struct->arg[5].num,
							command_struct->arg[6].num,
							command_struct->arg[7].num,
							command_struct->arg[8].num);
		return error;
	}

	if (!strcmp(command_struct->arg[0].text, "tekst"))
	{
		error = LOGIC_colorpicker(command_struct->arg[7].text,&command_struct->arg[5].num);
		API_draw_text(	command_struct->arg[1].num,
						command_struct->arg[2].num,
						command_struct->arg[3].num,
						command_struct->arg[4].text,
						command_struct->arg[5].text,
						command_struct->arg[6].num,
						command_struct->arg[7].num,
						command_struct->arg[8].num);
		return error;
	}

	if (!strcmp(command_struct->arg[0].text, "wacht"))
	{
		return COMMANDERROR;
	}

	//als dit deel van de functie bereikt wordt is het commando niet herkend
	return COMMANDERROR;
}

int API_perform(Q_INFO * performQ) //naam onder voorbehoud
{
	int error = NOERROR;
	COMMAND performCommand;


	error = API_Qreader(performQ, &performCommand);
	error = LOGIC_functionpicker(&performCommand);
	//error = LOGIC_functionpicker(&write_struct);

	return error;
}
