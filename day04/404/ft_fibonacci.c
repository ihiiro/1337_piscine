#include <stdio.h>

int ft_fibonacci(int index);

int main(void)
{
  printf("%d", ft_fibonacci(46));
}

int ft_fibonacci(int index)
{
  if (index == 0 || index == 1)
  {
    return index;
  }
  else if (index < 0)
  {
    return -1;
  }

  return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}
