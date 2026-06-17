#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 2) {
        FILE *f = fopen(argv[2], "r");
        char line[1024];
        if (f) { 
            while (fgets(line, sizeof(line), f)) {
                // strstr: 읽어온 줄(line) 안에 검색어(argv[1])가 포함되어 있는지 확인
                if (strstr(line, argv[1])) printf("%s", line); 
            }
            fclose(f); 
        }
    }
    return 0;
}