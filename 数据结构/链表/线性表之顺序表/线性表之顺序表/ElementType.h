#pragma once
/*
* Ϊ�˱���ͬһ��ͷ�ļ���������include����ε��±�����
* C/C++�������ֺ�ʵ�ַ�ʽ��һ����#ifndef��ʽ����һ����#pragma once��ʽ��
* ������֤����Ȼͬһͷ�ļ���������Σ����ǽ������һ��
*/
#define MAX_SIZE 255

//��������Ԫ��
typedef struct {
	int id;
	char *name;
}ElementType;

//����˳���ṹ
typedef struct {
	ElementType data[MAX_SIZE];
	int length;
}SequenceList;