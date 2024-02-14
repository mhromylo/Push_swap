/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:17:32 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/22 17:19:13 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above = true;
		else
			stack->above = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_a;
	t_stack_node	*target;
	long			closest_bigger;

	while (b)
	{
		closest_bigger = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->nbr > b->nbr && cur_a->nbr < closest_bigger)
			{
				closest_bigger = cur_a->nbr;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

static void	cost_push(t_stack_node *a, t_stack_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above))
			b->push_cost = b_len - (b->index);
		if (b->target->above)
			b->push_cost += b->target->index;
		else
			b->push_cost += a_len - (b->target->index);
		b = b->next;
	}
}

void	set_lowcost(t_stack_node *stack)
{
	long			lowcost_value;
	t_stack_node	*lowcost_node;

	if (stack == NULL)
		return ;
	lowcost_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < lowcost_value)
		{
			lowcost_value = stack->push_cost;
			lowcost_node = stack;
		}
		stack = stack->next;
	}
	lowcost_node->lowcost = true;
}

void	fill_node(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target(a, b);
	cost_push(a, b);
	set_lowcost(b);
}
