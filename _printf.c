#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_write_char - a function write a char
 *@c: the char to be write
 *
 * Return: Always 0
 */
int handle_write_char(char c)
{
	char buffer[2];

	buffer[0] = c;
	buffer[1] = '\0';

	write(1, buffer, 1);
	return (1);
}
/**
 * handle_string - a function to print a string
 * @str: the string to be printed
 * Return: the number of characters printed
 */
int handle_string(char *str)
{
	int length;
	length = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	while (str[length] != '\0')
		length++;

	write(1, str, length);
	return (length);
}
/**
 * _printf - a function produces output according to a format
 * @format: is a character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	const char *buffer = format;

	va_list args;

	va_start(args, format);

	while (*buffer != '\0')
	{
		if (*buffer == '%')
		{
			buffer++;
			if (*buffer == 'c')
			{
				char c = va_arg(args, int);

				count += handle_write_char(c);
			}
			else if (*buffer == 's')
			{
				char *str = va_arg(args, char *);

				count += handle_string(str);
			}
			else if (*buffer == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		else
		{
			write(1, buffer, 1);
			count++;
		}
		buffer++;
	}

	va_end(args);
	return (count);
}
