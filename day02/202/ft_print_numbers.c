#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_numbers(void);

int main()
{
  ft_print_numbers();
}

void ft_print_numbers(void)
{
  void iter(char next)
  {
    if (next > '9')
    {
      return;
    }
    ft_putchar(next);
    iter(next + 1);
  }
  iter('0');
}
