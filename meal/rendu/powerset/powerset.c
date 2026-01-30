/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:50:47 by equintas          #+#    #+#             */
/*   Updated: 2026/01/28 10:50:51 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_result(int *saco, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d", saco[i]);
		if (i < size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	find_subsets(int target, int *s, int size, int idx, int current_sum,
		int *subset, int sub_idx)
{
	if (idx == size)
	{
		if (current_sum == target)
			print_result(subset, sub_idx);
		return ;
	}
	find_subsets(target, s, size, idx + 1, current_sum, subset, sub_idx);
	subset[sub_idx] = s[idx];
	find_subsets(target, s, size, idx + 1, current_sum + s[idx], subset, sub_idx
		+ 1);
}

int	main(int ac, char *av[])
{
	int	size;
	int	*saco;
	int	*subset;
	int	target;

	if (ac <= 2)
		return (1);
	size = ac - 2;
	target = atoi(av[1]);
	if (size == 0)
	{
		saco = malloc(sizeof(int) * 1);
		subset = malloc(sizeof(int) * 1);
	}
	else
	{
		saco = malloc(sizeof(int) * size);
		subset = malloc(sizeof(int) * size);
	}
	if (!saco || !subset)
	{
		free(saco);
		free(subset);
		return (1);
	}
	for (int i = 0; i < size; i++)
		saco[i] = atoi(av[i + 2]);
	find_subsets(target, saco, size, 0, 0, subset, 0);
	free(saco);
	free(subset);
	return (0);
}
