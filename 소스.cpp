#include <stdio.h>
#include <conio.h> // _getch()
#include <time.h> // time()

void stopwatch(int onOff);
void secToHHMMSS(int secs, char* s, size_t size);

char timerBuffer[8 + 1]; // 06:17:20 ���� ��� �ð� ���ڿ��� ����� ���� ����


int main(void) {

	stopwatch(1); // 1�� �μ��� ������ Ÿ�̸Ӱ� ����
	puts("Ÿ�̸� ON! �ƹ�Ű�� ������ ����");


	// ������ �ƹ� Ű�� ���� ������ ������ ���
	_getch(); // _getch() �� getch() �� ���� ��ȭ ����


	stopwatch(0); // 0�� ������ Ÿ�̸Ӱ� ������ �ð� ���ڿ��� ���ۿ� ����
	printf("Ÿ�̸� OFF! ��� �ð���: [%s]\n", timerBuffer);


	return 0;
}


void stopwatch(int onOff) {
	static int oldTime; // stopwatch �Լ��� ����Ǿ ���� ����ϴ� "���� ���� ����"

	if (onOff == 1) { // Ÿ�̸� �ѱ�
		oldTime = (int)time(NULL);
	}

	if (onOff == 0) { // Ÿ�̸� ����, �ú��ʸ� timerBuffer �� ����
		secToHHMMSS(
			(int)time(NULL) - oldTime,
			timerBuffer,
			sizeof(timerBuffer)
		);
	}

}


void secToHHMMSS(int secs, char* s, size_t size) { // ������ �� ��(sec)�� �Է� �޾�, "06:17:20" ���� ������ ���ڿ��� �ú��ʸ� �迭�� ����
	int hour, min, sec;

	sec = secs % 60;
	min = secs / 60 % 60;
	hour = secs / 3600;

	sprintf_s(s, size, "%02d:%02d:%02d", hour, min, sec);
}