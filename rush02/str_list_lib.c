/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_lib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:14:18 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 21:21:41 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

t_str_list	*str_list_init(char *input_str, int input_size)
{
	t_str_list *head;

	head = NULL;
	head = (t_str_list*)malloc(sizeof(t_str_list));
	if (head == NULL)
		return (NULL);
	head->size = input_size;
	head->str = input_str;
	head->next = NULL;
	return (head);
}

t_str_list	*str_list_push_last(t_str_list **h, char *i_str, int i_size)
{
	t_str_list *cur;

	if (*h == NULL)
	{
		*h = str_list_init(i_str, i_size);
		return (*h);
	}
	cur = *h;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = (t_str_list*)malloc(sizeof(t_str_list));
	if (cur->next == NULL)
		return (NULL);
	cur->next->size = i_size;
	cur->next->str = i_str;
	cur->next->next = NULL;
	return (cur->next);
}

void		str_list_free(t_str_list *pt)
{
	if (pt == NULL)
		return ;
	if (pt->next != NULL)
		str_list_free(pt->next);
	free(pt->str);
	free(pt);
}
