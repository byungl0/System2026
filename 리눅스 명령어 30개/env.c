#include <stdio.h>

extern char **environ;

int main() {
    // printenv와 동일하게 환경변수 배열 순회 및 출력
    for (int i = 0; environ[i] != NULL; i++) printf("%s\n", environ[i]);
    return 0;
}