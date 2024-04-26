/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:44:32 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/04/26 15:45:39 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	calculate_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	check_arg(char *argv)
{
	int	i;

	i = 0;
	if (ft_strnstr(argv, ".ber", ft_strlen(argv)) == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map file must have .ber extension\n", 2);
		exit(1);
	}
}

void	check_nonvalid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
			&& map[i][j] != 'E' && map[i][j] != 'C')
			{
				ft_putstr_fd("Error\n", 2);
				ft_putstr_fd("Map contains invalid characters\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_map(char **map)
{
	size_t	i;
	size_t	j;
	size_t	lines;

	i = 0;
	lines = calculate_lines(map);
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if ((i == 0) || (i == lines - 1)
			|| (j == 0) || (j == ft_strlen(map[i]) - 1))
			{
				if (map[i][j] != '1')
				{
					ft_putstr_fd("Error\n", 2);
					ft_putstr_fd("Map is not surrounded by walls\n", 2);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	parse_map(char *argv, char **map)
{
	check_arg(argv);
	map_access(argv);
	check_nonvalid(map);
	check_map(map);
	map_valid(map);
	// map_blocked(map);
}
