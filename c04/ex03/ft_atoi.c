/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:19:25 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/21 01:29:54 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	posnum(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
	{
		return (3);
	}
	else if (c == '+' || c == '-')
	{
		return (2);
	}
	else if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(char *str)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while (*str && posnum(*str) == 3)
	{
		str++;
	}
	while (*str && posnum(*str) == 2)
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (*str && posnum(*str) == 1)
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (number * sign);
}
