#include <stdio.h>
#include "main.h"
/**
 * _printf - produces output according to format
 * @format: a string of char representing argument types
 * @...: variable list of args
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int print_chara = 0;

	va_list list_args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			print_chara++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
			print_chara++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_args, int);

				write(1, &c, 1);
				print_chara++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_args, char*);

				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				print_chara += str_len;
			}


		}
		format++;
	}
	va_end(list_args);

	return (print_chara);
}
