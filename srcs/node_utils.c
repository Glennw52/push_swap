/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:56:05 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/09 15:43:34 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node	*node_new(int num)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
		error_exit(MALLOC_ERROR);
	head->num = num;
	head->idx = -1;
	head->next = NULL;
	return (head);
}

t_node	*node_last(t_node *node)
{
	while (node)
	{
		if (!node->next)
			return (node);
		node = node->next;
	}
	return (node);
}

void	node_add_back(t_node **node, t_node *new)
{
	if (!*node)
		*node = new;
	else
		node_last(*node)->next = new;
}

void	node_add_front(t_node **node, t_node *new)
{
	new->next = *node;
	*node = new;
}
