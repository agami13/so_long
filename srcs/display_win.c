/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:30:38 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/06/02 21:37:52 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_pixel(t_long *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	display_square(t_long *game, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 250)
	{
		j = 0;
		while (j < 250)
		{
			put_pixel(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	display_circle(t_long *game, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 250)
	{
		j = 0;
		while (j < 250)
		{
			if (sqrt((i - 125) * (i - 125) + (j - 125) * (j - 125)) <= 125)
				put_pixel(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	display_triangle(t_long *game, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 250)
	{
		j = 0;
		while (j < 250)
		{
			if (i <= j)
				put_pixel(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int	ft_action(int keycode, t_long *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(game->mlx, game->img);
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	return (0);
}

int	key_hook(int key)
{
	ft_printf("key: %d\n", key);
	return (0);
}

void	display_win(t_long *game)
{
	void *img;
	int img_width;
	int img_height;
	char *path = ft_strdup("../imgs/Archer_Purple.xpm");
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "so_long");
	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	mlx_put_image_to_window(game->mlx, game->window, img, 150, 150);
	// display_square(game, 0, 0, 0x0000FF00);
	mlx_key_hook(game->window, key_hook, game);
	mlx_hook(game->window, 2, 1L<<0, ft_action, game);
	mlx_loop_hook(game->mlx, ft_action, game);
	mlx_loop(game->mlx);
}