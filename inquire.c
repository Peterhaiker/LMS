/* inquire.c
 * Copyright (C) 2018-01-12 20:34 
 * author:peterhaiker
 * email:vim.memory@gmail.com
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include<ctype.h>
#include<mysql/mysql.h>
#include"library.h"

void inquire()
{
  printf("\t显示主菜单?(y/n):_\b");
  char choice;
  while(1!=scanf("%[yYnN]",&choice)){
    while('\n'!=getchar());
    printf("\t显示主菜单?(y/n):_\b");
  }
  while('\n'!=getchar());

  choice=tolower(choice);
  if('y'==choice)
    showmenu();
  else{
    puts("\tbye");
    exit(EXIT_SUCCESS);
  }
  return;
}
