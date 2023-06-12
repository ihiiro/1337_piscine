#include <stdio.h>

int ft_recursive_power(int nb, int power);

int main(void)
{
  printf("%d", ft_recursive_power(10, 6));
}

int ft_recursive_power(int nb, int power)
{
  int iter(int power, int product)
  {
    if (power < 0)
    {
      return 0;
    }
    else if (power == 0)
    {
      return product;
    }
    iter(power - 1, product * nb);
  }

  return iter(power, 1);
}
