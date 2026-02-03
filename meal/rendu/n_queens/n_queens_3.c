/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:10:30 by equintas          #+#    #+#             */
/*   Updated: 2026/02/02 15:53:37 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_result(int *board, int size)
{
	int i = 0;
	while (i < size)
	{
		fprintf (stdout, "%d", board[i]);
		if (i < size - 1)
			fprintf (stdout, " ");
		i++;
	}
	fprintf (stdout, "\n");
}

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int validator (int *board, int row, int col)
{
	int i = 0;
	int dif_row;
	int dif_col;

	while (i < row)
	{
		if (board[i] == col)
			return (0);
		dif_row = row - i;
		dif_col = ft_abs((board[i] - col));
		if (dif_row == dif_col)
			return (0);
		i++;
	}
	return (1);
}

void solve(int *board, int row, int n)
{
	if (n == row)
	{
		print_result(board, n);
		return ;
	}
	int col = 0;
	while (col < n)
	{
		if (validator(board, row, col))
		{
			board[row] = col;
			solve (board, row + 1, n);
		}
		col++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		int i = atoi(av[1]);
		int board[i];
		solve (board, 0, i);
	}
	else
		return (1);
	return (0);
}
