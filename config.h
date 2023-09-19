#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<stdbool.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<windows.h>
#include<conio.h>
#include<stddef.h>

//配置结构体信息
struct ConfigInfo
{
	char key[64];
	char value[64];
};

//获取文件行数
int getFileLine(const char* filepath);

//判断有效行
int isInvalidLine(char* str);

//文件解析
void parseFile(const char* filepath, int lines, struct ConfigInfo** configInfo);