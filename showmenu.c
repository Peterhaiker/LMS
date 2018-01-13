/* showmenu.c
 * Copyright (C) 2018-01-12 17:35 
 * author:peterhaiker
 * email:vim.memory@gmail.com
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include"library.h"

void showmenu()
{
  system("reset");
  printf("\n\n\n\n\n");
  printf("\t||" Format_Double_Symbol "||\n");
  printf("\t||          Welcome to Lemon Books System           ||\n");
  printf("\t||" Format_Double_Symbol "||\n");
  printf("\t||         1 - 显示所有图书信息                     ||\n");
  printf("\t||         2 - 添加图书信息                         ||\n");
  printf("\t||         3 - 修改图书信息                         ||\n");
  printf("\t||         4 - 删除图书信息                         ||\n");
  printf("\t||         5 - 查询图书信息                         ||\n");
  printf("\t||         6 - 退出                                 ||\n");
  printf("\t||" Format_Double_Symbol "||\n");
  printf("\n            ENTER YOUR CHOICE(1-6)_\b:");
  return;
}
