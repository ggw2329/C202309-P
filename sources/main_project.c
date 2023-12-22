#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double AssetValue;

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
	printf("\n6.현재 asset value 보기\n");
	printf("0.프로그램 종료\n");


	for (int i = 0; i < 100; i++) {
		printf("\n\n이용할 옵션을 선택하세요.(0~5): ");
		scanf_s("%d", &choice);
		printf("%d번째 옵션을 선택하셨습니다.\n", choice);
		if (choice == 1) {
			int i;
			printf("몇 번째 거래의 수익률을 볼건지 입력하시오: ");
			scanf_s("%d", &i);
			CoinProfit(trades,i);
			if (trades[i - 1].StartPrice < trades[i - 1].EndPrice) {
				if (*trades[i - 1].CoinBuySell == 'L') {
					printf("해당 거래의 수익률은 %c%.1lf%c입니다.\n",'+', CoinProfit(trades, i),'%');
				}
				else if (*trades[i-1].CoinBuySell=='S') {
					printf("해당 거래의 수익률은 %c%.1lf%c입니다.\n", '-', CoinProfit(trades, i),'%');
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
			printf("\ncoin종류당 거래비율은 다음과 같습니다.\n");
			CoinTypeRate(trades, numTrades);
		}
		else if (choice == 3) {
			WinRate(trades, numTrades);
		}
		else if (choice == 4) {
			int i;
			printf("당일 몇번의 거래를 했는지 입력하시오: ");
			scanf_s("%d", &i);
			RecentPnl(trades, i,AssetValue);
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