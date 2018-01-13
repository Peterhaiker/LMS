/* AddBook.c
 * Copyright (C) 2018-01-12 21:05 
 * author:peterhaiker
 * email:vim.memory@gmail.com
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include<string.h>
#include"library.h"

void AddBook()
{
  int rowcount;//结果集中的行数
  char*sql;
  char id[10]={'\0'};//书籍编号
  char bookname[50]={'\0'};//书名
  char author[50]={'\0'};//作者
  char bookconcern[100]={'\0'};//出版社
  char dest[200]={'\0'};//存储插入记录的sql语句字符串
  //connect to sql
  if(!mysql_real_connect(&mysql,host,username,password,dbname,0,NULL,0))
    printf("\n\t不能连接数据库!!!\n");
  else{
    printf("\t=" Format_Double_Symbol "=\n");
    printf("\t           添加图书信息\n");
    printf("\t=" Format_Double_Symbol "=\n");
    if(mysql_query(&mysql,"select * from tb_books"))
      printf("\n\t查询tb_books数据库失败!!!\n");
    else{
      //获得结果集
      result=mysql_store_result(&mysql);
      rowcount=mysql_num_rows(result);
      row=mysql_fetch_row(result);
      printf("\tID:_\b");
      fgets(id,10,stdin);//enter book id
      id[strlen(id)-1]='\0';
      if(0!=mysql_num_rows(result)){
        //表中存在记录，判断插入的书籍编号是否已存在
        do{
          //存在相同编号
          if(!strcmp(id,row[0])){
            printf("\t记录已存在，按任意键继续!!!");
            getchar();
            mysql_free_result(result);//释放结果集
            mysql_close(&mysql);//释放连接
            return;
          }
        }while(row=mysql_fetch_row(result));
      }
      //不存在相同的编号，继续输入
      printf("\t图书名:_\b");
      fgets(bookname,50,stdin);
      bookname[strlen(bookname)-1]='\0';

      printf("\t作者:_\b");
      fgets(author,50,stdin);
      author[strlen(author)-1]='\0';

      printf("\t出版社:_\b");
      fgets(bookconcern,100,stdin);
      bookconcern[strlen(bookconcern)-1]='\0';

      sql="insert into tb_books(id,bookname,author,bookconcern) values(";

      strncat(dest,sql,200);
      strncat(dest,"'",200);
      strncat(dest,id,200);
      strncat(dest,"','",200);
      strncat(dest,bookname,200);
      strncat(dest,"','",200);
      strncat(dest,author,200);
      strncat(dest,"','",200);
      strncat(dest,bookconcern,200);
      strncat(dest,"')",200);

      if(0!=mysql_query(&mysql,dest))
        fprintf(stderr,"\t不能插入记录:%s!!!",mysql_error(&mysql));
      else
        printf("\t插入成功!!!\n");
      mysql_free_result(result);
    }
    mysql_close(&mysql);
  }
  inquire();
  return;
}
