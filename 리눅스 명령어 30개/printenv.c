#include <stdio.h>

// environ: 운영체제의 모든 환경변수를 담고 있는 전역 포인터 배열
extern char **environ; 

int main() {
    // 배열의 끝(NULL)을 만날 때까지 모든 환경변수를 출력
    for (int i = 0; environ[i] != NULL; i++) printf("%s\n", environ[i]);
    return 0;
}