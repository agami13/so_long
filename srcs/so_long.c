/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:18:07 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/09 10:20:20 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_reader(char *arv)
{
	char	*line;
	char	**map;

	line = read_map(arv);
	map = ft_split(line, '\n');
	return (map);
}

int main(int argc, char **argv)
{
	char **map;
	t_map *map_info;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
		return (1);
	}
	map = map_reader(argv[1]);
	parse_map(argv[1], map);
	map_info = struct_filler(map);
	display_win(map_info);
	ft_free(map);
	return (0);
}
