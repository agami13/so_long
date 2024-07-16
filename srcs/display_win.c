/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:30:38 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/16 19:40:25 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_action(int keycode, t_window *game)
{
	if (keycode == ESC)
	{
		clean(game);
		exit(0);
	}
	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		if (keycode == W)
			up_handler(keycode, game);
		else if (keycode == D)
			right_handler(keycode, game);
		else if (keycode == S)
			down_handler(keycode, game);
		else if (keycode == A)
			left_handler(keycode, game);
		ft_printf("Moves: %d\r", game->moves);
	}
	return (0);
}

void	put_img(t_window *game, char *path, int x, int y)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Texture not found\n", 2);
		clean(game);
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
	mlx_destroy_image(game->mlx, img);
}

void	give_value(t_window *game, t_map *map_info)
{
	game->width = map_width(map_info->map);
	game->height = map_height(map_info->map);
	game->left = "./imgs/left.xpm";
	game->right = "./imgs/right.xpm";
	game->up = "./imgs/front.xpm";
	game->down = "./imgs/back.xpm";
	game->map = map_info->map;
	game->collectibles = 0;
	game->moves = 0;
	player_pos(game, map_info->map);
	collectibles_count(game);
}

void	display_win(t_map *map_info)
{
	t_window	*game;

	game = malloc(sizeof(t_window));
	give_value(game, map_info);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->width,
			game->height, "so_long");
	game->img = mlx_new_image(game->mlx, game->width, game->height);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	put_map(game, map_info->map, game->up);
	mlx_hook(game->window, CLOSE, 1L << 0, close_win, game);
	mlx_hook(game->window, 2, 1L << 0, &ft_action, game);
	mlx_loop_hook(game->mlx, ft_action, game);
	mlx_loop(game->mlx);
}
