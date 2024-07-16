/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 02:56:59 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/16 01:31:18 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean(t_window *game)
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->window);
	ft_free(game->map);
	free(game);
	return ;
}

int	close_win(t_window *game)
{
	clean(game);
	exit(0);
	return (0);
}
