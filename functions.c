#include "main.h"
/**
 * convert_base - Convert base and add argument in the buffer
 * @base: Number of base to convert
 * @number: Number to convert
 * @band: Flag with order to follow
 * @add: A pointer pointing to a memory address within the buffer
 *
 * Return: length of string added to buffer
 */
int convert_base(int base, long int number, int band, char **add)
{
	char buffer[17];
	char buffer2[20];
	char *ptr = &buffer2[20];
	long int save = number, len_end = 0;
	char *hx_upper = "0123456789ABCDEF", *hx_lower = "0123456789abcdef";

	_strcpy(buffer, ((band == 0 || band == 2) ? hx_upper : hx_lower));
	*ptr = '\0', ptr--;
	if (number == 0)
	{
		**add = 48, (*add)++; /*_putchar(48);*/
		return (1);
	}
	if (number < 0)
		number = -number;
	while (number > 0)
	{
		*ptr-- = buffer[number % base];
		number = number / base;
	}
	if (save < 0)
		*ptr-- = '-';
	if (band == 16)
		*ptr-- = 'x', *ptr-- = '0';
	ptr++;
	if (_strlen(ptr) < 2 && band == 2)
		**add = '0', (*add)++, len_end++; /*_putchar('0');*/
	len_end += _strlen(ptr);
	while (len_end > 0)
	{
		**add = *ptr, ptr++, (*add)++;
		len_end--;
	}
	return (0);
}
/**
 * print_number - prints an integer.
 * @n: integer n to print using _putchar
 * @add: A pointer pointing to a memory address within the buffer
 *
 * Return: none - void function
 */
int print_number(long int n, char **add)
{
	unsigned int r;
	int _len = 0;

	if (n < 0)
	{
		**add = 45;
		(*add)++;
		/*_putchar(45);*/
		n *= -1;
		_len++;
	}
	r = n;

	if (r / 10)
	{
		_len += print_number(r / 10, add);
	}
	**add = r % 10 + '0';
	(*add)++;
	/*_putchar(r % 10 + '0');*/
	return (0);
}

/**
 * rot13 - Converts string to rot13
 * @list: string to convert
 * @add: A pointer pointing to a memory address within the buffer
 *
 * Return: converted string
 */
int rot13(va_list list, char **add)
{
	int i;
	int a;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (a = 0; a <= 52; a++)
		{
			if (str[i] == s[a])
			{
				**add = u[a];
				(*add)++;
				break;
			}
		}
		if (a == 53)
		{
			**add = str[i];
			(*add)++;
		}
	}
	return (0);
}

/**
 * print_rev_string - Print a string in reverse
 * @list: List of arguments
 * @add: A pointer pointing to a memory address within the buffer
 *
 * Return: Length of the string
 **/
int print_rev_string(va_list list, char **add)
{
	int i, size;
	char *str;

	str = va_arg(list, char *);

	size = _strlen(str);

	for (i = size - 1; i >= 0; i--)
	{
		**add = str[i];
		(*add)++;
	}
	return (0);
}
