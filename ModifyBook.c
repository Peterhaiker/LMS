/* ModifyBook.c
 * Copyright (C) 2018-01-12 22:56 
 * author:peterhaiker
 * email:vim.memory@gmail.com
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<mysql/mysql.h>
#include"library.h"

void ModifyBook()
{
  char id[10]={'\0'};//书籍编号
  char bookname[50]={'\0'};//书籍名
  char author[50]={'\0'};//作者
  char bookconcern[100]={'\0'};//出版社
  char*sql;
  char dest[200]={'\0'};//删除记录的sql语句字符串

  if(!mysql_real_connect(&mysql,host,username,password,dbname,0,NULL,0))
    printf("\t不能连接到数据库!!!\n");
  else{
    //数据库连接成功
    printf("\t请输入您想要修改的图书编号:_\b");
    fgets(id,10,stdin);
    id[strlen(id)-1]='\0';

    //判断数据库中是否存有此编号的图书
    sql="select * from tb_books where id=";
    strncat(dest,sql,200);
    strncat(dest,id,200);
    if(mysql_query(&mysql,dest))
      //如果查询失败
      printf("\n查询tb_books数据表失败!!!\n");
    else{
      result=mysql_store_result(&mysql);
      if(0!=mysql_num_rows(result)){
        //数据库存有记录，然后查看指定的记录是否在其中
        printf("\t发现记录信息，是否显示?(y/n):_\b");
        char ch;
        while(1!=scanf("%[yYnN]",&ch)){
          while('\n'!=getchar());
          printf("\t发现记录信息，是否显示?(y/n):_\b");
        }
        while('\n'!=getchar());
        ch=tolower(ch);
        if('y'==ch){//显示记录信息
          printf("\t=" Format_Double_Symbol "=\n");
          printf("\t       *****显示图书信息*****\n");
          printf("\t=" Format_Double_Symbol "=\n");
          printf("\t%-13s%-13s%-13s%-13s\n","图书编号","图书名","作者","出版社");
          printf("\t-" Format_Single_Symbol "-\n");
          while((row=mysql_fetch_row(result)))
            fprintf(stdout,"\t%-13s%-13s%-13s%-13s\n",row[0],row[1],row[2],row[3]);

          printf("\t=" Format_Double_Symbol "=\n");
          printf("\tModify?(y/n):_\b");
          while(1!=scanf("%[yYnN]",&ch)){
            while('\n'!=getchar());
            printf("\tModify?(y/n):_\b");
          }
          while('\n'!=getchar());
          ch=tolower(ch);
          if('y'==ch){
            //修改记录
            printf("\t图书名:_\b");
            fgets(bookname,50,stdin);
            bookname[strlen(bookname)-1]='\0';

            printf("\t作者:_\b");
            fgets(author,50,stdin);
            author[strlen(author)-1]='\0';

            printf("\t出版社:_\b");
            fgets(bookconcern,100,stdin);
            bookconcern[strlen(bookconcern)-1]='\0';

            sql="update tb_books set bookname='";
            strncpy(dest,sql,200);
            strncat(dest,bookname,200);
            strncat(dest,"',author='",200);
            strncat(dest,author,200);
            strncat(dest,"',bookconcern='",200);
            strncat(dest,bookconcern,200);
            strncat(dest,"' where id=",200);
            strncat(dest,id,200);

            if(0!=mysql_query(&mysql,dest))
              fprintf(stderr,"\t不能修改记录:%s!!!\n",mysql_error(&mysql));
            else
              printf("\t修改成功!!!\n");
          }//if
        }//if
      }//if
      else
        printf("\t没有发现要修改的信息\n");
    }//else
    mysql_free_result(result);
  }//else
  mysql_close(&mysql);
  inquire();
  return;
}//void
