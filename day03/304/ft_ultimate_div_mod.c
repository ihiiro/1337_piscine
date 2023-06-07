void ft_ultimate_div_mod(int *a, int *b);

void ft_ultimate_div_mod(int *a, int *b)
{
  if (a && b && *b != 0)
  {
    int a_value = *a;
    *a = *a / *b;
    *b = a_value % *b;
  }
}
