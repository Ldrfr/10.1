#define _CRT_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
#include<locale.h>
#include<string.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    FILE* fp1 = fopen("text.txt", "r+");
    FILE* fp2 = fopen("output.txt", "w");
    if (fp1 == NULL) return 1;
    char *str = (char*)malloc(100 * sizeof(char));
    fgets(str, 100, fp1); //������ ���� � ������ ��� ������
    char* str1=strtok(str, " ");//��������� ������
    char* recording = (char*)malloc(100 * sizeof(char));//������� ������ ��� ������
    char str2[100];
    recording[0] = '\0';
    strcat(recording, str1);//��������� � 1 ������
    str1 = strtok(NULL, " "); //������ �� �������� ������
    while (str1 != NULL) {
        strcat(recording, " ");
        strcat(recording, str1); //���������
        str1 = strtok(NULL, " ");//������ ������� ����(�����) -> ������ 
    }

    /////////////////////////////////////////////////////////////////////////////////////// all works with dot in the end -> clear string


    fprintf(fp2, "%s\n", recording);
    //fprintf(fp2, "%s", last);
    fclose(fp1);
    fclose(fp2);
}