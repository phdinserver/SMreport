#include <stdio.h>
#include <conio.h> // _getch()
#include <time.h> // time()

void stopwatch(int onOff);
void secToHHMMSS(int secs, char* s, size_t size);

char timerBuffer[8 + 1]; // 06:17:20 등의 경과 시간 문자열이 저장될 버퍼 정의


int main(void) {

	stopwatch(1); // 1을 인수로 넣으면 타이머가 켜짐
	puts("타이머 ON! 아무키나 누르면 종료");


	// 유저가 아무 키나 누를 때까지 무한정 대기
	_getch(); // _getch() 는 getch() 의 보안 강화 버전


	stopwatch(0); // 0을 넣으면 타이머가 꺼지고 시간 문자열을 버퍼에 설정
	printf("타이머 OFF! 경과 시간은: [%s]\n", timerBuffer);


	return 0;
}


void stopwatch(int onOff) {
	static int oldTime; // stopwatch 함수가 종료되어도 값을 기억하는 "정적 지역 변수"

	if (onOff == 1) { // 타이머 켜기
		oldTime = (int)time(NULL);
	}

	if (onOff == 0) { // 타이머 끄고, 시분초를 timerBuffer 에 저장
		secToHHMMSS(
			(int)time(NULL) - oldTime,
			timerBuffer,
			sizeof(timerBuffer)
		);
	}

}


void secToHHMMSS(int secs, char* s, size_t size) { // 정수로 된 초(sec)를 입력 받아, "06:17:20" 등의 형식의 문자열로 시분초를 배열에 저장
	int hour, min, sec;

	sec = secs % 60;
	min = secs / 60 % 60;
	hour = secs / 3600;

	sprintf_s(s, size, "%02d:%02d:%02d", hour, min, sec);
}