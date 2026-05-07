/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/04 00:00:00 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push_front(t_node **stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

static int	pop_front(t_node **stack)
{
	int		value;
	t_node	*tmp;

	if (*stack == NULL)
		return (0);
	value = (*stack)->value;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (value);
}

void	op_pa(t_stacks *s)
{
	int	value;

	if (stack_size(s->b) == 0)
		return ;
	value = pop_front(&s->b);
	push_front(&s->a, value);
	write(1, "pa\n", 3);
}

void	op_pb(t_stacks *s)
{
	int	value;

	if (stack_size(s->a) == 0)
		return ;
	value = pop_front(&s->a);
	push_front(&s->b, value);
	write(1, "pb\n", 3);
}
