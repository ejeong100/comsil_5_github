#include "Str.h"
#include <iostream>
#include <string.h>
using namespace std;

Str::Str(int leng){
        len = leng;
        str = new char[leng];
}

Str::Str(const char *neyong) //str에 문자열을 저장한뒤 len을 (문자열 + 1)의 크기로 초기화하는 방법
{
        str = new char[strlen(neyong)+1]; //초기화할 내용에 대한 동적할당
        strcpy(str, neyong); //neyong을문자열 길이 만큼  str으로 복사
        len = strlen(neyong); //neyong의 길이 측정
}

Str::~Str()
{
        delete(str); //동적 메모리할당 취소/ len을 0으로 초기화
}

char* Str::contents()
{
        return str; //주어진 문자열을 가리키는 포인터 리턴
}

int Str::length()
{
        return len; //주어진 문자열의 길이 리턴
}

int Str::compare(class Str& a)
{
        return strcmp(str, a.contents()); //str과 a.contents()를strcmp를 통해 비교하여 리턴
}

int Str::compare(const char* a)
{
        return strcmp(str, a); //str과 a를 strcmp를 통해 비교하여 리턴
}

//연산자의 다중정의 이용
void Str::operator=(class Str& a) //str 대입시 str타입을 매개변수로 이용하여 저장
{
        if (len < a.length())
        {
                delete []str;  //원래 입력받은 str의 동적할당 취소
                str = new char[a.length() + 1]; //str에 새롭게 동적할당
        }
        strcpy(str, a.contents()); //a.contents()를 str으로 복사
        len = a.length(); //len을 새롭게 정의
}

void Str::operator=(const char *a) //문자열을 대입시 문자열을 매개변수로 이용하여 저장
{
        if (len < strlen(a))
        {
                delete []str; //원래 입력받은 str의  동적할당 취소
                str = new char[strlen(a) + 1]; //str에 새롭게 동적할당
        }
        strcpy(str, a); //a를 str으로 복사
        len = strlen(a); //a의 길이를 len으로 정의
}       

