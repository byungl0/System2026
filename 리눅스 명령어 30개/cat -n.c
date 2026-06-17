#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 2) {
        FILE *f = fopen(argv[2], "r");
        char line[1024]; 
        int n = 1; // 줄 번호 저장 변수
        if (f) { 
            // fgets로 한 줄씩 읽은 뒤, 줄 번호(%6d)와 함께 출력
            while (fgets(line, sizeof(line), f)) printf("%6d  %s", n++, line); 
            fclose(f); 
        }
    }
    return 0;
}