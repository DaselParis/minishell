/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhtenzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:44:52 by dhtenzen          #+#    #+#             */
/*   Updated: 2024/10/04 17:53:28 by dhtenzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_space(char c)
{
    if ((c >= 9 && c <= 13) || c == ' ')
        return (-1);
    return (0);
}

int ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

size_t  ft_skipspace(char *line, size_t i)
{
	size_t  space;

	space = 0;
	while (line[i] != '\0' && is_space(line[i]) == -1)
	{
		space++;
		i++;
	}
	return (space);
}


size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

