#include "main.h"
/**
 * check_base_8 - Convert a number to base 8
 * @ptr: A variable that points to a list of arguments
 * @add: A pointer pointing to a memory address within the buffer
 *
 * Return: length of string added to buffer
 */
int check_base_8(va_list ptr, char **add)
{
	unsigned int save = va_arg(ptr, unsigned int);

	return (convert_base(8, save, 0, add));
}
/**
 * check_base_10 - Convert a number to base 10
 * @ptr: A variable that points to a list of arguments
 * @add: A pointer pointing to a memory address within the buffer
 *
 * Return: length of string added to buffer
 */
int check_base_10(va_list ptr, char **add)
{
	int save = va_arg(ptr, int);

	return (print_number(save, add));
}
/**
 * check_base_16_upper - Convert a number to base 16 in upper case
 * @ptr: A variable that points to a list of arguments
 * @add: A pointer pointing to a memory address within the buffer
 *
 * Return: length of string added to buffer
 */
int check_base_16_upper(va_list ptr, char **add)
{
	unsigned int save = va_arg(ptr, unsigned int);

	return (convert_base(16, save, 0, add));
}
/**
 * check_base_16_lower - Convert a number to base 16 in lower case
 * @ptr: A variable that points to a list of arguments
 * @add: A pointer pointing to a memory address within the buffer
 *
 * Return: length of string added to buffer
 */
int check_base_16_lower(va_list ptr, char **add)
{
	unsigned int save = va_arg(ptr, unsigned int);

	return (convert_base(16, save, 1, add));
}
