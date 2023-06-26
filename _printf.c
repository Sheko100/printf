#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: pointer to a string composed of zero or more directives
 *
 * Return: size of the printed characters
 */

int _printf(const char *format, ...)
{
	int len = 0;
	va_list ap;
	const char *frmtp = format;
	printerp printer;

	if (frmtp != NULL)
	{
		va_start(ap, format);
		while (*frmtp)
		{
			if (*frmtp == '%' && *(++frmtp) != '%')
			{
				printer = get_printer(frmtp);
				if (printer != NULL)
				{
					len += printer(va_arg(ap, void *));
				}
			}
			else
			{
				len += print_sch(frmtp);
			}
				frmtp++;
		}
		va_end(ap);
	}

	return (len);
}
