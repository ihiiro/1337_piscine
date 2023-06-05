#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_comb2(void);

int main()
{
  ft_print_comb2();
}

void ft_print_comb2(void)
{
  void iter(char one, char two, char three, char four)
  {
    // format the combination
    void display()
    {
      if (!(one == '0' && two == '0' && three == '0' && four == '1'))
      {
        ft_putchar(',');
        ft_putchar(' ');
      }
      ft_putchar(one);
      ft_putchar(two);
      ft_putchar(' ');
      ft_putchar(three);
      ft_putchar(four);
    }
    // main
    if (one == '9' && two == '7' && three == '9' && four == '9')
    {
      display();
      ft_putchar(',');
      ft_putchar(' ');
      ft_putchar('9');
      ft_putchar('8');
      ft_putchar(' ');
      ft_putchar('9');
      ft_putchar('9');
      return;
    }
    if (two == '9' && three == '9' && four == '9')
    {
      display();
      iter(one + 1, '0', one, one + 1);
      return;
    }
    if (two == '8' && three == '9' && four == '9')
    {
      display();
      iter(one, two + 1, one + 1, '0');
      return;
    }
    if (three == '9' && four == '9')
    {
      display();
      iter(one, two + 1, '0', two + 2);
      return;
    }
    if (three == '8' && four == '9')
    {
      display();
      iter(one, two, three + 1, '0');
      return;
    }
    if (four == '9')
    {
      display();
      iter(one, two, three + 1, '0');
      return;
    }

    display();
    iter(one, two, three, four + 1);
  }
  iter('0', '0', '0', '1');
}
