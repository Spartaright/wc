#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int charcalculate(char *file) {
	FILE *fp = NULL;
	int charcount = 0;
	fp = fopen(file, "r");//打开一个文本文件
	if (fp == NULL) {
		printf("文件寻找失败！\n");
		exit(-1);
	}
	char filechar;
	filechar = fgetc(fp);
	while (filechar != EOF) {
		filechar = fgetc(fp);//读取文件中的字符
		charcount++;//统计字符数
	}
	fclose(fp);
	return charcount - 1;
}

int wordcalculate(char *file) {
	FILE *fp = NULL;
	int wordcount = 0;
	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("文件寻找失败！\n");
		exit(-1);
	}
	char fileword;
	int word;
	fileword = fgetc(fp);
	while (fileword != EOF) {
		fileword = fgetc(fp);
		if (fileword<'A' || (fileword > 'Z'&&fileword < 'a') || fileword>'z')
		{
			word = 0;
		}
		else if (word == 0)
		{
			word = 1;
			wordcount++;
		}
	}
	if (word == 0)
	{
		wordcount++;
		word = 1;

	}
	return wordcount;
}

int linecalculate(char *file) {
	FILE *fp = NULL;
	int linecount = 0;
	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("文件寻找失败！\n");
		exit(-1);
	}
	char fileline;
	fileline = fgetc(fp);
	while (fileline != EOF) {
		if (fileline == '\n') {//出现换行时，统计行数
			linecount++;
			fileline = fgetc(fp);
		}
		else {
			fileline = fgetc(fp);
		}
		fclose(fp);
		return linecount + 1;
	}
}

int main() {
	char file[200], intput;
	printf("请输入用户命令：wc.exe-");
	intput = getchar();
	switch (intput)
	{
	case 'c':
		printf("请输入文件名：");
		scanf("%s", &file);
		int charcount = 0;
		charcount = charcalculate(file);
		printf("文件字符数为：%d\n", charcount);
		break;
	case 'w':
		printf("请输入文件名：");
		scanf("%s", &file);
		int wordcount = 0;
		wordcount = wordcalculate(file);
		printf("文件单词数为：%d\n", wordcount);
		break;
	case 'l':
		printf("请输入文件名：");
		scanf("%s", &file);
		int linecount = 0;
		linecount = linecalculate(file);
		printf("文件行数为：%d\n", linecount);
		break;
	default:
		printf("错误操作！请重新输入！");
	}
	getchar();
	return 0;
}