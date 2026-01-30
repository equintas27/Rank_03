/*/* ************************************************************************** */
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

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	char_sort(char *str,int start, int len)
{
	int		i;
	int		j;
	char	tmp;

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

void	permutations(char *str, int start, int end)
{
	int	i;
	int j;
	char tmp;

	if (start == end)
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		return ;
	}
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
		permutations(str, start + 1, end);
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

int	main(int ac, char *av[])
{
	if (ac != 2 || !av[1][0])
		return (1);
	int len = ft_strlen(av[1]);
	char *str = malloc (len + 1);
	if (!str)
		return (0);
	int i = 0;
	while (i < len)
	{
		str[i] = av[1][i];
		i++;
	}
	str[i] = 0;
	char_sort(str, 0, len);
	permutations(str, 0, len - 1);
	free (str);
	return (0);
}
