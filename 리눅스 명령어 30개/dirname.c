#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // 마지막 구분자(\ 또는 /)를 찾음
        char *p = strrchr(argv[1], '\\');
        if (!p) p = strrchr(argv[1], '/');
        if (p) { 
            *p = '\0'; // 마지막 구분자를 널 문자(\0)로 바꿔 문자열을 자름
            printf("%s\n", argv[1]); 
        }
        else printf(".\n"); // 경로 구분자가 없으면 현재 경로(.) 출력
    }
    return 0;
}