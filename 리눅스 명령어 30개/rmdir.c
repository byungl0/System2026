#include <direct.h>

int main(int argc, char *argv[]) {
    // 인자가 전달되었다면 _rmdir 함수로 빈 디렉토리 삭제
    if (argc > 1) _rmdir(argv[1]);
    return 0;
}