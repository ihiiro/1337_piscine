#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb);

int main()
{
  ft_putnbr(6942042);
}

void ft_putnbr(int nb)
{
  int nbr = nb;
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
