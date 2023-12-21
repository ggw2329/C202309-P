#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MONTH 1
#define WEEK 7
#define DAY 1


int Trade;
int AssetValue;
char CoinType[MONTH][10];//종류입력
char CoinBuySell[MONTH][10];//long,short입력
int Coinvalue[MONTH];//구매량 입력
double StartPrice[MONTH];//시작가 입력
double EndPrice[MONTH];//종료가 입력
int Magnification[MONTH];//배율 입력

void CoinProfit(double* value1,double* value2,int i,int*Mag) {
	double profit;
	if (*value1 <= *value2) {
		profit = *Mag * ((1-(double)value1[i-1] / (double)value2[i-1])*100);
		printf("%d번째 거래의 수익률은 %.2lf%c입니다.", i, profit,'%');
	}
	else if (*value1 > *value2) {
		profit = *Mag * (((double)value1[i-1] / (double)value2[i-1]-1) * 100);
		printf("%d번째 거래의 수익률은 %c %.2lf%c입니다.", i,'-', profit,'%');
	}
}

void CoinTypeCount(char*CoinType){
	int a = 0;
	int b = 0;
	int c = 0;
	for (int i=0; i < MONTH; i++) {
		if (CoinType[i] == "BTC") {
			a+=1;
		}
		else if (CoinType[i] == "ETH") {
			b+=1;
		}
		else if (CoinType[i] == "XRP") {
			c+=1;
		}
	}printf("BTC:%d번 거래, ETH:%d번 거래, XRP:%d번 거래", a, b, c);
}

void WinRate(double*SP,double*EP){
	int a=0;
	for (int i = 0; i < MONTH; i++) {
		if (SP[i] < EP[i]) {
			a++;
		}
	}
	printf("고객님의 거래 승률은 %d%c입니다", a / MONTH * 100, '%');
}
//void RecentPnl
//void TotalPnl


int main() {



	printf("계좌의 초기금액을 입력하세요(KRW).\n");
	scanf_s("%d", &AssetValue);

	printf("Position정보를 입력 받습니다.\n");

	for (int i = 0; i < MONTH; i++) {

		printf("종료된 %d번째 거래의 정보를 입력하시오.(coin종류(BTC,ETH,XRP),long/short,구매량(KRW))\n", i + 1);
		scanf_s("%s %s %d", CoinType[i], (int)sizeof(CoinType),CoinBuySell[i],(int)sizeof(CoinBuySell),&Coinvalue[i]);
		printf("종료된 %d번째 거래의 정보를 입력하시오.(시작가,종료가,배율)\n", i + 1);
		scanf_s("%lf %lf %d",&StartPrice[i],&EndPrice[i],&Magnification[i]);
	}
	
	int choice;
	printf("\n1.해당 거래의 수익률");
	printf("\n2.coin종류당 거래횟수");
	printf("\n3.내 거래 성공률");
	printf("\n4.당일 pnl보기");
	printf("\n5.total pnl 보기\n");
	printf("0.프로그램 종료\n");


	for (int i = 0; i < 100; i++) {
		printf("\n이용할 옵션을 선택하세요.(0~5)");
		scanf_s("%d", &choice);
		printf("%d번째 옵션을 선택하셨습니다.\n", choice);
		if (choice == 1) {
			int i;
			printf("몇 번째 거래의 수익률을 볼건지 입력하시오.\n");
			scanf_s("%d", &i);
			CoinProfit(StartPrice, EndPrice, i,Magnification);
		}
		else if (choice == 2) {
			printf("coin종류당 거래횟수는 다음과 같습니다.\n");
			CoinTypeCount(*CoinType);
		}
		else if (choice == 3) {
			WinRate(StartPrice, EndPrice);
		}
		else if (choice == 4) {
			//int i;
			//printf("당일 몇번의 거래를 했는지 입력하시오.\n");
			//scanf_s("%d",&i);
			//printf("당일 pnl은 %.1lf입니다.\n",RecentPnl());
		}
		else if (choice == 5) {
			//int i;
			//printf("총 pnl은 %.1lf입니다.\n",TotalPnl());
		}
		else if (choice == 0) {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else {
			printf("숫자를 잘못 입력하셨습니다(0~5).\n");
		}
	}
	return 0;
}