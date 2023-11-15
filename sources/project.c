#include <stdio.h>
#define MONTH 30

//void CoinProfit(int* CoinPrice) {}

int main() {
	char CoinPosition[MONTH][50] = {"coin종류","long/short"};
	double CoinPrice[MONTH][50] = {0,0,0,0};
	double ch = -1;
	for (int i = 0; i < MONTH; i++) {

		printf("종료된 포지션의 정보를 입력하시오.(coin종류,long/short)\n");
		scanf_s("%s", CoinPosition[i], (int)sizeof(CoinPosition));
		ch = getchar();
		printf("종료된 포지션의 정보를 입력하시오.(구매량,시작가,종료가,배율)(띄어쓰기로 구분)\n");
		scanf_s("%lf %lf %lf", &CoinPrice[i]);

	}
	CoinProfit(CoinPrice);
}