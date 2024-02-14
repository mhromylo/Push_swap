/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:11:58 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/23 12:44:42 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_stack_node
{
	int						nbr;
	int						index;
	int						final_pos;
	int						push_cost;
	bool					above;
	bool					lowcost;

	struct s_stack_node		*next;
	struct s_stack_node		*prev;
	struct s_stack_node		*target;
}	t_stack_node;

char			**split_static(char *s, char c);
int				wrong_input(char *s);
int				duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			errors(t_stack_node **a, char **argv, bool one_line_input);
long			atoi_long(const char *str);
void			fill_stack_a(t_stack_node **a, char **argv, bool argc_two);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
t_stack_node	*find_last(t_stack_node *stack);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);
void			fill_node(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_lowcoster(t_stack_node *stack);
void			make_top(t_stack_node **stack, t_stack_node *top, char name_s);
void			current_index(t_stack_node *stack);
void			min_on_top(t_stack_node **a);
void			sort(t_stack_node **a, t_stack_node **b);
void			free_argv(char **argv);
void			sort_five(t_stack_node **a, t_stack_node **b);

#endif
