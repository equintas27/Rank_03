/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:26:54 by equintas          #+#    #+#             */
/*   Updated: 2026/01/26 14:26:57 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    print_stars(int n)
{
    while (n--)
        write (1, "*", 1);
}

void *ft_memcpy(void *dest, void *src, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
        i++;
    }
    return (dest);
}

int main(int ac, char *av[])
{
    char *storage = NULL;
    size_t read_bytes;
    char tmp[1024];
    int len_av;
    char *new_str;
    size_t total_size = 0;
    void *found;
    size_t len_before;
    size_t len_remaining;

    if (ac == 2 && av[1][0])
    {
        len_av = strlen(av[1]);
        while ((read_bytes = read(0, tmp, 1024)))
        {   
            new_str = realloc(storage, total_size + read_bytes);
            if (!new_str)
            {
                free (storage);
                write(2, "Error\n", strlen("Error\n"));
            }
            storage = new_str;
            ft_memcpy(storage + total_size, tmp, read_bytes);
            total_size += read_bytes;
            while ((found = memmem(storage, total_size, av[1], len_av)))
            {
                write (1, storage, (char *)found - storage);
                print_stars(len_av);
                len_before = (char *)found - storage;
                len_remaining = total_size - (len_before + len_av);
                memmove(storage, (char *)found + len_av, len_remaining);
                total_size = len_remaining;
            }
        }
        if (total_size > 0)
            write(1, storage, total_size);
        free(storage);
    }
    else
        return (1);
    return(0);
}

