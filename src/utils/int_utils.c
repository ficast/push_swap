/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiolivei <fiolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:03:17 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/25 16:20:39 by fiolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
