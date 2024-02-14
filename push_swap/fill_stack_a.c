/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:30:44 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/23 14:49:25 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	set_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = node;
		node->prev = last;
	}
}

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	fill_stack_a(t_stack_node **a, char **argv, bool argc_two)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (wrong_input(argv[i]))
			errors(a, argv, argc_two);
		n = atoi_long(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			errors(a, argv, argc_two);
		if (duplicate(*a, (int)n))
			errors(a, argv, argc_two);
		set_node(a, (int)n);
		++i;
	}
	if (argc_two)
		free_argv(argv);
}
