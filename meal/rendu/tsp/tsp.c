/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:41:39 by equintas          #+#    #+#             */
/*   Updated: 2026/01/26 15:41:41 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

typedef struct {
    float x;
    float y;
} city;

float   calcu_distance(city a, city b)
{
    float dx;
    float dy;

    dx = a.x - b.x;
    dy = a.y - b.y;
    return (sqrtf((dx * dx) + (dy * dy)));
}

void    solve(int current, int count, int n,float dist, city *cities, int *visited, float *min_dist)
{
    int i = 0;
    if (count == n)
    {
        float final_dist =  dist + calcu_distance(cities[current], cities[0]);
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
                solve(i, count + 1, n, dist + calcu_distance(cities[current], cities[i]), cities, visited, min_dist);
                visited[i] = 0;
            }
        }
        i++;
    }
}

int main(void)
{
    city cities[12];
    float min_dist = FLT_MAX;
    int visited[12] = {0};
    int n = 0;
    while (n < 12 && fscanf(stdin, "%f, %f", &cities[n].x, &cities[n].y) == 2)
        n++;
    visited[0] = 1;
    if (n >= 2)
    {
        solve(0, 1, n, 0.0, cities, visited, &min_dist);
        printf ("%.2f\n", min_dist);
    }
    else
        printf("0.00\n");
    return (0);
}


