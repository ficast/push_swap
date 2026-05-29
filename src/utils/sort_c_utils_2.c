/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_c_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:53:02 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/25 16:20:39 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(t_stacks *s)
{
	int	a;
	int	b;
	int	c;

	if (stack_size(s->a) < 2)
		return ;
	if (stack_size(s->a) == 2)
	{
		if (s->a->value > s->a->next->value)
			op_sa(s);
		return ;
	}
	a = s->a->value;
	b = s->a->next->value;
	c = s->a->next->next->value;
	if (a > b && b < c && a < c)
		op_sa(s);
	else if (a > b && b > c)
		(op_sa(s), op_rra(s));
	else if (a > b && b < c && a > c)
		op_ra(s);
	else if (a < b && b > c && a < c)
		(op_sa(s), op_ra(s));
	else if (a < b && b > c && a > c)
		op_rra(s);
}

static int	target_position_in_a(int x, t_node *a)
{
	int		position;
	t_node	*max;
	t_node	*min;

	position = 0;
	max = find_max(a);
	min = find_min(a);
	while (a)
	{
		if (a->value == min->value && (x <= min->value || x > max->value))
			return (position);
		if (x > a->value && !a->next)
			return (0);
		if (x > a->value && x < a->next->value)
			return (++position);
		a = a->next;
		position++;
	}
	return (position);
}

int	target_position_in_b(int x, t_node *b)
{
	int		position;
	t_node	*max;
	t_node	*min;

	position = 0;
	max = find_max(b);
	min = find_min(b);
	while (b)
	{
		if (b->value == max->value && (x > max->value || x < min->value))
			return (position);
		if (x < b->value && !b->next)
			return (0);
		if (x < b->value && x > b->next->value)
			return (++position);
		b = b->next;
		position++;
	}
	return (position);
}

void	push_b_to_a(t_stacks *s)
{
	t_node	*x;
	int		pos;
	int		size_a;

	while (s->b)
	{
		x = s->b;
		pos = target_position_in_a(x->value, s->a);
		size_a = stack_size(s->a);
		if (pos <= size_a / 2)
		{
			while (pos--)
				op_ra(s);
		}
		else
		{
			pos = size_a - pos;
			while (pos--)
				op_rra(s);
		}
		op_pa(s);
	}
}
