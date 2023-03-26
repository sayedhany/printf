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
	int i = 0, count = 0, j = 0;
	va_list args;
	char c;
	char *str;
	int inum;
	char num_str[32];

	va_start(args, format);
	if (format == NULL)
		return (-1);
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
				case 'd':
				case 'i':
					inum = va_arg(args, int);
					do {
						num_str[j++] = inum % 10 + '0';
						inum /= 10;
					} while (inum != 0);
					while (j > 0)
					{
						write(1, &num_str[--j], 1);
					}
					i++;
					count++;
					break;
				default:
					return (-1);
			}
		} else
		{
			write(1, &format[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
