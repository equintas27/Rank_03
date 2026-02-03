/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:40:23 by equintas          #+#    #+#             */
/*   Updated: 2026/01/29 11:40:28 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int verify_argument(char *str,  int len)
{
    int i = 0;
    int exist = 0;

    while (i < len) 
    {
        if (str[i] == '(')
            exist++;
        else if (str[i] == ')')
        {
            exist--;
            if (exist < 0)
                return (0);
        }
        i++;
    }
    return (exist == 0);
}

void calc_defice(char *str, int *R, int *L)
{
    int balance = 0;
    *R = 0;
    *L = 0;
    int i;

    for (i = 0; str[i]; i++)
    {
        if (str[i] == '(')
            balance++;
        else if (str[i] == ')')
        {
            if (balance > 0)
                balance--;
            else
                (*R)++;
        }
    }
    *L = balance;
}

void    solve(char *str, int i, int rem_R, int rem_L, int len)
{
    char tmp;
    if (i == len)
    {
        if (!rem_R && rem_L && verify_argument(str, len))
            puts(str);
        return ;
    }
    tmp = str[i];
    if ((str[i] == '(') && rem_L > 0)
    {
        str[i] = ' ';
        solve(str, i + 1, rem_R, rem_L - 1, len);
    }
    else if (str[i] == 2)
    {

    }
    else
        solve(str, i + 1, rem_R, rem_L, len);
}

int main(int ac, char *av[])
{
    if (ac != 2)
        return (1);
    int i = ft_strlen(av[1]);
    printf ("Tem valor: %d", verify_argument(av[1], i));
}

