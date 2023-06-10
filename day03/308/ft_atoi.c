#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putnbr(int nb)
{
  if (nb == 0)
  {
    ft_putchar('0');
    return;
  }
  int nbr = nb;
  if (nbr < 0)
  {
    ft_putchar('-');
    nbr *= -1;
  }
  int arr[10];
  for (int i = 10; i > 0; i--)
  {
    arr[i] = nbr % 10;
    nbr /= 10;
  }

  for (int i = 0, bool = 0; i <= 10; i++)
  {
    if (!bool)
    {
      if (arr[i] > 0)
      {
        bool = 1;
        ft_putchar(48 + arr[i]);
      }
    }
    else
    {
      ft_putchar(48 + arr[i]);
    }
  }
}

int ft_atoi(char *str);

int main(void)
{
  char *str = "jdslfjfs333343";
  ft_putnbr(ft_atoi(str));
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
