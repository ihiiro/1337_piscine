#include <stdio.h>

int ft_atoi(char *str);

int main(void)
{
  char *str = "-100090-00-fdsjfljsfsdjf233";
  printf("%d", ft_atoi(str));
}

int ft_atoi(char *str)
{
  if (!str)
  {
    return 1;
  }
  int i = 0;
  int j = 0;
  int pot = 1;
  while (str[i] != '\0')
  {
    if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] < '0' || str[i + 1] > '9'))
    {
      while (i >= 0)
      {
        if (str[i - 1] < '0' || str[i - 1] > '9')
        {
          j += (str[i] - 48) * pot;
          if (str[i - 1] == '-')
          {
            j *= -1;
          }
          return j;
        }
        j += (str[i] - 48) * pot;
        pot *= 10;
        i--;
      }
    }
    i++;
  }
}
