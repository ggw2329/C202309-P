#include <stdio.h>
#define MONTH 30

//void CoinProfit(int* CoinPrice) {}

int main() {
	char CoinPosition[MONTH][50] = {"coin����","long/short"};
	double CoinPrice[MONTH][50] = {0,0,0,0};
	double ch = -1;
	for (int i = 0; i < MONTH; i++) {

		printf("����� �������� ������ �Է��Ͻÿ�.(coin����,long/short)\n");
		scanf_s("%s", CoinPosition[i], (int)sizeof(CoinPosition));
		ch = getchar();
		printf("����� �������� ������ �Է��Ͻÿ�.(���ŷ�,���۰�,���ᰡ,����)(����� ����)\n");
		scanf_s("%lf %lf %lf", &CoinPrice[i]);

	}
	CoinProfit(CoinPrice);
}