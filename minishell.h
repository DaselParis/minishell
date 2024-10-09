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
        EMPTY = 0,
        WORD = 1,
        WHITE_SPACE = 2,
        NEW_LINE = 3,
        QOUTE = 4,
        DOUBLE_QUOTE = 5,
        ESCAPE = 6,
        ENV = 7,
        PIPE = 8,
        REDIR_IN = 9,
        REDIR_OUT = 10,
        DOUBLEREDIR_IN = 11,
        DOUBLEREDIR_OUT = 12,
        HERE_DOC = 13,
        DREDIR_OUT = 14,
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


//redirection
//int is_redicandothers2(char *str, char *c);
int ft_directiontype(char *str);

//second main
int    ft_token(char **splited, t_token **command);
int     ft_tokenizer(char **splited, t_token **command);

//parsing.c
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
