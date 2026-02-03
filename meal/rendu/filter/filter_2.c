/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:19:55 by equintas          #+#    #+#             */
/*   Updated: 2026/02/02 12:03:38 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void	print_stars(int n)
{
	while (n--)
		write(1, "*", 1);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_1 = (unsigned char *)dst;
	unsigned char *src_1 = (unsigned char *)src;
	size_t i = 0;
	while (i < n)
	{
		dst_1[i] = src_1[i];
		i++;
	}
	dst_1[i] = 0;
	return (dst_1);
}

int main(int ac, char *av[])
{
	size_t read_bytes;
	char *storage = NULL;
	char tmp[1024];
	size_t total_bytes = 0;
	size_t len_av;
	char *new_str;
	void *found;

	if (ac == 2)
	{
		len_av = strlen(av[1]);
		while ((read_bytes = read(0, tmp, 1024)))
		{
			new_str = realloc(storage, total_bytes + read_bytes);
			if (!new_str)
			{
				free (storage);
				write (2, "Error\n", strlen("Error\n"));
				return (1);
			}
			storage = new_str;
			ft_memcpy (storage + total_bytes, tmp, read_bytes);
			total_bytes += read_bytes;
			while ((found = memmem(storage, total_bytes, av[1], len_av)))
			{
				write (1, storage, (char *)found - storage);
				print_stars(len_av);
				size_t len_before = (char *)found - storage;
				size_t len_remaining = total_bytes - (len_before + len_av);
				memmove (storage, (char *)found + len_av, len_av);
				total_bytes = len_remaining;
			}
		}
		if (total_bytes > 0)
			write (1, storage, total_bytes);
		free (storage);
	}
	else
		return (1);
}
