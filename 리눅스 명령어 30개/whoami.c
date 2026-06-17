#include <stdio.h>
#include <windows.h> // 윈도우 API 헤더

int main() {
    char buf[256];
    DWORD len = sizeof(buf);
    // GetUserName: 윈도우 시스템에 로그인된 현재 사용자 이름을 가져옴
    if (GetUserName(buf, &len)) printf("%s\n", buf);
    return 0;
}