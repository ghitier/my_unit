/*
** my_unit.h for my_unit in /home/hitier_g/Projects/my_unit
** 
** Made by Guillaume HITIER
** Login   <guillaume.hitier@epitech.eu>
** 
** Started on  Fri Mar 24 01:37:41 2017 Guillaume HITIER
** Last update Fri Mar 24 01:37:44 2017 Guillaume HITIER
*/

#ifndef _MY_UNIT_H_
# define _MY_UNIT_H_

#include <stdbool.h>

/* Definition ascii colors */
#define NORMAL		"\033[0m" // default normal color
#define SUCCESS		"\033[38;5;40m" // green by default
#define FAILURE		"\033[38;5;196m" // red by default
#define WARNING		"\033[38;5;226m" // yellow by default
#define DISABLED	"\033[38;5;247m" // grey by default
#define GROUP		"\033[38;5;45m" // blue by default

/* Definition of strings */
#define PASSED		"\u2714" // U+2714: Heavy check mark
#define FAILED		"\u2717" // U+2717: Cross mark
#define SKIPPED		"\u21A9" // U+21A9: Leftwards arrow with hook
#define INDENTATION	"\uFE30   " // string to indent groups

typedef struct	s_info
{
  unsigned int	total;
  unsigned int	passed;
  unsigned int	failed;
  unsigned int	skipped;
}		t_info;

typedef struct	s_group
{
  int		indentation;
  bool		skip;
}		t_group;

/* functions in "cunit.c" */
void	group(const char *, void (*func)(void *), void *data);
void	skip_group(const char *, void (*func)(void *), void *data);
void	test(const char *, bool);
void	skip_test(const char *, bool);
void	info(void);

#endif /* !_MY_UNIT_H_ */
