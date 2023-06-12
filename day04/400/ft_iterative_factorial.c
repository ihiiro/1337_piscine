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
  // any integer larger than 12 produces inaccurate results
  if (nb < 0 || nb > 12)
  {
    return 0;
  }
  // int i = nb;
  int fact = 1;
  while (nb != 0)
  {
    fact *= nb;
    nb--;
  }

  return fact;
}
