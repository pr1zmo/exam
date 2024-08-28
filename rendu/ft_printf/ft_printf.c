#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_digit(long long int number, int base, int *length)
{
	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &("0123456789abcdef"[number % base]), 1);
}

int	ft_printf(const char *format, ... )
{
	int length = 0;

	va_list	pointer;
	va_start(pointer, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &length);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length);
}

// void	put_str(char *str, int *len)
// {
// 	if (!str)
// 		str = "(null)";
// 	while (*str)
// 		*len += write(1, str++, 1);
// }

// void	put_nbr(int	nbr, int base, int *len)
// {
// 	char	*hex;

// 	hex = "0123456789abcdef";
// 	if (nbr < 0)
// 	{
// 		*len += write(1, "-", 1);
// 		nbr *= -1;
// 	}
// 	if (nbr >= base)
// 		put_nbr((nbr / base), base, len);
// 	*len += write(1, &hex[nbr % base], 1);
// }

// int ft_printf(const char *str, ...)
// {
// 	va_list	arg;
// 	int		count;

// 	va_start(arg, str);
// 	while(*str)
// 	{
// 		if ((*str == '%') && *(str + 1))
// 		{
// 			str++;
// 			if (*str == 's')
// 				put_str(va_arg(arg, char *), &count);
// 			else if (*str == 'd')
// 				put_nbr((long long int)va_arg(arg, int), 10, &count);
// 			else if (*str == 'x')
// 				put_nbr((long long int)va_arg(arg, unsigned int), 16, &count);
// 		}
// 		else
// 			count += write(1, str, 1);
// 		str++;
// 	}
// 	return (va_end(arg), count);
// }
/* 
int main(int ac, char **av)
{
	int	k = -9834928;
	printf("count: %d\n", ft_printf("%x", k));

} */