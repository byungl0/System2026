#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // 경로에서 마지막 백슬래시(\)나 슬래시(/)의 위치를 찾음
        char *p = strrchr(argv[1], '\\');
        if (!p) p = strrchr(argv[1], '/');
        // 슬래시가 있으면 그 다음 글자부터 출력, 없으면 원본 그대로 출력
        printf("%s\n", p ? p + 1 : argv[1]);
    }
    return 0;
}