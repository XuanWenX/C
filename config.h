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

//���ýṹ����Ϣ
struct ConfigInfo
{
	char key[64];
	char value[64];
};

//��ȡ�ļ�����
int getFileLine(const char* filepath);

//�ж���Ч��
int isInvalidLine(char* str);

//�ļ�����
void parseFile(const char* filepath, int lines, struct ConfigInfo** configInfo);