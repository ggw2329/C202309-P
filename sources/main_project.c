#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �Լ��� ������Ϸ� ����
double AssetValue;

struct TradeInfo {
	int Coinvalue;//���ŷ�
	int Magnification;//�ŷ���� ����
	double StartPrice;//���۰�
	double EndPrice;//���ᰡ
	char* CoinType;//coin����
	char* CoinBuySell;//long,short�Է�
};

void initializeTradeInfo(struct TradeInfo* trade) {
	printf("�ŷ��� coin������ �Է��ϼ���(BTC,ETH,XRP(�빮�ڷ� �Է�)): ");
	char temp[100];
	scanf_s("%s", temp, (int)sizeof(temp));
	trade->CoinType = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(trade->CoinType, strlen(temp) + 1, temp);

	printf("�ŷ��� Long/Short������ �Է��ϼ���(�빮�ڷ� �Է�): ");
	scanf_s("%s", temp, (int)sizeof(temp));
	trade->CoinBuySell = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(trade->CoinBuySell, strlen(temp) + 1, temp);

	printf("�ŷ��� ���ŷ�(KRW)�� �Է��ϼ���: ");
	scanf_s("%d", &trade->Coinvalue);

	printf("�ش�ŷ��� ����� ������ �Է��ϼ���: ");
	scanf_s("%d", &trade->Magnification);

	printf("�ش�ŷ��� ���۰��� ���ᰡ�� �Է��ϼ���: ");
	scanf_s("%lf %lf", &trade->StartPrice, &trade->EndPrice);
}

//�ռ� ���� �߰�
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
	printf("������ �Ѱŷ� �·��� %.1lf%c�Դϴ�", b, '%');
}

void RecentPnl(struct TradeInfo* trade, int num, double AV) {
	double a = 0;//���ͱ�
	double b;//���ͷ�
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
	printf("������ ����Pnl:%.1lfKRW(%.1lf%c)", a + AV, b, '%');
}

void TotalPnl(struct TradeInfo* trade, int num, double AV) {
	double a = 0;//���ͱ�
	double b;//���ͷ�
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
	printf("������ ��Pnl:%.1lfKRW(%.1lf%c)", a + AV, b, '%');
}

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
	printf("0.���α׷� ����\n");


	for (int i = 0; i < 100; i++) {
		printf("\n\n�̿��� �ɼ��� �����ϼ���.(0~5): ");
		scanf_s("%d", &choice);
		printf("%d��° �ɼ��� �����ϼ̽��ϴ�.\n", choice);
		if (choice == 1) {
			int i;
			printf("�� ��° �ŷ��� ���ͷ��� ������ �Է��Ͻÿ�: ");
			scanf_s("%d", &i);
			CoinProfit(trades, i);
			if (trades[i - 1].StartPrice < trades[i - 1].EndPrice) {
				if (*trades[i - 1].CoinBuySell == 'L') {
					printf("�ش� �ŷ��� ���ͷ��� %c%.1lf%c�Դϴ�.\n", '+', CoinProfit(trades, i), '%');
				}
				else if (*trades[i - 1].CoinBuySell == 'S') {
					printf("�ش� �ŷ��� ���ͷ��� %c%.1lf%c�Դϴ�.\n", '-', CoinProfit(trades, i), '%');
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
			printf("\ncoin������ �ŷ�Ƚ���� ������ �����ϴ�.\n");
			CoinTypeRate(trades, numTrades);
		}
		else if (choice == 3) {
			WinRate(trades, numTrades);
		}
		else if (choice == 4) {
			int i;
			printf("���� ����� �ŷ��� �ߴ��� �Է��Ͻÿ�: ");
			scanf_s("%d", &i);
			RecentPnl(trades, i, AssetValue);
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