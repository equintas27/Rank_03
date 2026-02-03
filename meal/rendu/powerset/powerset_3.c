/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:34:18 by equintas          #+#    #+#             */
/*   Updated: 2026/02/02 16:55:32 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

void	find_subset(int target, int size, int *saco, int i, int current_sum, int *sub_saco, int i_saco)
{
	if (i == size)
	{
		if (current_sum == target)
			print_result(sub_saco, i_saco);
		return ;
	}
	find_subset(target, size, saco, i + 1, current_sum, sub_saco, i_saco);
	sub_saco[i_saco] = saco[i];
	find_subset(target, size, saco, i + 1, current_sum + saco[i], sub_saco, i_saco + 1 );
}



int main(int ac, char *av[])
{
	if (ac <= 2)
		return (1);
	int size;

	size = ac - 2;
	int *saco = malloc(sizeof(int) * size);
	int *sub_saco = malloc(sizeof(int) * size);
	if (!saco || !sub_saco)
	{
		free (saco);
		free (sub_saco);
		return (1);
	}
	int i;
	for (i = 0; i < size; i++)
		saco[i] = atoi(av[i + 2]);
	int target = atoi(av[1]);
	find_subset(target, size, saco, 0, 0, sub_saco, 0);
	free (saco);
	free (sub_saco);
	return (0);
}
