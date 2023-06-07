#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

int ft_strlen(char *str);

int main(void)
{
  ft_putchar(48 + ft_strlen("hello"));
}

int ft_strlen(char *str)
{
  int length = 0;
  if (str)
  {
    while (str[length] != '\0')
    {
      length++;
    }
  }
  return length;
}
