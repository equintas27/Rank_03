/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:29:54 by equintas          #+#    #+#             */
/*   Updated: 2026/02/02 15:09:56 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    print_result(int *board, int n)
{
    int i = 0;

    while(i < n)
    {
        fprintf(stdout, "%i", board[i]);
        if (i < n - 1)
        	fprintf(stdout, " "); 
        i++;
    }
     fprintf(stdout, "\n");
}
int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int validator(int *board, int row, int col)
{
    int i = 0;
    int dist_row;
    int dist_col;

    while (i < row)
    {
        if (board[i] == col)
            return (0);
        dist_row = row - i;
        dist_col = ft_abs ((col - board[i]));
        if (dist_col == dist_row)
            return (0);
        i++;
    }
    return (1);
}

void    solver(int *board, int row, int n)
{
    int col;

    if (n == row)
    {
        print_result(board, n);
        return ;
    }
    col = 0;
    while (col < n)
    {
        if (validator(board, row, col))
        {
            board[row] = col;
            solver (board, row + 1, n);
        }
        col++;
    }
}

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        int i = atoi(av[1]);
        if (i <= 0)
            return (1); 
        int board[i];
        solver(board, 0, i);
    }
    else
        return (1);    
    return (0);
}
