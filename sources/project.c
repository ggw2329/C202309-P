#include <stdio.h>
#define MONTH 30
#define WEEK 7
#define DAY 1


int Trade;
int AssetValue;
char CoinType[MONTH][10];//종류입력
char CoinBuySell[MONTH][10];//long,short입력
int Coinvalue[MONTH][10];//구매량 입력
double StartPrice[MONTH][10];//시작가 입력
double EndPrice[MONTH][10];//종료가 입력
int Magnification[MONTH][10];//배율 입력

//void CoinProfit(int* CoinPrice) {}

int main() {

	printf("계좌의 초기금액을 입력하세요(KRW).\n");
	scanf_s("%d", &AssetValue);

	printf("Position정보를 입력 받습니다.\n");

	for (int i = 0; i < MONTH; i++) {

		printf("종료된 %d번째 거래의 정보를 입력하시오.(coin종류(ENG),long/short,구매량(KRW))\n", i + 1);
		scanf_s("%s %s %d", CoinType[i], (int)sizeof(CoinType),CoinBuySell[i],(int)sizeof(CoinBuySell),Coinvalue[i]);
		getchar();
		printf("종료된 %d번째 거래의 정보를 입력하시오.(시작가,종료가,배율)\n", i + 1);
		scanf_s("%lf %lf %d",StartPrice[i],EndPrice[i],Magnification[i]);
	}
	
	int choice;
	printf("1.해당 거래의 수익률");
	printf("2.coin종류당 비율");
	printf("3.내 거래 성공률");
	printf("4.당일 pnl보기");
	printf("5.total pnl 보기");
	sancf_s("%d", &choice);

	if (choice == 1) {
		printf("해당 거래의 수익률은 %lf%입니다.\n",);
	}
	else if (choice == 2) {
		printf("거래시 coin비율은 ");
	}
	else if (choice == 3) {
		printf("");
	}
	
	
	printf("몇번째 거래의 수익률을 볼건지 입력하세요.\n");
	scanf_s("%d",&Trade);

	//printf("%d번째 거래의 수익률은 %lf %입니다.\n",Trade,);

	//CoinProfit(CoinPrice);
	return 0;
}