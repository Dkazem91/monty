#include "monty.h"

/**
 * get_opcode - gets the opcode and sets push_arg if it's push
 * @string: the line of code
 *
 * Return: the opcode
 */
char *get_opcode(char *string)
{
        char *opcode;

        /** grabs first argument **/
        opcode = strtok(string, "\n\t ");
        if (opcode)
        {
                if (strcmp(opcode, "push") == 0)
                        /**grabs next argument if push **/
                        push_arg = strtok(NULL, "\n\t ");
        }
        return (opcode);
}
