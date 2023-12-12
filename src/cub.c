/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:49:22 by jquil             #+#    #+#             */
/*   Updated: 2023/12/12 14:37:33 by jquil            ###   ########.fr       */
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

void	ft_clear_mlx(t_vars *vars)
{
	if (vars->mlx)
	{
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		if (vars->map)
			free_map(vars->map);
		if (vars->size_line)
			free(vars->size_line);
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

int	main(int ac, char **av, char **envp)
{
	t_vars	game;

	if (!envp)
		return (printf("Error ENV\n"), 1);
	if (ac != 2 || !av || !valid_parsing(av[1]))
		return (printf("Error\nFichier de description invalide\n"), 2);
	if (!init_game(&game, av[1]))
		return (3);
	ft_game(&game);
	return (0);
}
