#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double AssetValue;

int main() {

	printf("������ �ʱ�ݾ��� �Է��ϼ���(KRW).\n");
	scanf_s("%lf", &AssetValue);

	int numTrades;
	printf("�� ���� �ŷ��� �Է��Ͻðڽ��ϱ�? \n");
	scanf_s("%d", &numTrades);

	struct TradeInfo* trades = (struct TradeInfo*)malloc(numTrades * sizeof(struct TradeInfo));

	if (trades == NULL) {
		return 1;
	}

	for (int i = 0; i < numTrades; i++) {
		printf("\n%d��° �ŷ��� ������ �Է��ϼ���.\n", i + 1);
		initializeTradeInfo(&trades[i]);
	}

	int choice;
	printf("\n1.�ش� �ŷ��� ���ͷ�");
	printf("\n2.coin������ �ŷ�Ƚ��");
	printf("\n3.�� �ŷ� ������");
	printf("\n4.���� pnl����");
	printf("\n5.total pnl ����");
	printf("\n6.���� asset value ����\n");
	printf("0.���α׷� ����\n");


	for (int i = 0; i < 100; i++) {
		printf("\n\n�̿��� �ɼ��� �����ϼ���.(0~5): ");
		scanf_s("%d", &choice);
		printf("%d��° �ɼ��� �����ϼ̽��ϴ�.\n", choice);
		if (choice == 1) {
			int i;
			printf("�� ��° �ŷ��� ���ͷ��� ������ �Է��Ͻÿ�: ");
			scanf_s("%d", &i);
			CoinProfit(trades,i);
			if (trades[i - 1].StartPrice < trades[i - 1].EndPrice) {
				if (*trades[i - 1].CoinBuySell == 'L') {
					printf("�ش� �ŷ��� ���ͷ��� %c%.1lf%c�Դϴ�.\n",'+', CoinProfit(trades, i),'%');
				}
				else if (*trades[i-1].CoinBuySell=='S') {
					printf("�ش� �ŷ��� ���ͷ��� %c%.1lf%c�Դϴ�.\n", '-', CoinProfit(trades, i),'%');
				}
			}
			else if (trades[i - 1].StartPrice >= trades[i - 1].EndPrice) {
				if (*trades[i - 1].CoinBuySell == 'S') {
					printf("�ش� �ŷ��� ���ͷ��� %c%.1lf%c�Դϴ�.\n", '+', CoinProfit(trades, i), '%');
				}
				else if (*trades[i - 1].CoinBuySell == 'L') {
					printf("�ش� �ŷ��� ���ͷ��� %c%.1lf%c�Դϴ�.\n", '-', CoinProfit(trades, i), '%');
				}
			}
		}
		else if (choice == 2) {
			printf("\ncoin������ �ŷ������� ������ �����ϴ�.\n");
			CoinTypeRate(trades, numTrades);
		}
		else if (choice == 3) {
			WinRate(trades, numTrades);
		}
		else if (choice == 4) {
			int i;
			printf("���� ����� �ŷ��� �ߴ��� �Է��Ͻÿ�: ");
			scanf_s("%d", &i);
			RecentPnl(trades, i,AssetValue);
		}
		else if (choice == 5) {
			TotalPnl(trades, numTrades, AssetValue);
		}
		else if (choice == 0) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else {
			printf("���ڸ� �߸� �Է��ϼ̽��ϴ�(0~5).\n");
		}
	}
	for (int i = 0; i < numTrades; i++) {
		free(trades[i].CoinType);
		free(trades[i].CoinBuySell);
	}
	free(trades);

	return 0;
}