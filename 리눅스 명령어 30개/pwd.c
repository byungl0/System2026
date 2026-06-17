#include <stdio.h>
#include <direct.h> // 윈도우 디렉토리 관련 헤더

int main() {
    char buf[1024];
    // _getcwd: 현재 작업 디렉토리의 절대 경로를 버퍼에 복사
    if (_getcwd(buf, sizeof(buf))) printf("%s\n", buf);
    return 0;
}