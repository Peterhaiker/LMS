/* QueryBook.c
 * Copyright (C) 2018-01-13 12:30 
 * author:peterhaiker
 * email:vim.memory@gmail.com
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include<string.h>
#include"library.h"

void QueryBook()
{
  char id[10]={'\0'};//图书编号
  char*sql=NULL;//存放sql语句通用部分
  char dest[200]={'\0'};//存放sql语句
  //连接数据库
  if(!mysql_real_connect(&mysql,host,username,password,dbname,0,NULL,0))
    printf("\t不能连接数据库!!!\n");
  else{
    printf("\t请输入您想要查询的图书编号:_\b");
    fgets(id,10,stdin);
    while('\0'!=id[9]&&'\n'!=id[9]){
      //输入的编号过长
      while('\n'!=getchar());
      printf("\t编号过长!重新输入您想查询的图书编号:_\b");
    }
    id[strlen(id)-1]='\0';
    sql="select * from tb_books where id=";
    strncat(dest,sql,200);
    strncat(dest,id,200);
    if(mysql_query(&mysql,dest))
      printf("\n\t查询tb_books数据表失败!!!\n");
    else{
      result=mysql_store_result(&mysql);//获得结果集
      if(0!=mysql_num_rows(result)){
        //有记录
        printf("\t" Format_Double_Symbol "=\n");
        printf("\t              显示图书信息\n");
        printf("\t=" Format_Double_Symbol "=\n");
        while(row=mysql_fetch_row(result))
          fprintf(stdout,"\t%-13s%-13s%-13s%-13s\n",row[0],row[1],row[2],row[3]);
        printf("\t=" Format_Double_Symbol "=\n");
      }
      else
        printf("\t没有发现要查询的记录!!!\n");
      mysql_free_result(result);
    }
    mysql_close(&mysql);
  }//else.连接数据库成功
  inquire();
  return;
}
