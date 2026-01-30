/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:12:32 by equintas          #+#    #+#             */
/*   Updated: 2026/01/26 12:12:36 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

int	match_space(FILE *f)
{
	int	i;

	i = fgetc(f);
	while (i != EOF && isspace(i))
		i = fgetc(f);
	if (i != EOF)
		ungetc(i, f);
	return (0);
}

int	match_char(FILE *f, char c)
{
	int	i;

	i = fgetc(f);
	if (i == c)
		return (1);
	ungetc(i, f);
	return (0);
}

int	scan_char(FILE *f, va_list ap)
{
	char	*dst;
	int		i;

	dst = va_arg(ap, char *);
	i = fgetc(f);
	if (i != EOF && !isspace(i))
    {
        *dst = i;
        return (1);
    }
	return (0);
}

int	scan_int(FILE *f, va_list ap)
{
	int	*dst;
	int	i;
	int	mult;
	int	result;
	int	count;

	mult = 1;
	result = 0;
	count = 0;
	dst = va_arg(ap, int *);
	i = fgetc(f);
	if (i == '+' || i == '-')
	{
		if (i == '-')
			mult = -1;
		i = fgetc(f);
	}
	while (i != EOF && isdigit(i))
	{
		result = result * 10 + (i - '0');
		i = fgetc(f);
		count++;
	}
	if (i != EOF)
		ungetc(i, f);
	if (count > 0)
	{
		*dst = result * mult;
		return (1);
	}
	return (0);
}

int	scan_string(FILE *f, va_list ap)
{
	char	*dst;
	int		c;
	int		i;

	i = 0;
	dst = va_arg(ap, char *);
	c = fgetc(f);
	while (c != EOF && !isspace(c))
	{
		dst[i] = c;
		c = fgetc(f);
		i++;
	}
	if (c != EOF)
		ungetc(c, f);
	return (i > 0);
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
	case 'c':
		return (scan_char(f, ap));
	case 'd':
		match_space(f);
		return (scan_int(f, ap));
	case 's':
		match_space(f);
		return (scan_string(f, ap));
	case EOF:
		return (-1);
	default:
		return (-1);
	}
}

int	ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int	nconv;
	int	c;

	nconv = 0;
	c = fgetc(f);
	if (c == EOF)
		return (EOF);
	ungetc(c, f);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break ;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break ;
		}
		else if (match_char(f, *format) != 1)
			break ;
		format++;
	}
	if (ferror(f))
		return (EOF);
	return (nconv);
}

int	ft_scanf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return (ret);
}

/*int	main(void)
{
	int		n;
	char	c;
	char	str[200];

	n = 0;
	c = '0';
	printf("Digite 42Luanda e clique Enter: ");
	ft_scanf("%d %s", &n,  str);
	printf("O valor inteiro lido é: %d %s\n", n, str);
	ft_scanf("%c", &c);
	printf("O valor char lido é: %c\n", c);
	ft_scanf("%s", str);
	printf("O valor string lido é: %s\n", str);
	return (0);
}*/
