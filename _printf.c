#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: pointer to a string composed of zero or more directives
 *
 * Return: size of the printed characters
 */

int _printf(const char *format, ...)
{
	int len = 0, written = 0;
	va_list ap;
	const char *frmtp = format;

	if (frmtp != NULL)
	{
		va_start(ap, format);
		while (*frmtp)
		{
			if (*frmtp == '%' && *(++frmtp) != '%')
			{
				written = spec_printer(frmtp, ap);
				if (written < 0)
					return (-1);
				len += written;
			}
			else
			{
				len += print_sch(frmtp);
			}
				frmtp++;
		}
		va_end(ap);
	}
	else
	{
		return (-1);
	}

	return (len);
}
