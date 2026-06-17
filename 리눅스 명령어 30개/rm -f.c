#include <stdio.h>

int main(int argc, char *argv[]) {
    // 인자가 3개(ex: rm.exe -f test.txt)일 때 3번째 인자(파일)를 삭제
    // 파일이 없거나 에러가 나도 조건문 없이 지나가므로 강제 삭제와 유사한 효과
    if (argc > 2) remove(argv[2]); 
    return 0;
}