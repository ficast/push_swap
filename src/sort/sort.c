/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/08 14:09:58 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort(t_stacks *s, char *strategy)
{
	double	disorder;

	disorder = compute_disorder(s->a);
	s->benchmarks.disorder = disorder;
	if (!ft_strncmp(strategy, "--simple", sizeof("--simple")))
		return (sort_a(s));
	if (!ft_strncmp(strategy, "--medium", sizeof("--medium")))
		return (sort_b(s));
	if (!ft_strncmp(strategy, "--complex", sizeof("--complex")))
		return (sort_c(s));
	if (disorder < 0.2)
	{
		s->benchmarks.executed = STRATEGY_SIMPLE;
		return (sort_a(s));
	}
	if (disorder < 0.5)
	{
		s->benchmarks.executed = STRATEGY_MEDIUM;
		return (sort_b(s));
	}
	s->benchmarks.executed = STRATEGY_COMPLEX;
	return (sort_c(s));
}
