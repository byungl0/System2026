#include <stdio.h>

int main(int argc, char *argv[]) {
    // remove: 표준 C 라이브러리의 파일 삭제 함수
    if (argc > 1) remove(argv[1]);
    return 0;
}