/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:13:52 by abracurcix        #+#    #+#             */
/*   Updated: 2023/03/23 18:43:27 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int	ft_atoi(char *str)
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
	while (str[i] >= '0' && str[i] <= '9')
	{
			result = result * 10 + (str[i] - '0');
			i++;
	}
	return (result * sign);
}

// int	main(void)
// {
// 	char str[] = " ---+--+1234ab567";
// 	char 	*str;
// 	int		result;

// 	str = " ---+--+1234ab567";
// 	result = ft_atoi(str);
// 	printf("Meu resultado = %d\n", result);
// 	printf("Biblioteca = %d\n", atoi(str));
// 	return (0);
// }
