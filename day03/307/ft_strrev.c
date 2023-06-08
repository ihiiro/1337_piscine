#include <unistd.h>

char *ft_strrev(char *str);
int string_length(char * str);


char *ft_strrev(char *str)
{
  char array[2024];
  int i = string_length(str) - 1;
  int j = 0;
  while (i >= 0)
  {
    array[j] = str[i];
    j++;
    i--;
  }

  str = array;
  return str;
}

int string_length(char *str)
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
