#include <stdio.h>

int get_rm_par(char *s)
{
    int aberto = 0;
    int fechado = 0;

    int i = 0;
    while (s[i])
    {
        if (s[i] == '(')
            aberto++;
        else if (s[i] == ')')
        {
            if (aberto > 0)
                aberto--;
            else
                fechado++;
        }
        i++;
    }
    return aberto + fechado;
}

void    backtrack(char *s, int n_rm_par, int pos)
{
    if (n_rm_par == 0 || s[pos] == '\0')
    {
        if (get_rm_par(s) == 0)
            puts(s);
        return ;
    }
    char tmp = s[pos];
    s[pos] = ' ';
    backtrack(s, n_rm_par - 1, pos + 1);

    s[pos] = tmp;
    backtrack(s, n_rm_par, pos + 1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
        
    backtrack(av[1], get_rm_par(av[1]), 0);
}