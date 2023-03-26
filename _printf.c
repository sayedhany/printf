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
	char c;
	char *str;

	va_start(args, format);
	if (format == NULL)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				  c = va_arg(args, int);
					write(1, &c, sizeof(char));
					i++;
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str != '\0')
					{
						write(1, str, 1);
						str++;
						count++;
					}
					i++;
					break;
				case '%':
					write(1, "%", 1);
					i++;
					count++;
					break;
				default:
					return (0);
			}
		} 
		else
		{
			write(1, &format[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
