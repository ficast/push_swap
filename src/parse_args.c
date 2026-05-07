/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/07 23:08:52 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

static int	has_duplicate(t_node *stack, int nb)
{
	while (stack)
	{
		if (stack->value == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	append_node(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return (1);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
	return (1);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*stack_a;
	long	nb;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < argc)
	{
		if (!is_valid_format(argv[i]))
			return (free_stack(&stack_a), NULL);
		nb = ft_atol(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX || has_duplicate(stack_a, (int)nb))
			return (free_stack(&stack_a), NULL);

		if (!append_node(&stack_a, (int)nb))
			return (free_stack(&stack_a), NULL);
		i++;
	}
	return (stack_a);
}
