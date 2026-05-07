/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/04 00:00:00 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_front(t_node **stack, int value)
{
	(void)stack;
	(void)value;
}

int	pop_front(t_node **stack)
{
	(void)stack;
	return (0);
}

int	peek(t_node *stack)
{
	(void)stack;
	return (0);
}

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	is_sorted(t_node *stack)
{
	(void)stack;
	return (1);
}

void	free_stack(t_node **stack)
{
	(void)stack;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		if (n == 0)
			return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}