#include <stdio.h>
#include <sys/stat.h> // 파일 상태 정보 헤더

int main(int argc, char *argv[]) {
    if (argc > 1) {
        struct _stat s;
        // _stat 함수로 파일의 정보를 가져와 구조체에 저장
        if (_stat(argv[1], &s) == 0) printf("Size: %ld bytes\n", s.st_size);
    }
    return 0;
}