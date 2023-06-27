#include "main.h"
#include <stdio.h>

/**
 * spec_printer - checks the format specifier to return the associtad function
 * @spec: pointer to a char
 * @ap: variable arguments list
 *
 * Return: length of bytes written
 * -1 if printing fails
 */

int spec_printer(const char *spec, va_list ap)
{
	int len = 0;
	char specstr[3] = {'%', '\0', '\0'};

	switch (*spec)
	{
		case 'c':
			len = print_ch(va_arg(ap, void *));
			break;
		case 's':
			len = print_str(va_arg(ap, void *));
			break;
		case 'i':
		case 'd':
			len = print_int(va_arg(ap, int));
			break;
		default:
			specstr[1] = *spec;
			len = print_str(specstr);
	}

	return (len);
}
