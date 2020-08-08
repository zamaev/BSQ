/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:54:33 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/26 21:00:26 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ch_val_1(int *arr, int *refer)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (refer[i] == 1 && !(arr[i] == 4))
			return (0);
		if (refer[i] == 2 && !(arr[i] == 3 || arr[i + 4] == 4))
			return (0);
		if (refer[i] == 3 && !(arr[i + 4] == 3 && arr[i + 12] == 4))
			return (0);
		if (refer[i] == 4 && !(arr[i] == 1 && arr[i + 4] == 2
				&& arr[i + 8] == 3 && arr[i + 12] == 4))
			return (0);
		i++;
	}
	return (1);
}

int		ch_val_2(int *arr, int *refer)
{
	int i;
	int j;

	i = 4;
	while (i < 8)
	{
		j = i - 4;
		if (refer[i] == 1 && (arr[j + 12] == 4))
			return (0);
		if (refer[i] == 2 && ((arr[j + 12] == 3 || arr[j + 8] == 4)))
			return (0);
		if (refer[i] == 3 && (arr[j + 8] == 3 && arr[j] == 4))
			return (0);
		if (refer[i] == 4 && (arr[j + 12] == 1 && arr[j + 8] == 2
				&& arr[j + 4] == 3 && arr[j] == 4))
			return (0);
		i++;
	}
	return (1);
}

int		ch_val_3(int *arr, int *refer)
{
	int i;
	int j;

	i = 8;
	while (i < 12)
	{
		j = (i - 8) * 4;
		if (refer[i] == 1 && (arr[j] == 4))
			return (0);
		if (refer[i] == 2 && ((arr[j] == 3 || arr[j + 1] == 4)))
			return (0);
		if (refer[i] == 3 && (arr[j + 1] == 3 && arr[j + 3] == 4))
			return (0);
		if (refer[i] == 4 && (arr[j] == 1 && arr[j + 1] == 2
				&& arr[j + 2] == 3 && arr[j + 3] == 4))
			return (0);
		i++;
	}
	return (1);
}

int		ch_val_4(int *arr, int *refer)
{
	int i;
	int j;

	i = 12;
	while (i < 16)
	{
		j = (i - 12) * 4;
		if (refer[i] == 1 && arr[j + 3] == 4)
			return (0);
		if (refer[i] == 2 && (arr[j + 3] == 3 || arr[j + 2] == 4))
			return (0);
		if (refer[i] == 3 && arr[j + 2] == 3 && arr[j] == 4)
			return (0);
		if (refer[i] == 4 && arr[j + 3] == 1 && arr[j + 2] == 2
				&& arr[j + 1] == 3 && arr[j] == 4)
			return (0);
		i++;
	}
	return (1);
}

int		check_valid(int *arr, int *refer)
{
	int result;

	result = 0;
	result += ch_val_1(arr, refer);
	result += ch_val_2(arr, refer);
	result += ch_val_3(arr, refer);
	result += ch_val_4(arr, refer);
	if (result == 4)
		return (1);
	else
		return (0);
}
