#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * _printf - our own printf
 * @format: string
 * Return: number of prints
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					char c = va_arg(args, int);

					write(1, &c, sizeof(char));
					count++;
					i++;
					break;
				case 's':
					char *str = va_arg(args, char *);

					while (*str)
						write(1, str, 1);
						str++;
						count++;
					i++;
					break;
			}
		}
	}
	return (count);
}
