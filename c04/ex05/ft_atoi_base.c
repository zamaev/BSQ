/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 04:51:54 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/21 07:26:17 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
    if (!base[i + 1] || base[i] == '+' || base[i] == '-')
        return (0);
    if (c == ' ' || (c >= '\t' && c <= '\r'))
        return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[j] == '-' || base[j] == '+')
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	sym_pos_aval(char c, char *base)
{
	int sym_pos;

	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (-3);
	else if (c == '+' || c == '-')
		return (-2);
	sym_pos = 0;
	while (base[sym_pos])
	{
		if (base[sym_pos] == c)
			return (sym_pos);
		sym_pos++;
	}
	return (-1);
}

int	powered(int a, int n)
{
	if (n == 0)
		return (1);
	if (n == 1)
		return (a);
	return (a * powered(a, --n));
}

int	get_number(char *str, int count, char *base)
{
	int base_count;
	int base_number;
	int number;
	int i;

	number = 0;
	base_count = get_base(base);
	i = 0;
	while (i < count)
	{
		base_number = sym_pos_aval(str[i], base);
		number = number + base_number * powered(base_count, count - 1 - i);
		i++;
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int sign;
	int bs_num_len;

	if (!get_base(base))
		return (0);
	while (*str && sym_pos_aval(*str, base) == -3)
		str++;
	sign = 1;
	while (*str && sym_pos_aval(*str, base) == -2)
		if (*str++ == '-')
			sign *= -1;
	bs_num_len = 0;
	while (str[bs_num_len] && sym_pos_aval(str[bs_num_len], base) > -1)
		bs_num_len++;
	return (get_number(str, bs_num_len, base) * sign);
}
