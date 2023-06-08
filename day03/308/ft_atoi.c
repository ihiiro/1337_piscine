#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putnbr(int nb)
{
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
  char *str = "-2147483640";
  ft_putnbr(ft_atoi(str));
}

int ft_atoi(char *str)
{
  if (!str)
  {
    return 0;
  }
  int i = 0;
  int pot = 1;
  // get length
  int length = 0;
  while (str[length] != '\0')
  {
    length++;
  }
  // match and add to i
  int end = length - 1;
  while (end >= 0)
  {

    if (str[end] == '1')
    {
      i += 1 * pot;
      pot *= 10;
    }
    else if (str[end] == '2')
    {
      i += 2 * pot;
      pot *= 10;
    }
    else if (str[end] == '3')
    {
      i += 3 * pot;
      pot *= 10;
    }
    else if (str[end] == '4')
    {
      i += 4 * pot;
      pot *= 10;
    }
    else if (str[end] == '5')
    {
      i += 5 * pot;
      pot *= 10;
    }
    else if (str[end] == '6')
    {
      i += 6 * pot;
      pot *= 10;
    }
    else if (str[end] == '7')
    {
      i += 7 * pot;
      pot *= 10;
    }
    else if (str[end] == '8')
    {
      i += 8 * pot;
      pot *= 10;
    }
    else if (str[end] == '9')
    {
      i += 9 * pot;
      pot *= 10;
    }
    else
    {
      pot *= 10;
    }
    end--;
  }
  if (str[0] == '-')
  {
    i *= -1;
  }
  return i;
}
