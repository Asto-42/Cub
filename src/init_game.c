/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:02:26 by dberreby          #+#    #+#             */
/*   Updated: 2023/11/22 14:10:57 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	set_var_null(t_vars *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->size_line = NULL;
	game->img->north_wall = NULL;
	game->img->south_wall = NULL;
	game->img->east_wall = NULL;
	game->img->west_wall = NULL;
    game->img->floor = NULL;
    game->img->roof = NULL;
    game->img->flooor = NULL;
    game->img->rooof = NULL;
    game->img->addr = NULL;
}

int	init_game(t_vars *game, char *filename)
{
	set_var_null(game);
}