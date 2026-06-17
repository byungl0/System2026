#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // "a" (append) 모드로 열어 파일이 없으면 생성, 있으면 내용을 유지함
        FILE *f = fopen(argv[1], "a");
        if (f) fclose(f); // 열린 파일 닫기
    }
    return 0;
}