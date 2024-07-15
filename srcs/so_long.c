/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:18:07 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/15 22:33:58 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	char **map;
	char **map_test;
	t_map *map_info;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
		return (1);
	}
	map = map_reader(argv[1]);
	map_test = map_reader(argv[1]);
	parse_map(argv[1], map);
	if (floodfill_app_collec(map_test, get_x(map_test), get_y(map_test)) == 0
		&& floodfill_app(map_test, get_x(map_test), get_y(map_test)) == 0)
	{
		ft_free(map);
		return (0);
	}
	map_info = struct_filler(map);
	display_win(map_info);
	return (0);
}
