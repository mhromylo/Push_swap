/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:06:08 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/23 11:07:22 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
t_stack_node *lowcoster)
{
	while (*a != lowcoster->target && *b != lowcoster)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
t_stack_node *lowcoster)
{
	while (*a != lowcoster->target && *b != lowcoster)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*lowcoster;

	lowcoster = get_lowcoster(*b);
	if (lowcoster->above && lowcoster->target->above)
		rotate_both(a, b, lowcoster);
	else if (!(lowcoster->above) && !(lowcoster->target->above))
		rev_rotate_both(a, b, lowcoster);
	make_top(b, lowcoster, 'b');
	make_top(a, lowcoster->target, 'a');
	pa(a, b, false);
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;
	int				len;

	len = stack_len(*a);
	if (len == 5)
		sort_five(a, b);
	else
	{
		while (len-- > 3)
			pb(b, a, false);
	}
	sort_three(a);
	while (*b)
	{
		fill_node(*a, *b);
		move_node(a, b);
	}
	current_index(*a);
	min = find_min(*a);
	if (min->above)
		while (*a != min)
			ra(a, false);
	else
		while (*a != min)
			rra(a, false);
}
