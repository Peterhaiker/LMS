/* DeleteBook.c
 * Copyright (C) 2018-01-13 10:40 
 * author:peterhaiker
 * email:vim.memory@gmail.com
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"library.h"

void DeleteBook()
{
  char id[10]={'\0'};
  char*sql=NULL;
  char dest[200]={'\0'};

  if(!mysql_real_connect(&mysql,host,username,password,dbname,0,NULL,0))
    printf("\t不能连接数据库!!!\n");
  else{
    printf("\t请输入您想删除的图书编号:_\b");
    fgets(id,10,stdin);
    while('\0'!=id[9]&&'\n'!=id[9]){
      printf("\t超过最大编号。请输入您想删除的图书编号:_\b");
      while('\n'!=getchar());
      fgets(id,10,stdin);
    }
    id[strlen(id)-1]='\0';
    sql="select * from tb_books where id=";
    strncat(dest,sql,200);
    strncat(dest,id,200);

    //查询该图书是否存在
    if(mysql_query(&mysql,dest))
      printf("\n查询tb_books数据表失败!!!\n");
    else{
      result=mysql_store_result(&mysql);//获得结果集
      if(0!=mysql_num_rows(result)){
        //有记录，开始取数据
        printf("\t发现有记录，是否显示?(y/n):_\b");
        char ch;
        while(1!=scanf("%[yYnN]",&ch)){
          printf("\t发现有记录，是否显示?(y/n):_\b");
          while('\n'!=getchar());
        }
        while('\n'!=getchar());
        ch=tolower(ch);
        if('y'==ch){
          printf("\t=" Format_Double_Symbol "=\n");
          printf("\t            ******显示图书信息******\n");
          printf("\t=" Format_Double_Symbol "=\n");
          printf("\t%-13s%-13s%-13s%-13s\n","图书编号","图书名","作者","出版社");
          printf("\t-" Format_Single_Symbol "-\n");
          while((row=mysql_fetch_row(result)))
            fprintf(stdout,"\t%-13s%-13s%-13s%-13s\n",row[0],row[1],row[2],row[3]);
          printf("\t=" Format_Double_Symbol "=\n");
        }
        printf("\t是否删除?(y/n):_\b");
        while(1!=scanf("%[yYnN]",&ch)){
          printf("\t输入错误!!!是否删除?(y/n):_\b");
          while('\n'!=getchar());
        }
        while('\n'!=getchar());
        ch=tolower(ch);
        if('y'==ch){
          //删除记录
          sql="delete from tb_books where id=";
          strncpy(dest,sql,200);
          strncat(dest,id,200);
          if(0!=mysql_query(&mysql,dest))
            fprintf(stderr,"\t不能删除记录:%s!!!\n",mysql_error(&mysql));
          else
            printf("\t删除成功!!!\n");
        }
      }
      else
        printf("\t没有发现要删除的记录!!!\n");
    }
    mysql_free_result(result);
  }
  mysql_close(&mysql);
  inquire();
  return;
}
