#include <stdio.h>
#include <windows.h>

int main() {
    char buf[256];
    DWORD len = sizeof(buf);
    // GetComputerName: 윈도우 시스템의 컴퓨터 이름을 가져옴
    if (GetComputerName(buf, &len)) printf("%s\n", buf);
    return 0;
}