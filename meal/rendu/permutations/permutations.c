/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:46:42 by equintas          #+#    #+#             */
/*   Updated: 2026/01/27 16:46:45 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	char_sort(char *str, int len)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
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

void	permutations(char *str, int start, int end)
{
	int	i;

	if (start == end)
	{
		write(1, str, end + 1);
		write(1, "\n", 1);
		return ;
	}
	i = start;
	while (i <= end)
	{
		ft_swap(&str[start], &str[i]);
		permutations(str, start + 1, end);
		ft_swap(&str[start], &str[i]);
		i++;
	}
}

int	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	if (ac == 2)
	{   
        char_sort(av[1], strlen(av[1]));
		permutations(av[1], 0, strlen(av[1]) - 1);
	}
}
