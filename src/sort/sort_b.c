/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 08:12:16 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/30 21:00:56 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	cmp_int(const void *a, const void *b)
{
	int	ia;
	int	ib;

	ia = *(const int *)a;
	ib = *(const int *)b;
	return (ia - ib);
}

static int	binary_search(int *arr, int size, int key)
{
	int	l;
	int	r;
	int	m;

	l = 0;
	r = size - 1;
	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (arr[m] == key)
			return (m);
		else if (arr[m] < key)
			l = m + 1;
		else
			r = m - 1;
	}
	return (-1);
}

static void	assign_index(t_stacks *s)
{
	int		size;
	int		*iarr;
	int		*sorted;
	t_node	*cur;
	int		i;
	int		idx;

	size = stack_size(s->a);
	if (size <= 0)
		return ;
	iarr = malloc(sizeof(int) * size);
	if (!iarr)
		return ;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(iarr);
		return ;
	}
	cur = s->a;
	i = 0;
	while (cur)
	{
		iarr[i] = cur->value;
		sorted[i] = cur->value;
		cur = cur->next;
		i++;
	}
	qsort(sorted, size, sizeof(int), cmp_int);
	cur = s->a;
	i = 0;
	while (cur)
	{
		idx = binary_search(sorted, size, cur->value);
		if (idx < 0)
			cur->index = 0;
		else
			cur->index = idx;
		cur = cur->next;
		i++;
	}
	free(iarr);
	free(sorted);
}

static int	get_max_bits(t_stacks *s)
{
	int	size;
	int	max_index;
	int	max_bits;

	size = stack_size(s->a);
	max_index = size - 1;
	max_bits = 0;
	while (max_index > 0)
	{
		max_bits++;
		max_index = max_index >> 1;
	}
	return (max_bits);
}

static void	execute_radix(t_stacks *s, int max_bits)
{
	int		size;
	int		i;
	int		j;
	int		atual_bit;
	t_node	*top;

	i = 0;
	size = stack_size(s->a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			top = s->a;
			atual_bit = (top->index >> i) & 1;
			if (atual_bit == 1)
				op_ra(s);
			else
				op_pb(s);
			j++;
		}
		while (s->b)
			op_pa(s);
		i++;
	}
}

void	sort_b(t_stacks *s)
{
	int	max_bits;

	assign_index(s);
	max_bits = get_max_bits(s);
	execute_radix(s, max_bits);
}
