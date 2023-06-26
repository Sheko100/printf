#include "main.h"

/**
 * get_printer - checks the format specifier to return the associtad function
 * @spec: pointer to a char
 *
 * Return: pointer to the associated function
 * NULL if the spec is wrong char
 */

printerp get_printer(const char *spec)
{
	spec_p spr[] = {
		{'c', print_ch},
		{'s', print_str},
		{'i', print_int},
		{'\0', NULL}
	};
	int i = 0;

	while (spr[i].spec)
	{
		if (spr[i].spec == *spec)
		{
			return (spr[i].printer);
		}
		i++;
	}

	return (NULL);
}
