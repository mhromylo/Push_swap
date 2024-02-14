/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:08:17 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/22 17:10:31 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	make_top(t_stack_node **stack, t_stack_node *top, char name_s)
{
	while (*stack != top)
	{
		if (name_s == 'a')
		{
			if (top->above)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name_s == 'b')
		{
			if (top->above)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

int	stack_len(t_stack_node *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = 0;
	while (stack)
	{
		++i;
		stack = stack->next;
	}
	return (i);
}

t_stack_node	*get_lowcoster(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->lowcost)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
