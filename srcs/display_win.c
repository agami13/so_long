/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:30:38 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/12 01:34:36 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_action(int keycode, t_window *game)
{
    static int i = 0;
    if (keycode == ESC)
    {
        mlx_destroy_image(game->mlx, game->img);
        mlx_destroy_window(game->mlx, game->window);
        exit(0);
    }
    if (keycode == W || keycode == A || keycode == S || keycode == D)
    {
        ft_printf("map[%d][%d] : %c\n", game->x, game->y, game->map[game->x][game->y]);
        i++;
        if (keycode == W)
            up_handler(keycode, game);
        else if (keycode == D)
            right_handler(keycode, game);
        else if (keycode == S)
            down_handler(keycode, game);
        else if (keycode == A)
            left_handler(keycode, game);
        else
            i--;
        ft_printf("Moves: %d\n", i);
    }
    return (0);
}
void    put_img(t_window *game, char *path, int x, int y)
{
    void    *img;
    int     width;
    int     height;

    img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
    if (!img)
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("Texture not found\n", 2);
        exit(1);
    }
    mlx_put_image_to_window(game->mlx, game->window, img, x, y);
    mlx_destroy_image(game->mlx, img);
}

void    display_win(t_map *map_info)
{
    t_window *game;
    game = malloc(sizeof(t_window));
    game->WIDTH = map_width(map_info->map);
    game->HEIGHT = map_height(map_info->map);
    game->left = "./imgs/left.xpm";
    game->right = "./imgs/right.xpm";
    game->up = "./imgs/front.xpm";
    game->down = "./imgs/back.xpm";
    game->map = map_info->map;
    player_pos(game, map_info->map);
    collectibles_count(game);
    for (int i = 0; game->map[i]; i++)
        ft_printf("%s\n", game->map[i]);
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, game->WIDTH, game->HEIGHT, "so_long");
    game->img = mlx_new_image(game->mlx, game->WIDTH, game->HEIGHT);
    game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
    put_map(game, map_info->map);
    mlx_hook(game->window, 2, 1L<<0, &ft_action, game);
    mlx_loop_hook(game->mlx, ft_action, game);
    mlx_loop(game->mlx);
}

