/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/04 00:00:00 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(t_stacks *s)
{
	if (s)
	{
		free_stack(&s->a);
		free_stack(&s->b);
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc < 2)
		return (0);
	s.a = parse_args(argc, argv);
	s.b = NULL;
	if (!s.a)
		error_exit(NULL);
	if (!is_sorted(s.a))
		sort(&s);
	free_stack(&s.a);
	free_stack(&s.b);
	return (0);
}
