/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:01:35 by equintas          #+#    #+#             */
/*   Updated: 2026/02/02 17:18:20 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_par(char *s)
{
	int i = 0;
	int open = 0;
	int close = 0;
	while (s[i])
	{
		if (s[i] == '(')
			open++;
		if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open + close);
}

void	backtrack(char *str, int n_par, int pos)
{
	if (n_par == 0 || str[pos] == '\0')
	{
		if (get_par(str) == 0)
			puts (str);
		return ;
	}

	char tmp = str[pos];
	str[pos] = ' ';
	backtrack (str, n_par - 1, pos + 1);
	str[pos] = tmp;
	backtrack (str, n_par, pos + 1);
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		backtrack (av[1], get_par(av[1]), 0);
	}
	else
		return (1);
	return (0);
}
