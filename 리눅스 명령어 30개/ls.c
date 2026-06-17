#include <stdio.h>
#include <io.h> // 윈도우 파일 탐색 관련 헤더

int main() {
    struct _finddata_t f; // 파일 정보를 저장할 구조체
    // 현재 디렉토리의 모든 파일("*.*")을 검색 시작
    intptr_t h = _findfirst("*.*", &f);
    if (h != -1L) {
        do { 
            // 리눅스 ls 기본 동작처럼 숨김 파일(.)로 시작하는 것은 제외하고 출력
            if (f.name[0] != '.') printf("%s\n", f.name); 
        } while (_findnext(h, &f) == 0); // 다음 파일 찾기
        _findclose(h); // 핸들 닫기
    }
    return 0;
}