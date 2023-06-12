#include <stdio.h>

int ft_sqrt(int nb);

int main(void)
{
  printf("%d", ft_sqrt(100));
}

int ft_sqrt(int nb)
{
  int i = 1;
  int iter(int a, int b)
  {
    if (nb < 0 || i > 22)
    {
      return 0;
    }
    else if (a * a == nb)
    {
      if (a > 0)
      {
        return a;
      }
      else
      {
        return -a;
      }
    }
    i++;
    iter(b, (a * a + nb) / (2 * a));
  }

  return iter(nb, (nb + 1) / 2);
}
