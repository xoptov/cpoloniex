#ifndef POLONIEX_MARKET_H
#define POLONIEX_MARKET_H

#include <stdlib.h>
#include <stdbool.h>
#include <glib-2.0/glib.h>

typedef enum orderType {BID, ASK} OrderType;

typedef enum tradeType {BUY, SELL} TradeType;

typedef struct currency
{
    GString *symbol;
    GString *name;
} Currency;

typedef struct currencyPair
{
    Currency *base;
    Currency *quote;
} CurrencyPair;

typedef struct active
{
    Currency *currency;
    double amount;
} Active;

typedef struct order
{
    guint32 id;
    CurrencyPair *pair;
    OrderType type;
    double rate;
    double volume;
    GDateTime *createdAt;
} Order;

typedef struct depthItem
{
    double rate;
    double volume;
} DepthItem;

typedef struct depth {
    GHashTable *bids;
    GHashTable *asks;
} Depth;

typedef struct trade
{
    guint32 id;
    CurrencyPair *pair;
    TradeType type;
    double rate;
    double volume;
    GDateTime *createdAt;
} Trade;

Currency * plnx_currency_new(gchar *, gchar *);

CurrencyPair * plnx_currency_pair_new(Currency *, Currency *);

Active * plnx_active_new(Currency *, double);

Order * plnx_order_new(guint32, CurrencyPair *, OrderType, double, double, GDateTime *);

Depth * plnx_depth_new();

DepthItem * plnx_depth_item_new(double, double);

Trade * plnx_trade_new(guint32, CurrencyPair *, TradeType, double, double, GDateTime *); 

#endif
