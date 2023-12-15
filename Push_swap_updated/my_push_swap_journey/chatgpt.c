#include "push_swap.h"

void ft_swp(int *item, int *i)
{
    int temp = *item;
    *item = *i;
    *i  = temp;
}
int partition_sort(int *tab, int low, int upper)
{
    int start;
    int end;
    int pivot;
    start = low;
    end = upper;
    pivot = tab[start];
    while(start < end)
    {
        while(tab[start] <= pivot )
            start ++;
        while (tab[end] > pivot)
            end --;
        if(start < end)
            ft_swp(&tab[start], &tab[end]);
        
    }
    ft_swp(&tab[end], &tab[low]);
    return end;
}

void quick_sort(int *tab, int low, int end)
{
    if(low < end)
    {
        int post = partition_sort(tab, low, end);
        quick_sort(tab, low, post-1);
        quick_sort(tab, post + 1, end);
    }
}

int main(void)
{
    int tab[5] = {0, 8,-1, 6, 3};
    quick_sort(tab, 0, 4);
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", tab[i]);
    }
}