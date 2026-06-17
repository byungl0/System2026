#include <stdio.h>
#include <windows.h>

int main() {
    // GetTickCount: 시스템 부팅 후 경과된 시간을 밀리초(ms) 단위로 반환
    DWORD ticks = GetTickCount(); 
    // 시간, 분, 초 단위로 변환 계산
    int s = (ticks / 1000) % 60, m = (ticks / 60000) % 60, h = (ticks / 3600000);
    printf("Uptime: %d hours, %d minutes, %d seconds\n", h, m, s);
    return 0;
}