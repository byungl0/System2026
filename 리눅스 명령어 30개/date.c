#include <stdio.h>
#include <time.h> // 시간 관련 헤더

int main() {
    time_t t = time(NULL); // 현재 시간의 타임스탬프 획득
    // ctime: 타임스탬프를 사람이 읽기 쉬운 문자열 형태로 변환하여 출력
    printf("%s", ctime(&t)); 
    return 0;
}