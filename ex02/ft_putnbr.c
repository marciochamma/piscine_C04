/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:17:27 by abracurcix        #+#    #+#             */
/*   Updated: 2023/03/20 17:46:18 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(int nb)
{
	int	unit;

	if (nb < 0)
	{
		write(1, "-", 1);
		unit = (nb % 10) * -1 + '0';
		nb /= -10;
	}
	else
	{
		unit = nb % 10 + '0';
		nb /= 10;
	}
	if (nb > 0)
		ft_putnbr(nb);
	write(1, &unit, 1);
}

// int	main(void)
// {
// 	int	nb;

// 	nb = 300;
// 	ft_putnbr(nb);
// 	return (0);
// }