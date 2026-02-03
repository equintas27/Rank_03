/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:27:43 by equintas          #+#    #+#             */
/*   Updated: 2026/01/31 16:01:02 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_result(int *saco, int size)
{
	int i = 0;
	while (i < size)
	{
		printf ("%d", saco[i]);
		if (i < size - 1)
			printf (" ");
		i++;
	}
	printf ("\n");
}

void	find_subset(int target, int *saco, int size, int i, int current_sum, int *subsaco, int i_saco)
{
	if (i == size)
	{
		if (current_sum == target)
			print_result(subsaco, i_saco);
		return ;
	}
	find_subset(target, saco, size, i + 1, current_sum, subsaco, i_saco);
	subsaco[i_saco] = saco[i];
	find_subset(target, saco, size, i + 1, current_sum + saco[i], subsaco, i_saco + 1);
}

int	main(int ac, char *av[])
{
	int target;
	int *saco;
	int *sub_saco;
	int size;
	int i;

	if (ac <= 2)
		return (1);
	size = ac - 2;
	saco = malloc (sizeof(int) * size);
	sub_saco = malloc (sizeof(int) * size);
	if (!saco || !sub_saco)
	{
		free (saco);
		free (sub_saco);
		return (1);
	}
	for (i = 0; i < size; i++)
		saco[i] = atoi(av[i + 2]);
	target = atoi(av[1]);
	find_subset(target, saco, size, 0, 0, sub_saco, 0);
	free (saco);
	free (sub_saco);
	return (0);
}
