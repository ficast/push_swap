/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_c_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:58:35 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/25 16:18:11 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_position_of_min(t_node *a)
{
	t_node	*min;
	int		pos;

	pos = 0;
	min = find_min(a);
	while (a->value > min->value)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}

void	rotate_min_to_top(t_stacks *s)
{
	int	pos;
	int	size_a;

	pos = find_position_of_min(s->a);
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
}
