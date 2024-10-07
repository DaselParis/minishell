/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhtenzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:48:49 by dhtenzen          #+#    #+#             */
/*   Updated: 2024/10/04 17:57:14 by dhtenzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int ft_directiontype(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strcmp(str, "<") == 0)
			return (REDIR_IN);
		else if (ft_strcmp(str, ">") == 0)
			return (REDIR_OUT);
		else if (ft_strcmp(str, "<<") == 0)
			return (DOUBLEREDIR_IN);
		else if (ft_strcmp(str, ">>") == 0)
			return (DOUBLEREDIR_OUT);
		i++;
	}
	return (0);
}
/*int is_redicandothers2(char *str, char *c)
  {
  int i;

  i = 0;
  while (str[i] != '\0')
  {
  if (str[i] == *c)
  return (0);
  i++;
  }
  return (1);
  }

// void is_redicandothers(t_token **command)
// {
//     t_token *current;
//     int i;

//     i = 0;
//     current = *command;
//     while (current != NULL)
//     {
//         if (is_redicandothers2(current->str, ">") == 0)
//             printf("dsaasdasda\n");
//         i++;
//         current = current->next;
//     }
// }
// */

