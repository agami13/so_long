/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:18:07 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/16 00:33:03 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	extension(char **argv, char **map)
{
	char	**map_test;
	char	**map_test2;

	map_test = map_reader(argv[1]);
	map_test2 = map_reader(argv[1]);
	if (floodfill_app_collec(map_test, get_x(map_test), get_y(map_test)) == 0)
	{
		ft_free(map);
		ft_free(map_test2);
		exit(0);
	}
	if (floodfill_app(map_test2, get_x(map_test2), get_y(map_test2)) == 0)
	{
		ft_free(map);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	char	**map;
	t_map	*map_info;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
		return (1);
	}
	map = map_reader (argv[1]);
	parse_map(argv[1], map);
	extension(argv, map);
	map_info = struct_filler(map);
	display_win(map_info);
	return (0);
}
