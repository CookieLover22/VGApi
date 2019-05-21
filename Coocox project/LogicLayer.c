#include <main.h>
#include "uart.h"


void LOGIC_errorhandler(int error)
{
	//if(error && error != EMPTYQ){UART_putint(error);UART_putchar('\n');}

	switch (error)
	{
	//case NOERROR: 							UART_puts("NOERROR\n"); break;
	case QSIZEERROR: 						UART_puts("QSIZEERROR\n"); break;
	//case EMPTYQ: 							UART_puts("EMPTYQ\n"); break;
	case FULLQ: 							UART_puts("FULLQ\n"); break;
	case COMMANDERROR: 						UART_puts("COMMANDERROR\n"); break;
	case UNDEFINEDCOLOR: 					UART_puts("UNDEFINEDCOLOR\n"); break;
	case OUT_OF_BAUNCE: 					UART_puts("OUT_OF_BOWNZZ\n"); break;
	case UNDEFINED_BITMAP_NR: 				UART_puts("UNDEFINED_BITMAP_NR\n"); break;
	case ONLY_FONTSTYLE_NORMAL_AVAILIBLE: 	UART_puts("ONLY_FONTSTYLE_NORMAL_AVAILIBLE\n"); break;
	case UNDEFINED_FONTNAME: 				UART_puts("UNDEFINED_FONTNAME\n"); break;
	case FONTSIZE_NOT_EXISTING: 			UART_puts("FONTSIZE_NOT_EXISTING\n"); break;
	case FILLED_NOT_0_OR_1: 				UART_puts("FILLED_NOT_0_OR_1\n"); break;
	case TOOFARBACKERROR: 					UART_puts("TOOFARBACKERROR\n"); break;

	default : return;
	}

	//print de commando's
	int i;
	for (i = 0; i < ARGAMOUNT; i++)
	{
		UART_puts(front_to_logic_Q.Q_members[front_to_logic_Q.last_read_Q_member-1].arg[i].text);
		UART_puts(", ");
	}

	UART_puts("\n");
}


/*! Deze functie genereert de Queue die gebruikt kan worden.
 *  Het aantal leden van deze Queue wordt meegegeven en de
 *  functie geeft het adres van de Queue terug.
 */

/*
int API_Qinit(Q_INFO * initQ, int Qsize)
{
	if(Qsize < 1) return QSIZEERROR;

	COMMAND initCommand[Qsize];
	//LCD_putint(sizeof(initCommand));
	void * command_pointer = malloc(sizeof(initCommand));

	//UART_puts("\naddr:");
	//UART_putint((int)command_pointer);

	initQ->Q_size = Qsize;
	initQ->last_written_Q_member = 0;
	initQ->last_read_Q_member = 0;
	initQ->Q_members = command_pointer;

	return NOERROR;
}
*/

/*!Deze functie schrijft een nieuw lid in de Q en returnt een errorcode.
 * Het adres van de Q (van API_Qinit()) wordt meegegeven aan de functie.
 * Ook wordt de COMMAND struct die in de Q moet komen meegegeven
 */
int API_Qwriter(Q_INFO * writeQ, COMMAND * writeCommand)
{

	if (writeQ->last_written_Q_member < writeQ->Q_size - 1)
		{if (writeQ->last_read_Q_member == writeQ->last_written_Q_member+1) return FULLQ;}
	else {if (writeQ->last_read_Q_member == 0) return FULLQ;}

	//if (writeQ->last_written_Q_member == 1) writeQ->last_written_Q_member =4; //kapot geheugen over slaan

	//UART_puts("\naddr:");
	//UART_putint((int)&writeQ->Q_members[writeQ->last_written_Q_member]);

	writeQ->Q_members[writeQ->last_written_Q_member] = *writeCommand;

	//UART_puts("\naddr:");
	//UART_putint((int)&writeQ->Q_members[writeQ->last_written_Q_member]);

	//UART_puts("\nqsize:");
	//UART_putint(writeQ->Q_size);
	//UART_puts("\nlastw:");
	//UART_putint(writeQ->last_written_Q_member);
	//UART_puts("\nlastr:");
	//UART_putint(writeQ->last_read_Q_member);

	if (writeQ->last_written_Q_member < writeQ->Q_size - 1) writeQ->last_written_Q_member++;
	else writeQ->last_written_Q_member = 0;

	return NOERROR;

}

