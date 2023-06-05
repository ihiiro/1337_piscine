#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_reverse_alphabet(void);

int main()
{
  ft_print_reverse_alphabet();
}

void ft_print_reverse_alphabet(void)
{
  void iter(int ascii)
  {
    if (ascii < 97)
    {
      return;
    }

    ft_putchar(ascii);
    iter(ascii - 1);
  }

  iter(122);
}
