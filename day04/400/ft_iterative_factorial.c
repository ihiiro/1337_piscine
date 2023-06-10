#include <stdio.h>

int ft_iterative_factorial(int nb);

int main(void)
{
  printf("%d", ft_iterative_factorial(12));
}

int ft_iterative_factorial(int nb)
{
  if (nb == 0)
  {
    return 1;
  }
  if (nb < 0)
  {
    return 0;
  }
  int i = nb;
  int fact = 1;
  while (i != 0)
  {
    fact *= i;
    i--;
  }

  return fact;
}
