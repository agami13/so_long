/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:18:07 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/06/02 21:35:14 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_long game;
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
		return (1);
	}
	char *map = read_map(argv[1]);
	char **map2 = ft_split(map, '\n');
	game.map = map2;
	parse_map(argv[1], map2);
	// map_blocked(map2);
	ft_free(map2);
	display_win(&game);
	return (0);
}
