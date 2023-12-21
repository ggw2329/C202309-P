#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MONTH 1
#define WEEK 7
#define DAY 1

// �迭�� ����ü�� ����
// (�迭�� �����޸� ����->define ����)
// �Լ��� ������Ϸ� ����
int Trade;
int AssetValue;
char CoinType[MONTH][10];//�����Է�
char CoinBuySell[MONTH][10];//long,short�Է�
int Coinvalue[MONTH];//���ŷ� �Է�
double StartPrice[MONTH];//���۰� �Է�
double EndPrice[MONTH];//���ᰡ �Է�
int Magnification[MONTH];//���� �Է�

//�ռ� ���� �߰�
void CoinProfit(double* value1,double* value2,int i,int*Mag) {
	double profit;
	if (*value1 <= *value2) {
		profit = *Mag * ((1-(double)value1[i-1] / (double)value2[i-1])*100);
		printf("%d��° �ŷ��� ���ͷ��� %.2lf%c�Դϴ�.", i, profit,'%');
	}
	else if (*value1 > *value2) {
		profit = *Mag * (((double)value1[i-1] / (double)value2[i-1]-1) * 100);
		printf("%d��° �ŷ��� ���ͷ��� %c %.2lf%c�Դϴ�.", i,'-', profit,'%');
	}
}

void CoinTypeCount(char*CoinType){
	int a = 0;
	int b = 0;
	int c = 0;
	for (int i=0; i < MONTH; i++) {
		if (CoinType[i] == 'B') {
			a+=1;
		}
		else if (CoinType[i] == 'E') {
			b+=1;
		}
		else if (CoinType[i] == 'X') {
			c+=1;
		}
	}printf("BTC:%d�� �ŷ�, ETH:%d�� �ŷ�, XRP:%d�� �ŷ�", a, b, c);
}

//�ռ� ���� �߰�
void WinRate(double*SP,double*EP){
	int a=0;
	for (int i = 0; i < MONTH; i++) {
		if (SP[i] < EP[i]) {
			a++;
		}
	}
	printf("������ �Ѱŷ� �·��� %d%c�Դϴ�", a / MONTH * 100, '%');
}
//void RecentPnl
//void TotalPnl


int main() {



	printf("������ �ʱ�ݾ��� �Է��ϼ���(KRW).\n");
	scanf_s("%d", &AssetValue);

	printf("Position������ �Է� �޽��ϴ�.\n");

	for (int i = 0; i < MONTH; i++) {

		printf("����� %d��° �ŷ��� ������ �Է��Ͻÿ�.(coin����(BTC,ETH,XRP),��/��(L,S),���ŷ�(KRW))(�����Է½� �ձ��ڸ� �Է�)\n", i + 1);
		scanf_s("%s %s %d", CoinType[i], (int)sizeof(CoinType),CoinBuySell[i],(int)sizeof(CoinBuySell),&Coinvalue[i]);
		printf("����� %d��° �ŷ��� ������ �Է��Ͻÿ�.(���۰�,���ᰡ,����)\n", i + 1);
		scanf_s("%lf %lf %d",&StartPrice[i],&EndPrice[i],&Magnification[i]);
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
		printf("\n�̿��� �ɼ��� �����ϼ���.(0~5)");
		scanf_s("%d", &choice);
		printf("%d��° �ɼ��� �����ϼ̽��ϴ�.\n", choice);
		if (choice == 1) {
			int i;
			printf("�� ��° �ŷ��� ���ͷ��� ������ �Է��Ͻÿ�.\n");
			scanf_s("%d", &i);
			CoinProfit(StartPrice, EndPrice, i,Magnification);
		}
		else if (choice == 2) {
			printf("coin������ �ŷ�Ƚ���� ������ �����ϴ�.\n");
			CoinTypeCount(*CoinType);
		}
		else if (choice == 3) {
			WinRate(StartPrice, EndPrice);
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
			//assetvalue= ó��value+value*���ͷ�
			//printf("���� assetvalue�� %d�Դϴ�.\n",Assetvalue);
		}
		else if (choice == 0) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else {
			printf("���ڸ� �߸� �Է��ϼ̽��ϴ�(0~5).\n");
		}
	}
	return 0;
}