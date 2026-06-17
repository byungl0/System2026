#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r"); // "r" (읽기) 모드로 파일 열기
        int c;
        if (f) { 
            // 파일의 끝(EOF)에 도달할 때까지 한 글자씩 읽어서 화면에 출력
            while ((c = fgetc(f)) != EOF) putchar(c); 
            fclose(f); 
        }
    }
    return 0;
}