/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhtenzen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:14:20 by dhtenzen          #+#    #+#             */
/*   Updated: 2024/10/04 17:33:26 by dhtenzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct  s_size
{
        int word;
        int pipe;
}   t_size;

enum e_token
{
        EMPTY = 9,
        WORD = 10,
        WHITE_SPACE = 11,
        NEW_LINE = 12,
        QOUTE = 13,
        DOUBLE_QUOTE = 14,
        ESCAPE = 15,
        ENV = 16,
        PIPE = 17,
        REDIR_IN = 18,
        REDIR_OUT = 19,
        DOUBLEREDIR_IN = 180,
        DOUBLEREDIR_OUT = 190,
        HERE_DOC = 20,
        DREDIR_OUT = 21,
};

typedef struct s_token
{
        char    *str;
        int type;
        struct s_token  *next;
}t_token;


//list_utils.c

void    ft_lstadd_back(t_token **lst, t_token *new);
t_token *ft_lstlast(t_token *lst);
t_token *ft_lstnew(char *str);
void    ft_freelist(t_token *L);
void    ft_printflist(t_token *line);


//main.c
int ft_checkline(char *line);
int     ft_inputcheck(char *line);
int     ft_prompt(void);


//minishell
int is_redicandothers2(char *str, char *c);
int ft_directiontype(char *str);
int    ft_token(char **splited, t_token **command);
int     ft_tokenizer(char **splited, t_token **command);

//split.c
size_t  ft_size(char *line);
int ft_word2(char *line, int i, size_t word_size);
size_t  ft_word(char *line, int i);
char    **ft_split(char *line);

//utils2.c
int     is_space(char c);
size_t  ft_skipspace(char *line, size_t i);
int ft_strcmp(char *src, char *search);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);


//utils.c
void    ft_putstr(char *str);
void    ft_free(char **str);
int     ft_strlen(const char *str);
int ft_isalpha(char c);
int ft_isspace(char c);




#endif
