#include "main.h"

/**
 * print_ch - prints a character to stdout
 * @ch: char to print
 *
 * Return: bytes written
 * -1 on error
 */

int print_ch(const void *ch)
{
	int len = 0;

	len = write(STDOUT_FILENO, &ch, 1);
	return (len);
}

/**
 * print_sch - prints a character in a string to stdout
 * @ch: pointer to char in a string
 *
 * Return: bytes written
 * -1 on error
 */

int print_sch(const void *ch)
{
	int len = 0;

	len = write(STDOUT_FILENO, ch, 1);

	return (len);
}

/**
 * print_str - prints string to stdout
 * @s: string to print
 *
 * Return: string length
 */

int print_str(const void *s)
{
	int len = 0;
	const char *str = s;

	if (str == NULL)
	{
		len += write(STDOUT_FILENO, "(null)", 6);
		return (len);
	}

	while (*str)
	{
		len += print_sch(str);

		str++;
		/* check if len is negative */
	}

	return (len);
}

/**
 * print_int - prints integer to stdout
 * @n: integer to print
 *
 * Return: integer length
 */

int print_int(const void *n)
{
	int len = 0;
	const int *np = n;
	int rest, outnum;
	void *restp, *outnump;

	rest = *np;
	outnum = rest % 10;
	if (rest > 9)
	{
		rest = rest / 10;
		restp = &rest;
		len = print_int(restp);
	}
	outnum = outnum + 48;
	outnump = &outnum;
	len += print_ch(outnump);

	/* check if len is negative*/
	return (len);
}
