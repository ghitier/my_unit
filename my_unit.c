/*
** my_unit.c for my_unit in /home/hitier_g/Projects/my_unit
** 
** Made by Guillaume HITIER
** Login   <guillaume.hitier@epitech.eu>
** 
** Started on  Fri Mar 24 01:37:57 2017 Guillaume HITIER
** Last update Fri Mar 24 01:38:04 2017 Guillaume HITIER
*/

#include <err.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "my_unit.h"

static t_info	info_t = {0, 0, 0, 0};
static t_group	group_t = {0, 0};

static void	indent()
{
  for (int i = 0; i < group_t.indentation; i++)
    printf(INDENTATION);
}

void	skip_group(const char *description, void (*func)(void *), void *data)
{
  bool	tmp;

  indent();
  if (!group_t.skip)
    printf(WARNING "%s ", SKIPPED);
  printf(DISABLED "\"%s\" :\n" NORMAL, description);
  group_t.indentation++;
  tmp = group_t.skip;
  group_t.skip = true;
  func(data);
  group_t.skip = tmp;
  group_t.indentation--;
  printf(NORMAL);
}

void	group(const char *description, void (*func)(void *), void *data)
{
  if (group_t.skip)
    return skip_group(description, func, data);

  indent();
  group_t.indentation++;
  printf(GROUP "\"%s\" :\n" NORMAL, description);
  func(data);
  group_t.indentation--;
}

void	test(const char *description, bool expression)
{
  indent();
  if (group_t.skip)
    {
      printf(DISABLED);
      info_t.skipped++;
    }
  else if (expression)
    {
      printf(SUCCESS "%s" NORMAL, PASSED);
      info_t.passed++;
    }
  else
    {
      printf(FAILURE "%s" NORMAL, FAILED);
      info_t.failed++;
    }
  printf(" %s\n" NORMAL, description);
  info_t.total++;
}

void	skip_test(const char *description, bool expression)
{
  indent();
  if (!group_t.skip)
    printf(WARNING "%s", SKIPPED);
  printf(DISABLED " %s\n" NORMAL, description);
  info_t.skipped++;
  info_t.total++;
}

void	info()
{
  printf("%d tests in total, ", info_t.total);
  printf(SUCCESS "%d passed%s", info_t.passed, NORMAL ", ");
  printf(FAILURE "%d failed%s", info_t.failed, NORMAL ", ");
  printf(WARNING "%d skipped%s\n" NORMAL, info_t.skipped, NORMAL ".");
}
