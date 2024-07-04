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

        printf("문자를 입력하시오: ");
        gets_s(sentence, LENGTH);

        printf("찾을 단어 : ");
        gets_s(target, LENGTH);

        printf("바꿀 단어: ");
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
            printf("변경할 문자열을 찾지 못했습니다");
            return;
        }

        strncat(resultBuffer, str, indexPointer - str);
        strcat(resultBuffer, replaceStr);
        strcat(resultBuffer, indexPointer + strlen(subStr));
    }
};