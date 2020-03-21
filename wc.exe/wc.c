#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int charcalculate(char *file) {
	FILE *fp = NULL;
	int charcount = 0;
	fp = fopen(file, "r");//��һ���ı��ļ�
	if (fp == NULL) {
		printf("�ļ�Ѱ��ʧ�ܣ�\n");
		exit(-1);
	}
	char filechar;
	filechar = fgetc(fp);
	while (filechar != EOF) {
		filechar = fgetc(fp);//��ȡ�ļ��е��ַ�
		charcount++;//ͳ���ַ���
	}
	fclose(fp);
	return charcount - 1;
}

int wordcalculate(char *file) {
	FILE *fp = NULL;
	int wordcount = 0;
	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("�ļ�Ѱ��ʧ�ܣ�\n");
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
		printf("�ļ�Ѱ��ʧ�ܣ�\n");
		exit(-1);
	}
	char fileline;
	fileline = fgetc(fp);
	while (fileline != EOF) {
		if (fileline == '\n') {//���ֻ���ʱ��ͳ������
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
	printf("�������û����wc.exe-");
	intput = getchar();
	switch (intput)
	{
	case 'c':
		printf("�������ļ�����");
		scanf("%s", &file);
		int charcount = 0;
		charcount = charcalculate(file);
		printf("�ļ��ַ���Ϊ��%d\n", charcount);
		break;
	case 'w':
		printf("�������ļ�����");
		scanf("%s", &file);
		int wordcount = 0;
		wordcount = wordcalculate(file);
		printf("�ļ�������Ϊ��%d\n", wordcount);
		break;
	case 'l':
		printf("�������ļ�����");
		scanf("%s", &file);
		int linecount = 0;
		linecount = linecalculate(file);
		printf("�ļ�����Ϊ��%d\n", linecount);
		break;
	default:
		printf("������������������룡");
	}
	getchar();
	return 0;
}