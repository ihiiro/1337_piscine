#include <stdio.h>

int ft_is_prime(int nb);

int main(void)
{
  printf("%d", ft_is_prime(53));
}

int ft_is_prime(int nb)
{
  int iter(int i)
  {
    if (nb <= 1 || (nb % i == 0 && i != nb))
    {
      return 0;
    }
    else if (i == nb)
    {
      return 1;
    }
    iter(i + 1);
  }

  return iter(2);
}
