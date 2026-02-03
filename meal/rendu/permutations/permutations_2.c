/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:54:52 by equintas          #+#    #+#             */
/*   Updated: 2026/02/02 16:24:54 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	sort_char(char *str, int start, int len)
{
	int i = 0;
	int j = 0;
	char tmp;

	i = start;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void permutations(char *str, int start, int end)
{
	if(start == end)
	{
		write (1, str, ft_strlen(str));
		write (1, "\n", 1);
		return ;
	}

	int i;
	int j;
	char tmp;

	i = start; 
	while (i <= end)
	{
		tmp = str[i];
		j = i;
		while (j > start)
		{
			str[j] = str[j - 1];
			j--;
		}
		str[start] = tmp;
		permutations (str, start + 1, end);
		j = start;
		while (j < i)
		{
			str[j] = str[j + 1];
			j++;
		}
		str[i] = tmp;
		i++;
	}


}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		sort_char(av[1], 0, ft_strlen(av[1]));
		permutations (av[1], 0, ft_strlen(av[1]) - 1);
	}
	else
		return (1);
	return (0);
}
