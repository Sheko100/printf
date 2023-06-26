#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * printerp - typedef for pointer to printers functions
 */
typedef int (*printerp)(const void *);

/**
 * struct spec_printer - Struct for format specifier
 * @spec: format specifier character
 * @printer: pointer to the associated function
 *
 * Struct for format specifier and its associated printing function
 */
typedef struct spec_printer
{
	char spec;
	printerp printer;
} spec_p;

int _printf(const char *format, ...);
printerp get_printer(const char *spec);
int print_ch(const void *ch);
int print_sch(const void *ch);
int print_str(const void *s);
int print_int(const void *n);
#endif
