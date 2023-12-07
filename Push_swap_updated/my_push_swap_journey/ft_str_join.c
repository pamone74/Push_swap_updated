/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:14:25 by pamone            #+#    #+#             */
/*   Updated: 2023/12/05 21:21:22 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_join_free(char *temp, int k)
{
    if (temp == NULL)
    {
        while (--k >= 0)
            free(temp);
        free(temp);
        return ;
    }
}
int ft_get_enough_space(char **arg)
{
    int i = 1;
    int j;
    int total = 0;
    while (arg[i] != NULL)
    {
            j = 0;
            while (arg[i][j] != '\0')
            {
                    j++;
            }
            j++;
            total += j;
        i++;
    }
    return (total);
}
// int main(int av, char *argv[])
// {
    // char *str = ft_strjoin(argv,av);
    // char **deg = ft_split(str, ' ');
    // int i = 0;
    // int j = 0;
    // while (deg[i] != NULL)
    // {
        // j = ft_atoi(deg[i]);
        //  printf("The joined string is %d and + 2 %d\n",  j, j + 2);
        //  i++;
    // }
    // i = 0;
    // while (deg[i] != NULL)
    // {
        // ft_join_free(deg[i], av);
        // 
        // i++;
    // }
    // 
// }
char *ft_strjoin(char *arg[], int argc)
{
    char *mem = malloc(sizeof(char) *(ft_get_enough_space(arg)+argc) + 1);
    int i = 1;
    int j = 0;
    int k = 0;
    int flag = 1;
    while (arg[i] != NULL)
    {
            j = 0;
            while (arg[i][j] != '\0')
            {
                if(arg[i][j + 1] && flag)
                {
                     mem[k++] = ' ';
                     flag = 0;
                }
            mem[k++] = arg[i][j++];
            }
        flag = 1;
        mem[k++] = ' ';
        i++;
    }
    mem[k] ='\0';
    return (mem);
}