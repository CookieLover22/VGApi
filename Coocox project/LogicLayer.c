#include <main.h>
#include "uart.h"

/**@file LogicLayer.c
 * @author Kaya Hartwig
 *
 * In deze file staan de LogicLayer functies. Dit zijn de errorhandler, de functionpicker en de queue read en write functies.
 */

 /**
 * @brief Deze functie krijgt de errorcode mee en print dan de naam van de error en de inhoud van het laatste commando op de
 * uart.
 *
 * @note  Dit is een van de weinige functies die geen errors returnt.
 *
 * @param error Dit is de errorcode
 *
 */
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
	case OUT_OF_BOUNDS: 					UART_puts("OUT_OF_BOWNZZ\n"); break;
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

/**
* @brief Deze functie schrijft een nieuw lid in de Q en returnt een errorcode.
*
* @warning Deze functie kan niet in de Queue schrijven als de Queue vol is.
* @param writeQ Dit is het Q_INFO struct waar de informatie over de Queue in staat
* @param writeCommand Dit is het COMMAND struct dat in de Queue geplaatst moet worden.
* @return De functie returnt een errorcode, namelijk: NOERROR of FULLQ
*/
int API_Qwriter(Q_INFO * writeQ, COMMAND * writeCommand)
{

	if (writeQ->last_written_Q_member < writeQ->Q_size - 1)
		{if (writeQ->last_read_Q_member == writeQ->last_written_Q_member+1) return FULLQ;}
	else {if (writeQ->last_read_Q_member == 0) return FULLQ;}

	writeQ->Q_members[writeQ->last_written_Q_member] = *writeCommand;

	if (writeQ->last_written_Q_member < writeQ->Q_size - 1) writeQ->last_written_Q_member++;
	else writeQ->last_written_Q_member = 0;

	return NOERROR;

}


/**
* @brief Deze functie leest het oudste lid uit de Q en returnt een errorcode.
* Het net gelezen lid wordt uit de Q gehaald.
*
* @param readQ Dit is het Q_INFO struct waar de informatie over de Queue in staat
* @param writeCommand Dit is een pointer naar het COMMAND struct dat uitgelezen wordt.
* @return De functie returnt een errorcode, namelijk: NOERROR of EMPTYQ
*/
int API_Qreader(Q_INFO * readQ, COMMAND * readCommand)
{
	if (readQ->last_read_Q_member == readQ->last_written_Q_member) return EMPTYQ;

	*readCommand = readQ->Q_members[readQ->last_read_Q_member];

	if (readQ->last_read_Q_member < readQ->Q_size - 1) readQ->last_read_Q_member++;
	else readQ->last_read_Q_member = 0;

	return NOERROR;
}

/**
* @brief Deze functie leest het oudste lid uit de Q en returnt een errorcode.
* Het enige verschil tussen deze functie en API_Qreader is dat deze functie
* het zojuist gelezen lid niet uit de Q haalt.
*
* @param readQ Dit is het Q_INFO struct waar de informatie over de Queue in staat
* @param writeCommand Dit is een pointer naar het COMMAND struct dat uitgelezen wordt.
* @return De functie returnt een errorcode, namelijk: NOERROR of EMPTYQ
*/
int API_Qreader_stealth(Q_INFO * readQ, COMMAND * readCommand)
{
	if (readQ->last_read_Q_member == readQ->last_written_Q_member) return EMPTYQ;

	*readCommand = readQ->Q_members[readQ->last_read_Q_member+1];

	return NOERROR;
}

/**
* @brief Deze functie voert het herhaal commando uit.
* Het herhaal commando wordt uitgevoerd door de laatste paar
* leden in de queue opnieuw in de queue te plaatsen
*
* @note Er kan niet meer herhaald worden dan de queue lang is.
* @param command_struct Dit is een pointer naar het COMMAND struct dat het herhaalcommando bevat
* @return De functie returnt een errorcode, namelijk: NOERROR, TOOFARBACKERROR of de queue functie errors
*/
int LOGIC_repeat(COMMAND * command_struct)
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
			int error = API_Qwriter(&front_to_logic_Q, &front_to_logic_Q.Q_members [(herhaalplaats + k) % front_to_logic_Q.Q_size] );
			if (error != NOERROR) return error;
		}
	}

	//voeg herhaal weer toe als eindeloos herhaald moet worden
	if(!strcmp(command_struct->arg[2].text, "eindeloos"))
	{
		int error = NOERROR;
		if (front_to_logic_Q.last_read_Q_member > 0) error = API_Qwriter(&front_to_logic_Q, &front_to_logic_Q.Q_members[front_to_logic_Q.last_read_Q_member-1]);
		else error = API_Qwriter(&front_to_logic_Q, &front_to_logic_Q.Q_members[front_to_logic_Q.Q_size-1]);
		if (error != NOERROR) return error;
	}

	return NOERROR;
}


