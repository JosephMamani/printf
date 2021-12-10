#include "main.h"
/**
 * match_case - function that matches the flag passed as an argument
 * @flag: pointer to flag
 *
 * Return: Pointer to function associated to flag
 */
int (*match_case(const char *flag))(va_list ptr, char **add)
{
	int pos = 0;

	c_mtc flag_store[] = {
		{"s", string_case},
		{"c", char_case},
		{"d", check_base_10},
		{"i", check_base_10},
		{"b", check_base_2},
		{"x", check_base_16_lower},
		{"X", check_base_16_upper},
		{"o", check_base_8},
		{"u", check_case_u},
		{"S", check_case_S},
		{"p", check_case_address},
		{"R", rot13},
		{"r", print_rev_string},
		{NULL, NULL}
	};

	while (pos < 13)
	{
		if (*(flag_store[pos]).c == *flag)
			return (flag_store[pos].f);
		pos++;
	}
	return (flag_store[pos].f);
}
