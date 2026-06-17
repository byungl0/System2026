#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        struct _stat s;
        if (_stat(argv[1], &s) == 0) {
            // st_mode 비트 연산으로 파일인지 디렉토리(_S_IFDIR)인지 판별
            if (s.st_mode & _S_IFDIR) printf("%s: directory\n", argv[1]);
            else printf("%s: regular file\n", argv[1]);
        }
    }
    return 0;
}