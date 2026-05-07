/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/04 00:00:00 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
}				t_stacks;

/* stack utils */
void	push_front(t_node **stack, int value);
int		pop_front(t_node **stack);
int		peek(t_node *stack);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
void	free_stack(t_node **stack);

/* operations */
void	op_sa(t_stacks *s);
void	op_sb(t_stacks *s);
void	op_ss(t_stacks *s);
void	op_pa(t_stacks *s);
void	op_pb(t_stacks *s);
void	op_ra(t_stacks *s);
void	op_rb(t_stacks *s);
void	op_rr(t_stacks *s);
void	op_rra(t_stacks *s);
void	op_rrb(t_stacks *s);
void	op_rrr(t_stacks *s);

/* sort */
double		compute_disorder(t_node *stack);
void	sort(t_stacks *s, char *strategy);

/* input */
t_node	*parse_args(int argc, char **argv);
void	error_exit(t_stacks *s);

#endif
