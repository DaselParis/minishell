/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhtenzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:43:49 by dhtenzen          #+#    #+#             */
/*   Updated: 2024/10/04 17:50:30 by dhtenzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstlast(t_token *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*cur;

	cur = *lst;
	if (lst != NULL && *lst != NULL)
	{
		cur = ft_lstlast(*(lst));
		cur->next = new;
		return ;
	}
	*lst = new;
}

void    ft_freelist(t_token *L)
{
	t_token *tmp;

	tmp = NULL;
	while (L)
	{

		tmp = L->next;
		free(L);
		L = tmp;
	}
}

t_token *ft_lstnew(char *str)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->str = str;
	token->next = NULL;
	token->type = EMPTY;
	return (token);
}

void    ft_printflist(t_token *line)
{
	while (line != NULL)
	{
		ft_putstr(line->str);
		line = line->next;
	}
}
