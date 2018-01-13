/* ShowAll.c
 * Copyright (C) 2018-01-12 19:11 
 * author:peterhaiker
 * email:vim.memory@gmail.com
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include"library.h"
#include<mysql/mysql.h>

void ShowAll()
{
  if(!mysql_real_connect(&mysql,host,username,password,dbname,0,NULL,0))
    printf("\n\t不能连接数据库\n");
  else{
    //数据库连接成功
    if(mysql_query(&mysql,"select * from tb_books"))
      //查询失败
      printf("\n\t查询tb_books数据表失败!!!\n");
    else{
      result=mysql_store_result(&mysql);//获得结果集
      if(mysql_num_rows(result)!=0){
        //有记录
        printf("\t=" Format_Double_Symbol "=\n");
        printf("\t           显示所有图书信息\n");
        printf("\t=" Format_Double_Symbol "=\n");
        printf("\t%-13s\t%-13s\t%-13s\t%-13s\n","图书编号","图书名","作者","出版社");
        printf("\t-" Format_Single_Symbol "-\n");
        while((row=mysql_fetch_row(result)))
          fprintf(stdout,"\t%-13s\t%-13s\t%-13s\t%-13s\n",row[0],row[1],row[2],row[3]);
        printf("\t=" Format_Double_Symbol "=\n");
      }
      else
        printf("\n\t没有记录信息!!!\n");

      mysql_free_result(result);//释放结果集
    }
    mysql_close(&mysql);
  }
  inquire();
  return;
}
