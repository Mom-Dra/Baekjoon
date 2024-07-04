#define _CRT_SECURE_NO_WARNINGS

#include "Solution.h"
#include <iostream>

#define LENGTH 100

class _7662 : public Solution
{
    void Solve() override
    {
        char sentence[LENGTH];
        char target[LENGTH];
        char change[LENGTH];

        printf("���ڸ� �Է��Ͻÿ�: ");
        gets_s(sentence, LENGTH);

        printf("ã�� �ܾ� : ");
        gets_s(target, LENGTH);

        printf("�ٲ� �ܾ�: ");
        gets_s(change, LENGTH);

        char buffer[LENGTH] = { NULL };
        ChangeStr(sentence, target, change, buffer);

        printf("%s", buffer);
    }

    void ChangeStr(char* str, char* subStr, char* replaceStr, char* resultBuffer)
    {
        char* indexPointer =  strstr(str, subStr);
        if (indexPointer == NULL)
        {
            printf("������ ���ڿ��� ã�� ���߽��ϴ�");
            return;
        }

        strncat(resultBuffer, str, indexPointer - str);
        strcat(resultBuffer, replaceStr);
        strcat(resultBuffer, indexPointer + strlen(subStr));
    }
};