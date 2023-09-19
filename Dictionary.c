#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<stdbool.h>
#include<sys/stat.h>
#include<sys/types.h>

typedef struct _dict
{
	char key[256];
	char content[256];
}DICT;

void dict_init(DICT** temp)
{
	DICT* p =NULL;
	p = malloc(sizeof(DICT) * 2);
	strcpy(p[0].key, "hello");
	strcpy(p[0].content, "你好");

	strcpy(p[1].key, "world");
	strcpy(p[1].content, "世界");

	*temp = p;

}

int search_dict(char* cmd, DICT* dict, int n, char* content)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(cmd, dict[i].key) == 0)
		{
			strcpy(content, dict[i].content);
			return 1;
		}
	}
	return 0;
}

int main()
{
	DICT* dict = NULL;
	dict_init(&dict);
	char cmd[256] = "";
	char content[256] = "";
	int ret = 0;
	while (1)
	{
		printf("请输入");
		fgets(cmd, sizeof(cmd), stdin);
		cmd[strlen(cmd) - 1] = 0;
		ret = search_dict(cmd, dict, 2, content);
		if (ret == 0)
		{
			printf("not found\n");
		}
		else
		{
			printf("翻译为：%s", content);
		}
	}


	return 0;
}