/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:08:47 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 21:28:00 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

int			error(char *str)
{
	ft_print_str(str);
	return (0);
}

int			input_file_ext(int fd, int *read_size, char **str)
{
	errno = 0;
	*str = (char*)malloc(sizeof(char) * INPUT_BUF);
	if (errno != 0)
		return (error("Dict Error\n"));
	*read_size = (int)read(fd, *str, INPUT_BUF - 1);
	if (errno != 0)
		return (error("Dict Error\n"));
	(*str)[INPUT_BUF - 1] = '\0';
	return (1);
}

t_str_list	*input_file(char *file)
{
	t_str_list	*pt;
	int			read_size;
	char		*str;
	int			fd;

	pt = NULL;
	read_size = 0;
	errno = 0;
	fd = open(file, O_RDONLY);
	if (errno != 0)
		return (NULL);
	if (!input_file_ext(fd, &read_size, &str))
		return (NULL);
	while (read_size > 0)
	{
		if (!str_list_push_last(&pt, str, read_size))
		{
			error("Dict Error\n");
			return (NULL);
		}
		if (!input_file_ext(fd, &read_size, &str))
			return (NULL);
	}
	close(fd);
	return (pt);
}

char		get_lc(int i, t_str_list *pt)
{
	while (i / (INPUT_BUF - 1) > 0)
	{
		pt = pt->next;
		i = i / (INPUT_BUF - 1);
	}
	return ((i < pt->size) ? pt->str[i] : '\0');
}

int			ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
