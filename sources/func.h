#pragma once
struct TradeInfo {
	int Coinvalue;//구매량
	int Magnification;//거래당시 배율
	double StartPrice;//시작가
	double EndPrice;//종료가
	char* CoinType;//coin종류
	char* CoinBuySell;//long,short입력
};

void initializeTradeInfo(struct TradeInfo* trade);

double CoinProfit(const struct TradeInfo* trade, int i);

void CoinTypeRate(struct TradeInfo* trade, int numTrades);

void WinRate(struct TradeInfo* trade, int num);

void RecentPnl(struct TradeInfo* trade, int num, double AV);

void TotalPnl(struct TradeInfo* trade, int num, double AV);