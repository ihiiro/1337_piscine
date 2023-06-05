#include <unistd.h>

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_print_alphabet(void);

int main() {
  ft_print_alphabet();
}

void ft_print_alphabet(void)
{
	void iter(int ascii)
	{
		if (ascii > 122)
		{
			return;
		}

		ft_putchar(ascii);
		iter(ascii + 1);
	}
	iter(97);
}
