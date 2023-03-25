#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
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
					char c = va_arg(args, char);
					write(1, &c, sizeof(char));
					count++;
					break;

			}
		}
	}
	return (count);
}
