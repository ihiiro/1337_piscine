#include <stdio.h>

void ft_sort_integer_table(int *tab, int size);

// O(n^2) time complexity
void ft_sort_integer_table(int *tab, int size)
{
  if (!tab || size <= 0)
  {
    return;
  }
  void swap(int n, int p)
  {
    int temp = tab[n];
    tab[n] = tab[p];
    tab[p] = temp;
  }

  int i = 0;
  int j = 0;
  while (i < size * size)
  {
    j = 0;
    while (j < size)
    {
      if (tab[j] > tab[j + 1] && j != size - 1)
      {
        swap(j, j + 1);
      }
      j++;
    }
    i++;
  }
}
