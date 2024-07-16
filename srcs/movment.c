/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:32:26 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/16 19:58:42 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	up_handler(int keycode, t_window *game)
{
	if (keycode == W)
	{
		if (game->map[game->y - 1][game->x] == '1')
			return ;
		else if (game->map[game->y - 1][game->x] == 'E'
				&& game->collectibles != 0)
		{
			ft_putstr_fd("You need to collect all the collectibles!\n", 1);
			return ;
		}
		else if (game->map[game->y - 1][game->x] == 'E'
				&& game->collectibles == 0)
		{
			ft_putstr_fd("\nYou Won!\n", 1);
			clean(game);
			exit(0);
		}
		if (game->map[game->y - 1][game->x] == 'C')
			game->collectibles--;
		game->map[game->y][game->x] = '0';
		game->y--;
		game->map[game->y][game->x] = 'P';
		game->moves++;
		put_map(game, game->map, game->down);
	}
}

void	down_handler(int keycode, t_window *game)
{
	if (keycode == S)
	{
		if (game->map[game->y + 1][game->x] == '1')
			return ;
		else if (game->map[game->y + 1][game->x] == 'E'
				&& game->collectibles != 0)
		{
			ft_putstr_fd("You need to collect all the collectibles!\n", 1);
			return ;
		}
		else if (game->map[game->y + 1][game->x] == 'E'
				&& game->collectibles == 0)
		{
			ft_putstr_fd("\nYou Won!\n", 1);
			clean(game);
			exit(0);
		}
		if (game->map[game->y + 1][game->x] == 'C')
			game->collectibles--;
		game->map[game->y][game->x] = '0';
		game->y++;
		game->map[game->y][game->x] = 'P';
		game->moves++;
		put_map(game, game->map, game->up);
	}
}

void	left_handler(int keycode, t_window *game)
{
	if (keycode == A)
	{
		if (game->map[game->y][game->x - 1] == '1')
			return ;
		else if (game->map[game->y][game->x - 1] == 'E'
				&& game->collectibles != 0)
		{
			ft_putstr_fd("You need to collect all the collectibles!\n", 1);
			return ;
		}
		else if (game->map[game->y][game->x - 1] == 'E'
				&& game->collectibles == 0)
		{
			ft_putstr_fd("\nYou Won!\n", 1);
			clean(game);
			exit(0);
		}
		if (game->map[game->y][game->x - 1] == 'C')
			game->collectibles--;
		game->map[game->y][game->x] = '0';
		game->x--;
		game->map[game->y][game->x] = 'P';
		game->moves++;
		put_map(game, game->map, game->left);
	}
}

void	right_handler(int keycode, t_window *game)
{
	if (keycode == D)
	{
		if (game->map[game->y][game->x + 1] == '1')
			return ;
		else if (game->map[game->y][game->x + 1] == 'E'
				&& game->collectibles != 0)
		{
			ft_putstr_fd("You need to collect all the collectibles!\n", 1);
			return ;
		}
		else if (game->map[game->y][game->x + 1] == 'E'
				&& game->collectibles == 0)
		{
			ft_putstr_fd("\nYou Won!\n", 1);
			clean(game);
			exit(0);
		}
		if (game->map[game->y][game->x + 1] == 'C')
			game->collectibles--;
		game->map[game->y][game->x] = '0';
		game->x++;
		game->map[game->y][game->x] = 'P';
		game->moves++;
		put_map(game, game->map, game->right);
	}
}
