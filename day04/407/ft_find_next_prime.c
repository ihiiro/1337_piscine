#include <stdio.h>

int ft_find_next_prime(int nb);

int main(void)
{
  printf("%d", ft_find_next_prime(214748));
}

int ft_find_next_prime(int nb)
{
  int iter(int i, int nb)
  {
    if (i > 2147483640)
    {
      return -1;
    }
    if (nb <= 2)
    {
      return 2;
    }
    else if (nb % i == 0 && i != nb)
    {
      iter(2, nb + 1);
    }
    else if (i == nb)
    {
      return nb;
    }
    else
    {
      iter(i + 1, nb);
    }
  }
  iter(2, nb);
}
