#include <stdio.h>

int main(int argc, char *argv[]) {
    // argv[1]부터 마지막 인자까지 공백을 두고 출력
    for (int i = 1; i < argc; i++) printf("%s ", argv[i]);
    printf("\n"); // 마지막에 줄바꿈
    return 0;
}