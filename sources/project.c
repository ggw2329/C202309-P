#include <stdio.h>
#define MONTH 30
#define WEEK 7
#define DAY 1


int Trade;
int AssetValue;
char CoinType[MONTH][10];//�����Է�
char CoinBuySell[MONTH][10];//long,short�Է�
int Coinvalue[MONTH][10];//���ŷ� �Է�
double StartPrice[MONTH][10];//���۰� �Է�
double EndPrice[MONTH][10];//���ᰡ �Է�
int Magnification[MONTH][10];//���� �Է�

//double CoinProfit(double* StartPrice,double*EndProce,int i) {
	//double profit;
	//profit =(double)(EndPrice[i] / StartPrice[i]) * 100;
	//return profit;
//}

//void CoinTypeRate(char*CoinType){}

//void WinRate(int*){}
//void RecentPnl
//void TotalPnl


int main() {

	printf("������ �ʱ�ݾ��� �Է��ϼ���(KRW).\n");
	scanf_s("%d", &AssetValue);

	printf("Position������ �Է� �޽��ϴ�.\n");

	for (int i = 0; i < MONTH; i++) {

		printf("����� %d��° �ŷ��� ������ �Է��Ͻÿ�.(coin����(ENG),long/short,���ŷ�(KRW))\n", i + 1);
		scanf_s("%s %s %d", CoinType[i], (int)sizeof(CoinType),CoinBuySell[i],(int)sizeof(CoinBuySell),Coinvalue[i]);
		getchar();
		printf("����� %d��° �ŷ��� ������ �Է��Ͻÿ�.(���۰�,���ᰡ,����)\n", i + 1);
		scanf_s("%lf %lf %d",StartPrice[i],EndPrice[i],Magnification[i]);
	}
	
	int choice;
	printf("1.�ش� �ŷ��� ���ͷ�");
	printf("2.coin������ ����");
	printf("3.�� �ŷ� ������");
	printf("4.���� pnl����");
	printf("5.total pnl ����");
	sancf_s("%d", &choice);

	if (choice == 1) {
		int i;
		printf("�� ��° �ŷ��� ���ͷ��� ������ �Է��Ͻÿ�.\n");
		scanf_s("%d", &i);
		//printf("�ش� �ŷ��� ���ͷ��� %lf%�Դϴ�.\n",CoinProfit(StartPrice,EndPrice,i));
	}
	else if (choice == 2) {
		//printf("�ŷ��� coin������ ");
	}
	else if (choice == 3) {
		//printf("�� �ŷ��� �������� %.1lf%�Դϴ�.\n",WinRate());
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
	else {
		printf("���ڸ� �߸� �Է��ϼ̽��ϴ�(1~5).\n");
	}
	return 0;
}