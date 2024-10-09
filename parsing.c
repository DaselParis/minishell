/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhtenzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:44:32 by dhtenzen          #+#    #+#             */
/*   Updated: 2024/10/07 16:45:04 by dhtenzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_word2(char *line, int i, size_t word_size)
{
	if (line[i] == '<' && line[i + 1] == '<' && word_size != 0)
		return (-1);
	else if (line[i] == '<' && line[i + 1] == '<')
		return (-3);
	else if (line[i] == '>' && line[i + 1] == '>' && word_size != 0)
		return (-1);
	else if (line[i] == '>' && line[i + 1] == '>')
		return (-3);
	else if ((line[i] == '|' || line[i] == '<' || line[i] == '>') && word_size != 0)
		return (-1);
	else if (line[i] == '|' || line[i] == '<' || line[i] == '>')
		return (-2);
	return (1);
}

size_t  ft_word(char *line, int i)
{
	size_t  word_size;
	size_t  j;
	int  temp;

	word_size = 0;
	while (is_space(line[i]) == -1)
		i++;
	while (line[i] != '\0' && (is_space(line[i]) != -1))
	{
		if (line[i] == '"' || line[i] == '\'' )
		{
			j = i;
			word_size++;
			i++;
			while (line[i] != '\0' && line[i] != line[j])
			{
				i++;
				word_size++;
			}
		}
		temp = ft_word2(line, i, word_size);
		if (temp == -2)
			word_size++;
		if (temp == -3)
			word_size += 2;
		if (temp < 0)
			break;
		i += temp;
		word_size += temp;
	}
	return (word_size);
}

size_t ft_size(char *line)
{
	int words;
	int i;
	int ret;

	words = 0;
	ret = 1;
	i = 0;
	while (ret != 0)
	{
		ret = ft_word(line, i);
		if (ret == 0)
			break;
		if (!ft_isspace(line[i]))
			words++;
		i += ret;
	}
	printf("words = %d\n", words);
	return (words);	
}

char    **ft_split(char *line)
{
	size_t i;
	size_t j;
	char **splited;

	i = 0;
	j = 0;
	splited = malloc(sizeof(char *) * (ft_size(line) + 1));
	if (!splited)
		return (NULL);
	while (line && line[i] != '\0')
	{
		splited[j] = malloc(sizeof(char) * (ft_word(line, i) + 1));
		if (splited[j] == NULL)
			return (ft_free(splited), NULL);
		while (is_space(line[i]) == -1)
			i++;
		ft_strlcpy(splited[j], &line[i], ft_word(line, i) + 1);
		i += ft_word(line, i);
		while (line[i] != '\0' && is_space(line[i]) == -1)
			i++;
		printf("splited = %s \n", splited[j]);
		j++;
	}
	splited[j] = malloc(sizeof(char) * 1);
	if (!splited[j])
		return (ft_free(splited), NULL);
	splited[j] = NULL;
	return (splited);
}
