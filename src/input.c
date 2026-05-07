/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/04 00:00:00 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_int(char c);
int	has_duplicates(int *arr);
int	is_valid_strategy(char *s);
int	is_bench(char *s);

t_node	*parse_args(int argc, char **argv)
{
	char	flags[5];

	flags = {"--simple", "--medium", "--complex",
		"--adptative", "--bench"};
	if ()
}