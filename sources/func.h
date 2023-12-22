#pragma once
struct TradeInfo {
	int Coinvalue;//���ŷ�
	int Magnification;//�ŷ���� ����
	double StartPrice;//���۰�
	double EndPrice;//���ᰡ
	char* CoinType;//coin����
	char* CoinBuySell;//long,short�Է�
};

void initializeTradeInfo(struct TradeInfo* trade);

double CoinProfit(const struct TradeInfo* trade, int i);

void CoinTypeRate(struct TradeInfo* trade, int numTrades);

void WinRate(struct TradeInfo* trade, int num);

void RecentPnl(struct TradeInfo* trade, int num, double AV);

void TotalPnl(struct TradeInfo* trade, int num, double AV);