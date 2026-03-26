#include <stdio.h>

/* 파일 복사 프로그램 */
int main(int argc, char *argv[])
{
    int c; // fgetc는 EOF를 판별하기 위해 int 타입을 사용하는 것이 안전합니다.
    FILE *fp1, *fp2;

    // 인자 개수 확인 (실행파일명, 원본파일, 복사될파일)
    if (argc != 3) {
        fprintf(stderr, "사용법: %s 파일1 파일2\n", argv[0]);
        return 1;
    }

    // 원본 파일 읽기 모드("r")로 열기
    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
        return 2;
    }

    // 대상 파일 쓰기 모드("w")로 열기
    fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
        fprintf(stderr, "파일 %s 생성 오류\n", argv[2]);
        fclose(fp1);
        return 3;
    }

    // 한 글자씩 읽어서 복사
    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);
    
    return 0;
include <stdio.h>

int main(int argc, char *argv[])
{
    int c; 
    FILE *fp1, *fp2;
    if (argc != 3) {
            fprintf(stderr, "사용법: %s 파일1 파일2\n", argv[0]);
            return 1;
        }

    
    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
            fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
            return 2;
        }

    
    fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
            fprintf(stderr, "파일 %s 생성 오류\n", argv[2]);
            fclose(fp1);
            return 3;
        }

    
    while ((c = fgetc(fp1)) != EOF) {
            fputc(c, fp2);
        }

    fclose(fp1);
    fclose(fp2);
    
    return 0;
}}
