/* library.h
 * Copyright (C) 2018-01-12 17:30 
 * author peterhaiker 
 * email  vim.memory@gmail.com
 *
 * Distributed under terms of the MIT license.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#define Format_Double_Symbol "=================================================="
#define Format_Single_Symbol "--------------------------------------------------"

#include<mysql/mysql.h>

MYSQL mysql;//定义Mysql对象
MYSQL_RES * result;//定义Mysql结果集
MYSQL_ROW row;//定义行变量
char ch[2];//定义字符变量
static const char*username="root";
static const char*host="localhost";
static const char*password="2391457146";
static const char*dbname="tb_books";

void showmenu();//显示菜单信息
void ShowAll();//显示所有的图书信息
void AddBook();//添加图书信息
void ModifyBook();//修改图书信息
void DeleteBook();//删除图书信息
void QueryBook();//查询图书信息
void inquire();//询问是否显示主菜单

#endif /* !LIBRARY_H */
