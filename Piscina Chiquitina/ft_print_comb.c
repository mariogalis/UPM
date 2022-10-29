
void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = '0';
	j = '1';
	k = '2';
	while (i <= '9')
	{
		while (j <= '9')
		{
			while (k <= '9')
			{
				print(i, j, k);
				k++;
			}
			k = ++j + 1;
		}
		j = ++i ;
	}
}

int main()
{
    ft_print_comb();
}