/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:09:28 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/26 20:54:43 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_valid(int *arr, int *refer);
void	ft_putnbr(int a);
void	ft_putstr(char *str);
void	print_arr(int *arr);

int		check_sud(int i, int *arr)
{
	int first_col;
	int j;
	int check_num;

	check_num = arr[i];
	first_col = i / 4 * 4;
	j = i;
	i--;
	while (i >= first_col)
	{
		if (check_num == arr[i])
			return (0);
		i--;
	}
	while (j > 3)
	{
		if (check_num == arr[j - 4])
			return (0);
		j -= 4;
	}
	return (1);
}

int		set_num(int i, int *arr, int *refer)
{
	int n;

	n = 1;
	if (i == 15)
	{
		while (n <= 4)
		{
			arr[i] = n;
			if (check_sud(i, arr) == 1)
				if (check_valid(arr, refer) == 1)
					return (1);
			n++;
		}
		return (0);
	}
	while (n <= 4)
	{
		arr[i] = n;
		if (check_sud(i, arr) == 1)
			if (set_num(i + 1, arr, refer) == 1)
				return (1);
		n++;
	}
	return (0);
}

int		*get_refer(char *str)
{
	int i;
	int *ref;

	ref = malloc(sizeof(ref) * 16);
	i = 0;
	while (i < 32)
	{
		ref[i] = (int)(str[i] - '0');
		i += 2;
	}
	return (ref);
}

int		main(int argc, char **argv)
{
	int arr[16];
	int *ref;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	ref = get_refer(argv[1]);
	while (*ref)
		ref++;
	if (!set_num(0, arr, ref))
		ft_putstr("Error\n");
	else
		print_arr(arr);
	return (0);
}
