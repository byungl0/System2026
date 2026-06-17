# 시스템 프로그래밍
## 리눅스 명령어 C언어 구현 30선
* **GitHub:** [본인의 깃허브 주소 입력]
* **학번 / 이름:** [학번 입력] [이름 입력]

---

## I. 파일 및 디렉토리 관리 명령어
이 명령어들은 파일 시스템을 조작하고 관리하는 데 기본적으로 사용됩니다.

### 1. pwd
* **기능:** 현재 작업 디렉토리의 전체 경로를 출력합니다.
```c
#include <stdio.h>
#include <direct.h> // 윈도우 디렉토리 관련 헤더

int main() {
    char buf[1024];
    // _getcwd: 현재 작업 디렉토리의 절대 경로를 버퍼에 복사
    if (_getcwd(buf, sizeof(buf))) printf("%s\n", buf);
    return 0;
}
```

### 2. ls
* **기능:** 디렉토리의 내용(파일 및 하위 디렉토리)을 나열합니다.
```c
#include <stdio.h>
#include <io.h> // 윈도우 파일 탐색 관련 헤더

int main() {
    struct _finddata_t f; // 파일 정보를 저장할 구조체
    // 현재 디렉토리의 모든 파일("*.*")을 검색 시작
    intptr_t h = _findfirst("*.*", &f);
    if (h != -1L) {
        do { 
            // 숨김 파일(.)로 시작하는 것은 제외하고 출력
            if (f.name[0] != '.') printf("%s\n", f.name); 
        } while (_findnext(h, &f) == 0); // 다음 파일 찾기
        _findclose(h); // 핸들 닫기
    }
    return 0;
}
```

### 3. mkdir
* **기능:** 새로운 디렉토리를 생성합니다.
```c
#include <direct.h>

int main(int argc, char *argv[]) {
    // 인자가 전달되었다면 _mkdir 함수로 디렉토리 생성
    if (argc > 1) _mkdir(argv[1]);
    return 0;
}
```

### 4. rmdir
* **기능:** 비어 있는 디렉토리를 삭제합니다.
```c
#include <direct.h>

int main(int argc, char *argv[]) {
    // 인자가 전달되었다면 _rmdir 함수로 빈 디렉토리 삭제
    if (argc > 1) _rmdir(argv[1]);
    return 0;
}
```

### 5. touch
* **기능:** 빈 파일을 생성하거나 파일의 수정 시간을 갱신합니다.
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // "a" (append) 모드로 열어 파일이 없으면 생성, 있으면 내용을 유지함
        FILE *f = fopen(argv[1], "a");
        if (f) fclose(f); // 열린 파일 닫기
    }
    return 0;
}
```

### 6. rm
* **기능:** 파일이나 디렉토리를 삭제합니다.
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    // remove: 표준 C 라이브러리의 파일 삭제 함수
    if (argc > 1) remove(argv[1]);
    return 0;
}
```

### 7. rm -f
* **기능:** 강제로 파일을 삭제합니다. (에러 무시)
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    // 인자가 3개(ex: rm.exe -f test.txt)일 때 3번째 인자(파일)를 삭제
    if (argc > 2) remove(argv[2]); 
    return 0;
}
```

### 8. basename
* **기능:** 경로에서 디렉토리를 제외한 파일명만 추출합니다.
```c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // 경로에서 마지막 백슬래시(\)나 슬래시(/)의 위치를 찾음
        char *p = strrchr(argv[1], '\\');
        if (!p) p = strrchr(argv[1], '/');
        // 슬래시가 있으면 그 다음 글자부터 출력, 없으면 원본 그대로 출력
        printf("%s\n", p ? p + 1 : argv[1]);
    }
    return 0;
}
```

### 9. dirname
* **기능:** 파일 경로에서 디렉토리 경로만 추출합니다.
```c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // 마지막 구분자(\ 또는 /)를 찾음
        char *p = strrchr(argv[1], '\\');
        if (!p) p = strrchr(argv[1], '/');
        if (p) { 
            *p = '\0'; // 마지막 구분자를 널 문자(\0)로 바꿔 문자열을 자름
            printf("%s\n", argv[1]); 
        }
        else printf(".\n"); // 경로 구분자가 없으면 현재 경로(.) 출력
    }
    return 0;
}
```

### 10. file
* **기능:** 파일 또는 디렉토리 형식을 판별합니다.
```c
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
```

---

## II. 텍스트 및 파일 출력 명령어
파일 내용을 터미널에 출력하거나 텍스트를 처리하는 데 사용됩니다.

### 11. echo
* **기능:** 입력받은 문자열을 터미널에 그대로 출력합니다.
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    // argv[1]부터 마지막 인자까지 공백을 두고 출력
    for (int i = 1; i < argc; i++) printf("%s ", argv[i]);
    printf("\n"); // 마지막에 줄바꿈
    return 0;
}
```

