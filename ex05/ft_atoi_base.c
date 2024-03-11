/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:06:46 by abracurcix        #+#    #+#             */
/*   Updated: 2023/03/21 06:48:25 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

// 3rd step - Convert string to a base input
int	ft_convert_base(char *str, char *base, int base_size, int i)
{
	int	j;
	int	result;

	result = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
			{
				result = result * base_size + j;
				break ;
			}
			j++;
			if (base[j] == '\0')
				return (result);
		}
		i++;
	}
	return (result);
}

// 2nd step - Extract a number from string
int	ft_atoi(char *str, char *base, int base_size)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = ft_convert_base(str, base, base_size, i);
	return (result * sign);
}

// 1st step - Check the base
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
		if (freq['-'] > 0 || freq['+'] > 0 || freq[' '] > 0)
			return (0);
	}
	if (i < 2)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_size;
	int	nbr;

	nbr = 0;
	if (ft_check_base(base) == 1)
	{
		base_size = 0;
		while (base[base_size] != '\0')
		{
			base_size++;
		}
		nbr = ft_atoi(str, base, base_size);
	}
	return (nbr);
}

// int	main(void)
// {
// 	char	*str;
// 	char	base[] = "0123456789abcdef";

// 	str = "   --------+-2aj";
// 	printf("%d", ft_atoi_base(str, base));
// 	return (0);
// }
