#include "push_swap.h"
int ft_strln(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
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
char	**ft_strjoin(char **argv, int argc)
{
    int len;
    int j = 0;
    int k = 0;
    char **temp;
    int l;

    len = ft_strln(argv[j]);
    temp = (char **)malloc(sizeof(char *) * (argc * 2));
    if(temp)
    {
        while (argv[++j] != NULL)
        {
            temp[k] = (char *)malloc(len + 1);
            ft_join_free(temp[k], k);
            l = -1;
            while (argv[j][++l] != '\0')
                temp[k][l] = argv[j][l];
            temp[k][l] = '\0';
            k++;
            temp[k] = " ";
            k++;
        }
    }
    temp[k] = NULL;
    return (temp);
}

int main(int av, char *argv[])
{
    char **str = ft_strjoin(argv, av);
    int i = 0;
    while(str[i] != NULL)
    {
        printf("The elemet is >>>> %d <<<<<<\n", ft_atoi(*ft_split(str[i], ' ')));
        i++;
    }
}