#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 함수들 헤더파일로 변경
int AssetValue;

struct TradeInfo {
	int Coinvalue;//구매량
	int Magnification;//거래당시 배율
	double StartPrice;//시작가
	double EndPrice;//종료가
	char* CoinType;//coin종류
	char* CoinBuySell;//long,short입력
};

void initializeTradeInfo(struct TradeInfo* trade) {
	printf("거래시 coin종류를 입력하세요(BTC,ETH,XRP(앞 대문자만 입력)): ");
	char temp[100];
	scanf_s("%s", temp, (int)sizeof(temp));
	trade->CoinType = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(trade->CoinType, strlen(temp) + 1, temp);

	printf("거래시 Long/Short정보를 입력하세요(앞 대문자만 입력): ");
	scanf_s("%s", temp, (int)sizeof(temp));
	trade->CoinBuySell = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(trade->CoinBuySell, strlen(temp) + 1, temp);

	printf("거래시 구매량(KRW)을 입력하세요: ");
	scanf_s("%d", &trade->Coinvalue);

	printf("해당거래에 사용한 배율을 입력하세요: ");
	scanf_s("%d", &trade->Magnification);

	printf("해당거래의 시작가와 종료가를 입력하세요: ");
	scanf_s("%lf %lf", &trade->StartPrice, &trade->EndPrice);
}

//롱숏 조건 추가
void CoinProfit(struct TradeInfo* trade) {
	double profit;
	if (trade->StartPrice <= trade->EndPrice) {
		profit = trade->Magnification * ((1-(double)trade->StartPrice / (double)trade->EndPrice)*100);
		printf("해당 거래의 수익률은 %.2lf%c입니다.", profit,'%');
	}
	else if (trade->StartPrice > trade->EndPrice) {
		profit = trade->Magnification * (((double)trade->StartPrice / (double)trade->EndPrice -1) * 100);
		printf("해당 거래의 수익률은 %c %.2lf%c입니다.",'-', profit,'%');
	}
}

void CoinTypeCount(struct TradeInfo* trade, int numTrades){
	int a = 0;
	int b = 0;
	int c = 0;
	for (int i=0; i < numTrades; i++) {
		if (trade->CoinType == 'B') {
			a+=1;
		}
		else if (trade->CoinType == 'E') {
			b+=1;
		}
		else if (trade->CoinType == 'X') {
			c+=1;
		}
	}printf("BTC:%d번 거래, ETH:%d번 거래, XRP:%d번 거래", a, b, c);
}

//롱숏 조건 추가
void WinRate(struct TradeInfo* trade, int numTrades){
	int a=0;
	for (int i = 0; i < numTrades; i++) {
		if (trade->StartPrice < trade->EndPrice) {
			a++;
		}
	}
	printf("고객님의 총거래 승률은 %d%c입니다", a / numTrades * 100, '%');
}
//void RecentPnl
//void TotalPnl
//void NowAssetValue


int main() {

	printf("계좌의 초기금액을 입력하세요(KRW).\n");
	scanf_s("%d", &AssetValue);

	int numTrades;
	printf("몇새의 정보를 입력하시겠습니까? \n");
	scanf_s("%d", &numTrades);

	struct TradeInfo* trades = (struct TradeInfo*)malloc(numTrades * sizeof(struct TradeInfo));

	if (trades == NULL) {
		return 1;
	}

	for (int i = 0; i < numTrades; i++) {
		printf("\n%d번째 거래의 정보를 입력하세요.\n", i + 1);
		initializeTradeInfo(&trades[i]);
	}

	for (int i = 0; i < numTrades; i++) {
		free(trades[i].CoinType);
		free(trades[i].CoinBuySell);
	}
	free(trades);

	
	int choice;
	printf("\n1.해당 거래의 수익률");
	printf("\n2.coin종류당 거래횟수");
	printf("\n3.내 거래 성공률");
	printf("\n4.당일 pnl보기");
	printf("\n5.total pnl 보기");
	printf("\n6.asset value 보기\n");
	printf("0.프로그램 종료\n");


	for (int i = 0; i < 100; i++) {
		printf("\n이용할 옵션을 선택하세요.(0~5)");
		scanf_s("%d", &choice);
		printf("%d번째 옵션을 선택하셨습니다.\n", choice);
		if (choice == 1) {
			int i;
			printf("몇 번째 거래의 수익률을 볼건지 입력하시오.\n");
			scanf_s("%d", &i);
			CoinProfit((&trades[i - 1]);
		}
		else if (choice == 2) {
			printf("coin종류당 거래횟수는 다음과 같습니다.\n");
			CoinTypeCount(&trades[i], numTrades);
		}
		else if (choice == 3) {
			WinRate(&trades[i], numTrades);
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
		else if (choice == 6) {
			//assetvalue= 초기value+Coinvalue*수익률
			//printf("현재 assetvalue는 %d입니다.\n",Assetvalue);
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