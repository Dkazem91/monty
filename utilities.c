#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
int isInt(char *str)
{
	int i = 0;
	if(str == NULL)
		return (0);
	if(*str == '-')
		i++;
	for(;str[i];i++)
	{
		if(!isdigit(str[i]))
			return (0);
	}
	return (1);
}

char *getopcode(char* string)
{
	char *opcode;
	/** grabs first argument **/
	opcode = strtok(string, " \n\t");
	if(strncmp(opcode,"push") == 0)
		/**grabs next argument if push **/
		push_arg = strtok(NULL," \n\t");
	return(opcode);
}