### 12. cat
* **기능:** 파일의 내용을 터미널에 출력합니다.
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r"); // "r" (읽기) 모드로 파일 열기
        int c;
        if (f) { 
            // 파일의 끝(EOF)에 도달할 때까지 한 글자씩 읽어서 화면에 출력
            while ((c = fgetc(f)) != EOF) putchar(c); 
            fclose(f); 
        }
    }
    return 0;
}
```

### 13. cat -n
* **기능:** 파일의 내용을 줄 번호와 함께 출력합니다.
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 2) {
        FILE *f = fopen(argv[2], "r");
        char line[1024]; 
        int n = 1; // 줄 번호 저장 변수
        if (f) { 
            // fgets로 한 줄씩 읽은 뒤, 줄 번호(%6d)와 함께 출력
            while (fgets(line, sizeof(line), f)) printf("%6d  %s", n++, line); 
            fclose(f); 
        }
    }
    return 0;
}
```

### 14. head
* **기능:** 파일의 시작 부분(기본 10줄)을 출력합니다.
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        char line[1024]; 
        int count = 0; // 출력된 줄 수 추적
        if (f) { 
            // 읽은 줄이 10줄 미만일 때까지만 루프 실행
            while (count < 10 && fgets(line, sizeof(line), f)) { 
                printf("%s", line); 
                count++; 
            } 
            fclose(f); 
        }
    }
    return 0;
}
```

### 15. grep
* **기능:** 파일 내용에서 특정 패턴(문자열)을 검색합니다.
```c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 2) {
        FILE *f = fopen(argv[2], "r");
        char line[1024];
        if (f) { 
            while (fgets(line, sizeof(line), f)) {
                // strstr: 읽어온 줄(line) 안에 검색어(argv[1])가 포함되어 있는지 확인
                if (strstr(line, argv[1])) printf("%s", line); 
            }
            fclose(f); 
        }
    }
    return 0;
}
```

### 16. wc
* **기능:** 파일의 줄 수, 단어 수, 문자 수를 계산하여 출력합니다.
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        int c, nl = 0, nw = 0, nc = 0, inw = 0; // 줄, 단어, 글자, 단어 내부여부 플래그
        if (f) {
            while ((c = fgetc(f)) != EOF) {
                nc++; // 글자 수 증가
                if (c == '\n') nl++; // 줄바꿈 문자면 줄 수 증가
                // 공백, 줄바꿈, 탭이면 단어 내부 플래그 해제
                if (c == ' ' || c == '\n' || c == '\t') inw = 0; 
                else if (!inw) { inw = 1; nw++; } // 새 단어 진입 시 단어 수 증가
            }
            printf("%d %d %d %s\n", nl, nw, nc, argv[1]); 
            fclose(f);
        }
    }
    return 0;
}
```

---

## III. 시스템 정보 및 네트워크 명령어
시스템의 상태를 확인하고 네트워크 연결을 테스트하는 데 사용됩니다.

### 17. whoami
* **기능:** 현재 로그인한 사용자의 이름을 출력합니다.
```c
#include <stdio.h>
#include <windows.h> // 윈도우 API 헤더

int main() {
    char buf[256];
    DWORD len = sizeof(buf);
    // GetUserName: 윈도우 시스템에 로그인된 현재 사용자 이름을 가져옴
    if (GetUserName(buf, &len)) printf("%s\n", buf);
    return 0;
}
```

