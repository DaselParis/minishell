/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhtenzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:44:26 by dhtenzen          #+#    #+#             */
/*   Updated: 2024/10/04 17:54:18 by dhtenzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int    ft_token(char **splited, t_token **command)
{
	int i;
	t_token *current;

	i = 0;
	current = *command;
	while (splited[i] != NULL)
	{
		current = ft_lstnew(splited[i]);
		if (ft_strcmp(splited[i], "<") == 0 || ft_strcmp(splited[i], ">") == 0 ||
				ft_strcmp(splited[i], "<<") == 0 || ft_strcmp(splited[i], ">>") == 0)
			current->type = ft_directiontype(splited[i]);
		else if (ft_strcmp(splited[i], "|") == 0)
			current->type = PIPE;
		else if (ft_strcmp(splited[i], "$") == 0)
			current->type = ENV;
		else
			current->type = WORD;
		printf("%d\n", current->type);
		ft_lstadd_back(command, current);
		i++;
	}
	return (0);
}

int ft_tokenizer(char **splited, t_token **command)
{
	// t_token *current;

	// current = *command;
	if (ft_token(splited, command) == -1)
		return (-1);
	// if (ft_multiplespecialcarac(splited) == -1)
	//     return (-1);
	// is_redicandothers(command);
	return (0);
}
