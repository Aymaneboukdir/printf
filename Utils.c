#include "main.h"

/**
 * is_printable - Evaluates a character to printable
 * @c: Character to evaluated.
 *
 * Return: 1 if c is printable,you get 0 in otherwise
*/
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
 * append_hexa_code - Append ascci in code to buffer
 * @buffer: array  characters.
 * @i: Index to start appending.
 * @ascii_code: using to print code.
 * Return: always 3 to print
*/
int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
/* The hexa format code is always 2 digits long */
if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}

/**
 * is_digit - Verifies characters in digit
 * @c: char evaluated
 *
 * Return: 1 if c is a digit,  get 0 in otherwise
*/
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}

/**
 * convert_size_number - Casts a num to the specific size
 * @num: Num to be casted.
 * @size: Num indicating type to be casted.
 *
 * Return: Casted to value the num
*/
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);

return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a num to the specific size
 * @num: Num to casted
 * @size: Num indicating  types to casted
 *
 * Return: Casted value of num
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);

return ((unsigned int)num);
}
