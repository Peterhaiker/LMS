/* library.c
 * Copyright (C) 2018-01-12 17:45 
 * author:peterhaiker
 * email:vim.memory@gmail.com
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include<mysql/mysql.h>
#include"library.h"

int main(int argc,char*argv[])
{
  int n;//store the user input value
  mysql_init(&mysql);//init the mysql structure
  showmenu();//show menu
  while(1!=scanf("%d",&n))
    while('\n'!=getchar());
  while('\n'!=getchar());

  while(n){
    switch(n){
      case 1:ShowAll();break;
      case 2:AddBook();break;
      case 3:ModifyBook();break;
      case 4:DeleteBook();break;
      case 5:QueryBook();break;
      case 6:exit(EXIT_SUCCESS);
      default:break;
    }
    while(1!=scanf("%d",&n))
      while('\n'!=getchar());
    while('\n'!=getchar());
  }
  return 0;
}