/**
* @brief Deze zet een string met de naam van een kleur om in een 8-bits kleur
*
* @note Onherkende strings worden als zwart gezien. Er wordt dan ook een error gereturnt
* @param color_string Dit is de string met de naam van de kleur er in.
* @param color_num Dit is een pointer naar een int waar deze functie de 8-bits kleur in gaat zetten.
* @return De functie returnt een errorcode, namelijk: NOERROR of UNDEFINEDCOLOR
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
	if (0==strcmp(color_string, "oranje"))   	{*color_num = 168; 								return NOERROR; }

	*color_num = VGA_COL_BLACK;
	return UNDEFINEDCOLOR;
}

/**
* @brief Deze functie leest het commando uit, zet de getallen om in integers en stuurt het door naar de IO layer
*
* @param command_struct Dit is de pointer naar het COMMAND struct dat uitgelezen wordt.
* @return De functie returnt een errorcode, namelijk: de errors uit de IO layer, de errors uit de Q functies en COMMANDERROR
*/
int LOGIC_functionpicker(COMMAND *command_struct)
{
	int error = NOERROR;

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
		error = API_draw_bitmap(command_struct->arg[2].num,
								command_struct->arg[3].num,
								command_struct->arg[1].num);
		return error;
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

		error = LOGIC_colorpicker(command_struct->arg[5].text, &command_struct->arg[5].num);

		if (error) return error;

		error = API_draw_line(	command_struct->arg[1].num,
						command_struct->arg[2].num,
						command_struct->arg[3].num,
						command_struct->arg[4].num,
						command_struct->arg[5].num,
						command_struct->arg[6].num,
						0);

		return error;

	}

	if (!strcmp(command_struct->arg[0].text, "rechthoek"))
	{

		error = LOGIC_colorpicker(command_struct->arg[5].text,&command_struct->arg[5].num);
		API_draw_rectangle(	command_struct->arg[1].num,
							command_struct->arg[2].num,
							command_struct->arg[3].num,
							command_struct->arg[4].num,
							command_struct->arg[5].num,
							command_struct->arg[6].num,
							0,
							0);
		return error;
	}

	if (!strcmp(command_struct->arg[0].text, "tekst"))
	{

		error = LOGIC_colorpicker(command_struct->arg[3].text,&command_struct->arg[3].num);
		if (error) return error;
		error = API_draw_text(	command_struct->arg[1].num,
								command_struct->arg[2].num,
								command_struct->arg[3].num,
								command_struct->arg[4].text,
								command_struct->arg[5].text,
								command_struct->arg[6].num,
								0,
								0);
		return error;
	}

	if (!strcmp(command_struct->arg[0].text, "figuur"))
		{

			error = LOGIC_colorpicker(command_struct->arg[11].text,&command_struct->arg[11].num);
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
									0);
			return error;
		}

	if (!strcmp(command_struct->arg[0].text, "wacht"))
	{
		DELAY_screens(command_struct->arg[1].num);
		return NOERROR;
	}

	if (!strcmp(command_struct->arg[0].text, "herhaal"))
	{
		error = LOGIC_repeat(command_struct);

		return error;
	}

	//als dit deel van de functie bereikt wordt is het commando niet herkend
	return COMMANDERROR;
}
/**
* @brief Deze functie leest de meegegeven queue uit en stuurt de commando's door naar de functionpicker
*
* @note Deze functie hoort in de main samen met de errorhandler.
* @param performQ Dit is een pointer naar de Q_info struct van de queue tussen de front- en logiclayer.
* @return De functie returnt de errorcodes die door de aangeroepen functies zijn teruggegeven.
*/
int API_perform(Q_INFO * performQ) //naam onder voorbehoud
{
	int error = NOERROR;
	COMMAND performCommand;

	error = API_Qreader(performQ, &performCommand);
	if(error != NOERROR) return error;
	error = LOGIC_functionpicker(&performCommand);

	return error;
}
