/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/25 16:20:38 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}					t_strategy;

typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				pa;
	int				pb;
	int				rra;
	int				rrb;
	int				rrr;
	t_strategy		mode;
	t_strategy		executed;
	double			disorder;

}					t_bench;

typedef struct s_stacks
{
	t_node			*a;
	t_node			*b;
	t_bench			benchmarks;
}					t_stacks;

typedef enum e_scenario
{
	BOTH_UP,
	BOTH_DOWN,
	A_UP_B_DOWN,
	A_DOWN_B_UP
}					t_scenario;

typedef struct s_cost
{
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				total;
	t_scenario		scenario;
}					t_cost;

/* stack utils */
int					stack_size(t_node *stack);
int					is_sorted(t_node *stack);
void				free_stack(t_node **stack);
t_node				*find_max(t_node *stack);
t_node				*find_min(t_node *stack);

/* utils */
int					max_int(int a, int b);
int					min_int(int a, int b);

/* bench utils */
void				bench_init(t_bench *b, t_strategy mode);
t_strategy			get_strategy_from_flag(const char *flag);
const char			*get_strategy_name(t_strategy s);
const char			*get_strategy_complexity(t_strategy s);

/* operations */
void				op_sa(t_stacks *s);
void				op_sb(t_stacks *s);
void				op_ss(t_stacks *s);
void				op_pa(t_stacks *s);
void				op_pb(t_stacks *s);
void				op_ra(t_stacks *s);
void				op_rb(t_stacks *s);
void				op_rr(t_stacks *s);
void				op_rra(t_stacks *s);
void				op_rrb(t_stacks *s);
void				op_rrr(t_stacks *s);

/* sort */
double				compute_disorder(t_node *stack);
void				sort(t_stacks *s, char *strategy);
void				sort_a(t_stacks *s);
void				sort_b(t_stacks *s);
void				sort_c(t_stacks *s);

/* sortc utils*/
void				execute_move(t_cost *c, t_stacks *s);
void				sort_three(t_stacks *s);
void			push_b_to_a(t_stacks *s);
int				find_position_of_min(t_node *a);
void			rotate_min_to_top(t_stacks *s);
int				target_position_in_b(int x, t_node *b);

/* input */
t_node				*parse_args(int argc, char **argv);
void				error_exit(t_stacks *s);

#endif
