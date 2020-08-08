/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:27:44 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 17:16:41 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

t_list	*list_init(char *input_id, char *input_str)
{
	t_list *head;

	head = NULL;
	head = (t_list*)malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->id = input_id;
	head->str = input_str;
	head->next = NULL;
	return (head);
}

t_list	*list_push_last(t_list **head, char *input_id, char *input_str)
{
	t_list *cur;

	if (*head == NULL)
	{
		*head = list_init(input_id, input_str);
		return (*head);
	}
	cur = *head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = (t_list*)malloc(sizeof(t_list));
	if (cur->next == NULL)
		return (NULL);
	cur->next->id = input_id;
	cur->next->str = input_str;
	cur->next->next = NULL;
	return (cur->next);
}

void	list_free(t_list *pt)
{
	if (pt == NULL)
		return ;
	if (pt->next != NULL)
		list_free(pt->next);
	free(pt->id);
	free(pt->str);
	free(pt);
}

t_list	*list_get_by_id(t_list *head, char *input_id)
{
	if (head == NULL)
		return (NULL);
	while (head != NULL && ft_strcmp(head->id, input_id) != 0)
		head = head->next;
	if (head != NULL)
		return (head);
	else
		return (NULL);
}
