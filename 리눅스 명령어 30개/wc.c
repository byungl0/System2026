#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        int c, nl = 0, nw = 0, nc = 0, inw = 0; // 줄, 단어, 글자, 단어 내부여부 플래그
        if (f) {
            while ((c = fgetc(f)) != EOF) {
                nc++; // 글자 수 증가
                if (c == '\n') nl++; // 줄바꿈 문자면 줄 수 증가
                // 공백, 줄바꿈, 탭이면 단어 내부 플래그 해제
                if (c == ' ' || c == '\n' || c == '\t') inw = 0; 
                else if (!inw) { inw = 1; nw++; } // 새 단어 진입 시 단어 수 증가
            }
            printf("%d %d %d %s\n", nl, nw, nc, argv[1]); 
            fclose(f);
        }
    }
    return 0;
}