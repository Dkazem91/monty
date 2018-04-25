#include "monty.h"

int is_int(char *str)
{
	int i = 0;
	if(str == NULL)
		return (0);
	if(*str == '-')
		i++;
	for(; str[i]; i++)
	{
		if(!isdigit(str[i]))
			return (0);
	}
	return (1);
}
