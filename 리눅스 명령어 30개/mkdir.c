#include <direct.h>

int main(int argc, char *argv[]) {
    // 인자가 전달되었다면 _mkdir 함수로 디렉토리 생성
    if (argc > 1) _mkdir(argv[1]);
    return 0;
}