/*!Deze functie leest het oudste lid naar de Q en returnt een errorcode.
 * Het adres van de Q (van API_Qinit()) wordt meegegeven aan de functie.
 * Deze functie verwijderd het zojuist gelezen lid.
 */
int API_Qreader(Q_INFO * readQ, COMMAND * readCommand)
{
	if (readQ->last_read_Q_member == readQ->last_written_Q_member) return EMPTYQ;

	*readCommand = readQ->Q_members[readQ->last_read_Q_member];

	if (readQ->last_read_Q_member < readQ->Q_size - 1) readQ->last_read_Q_member++;
	else readQ->last_read_Q_member = 0;



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
	//UART_puts(color_string);
	if (0==strcmp(color_string, "zwart"))  		{*color_num = VGA_COL_BLACK;					return NOERROR; }
	if (0==strcmp(color_string, "blauw"))  		{*color_num = VGA_COL_BLUE;						return NOERROR; }
	if (0==strcmp(color_string, "lichtblauw"))  {*color_num = VGA_COL_BLUE | 0b01001101;		return NOERROR; }
	if (0==strcmp(color_string, "groen"))  		{*color_num = VGA_COL_GREEN;					return NOERROR; }
	if (0==strcmp(color_string, "rood"))   		{*color_num = VGA_COL_RED;						return NOERROR; }
	if (0==strcmp(color_string, "wit"))    		{*color_num = VGA_COL_WHITE;  					return NOERROR; }
	if (0==strcmp(color_string, "cyaan"))  		{*color_num = VGA_COL_CYAN; 	 				return NOERROR; }
	if (0==strcmp(color_string, "lichtcyaan"))  {*color_num = VGA_COL_CYAN | 0b01101101; 	 	return NOERROR; }
	if (0==strcmp(color_string, "magenta"))		{*color_num = VGA_COL_MAGENTA;					return NOERROR; }
	if (0==strcmp(color_string, "geel"))   		{*color_num = VGA_COL_YELLOW; 					return NOERROR; }
	if (0==strcmp(color_string, "bruin"))   	{*color_num = VGA_COL_BROWN; 					return NOERROR; }
	if (0==strcmp(color_string, "oranje"))   	{*color_num = 168; 					return NOERROR; }

	*color_num = VGA_COL_BLACK;
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
		if (command_struct->arg[i].text[0] == '-' ||
		   (command_struct->arg[i].text[0] >= '0' &&
			command_struct->arg[i].text[0] <= '9'))
		{
			//het argument is een union tussen num en text (een int en een string)
			//deze lijn zet de string om in een int en plaatst het terug in het zelfde geheugen!
			command_struct->arg[i].num = atoi(command_struct->arg[i].text);
		}
	}



	if (!strcmp(command_struct->arg[0].text, "bitmap"))
	{
		//return COMMANDERROR;
		error = API_draw_bitmap(command_struct->arg[2].num,
								command_struct->arg[3].num,
								command_struct->arg[1].num);
		return error;
	}

	if (!strcmp(command_struct->arg[0].text, "clearscherm"))
	{
		//UART_puts("clear");

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

	if (!strcmp(command_struct->arg[0].text, "cirkel"))
	{

		error = LOGIC_colorpicker(command_struct->arg[4].text, &command_struct->arg[4].num);
		if(error) return error;
		error = API_draw_circle(command_struct->arg[1].num,
								command_struct->arg[2].num,
								command_struct->arg[3].num,
								command_struct->arg[4].num,
								0);//command_struct->arg[5].num);

		return error;
	}

	if (!strcmp(command_struct->arg[0].text, "lijn"))
	{
		//UART_puts("lijn");

		error = LOGIC_colorpicker(command_struct->arg[5].text, &command_struct->arg[5].num); //CHECK

		if (error) return error;

		error = API_draw_line(	command_struct->arg[1].num,
						command_struct->arg[2].num,
						command_struct->arg[3].num,
						command_struct->arg[4].num,
						command_struct->arg[5].num, //CHECK
						command_struct->arg[6].num, //CHECK
						0);//command_struct->arg[7].num);

		return error;

	}

	if (!strcmp(command_struct->arg[0].text, "rechthoek"))
	{
		//char * stringcol = command_struct->arg[5].text;
		//char stringtest [] = "blauw";
		//UART_puts("rechthoek");
		error = LOGIC_colorpicker(command_struct->arg[5].text,&command_struct->arg[5].num);
		API_draw_rectangle(	command_struct->arg[1].num,
							command_struct->arg[2].num,
							command_struct->arg[3].num,
							command_struct->arg[4].num,
							command_struct->arg[5].num,
							command_struct->arg[6].num,
							0,//command_struct->arg[7].num,
							0);//command_struct->arg[8].num);
		return error;
	}

	if (!strcmp(command_struct->arg[0].text, "tekst"))
	{
		//UART_puts("tekst");

		error = LOGIC_colorpicker(command_struct->arg[3].text,&command_struct->arg[3].num);//CHECK
		if (error) return error;
		error = API_draw_text(	command_struct->arg[1].num,
								command_struct->arg[2].num,
								command_struct->arg[3].num,//CHECK
								command_struct->arg[4].text,//CHECK
								command_struct->arg[5].text,
								command_struct->arg[6].num,
								0,//command_struct->arg[7].num,
								0);//command_struct->arg[8].num);
		return error;
	}

	if (!strcmp(command_struct->arg[0].text, "figuur"))
		{

			error = LOGIC_colorpicker(command_struct->arg[11].text,&command_struct->arg[11].num);//CHECK
			if (error) return error;
			error = API_draw_figure(command_struct->arg[1].num,
									command_struct->arg[2].num,
									command_struct->arg[3].num,
									command_struct->arg[4].num,
									command_struct->arg[5].num,
									command_struct->arg[6].num,
									command_struct->arg[7].num,
									command_struct->arg[8].num,
									command_struct->arg[9].num,
									command_struct->arg[10].num,
									command_struct->arg[11].num,
									0//command_struct->arg[12].num
									);
			return error;
		}

	if (!strcmp(command_struct->arg[0].text, "wacht"))
	{
		DELAY_screens(command_struct->arg[1].num);
		return NOERROR;
	}

	if (!strcmp(command_struct->arg[0].text, "herhaal"))
	{
		if(command_struct->arg[1].num > QLENGTH) return TOOFARBACKERROR;

		int herhaalaantal;
		int herhaalplaats;


		if(!strcmp(command_struct->arg[2].text, "eindeloos")) herhaalaantal = 1; //in geval van eindeloos, voeg maar een keer toe, meer later
		else herhaalaantal = command_struct->arg[2].num;

		if(front_to_logic_Q.last_read_Q_member > command_struct->arg[1].num)
			herhaalplaats = front_to_logic_Q.last_read_Q_member - command_struct->arg[1].num;
		else herhaalplaats = front_to_logic_Q.last_read_Q_member + front_to_logic_Q.Q_size - command_struct->arg[1].num;

		int i, k;
		for (i = 0; i < herhaalaantal; i++)
		{
			for (k = 0; k < command_struct->arg[1].num-1; k++)
			{
				API_Qwriter(&front_to_logic_Q, &front_to_logic_Q.Q_members [(herhaalplaats + k) % front_to_logic_Q.Q_size] );

			}
		}

		//voeg herhaal weer toe als eindeloos herhaald moet worden
		if(!strcmp(command_struct->arg[2].text, "eindeloos"))
		{
			if (front_to_logic_Q.last_read_Q_member > 0) API_Qwriter(&front_to_logic_Q, &front_to_logic_Q.Q_members[front_to_logic_Q.last_read_Q_member-1]);
			else API_Qwriter(&front_to_logic_Q, &front_to_logic_Q.Q_members[front_to_logic_Q.Q_size-1]);
		}


		return NOERROR;
	}

	//als dit deel van de functie bereikt wordt is het commando niet herkend
	return COMMANDERROR;
}

int API_perform(Q_INFO * performQ) //naam onder voorbehoud
{
	int error = NOERROR;
	COMMAND performCommand;


	error = API_Qreader(performQ, &performCommand);
	if(error) return error;
	error = LOGIC_functionpicker(&performCommand);
	//error = LOGIC_functionpicker(&write_struct);

	return error;
}
