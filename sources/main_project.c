#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 함수들 헤더파일로 변경
double AssetValue;

struct TradeInfo {
	int Coinvalue;//구매량
	int Magnification;//거래당시 배율
	double StartPrice;//시작가
	double EndPrice;//종료가
	char* CoinType;//coin종류
	char* CoinBuySell;//long,short입력
};

void initializeTradeInfo(struct TradeInfo* trade) {
	printf("거래시 coin종류를 입력하세요(BTC,ETH,XRP(대문자로 입력)): ");
	char temp[100];
	scanf_s("%s", temp, (int)sizeof(temp));
	trade->CoinType = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(trade->CoinType, strlen(temp) + 1, temp);

	printf("거래시 Long/Short정보를 입력하세요(대문자로 입력): ");
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
void CoinProfit(const struct TradeInfo* trade, int i) {
	double profit1,profit2;
	double a, b;
	int c;
	a = trade[i - 1].StartPrice;
	b = trade[i - 1].EndPrice;
	c = trade[i - 1].Magnification;
	if (a <= b) {
		profit1 =(double) c * (((b - a) / a) * 100);
		return profit1;
	}
	else if (a > b) {
		profit2 = (double)c * (((a - b) / a) * 100);
		return profit2;
	}
}

void CoinTypeRate(struct TradeInfo* trade, int numTrades){
	int a = 0;
	int b = 0;
	int c = 0;
	double d, e, f;
	for (int i=0; i < numTrades; i++) {
		if (*trade[i].CoinType == 'B') {
			a+=1;
		}
		else if (*trade[i].CoinType == 'E') {
			b+=1;
		}
		else if (*trade[i].CoinType == 'X') {
			c+=1;
		}
	}
	d = (double)a / (a + b + c) * 100;
	e = (double)b / (a + b + c) * 100;
	f = (double)100 - (d + e);
	printf("BTC:%.1lf%c, ETH:%.1lf%c, XRP:%.1lf%c\n", d, '%', e, '%', f, '%');
}


void WinRate(struct TradeInfo* trade, int numTrades){
	int a=0;
	for (int i = 0; i < num; i++) {
		if (trade[i].StartPrice < trade[i].EndPrice) {
			if (*trade[i].CoinBuySell == 'L') {
				a++;
			}
		}
		else if (trade[i].StartPrice >= trade[i].EndPrice) {
			if (*trade[i].CoinBuySell == 'S') {
				a++;
			}
		}
	}
	double b = (double)a / num * 100;
	printf("고객님의 총거래 승률은 %.1lf%c입니다", b, '%');
}

void RecentPnl(struct TradeInfo* trade, int num, double AV) {
	double a = 0;//수익금
	double b;//수익률
	for (int i = 0; i < num; i++) {
		if (trade[i].StartPrice < trade[i].EndPrice) {
			if (*trade[i].CoinBuySell == 'L') {
				a += (double)trade[i].Coinvalue * (((CoinProfit(trade, i + 1)) / 100));
			}
			else if (*trade[i].CoinBuySell == 'S') {
				a -= (double)trade[i].Coinvalue * (((CoinProfit(trade, i + 1)) / 100));
			}
		}
		else if (trade[i].StartPrice >= trade[i].EndPrice) {
			if (*trade[i].CoinBuySell == 'S') {
				a += (double)trade[i].Coinvalue * (((CoinProfit(trade, i + 1)) / 100));
			}
			else if (*trade[i].CoinBuySell == 'L') {
				a -= (double)trade[i].Coinvalue * (((CoinProfit(trade, i + 1)) / 100));
			}
		}
	}
	b = (double)a / AV * 100;
	printf("고객님의 금일Pnl:%.1lfKRW(%.1lf%c)", a + AV, b, '%');
}

void TotalPnl(struct TradeInfo* trade, int num, double AV) {
	double a = 0;//수익금
	double b;//수익률
	for (int i = 0; i < num; i++) {
		if (trade[i].StartPrice < trade[i].EndPrice) {
			if (*trade[i].CoinBuySell == 'L') {
				a += (double)trade[i].Coinvalue * (((CoinProfit(trade, i + 1)) / 100));
			}
			else if (*trade[i].CoinBuySell == 'S') {
				a -= (double)trade[i].Coinvalue * (((CoinProfit(trade, i + 1)) / 100));
			}
		}
		else if (trade[i].StartPrice >= trade[i].EndPrice) {
			if (*trade[i].CoinBuySell == 'S') {
				a += (double)trade[i].Coinvalue * (((CoinProfit(trade, i + 1)) / 100));
			}
			else if (*trade[i].CoinBuySell == 'L') {
				a -= (double)trade[i].Coinvalue * (((CoinProfit(trade, i + 1)) / 100));
			}
		}
	}
	b = (double)a / AV * 100;
	printf("고객님의 총Pnl:%.1lfKRW(%.1lf%c)", a + AV, b, '%');
}

int main() {

	printf("계좌의 초기금액을 입력하세요(KRW).\n");
	scanf_s("%lf", &AssetValue);

	int numTrades;
	printf("몇 번의 거래를 입력하시겠습니까? \n");
	scanf_s("%d", &numTrades);

	struct TradeInfo* trades = (struct TradeInfo*)malloc(numTrades * sizeof(struct TradeInfo));

	if (trades == NULL) {
		return 1;
	}

	for (int i = 0; i < numTrades; i++) {
		printf("\n%d번째 거래의 정보를 입력하세요.\n", i + 1);
		initializeTradeInfo(&trades[i]);
	}

	
	int choice;
	printf("\n1.해당 거래의 수익률");
	printf("\n2.coin종류당 거래횟수");
	printf("\n3.내 거래 성공률");
	printf("\n4.당일 pnl보기");
	printf("\n5.total pnl 보기");
	printf("0.프로그램 종료\n");


	for (int i = 0; i < 100; i++) {
		printf("\n\n이용할 옵션을 선택하세요.(0~5): ");
		scanf_s("%d", &choice);
		printf("%d번째 옵션을 선택하셨습니다.\n", choice);
		if (choice == 1) {
			int i;
			printf("몇 번째 거래의 수익률을 볼건지 입력하시오: ");
			scanf_s("%d", &i);
			CoinProfit(trades, i);
			if (trades[i - 1].StartPrice < trades[i - 1].EndPrice) {
				if (*trades[i - 1].CoinBuySell == 'L') {
					printf("해당 거래의 수익률은 %c%.1lf%c입니다.\n", '+', CoinProfit(trades, i), '%');
				}
				else if (*trades[i - 1].CoinBuySell == 'S') {
					printf("해당 거래의 수익률은 %c%.1lf%c입니다.\n", '-', CoinProfit(trades, i), '%');
				}
			}
			else if (trades[i - 1].StartPrice >= trades[i - 1].EndPrice) {
				if (*trades[i - 1].CoinBuySell == 'S') {
					printf("해당 거래의 수익률은 %c%.1lf%c입니다.\n", '+', CoinProfit(trades, i), '%');
				}
				else if (*trades[i - 1].CoinBuySell == 'L') {
					printf("해당 거래의 수익률은 %c%.1lf%c입니다.\n", '-', CoinProfit(trades, i), '%');
				}
			}
		}
		else if (choice == 2) {
			printf("\ncoin종류당 거래횟수는 다음과 같습니다.\n");
			CoinTypeRate(trades, numTrades);
		}
		else if (choice == 3) {
			WinRate(trades, numTrades);
		}
		else if (choice == 4) {
			int i;
			printf("당일 몇번의 거래를 했는지 입력하시오: ");
			scanf_s("%d", &i);
			RecentPnl(trades, i, AssetValue);
		}
		else if (choice == 5) {
			TotalPnl(trades, numTrades, AssetValue);
		}
		else if (choice == 0) {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else {
			printf("숫자를 잘못 입력하셨습니다(0~5).\n");
		}
	}
	for (int i = 0; i < numTrades; i++) {
		free(trades[i].CoinType);
		free(trades[i].CoinBuySell);
	}
	free(trades);
	return 0;
}