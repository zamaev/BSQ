/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:12:01 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 21:26:46 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

int	get_key(t_str_list *in, char **key, int *i)
{
	int key_len;
	int tmp_i;
	int j;

	key_len = 1;
	while ((ft_isspace(get_lc(*i, in))
			|| get_lc(*i, in) == '\n') && get_lc(*i, in))
		(*i)++;
	tmp_i = *i;
	while (get_lc(*i, in) >= '0' && get_lc((*i)++, in) <= '9')
		key_len++;
	if (key_len == 1)
		return (1);
	*i = tmp_i;
	if (!((*key) = (char*)malloc(sizeof(char) * key_len)))
		return (1);
	j = 0;
	while (get_lc(*i, in) >= '0' && get_lc(*i, in) <= '9')
		(*key)[j++] = get_lc((*i)++, in);
	(*key)[j] = '\0';
	while (ft_isspace(get_lc(*i, in)))
		(*i)++;
	if (get_lc(*i, in) != ':')
		return (1);
	return (0);
}

int	get_value(t_str_list *in, char **value, int *i)
{
	int value_len;
	int tmp_i;
	int j;

	value_len = 1;
	while (ft_isspace(get_lc(*i, in)))
		(*i)++;
	tmp_i = (*i);
	while (get_lc(++(*i), in) != '\n' && get_lc(*i, in) != '\0')
		if (!(ft_isspace(get_lc(((*i) - 1), in)) && ft_isspace(get_lc(*i, in))))
			value_len++;
	*i = tmp_i - 1;
	if (value_len == 1)
		return (1);
	if (!((*value) = (char*)malloc(sizeof(char) * value_len)))
		return (1);
	j = 0;
	while (get_lc(++(*i), in) != '\n' && get_lc(*i, in) != '\0')
		if (!((ft_isspace(get_lc(((*i) - 1), in)) && ft_isspace(get_lc(*i, in)))
			|| (ft_isspace(get_lc(*i, in)) && (get_lc(((*i) + 1), in) == '\0'
			|| get_lc(((*i) + 1), in) == '\n'))))
			(*value)[j++] = get_lc(*i, in);
	(*value)[j] = '\0';
	return (0);
}

int	parse_input(t_str_list *in, t_list **pt)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	key = NULL;
	value = NULL;
	while (get_lc(i, in))
	{
		if (get_key(in, &key, &i))
		{
			ft_print_str("Dict Error\n");
			return (1);
		}
		i++;
		if (get_value(in, &value, &i))
		{
			ft_print_str("Dict Error\n");
			return (1);
		}
		i++;
		list_push_last(pt, key, value);
	}
	return (0);
}
