#include "monty.h"

char *get_opcode(char* string)
{
	char *opcode;

	/** grabs first argument **/
	opcode = strtok(string, " \n\t");
	if (opcode)
	{
		if(strcmp(opcode, "push") == 0)
			/**grabs next argument if push **/
			push_arg = strtok(NULL," \n\t");
	}
	return(opcode);
}
