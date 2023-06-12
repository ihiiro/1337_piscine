#include <stdio.h>

int ft_recursive_factorial(int nb);

int main(void)
{
  printf("%d", ft_recursive_factorial(12));
}

int ft_recursive_factorial(int nb)
{
  int iter(int nb, int factorial)
  {
    if (nb < 0 || nb > 12)
    {
      return 0;
    }
    else if (nb == 0)
    {
      return factorial;
    }
    iter(nb - 1, factorial * nb);
  }
  iter(nb, 1);
}
