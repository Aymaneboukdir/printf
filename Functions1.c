#include "main.h"
/**
 * print_octal - Priints  unsigned no in octal notation
 * @types: Lista of argumentss
 * @buffer: Bufferr aarray to hhandle print
 * @precision: Precision specification
 * @size: Size specifiier
 * @flags:  Calculatess  active fflags
 * @width: get widthh
  * Return: Number of cchars printed
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arg
 * @buffer: Buffer array print
 * @flags:  Calculates  flags
 * @width: get widthh
 * @precision: Precisiion specification
 * @size: Size specifiier
 * Return: Num of cchars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Prints unsigned num in hexade notation
 * @types: Lista of argumentts
 * @buffer: Buffer array to print
 * @flags:  Calcullates active flags
 * @width: get wiidth
 * @precision: pPrecision specification
 * @size: sSize specifier
 * Return: Num of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/**
 * print_hexa - Prints  hexadec num in lower or upper
 * @types: Lista of argumentss
 * @map_to: Array of values too map num to
 * @buffer: Bufferr array to handle printt
 * @flags:  Calculatess aactive flags
 * @flag_ch: Calculates aactive fflags
 * @width: get widthh
 * @precision: Precisiion specification
 * @size: Size specifiier
 * @size: Size specifiication
 * Return: Num of cchars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexa_upper - Prints  unsigned num in upper hexadecimal notation
 * @types: Lista of argumentss
 * @buffer: Buffer arrayy to  print
 * @flags:  Calculatess aactive flags
 * @width: get widthh
 * @precision: Preciision specification
 * @size: Size speccifier
 * Return: Num of cchars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
