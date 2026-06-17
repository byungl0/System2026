#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 3) {
        char cmd[256];
        // 리눅스의 '-c' 옵션은 윈도우 ping 명령어의 '-n' (전송 횟수)과 같음
        sprintf(cmd, "ping -n %s %s", argv[2], argv[3]); 
        system(cmd);
    }
    return 0;
}