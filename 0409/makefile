# 1. 변수(매크로) 설정
CC = gcc
CFLAGS = -Wall -O2
TARGET = test.out
OBJS = main.o A.o B.o

# 2. 최종 실행 파일 생성 규칙
# TARGET을 만들기 위해 OBJS가 필요함
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 3. 각각의 .c 파일을 .o(오브젝트) 파일로 컴파일하는 규칙
# $<는 첫 번째 의존성 파일(.c)을, $@는 타겟 파일(.o)을 의미함
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 4. 빌드된 파일들을 삭제하는 정리 규칙
clean:
	rm -f $(OBJS) $(TARGET)