### 18. hostname
* **기능:** 시스템의 호스트(컴퓨터) 이름을 표시합니다.
```c
#include <stdio.h>
#include <windows.h>

int main() {
    char buf[256];
    DWORD len = sizeof(buf);
    // GetComputerName: 윈도우 시스템의 컴퓨터 이름을 가져옴
    if (GetComputerName(buf, &len)) printf("%s\n", buf);
    return 0;
}
```

### 19. uname
* **기능:** 시스템 운영체제 정보를 출력합니다.
```c
#include <stdio.h>

int main() {
    // 윈도우 환경에서 빌드 및 실행되므로 정적으로 출력
    printf("Windows\n");
    return 0;
}
```

### 20. date
* **기능:** 현재 날짜와 시간 정보를 출력합니다.
```c
#include <stdio.h>
#include <time.h> // 시간 관련 헤더

int main() {
    time_t t = time(NULL); // 현재 시간의 타임스탬프 획득
    // ctime: 타임스탬프를 사람이 읽기 쉬운 문자열 형태로 변환하여 출력
    printf("%s", ctime(&t)); 
    return 0;
}
```

### 21. uptime
* **기능:** 시스템 부팅 후 경과된 시간을 보여줍니다.
```c
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
```

### 22. stat
* **기능:** 파일의 상세 상태 정보(크기 등)를 출력합니다.
```c
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
```

### 23. printenv
* **기능:** 시스템의 모든 환경 변수를 출력합니다.
```c
#include <stdio.h>

// environ: 운영체제의 모든 환경변수를 담고 있는 전역 포인터 배열
extern char **environ; 

int main() {
    // 배열의 끝(NULL)을 만날 때까지 모든 환경변수를 출력
    for (int i = 0; environ[i] != NULL; i++) printf("%s\n", environ[i]);
    return 0;
}
```

### 24. env
* **기능:** 환경 변수를 출력합니다. (`printenv`와 동일하게 구현)
```c
#include <stdio.h>

extern char **environ;

int main() {
    for (int i = 0; environ[i] != NULL; i++) printf("%s\n", environ[i]);
    return 0;
}
```

### 25. ping
* **기능:** 네트워크 호스트와의 연결성을 테스트합니다.
```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char cmd[256];
        // 윈도우 시스템의 기본 ping 명령어를 문자열로 조합하여 실행
        sprintf(cmd, "ping %s", argv[1]);
        system(cmd);
    }
    return 0;
}
```

### 26. ping -c
* **기능:** 지정된 횟수만큼 패킷을 보내 연결성을 테스트합니다.
```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 3) {
        char cmd[256];
        // 리눅스의 '-c' 옵션은 윈도우 ping 명령어의 '-n' (전송 횟수)과 같음
        sprintf(cmd, "ping -n %s %s", argv[2], argv[3]); 
        system(cmd);
    }
    return 0;
}
```

### 27. curl
* **기능:** URL을 통해 웹 데이터를 다운로드하거나 요청합니다.
```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char cmd[256];
        // 최근 윈도우 10/11에는 curl이 내장되어 있어 시스템 명령으로 호출 가능
        sprintf(cmd, "curl %s", argv[1]);
        system(cmd);
    }
    return 0;
}
```

---

## IV. 프로세스 및 시스템 제어 명령어
터미널을 제어하거나 프로세스의 실행 흐름을 관리합니다.

### 28. clear
* **기능:** 터미널 화면을 깨끗하게 지웁니다.
```c
#include <stdlib.h>

int main() {
    // 윈도우 cmd의 화면 지우기 명령어인 'cls'를 시스템 함수로 실행
    system("cls");
    return 0;
}
```

### 29. sleep
* **기능:** 프로세스를 지정된 시간 동안 일시 중단합니다.
```c
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // Sleep 함수는 밀리초 단위이므로 초 단위 인자에 1000을 곱함
        Sleep(atoi(argv[1]) * 1000); 
    }
    return 0;
}
```

### 30. exit
* **기능:** 프로그램을 정상적으로 종료합니다.
```c
#include <stdlib.h> // exit 함수가 포함된 헤더

int main() {
    // exit(0): 프로그램 정상 종료 (상태 코드 0 반환)
    exit(0);
    return 0;
}
```
