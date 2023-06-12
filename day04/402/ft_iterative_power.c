#include <stdio.h>

int ft_iterative_power(int nb, int power);

int main(void)
{
  printf("%d", ft_iterative_power(10, 6));
}

int ft_iterative_power(int nb, int power)
{
  int n = 1;
  if (power < 0)
  {
    return 0;
  }
  while (power > 0)
  {
    n *= nb;
    power--;
  }

  return n;
}
