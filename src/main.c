/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 00:00:00 by fiolivei          #+#    #+#             */
/*   Updated: 2026/05/07 23:11:03 by ipinto-m         ###   ########.fr       */
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

static int	define_strategy(int argc, char **argv, char **strategy, int *bench)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--simple", ft_strlen("--simple")) == 0
			|| ft_strncmp(argv[i], "--medium", ft_strlen("--medium")) == 0
			|| ft_strncmp(argv[i], "--complex", ft_strlen("--complex")) == 0
			|| ft_strncmp(argv[i], "--adaptive", ft_strlen("--adaptive")) == 0)
			*strategy = argv[i];
		else if (ft_strncmp(argv[i], "--bench", ft_strlen("--bench")) == 0)
			*bench = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	char		*strategy;
	int			bench_mode;
	int			i;

	if (argc < 2)
		return (0);
	s.a = NULL;
	s.b = NULL;
	strategy = "--adaptive";
	bench_mode = 0;
	i = define_strategy(argc, argv, &strategy, &bench_mode);
	s.a = parse_args(argc - i, argv + i);
	if (!s.a)
		error_exit(&s);
	if (!is_sorted(s.a))
		sort(&s, strategy);
	free_stack(&(s.a));
	return (0);
}
