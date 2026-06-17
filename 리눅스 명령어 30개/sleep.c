#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // Sleep 함수는 밀리초 단위이므로 초 단위 인자에 1000을 곱합
        Sleep(atoi(argv[1]) * 1000); 
    }
    return 0;
}