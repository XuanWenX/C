#include"config.h"

//获取文件^有效^行数
int getFileLine(const char* filepath)
{
	FILE* file = fopen(filepath, "r");
	if (NULL == file)
	{
		return -1;
	}
	char buf[1024] = {0};
	int line = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		if (isInvalidLine(buf))
		{
			line++;

		}
		
	}
	return line; //未筛选

}

int isInvalidLine(char* str)
{
	if (str[0] == '\n' || NULL == strchr(str, ':'))
	{
		return 0;
	}
	return 1;
}

void parseFile(const char* filepath, int lines, struct ConfigInfo** configInfo)
{
	struct ConfigInfo* config = malloc(sizeof(struct ConfigInfo)*lines);
	//heroname:卡特琳娜
	if (NULL == config)
	{
		return;
	}

	FILE* file = fopen(filepath, "r");
	if (NULL == file)
	{
		return;
	}

	char buf[1024] = { 0 };
	int index = 0;
	while (NULL != fgets(buf, 1024, file))
	{
		if (isInvalidLine(buf))
		{
			//heroname:卡特琳娜
			memset(config[index].key, 0, 64);
			memset(config[index].value, 0, 64);
			

			char* pos =strchr(buf,':');
			strncpy(config[index].key, buf, pos-buf);
			strncpy(config[index].value, pos+1,strlen(pos+1)-1);
			printf("key=%s\n", config[index].key);
			printf("value=%s\n", config[index].value);

			index++;
		}
		memset(buf, 0, 1024);
		
	}

	*configInfo = config;
}
