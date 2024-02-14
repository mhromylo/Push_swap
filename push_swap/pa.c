/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:09:37 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/23 11:00:59 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*push;

	if (*b == NULL)
		return ;
	push = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	push->prev = NULL;
	if (*a == NULL)
	{
		*a = push;
		push->next = NULL;
	}
	else
	{
		push->next = *a;
		push->next->prev = push;
		*a = push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		write (1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		write (1, "pb\n", 3);
}
