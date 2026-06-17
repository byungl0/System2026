#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char cmd[256];
        // 윈도우 시스템의 기본 ping 명령어를 문자열로 조합하여 실행
        sprintf(cmd, "ping %s", argv[1]);
        system(cmd);
    }
    return 0;
}