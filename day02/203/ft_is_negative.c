#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_is_negative(int n);

int main()
{
  ft_is_negative(0);
}

void ft_is_negative(int n)
{
  ft_putchar(
    (n >= 0) ? 'P' : 'N'
  );
}
