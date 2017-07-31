#ifndef POLONIEX_MARKET_H
#define POLONIEX_MARKET_H

#include <stdlib.h>
#include <stdbool.h>
#include <glib-2.0/glib.h>

typedef enum orderType {BID, ASK} OrderType;

typedef enum tradeType {BUY, SELL} TradeType;

typedef struct currency
{
    char symbol[4];
    char name[16];
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
    unsigned int id;
    CurrencyPair *pair;
    OrderType type;
    double rate;
    double volume;
    unsigned int date;
} Order;

typedef struct depthRow
{
    double rate;
    double volume;
} DepthRow;

typedef struct depth
{
    DepthSide *bids;
    DepthSide *asks;
} Depth;

typedef struct trade
{
    unsigned int id;
    CurrencyPair *pair;
    TradeType type;
    double rate;
    double volume;
    unsigned int date;
} Trade;

Currency * plnx_create_currency(char *, char *);

CurrencyPair * plnx_create_currency_pair(Currency *, Currency *);

Active * plnx_create_active(Currency *, double);

Order * plnx_create_order(unsigned int, CurrencyPair *, OrderType, double, double, unsigned int);

Depth * plnx_create_depth();

DepthRow * plnx_create_depth_row(double, double);

Trade * plnx_create_trade(unsigned int, CurrencyPair *, TradeType, double, double, unsigned int);

#endif
