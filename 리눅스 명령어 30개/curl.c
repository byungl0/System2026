#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char cmd[256];
        // 최근 윈도우 10/11에는 curl이 내장되어 있어 시스템 명령으로 호출 가능
        sprintf(cmd, "curl %s", argv[1]);
        system(cmd);
    }
    return 0;
}