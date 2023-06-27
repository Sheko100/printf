#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int spec_printer(const char *spec, va_list ap);
int print_ch(const void *ch);
int print_sch(const void *ch);
int print_str(const void *s);
int print_int(int n);
#endif
