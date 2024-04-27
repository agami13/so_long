/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:30:38 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/04/27 10:36:42 by ybouaoud         ###   ########.fr       */
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

void	display_win(t_long *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "so_long");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	// put_pixel(game, 400, 400, 0x00FF0000);
	display_map(game, game->map);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	mlx_loop(game->mlx);
}