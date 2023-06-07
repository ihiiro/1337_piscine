#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putstr(char *str);

int main(void)
{
  ft_putstr("hello there");
}

void ft_putstr(char *str)
{
  if (str)
  {
    int i = 0;
    while (str[i] != '\0')
    {
      ft_putchar(str[i]);
      i++;
    }
  }
}
