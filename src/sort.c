/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/04 00:00:00 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//sort_a (O(n²)) → insertion? selection? bubble? min/max extraction?
static void	sort_a(t_stacks *s)
{
	(void)s;
}

// sort_b (O(n√n)) → chunks de quantos? bucket? como define ranges?
static void	sort_b(t_stacks *s)
{
	(void)s;
}
//  (O(n log n)) → radix LSD? quicksort com partição? Turkish?
static void	sort_c(t_stacks *s)
{
	(void)s;
}

void	sort(t_stacks *s, char *strategy)
{
	double	disorder;

	if (!ft_strncmp(strategy, "--simple", sizeof("--simple")))
		return (sort_a(s));
	if (!ft_strncmp(strategy, "--medium", sizeof("--medium")))
		return (sort_b(s));
	if (!ft_strncmp(strategy, "--complex", sizeof("--complex")))
		return (sort_c(s));
	disorder = compute_disorder(s->a);
	if (disorder < 0.2)
		return (sort_a(s));
	if ((disorder < 0.5))
		return (sort_b(s));
	return (sort_c(s));
}
