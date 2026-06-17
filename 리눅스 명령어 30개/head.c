#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        char line[1024]; 
        int count = 0; // 출력된 줄 수 추적
        if (f) { 
            // 읽은 줄이 10줄 미만일 때까지만 루프 실행
            while (count < 10 && fgets(line, sizeof(line), f)) { 
                printf("%s", line); 
                count++; 
            } 
            fclose(f); 
        }
    }
    return 0;
}