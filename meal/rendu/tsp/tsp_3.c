/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:20:31 by equintas          #+#    #+#             */
/*   Updated: 2026/02/02 15:06:26 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <stdio.h>

typedef struct 
{
	float x;
	float y;
} city;

float	calc_distance(city a, city b)
{
	float dx;
	float dy;

	dx = a.x - b.x;
	dy = a.y - b.y;
       	return ((dx * dx) + (dy * dy));	
}

void	solve(int current, int count, int n, float dist, city *cities, int *visited, float *min_dist)
{
	int i = 0;
	if (count == n)
	{
		float final_dist = dist + calc_distance(cities[current], cities[0]);
		if (final_dist < *min_dist)
			*min_dist = final_dist;
		return ;
	}
	while (i < n)
	{
		if (!visited[i])
		{
			if (dist < *min_dist)
			{
				visited[i] = 1;
				solve (i, count + 1, n, dist + calc_distance(cities[current], cities[i]), cities, visited, min_dist);
				visited[i] = 0;
			}
		}
		i++;

	}
}

int main(void)
{
	city cities[12];
	int n = 0;
	int visited[12] = {0};
	float min_dist = FLT_MAX;

	while (n < 12 && fscanf(stdin, "%f, %f", &cities[n].x, &cities[n].y) == 2)
		n++;
	if (n >= 2)
	{
		solve(0, 1, n, 0.0, cities, visited, &min_dist);
		printf ("%.2f", min_dist);

	}
	else
		printf("0.00\n");
}
