#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


double CoinProfit(const struct TradeInfo* trade, int i) {
	double profit1, profit2;
	double a, b;
	int c;
	a = trade[i - 1].StartPrice;
	b = trade[i - 1].EndPrice;
	c = trade[i - 1].Magnification;
	if (a <= b) {
		profit1 = (double)c * (((b - a) / a) * 100);
		return profit1;
	}
	else if (a > b) {
		profit2 = (double)c * (((a - b) / a) * 100);
		return profit2;
	}
}

void CoinTypeRate(struct TradeInfo* trade, int numTrades) {
	int a = 0;
	int b = 0;
	int c = 0;
	double d, e, f;
	for (int i = 0; i < numTrades; i++) {
		if (*trade[i].CoinType == 'B') {
			a += 1;
		}
		else if (*trade[i].CoinType == 'E') {
			b += 1;
		}
		else if (*trade[i].CoinType == 'X') {
			c += 1;
		}
	}
	d = (double)a / (a + b + c) * 100;
	e = (double)b / (a + b + c) * 100;
	f = (double)100 - (d + e);
	printf("BTC:%.1lf%c, ETH:%.1lf%c, XRP:%.1lf%c\n", d, '%', e, '%', f, '%');
}


void WinRate(struct TradeInfo* trade, int num) {
	int a = 0;
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