/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:00:35 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/07/15 20:12:24 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_x(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}
int	get_y(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				return (y);
			y++;
		}
		x++;
	}
	return (0);
}

int    floodfill(char **map, int x, int y, char target)
{
    if (x < 0 || x >= calculate_lines(map) || y < 0 || y >= (int)ft_strlen(map[0])
		|| map[x][y] == '1' || map[x][y] == '*')
		return (0);
	if (map[x][y] == target)
		return (1);
	map[x][y] = '*';
	return (floodfill(map, x + 1, y, target) || floodfill(map, x - 1, y,
			target) || floodfill(map, x, y + 1, target) || floodfill(map, x, y
			- 1, target));
}

int    floodfill_app(char **map, int x, int y)
{
    int i;
    
    i = 0;
    if (!floodfill(map, x, y, 'E'))
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("No valid path found!\n", 2);
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
        return (0);
    }
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    return (1);
}
