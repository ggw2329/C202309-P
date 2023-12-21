#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �Լ��� ������Ϸ� ����
int AssetValue;

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
	double profit;
	double a, b;
	int c;
	a = trade[i - 1].StartPrice;
	b = trade[i - 1].EndPrice;
	c = trade[i - 1].Magnification;
	if (a <= b) {
		profit = c * ((1 - (double)a / (double)b) * 100);
		printf("�ش� �ŷ��� ���ͷ��� %.2lf%c�Դϴ�.", profit, '%');
	}
	else if (a > b) {
		profit = c * (((double)a / (double)b - 1) * 100);
		printf("�ش� �ŷ��� ���ͷ��� %c%.2lf%c�Դϴ�.", '-', profit, '%');
	}
}

void CoinTypeCount(struct TradeInfo* trade, int numTrades){
	int a = 0;
	int b = 0;
	int c = 0;
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
	}printf("BTC:%d�� �ŷ�, ETH:%d�� �ŷ�, XRP:%d�� �ŷ�", a, b, c);
}

//�ռ� ���� �߰�
void WinRate(struct TradeInfo* trade, int numTrades){
	int a=0;
	for (int i = 0; i < numTrades; i++) {
		if (trade->StartPrice < trade->EndPrice) {
			a++;
		}
	}
	double b = (double)a / num * 100;
	printf("������ �Ѱŷ� �·��� %.1lf%c�Դϴ�", b, '%');
}
//void RecentPnl
//void TotalPnl
//void NowAssetValue


int main() {

	printf("������ �ʱ�ݾ��� �Է��ϼ���(KRW).\n");
	scanf_s("%d", &AssetValue);

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
	printf("\n6.asset value ����\n");
	printf("0.���α׷� ����\n");


	for (int i = 0; i < 100; i++) {
		printf("\n�̿��� �ɼ��� �����ϼ���.(0~6): ");
		scanf_s("%d", &choice);
		printf("%d��° �ɼ��� �����ϼ̽��ϴ�.\n", choice);
		if (choice == 1) {
			int i;
			printf("�� ��° �ŷ��� ���ͷ��� ������ �Է��Ͻÿ�.\n");
			scanf_s("%d", &i);
			CoinProfit(trades,i);
		}
		else if (choice == 2) {
			printf("coin������ �ŷ�Ƚ���� ������ �����ϴ�.\n");
			CoinTypeCount(trades, numTrades);
		}
		else if (choice == 3) {
			WinRate(trades, numTrades);
		}
		else if (choice == 4) {
			//int i;
			//printf("���� ����� �ŷ��� �ߴ��� �Է��Ͻÿ�.\n");
			//scanf_s("%d",&i);
			//printf("���� pnl�� %.1lf�Դϴ�.\n",RecentPnl());
		}
		else if (choice == 5) {
			//int i;
			//printf("�� pnl�� %.1lf�Դϴ�.\n",TotalPnl());
		}
		else if (choice == 6) {
			//assetvalue= �ʱ�value+Coinvalue*���ͷ�
			//printf("���� assetvalue�� %d�Դϴ�.\n",Assetvalue);
		}
		else if (choice == 0) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else {
			printf("���ڸ� �߸� �Է��ϼ̽��ϴ�(0~6).\n");
		}
	}
	for (int i = 0; i < numTrades; i++) {
		free(trades[i].CoinType);
		free(trades[i].CoinBuySell);
	}
	free(trades);
	return 0;
}