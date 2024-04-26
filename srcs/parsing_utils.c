/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:31:02 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/04/26 12:47:08 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_access(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Can't open the map\n", 2);
		close(fd);
		exit(1);
	}
	close(fd);
}

void	map_valid3(int E, int player, int collectible)
{
	if (E != 1 || player != 1 || collectible < 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map Has 0 Collectibles Or More/Less Than 1 Exit/Player's Starting Point\n", 2);
		exit(1);
	}
}

void	map_valid2(char **map, int exit, int player, int collectible)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit += 1;
			else if (map[i][j] == 'P')
				player += 1;
			else if (map[i][j] == 'C')
				collectible += 1;
			j++;
		}
		i++;
	}
	map_valid3(exit, player, collectible);
}

void	map_valid(char **map)
{
	int exit;
	int player;
	int collectible;

	exit = 0;
	player = 0;
	collectible = 0;
	map_valid2(map, exit, player, collectible);
}