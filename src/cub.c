/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:49:22 by jquil             #+#    #+#             */
/*   Updated: 2023/11/03 14:51:50 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_format_fd(char *arg)
{
	int	x;

	x = ft_strlen(arg);
	if (arg[x - 4] != '.')
		return (0);
	if (arg[x - 1] == 'b' && arg[x - 2] == 'u' && arg[x - 3] == 'c')
		return (1);
	return (0);
}

void	free_map(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free(map);
}

void	ft_clear_mlx(t_vars *vars)
{
	if (vars->mlx)
	{
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		if (vars->map)
			free_map(vars->map);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
}

int	ft_key_hook_2(t_vars *vars)
{
	ft_clear_mlx(vars);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	if (!envp)
	{
		printf("Error ENV\n");
		return (1);
	}
	(void)argc;
	// if (argc < 2 || (argc != 2 || ft_check_format_fd(argv[1]) == 0))
	// {
	// 	printf("ERROR ARG\n");
	// 	return (1);
	// }
	if (ft_extract_map_for_parse(argv[1]) == 0)
	{
		printf("ERROR MAP\n");
		return (1);
	}
	ft_game(argv[1]);
	return (0);
}
