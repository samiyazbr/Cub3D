/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:53:24 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/10/28 19:34:59 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int is_valid_map_character(char c) {
    return (c == ' ' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

static int is_valid_map_line(const char* line) {
    int i = 0;
    while (line[i] && is_valid_map_character(line[i])) {
        i++;
    }
    return (line[i] == '\0');
}

static int parse_valid_map_line(char* line) {
    if (build_map(line) == 1) {
        return 1;
    }
    return 0;
}

int parse_map(int fd) {
    char *line;
    int mapEmpty;

	mapEmpty = 1;
    while (1) {
        line = get_next_line(fd);
        line = ft_strtrim(line, "\n");
		if (ft_strlen(line) == 0 && !data()->map)
			;
        if (!line || ft_strlen(line) == 0) {
            free(line);
            break;
        }
        if (is_valid_map_line(line)) {
            mapEmpty = 0;
            if (parse_valid_map_line(line) == 1) {
                free(line);
                return 1;
            }
        }
        free(line);
    }
    if (mapEmpty)
        return 1;
    return 0;
}
