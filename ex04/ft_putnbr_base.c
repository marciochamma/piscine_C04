/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:04:35 by abracurcix        #+#    #+#             */
/*   Updated: 2023/03/21 06:50:45 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

// 2nd step - Convert a number in other system base
void	ft_putnbr(int nbr, char *base, int base_size)
{
	int	unit;

	if (nbr < 0)
	{
		write(1, "-", 1);
		unit = (nbr % base_size) * -1;
		nbr /= -base_size;
	}
	else
	{
		unit = nbr % base_size;
		nbr /= base_size;
	}
	if (nbr > 0)
		ft_putnbr(nbr, base, base_size);
	write(1, &base[unit], 1);
}

// 1st step - Check de base
int	ft_check_base(char *base)
{
	int	i;
	int	freq[256];

	i = -1;
	while (++i < 256)
		freq[i] = 0;
	i = -1;
	while (base[++i] != '\0')
	{
		freq[(int)base[i]]++;
		if (freq[(int)base[i]] > 1)
			return (0);
		if (freq['-'] > 0 || freq['+'] > 0)
			return (0);
	}
	if (i < 2)
		return (0);
	return (1);
}

// 1st step - Check de base
// 2nd step - Convert a number to other system base
void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;

	if (ft_check_base(base) == 1)
	{
		base_size = 0;
		while (base[base_size] != '\0')
		{
			base_size++;
		}
		ft_putnbr(nbr, base, base_size);
	}
}

// int	main(void)
// {
// 	int		nbr;
// 	char	base[] = "0123456789ABCDEF";

// 	nbr = 42;
// 	ft_putnbr_base(nbr, base);
// 	return (0);
// }
