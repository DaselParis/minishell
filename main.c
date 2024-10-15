/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhtenzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:44:02 by dhtenzen          #+#    #+#             */
/*   Updated: 2024/10/04 17:54:49 by dhtenzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_checkline(char *line)
{
	int i;
	int open_quote;

	i = 0;
	open_quote = 0;
	if (line == NULL)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == '\'' || line[i] == '"')
			open_quote++;
		i++;
	}
	if (open_quote % 2 != 0)
		return (printf("-bash: syntax error\n"), -1);
	return (0);
}

int    ft_inputcheck(char *line)
{
	char **splited;

	t_token *token;

	token = NULL;
	if (ft_checkline(line) == -1)
		return (-1);
	splited = ft_split(line);
	if(splited == NULL)
		return (-1);
	if (ft_tokenizer(splited, &token) == -1)
		return (ft_free(splited), -1);
	return (0);
}

int   ft_prompt(void)
{
	char    *line;

	line = NULL;
	while (1)
	{
		line = readline("Minishell : ");
		if (!line)
		{
			printf("exit\n");
			exit(1);
		}
		if (strlen(line) > 0)
			add_history(line);
		if (ft_inputcheck(line) == -1)
			return (free(line), -1);
		free(line);
	}
	return (0);
}

int    main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	if (ft_prompt() == -1)
		return (0);
	return (0);
}
