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

//void CoinProfit(int* CoinPrice) {}

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
		printf("�ش� �ŷ��� ���ͷ��� %lf%�Դϴ�.\n",);
	}
	else if (choice == 2) {
		printf("�ŷ��� coin������ ");
	}
	else if (choice == 3) {
		printf("");
	}
	
	
	printf("���° �ŷ��� ���ͷ��� ������ �Է��ϼ���.\n");
	scanf_s("%d",&Trade);

	//printf("%d��° �ŷ��� ���ͷ��� %lf %�Դϴ�.\n",Trade,);

	//CoinProfit(CoinPrice);
	return 0;
}