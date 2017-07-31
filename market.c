#include <string.h>
#include "market.h"


Currency * plnx_create_currency(char *symbol, char *name)
{
    Currency *c = (Currency *)malloc(sizeof(Currency));
    strncpy(c->symbol, symbol, 4);
    strncpy(c->name, name, 16);

    return c;
}

CurrencyPair * plnx_create_currency_pair(Currency *base, Currency *quote)
{
    CurrencyPair *pair = (CurrencyPair *)malloc(sizeof(CurrencyPair));
    pair->base = base;
    pair->quote = quote;

    return pair;
}

Active * plnx_create_active(Currency *currency, double amount)
{
    Active *a = (Active *)malloc(sizeof(Active));
    a->currency = currency;
    a->amount = amount;

    return a;
}

Order * plnx_create_order(unsigned int id, CurrencyPair *pair, OrderType type, double rate, double volume, unsigned int date)
{
    Order *o = (Order *)malloc(sizeof(Order));
    o->id = id;
    o->pair = pair;
    o->rate = rate;
    o->volume = volume;
    o->date = date;

    return o;
}

Depth * plnx_create_depth()
{
    Depth *d = (Depth *)malloc(sizeof(Depth));

    d->bids = plnx_create_depth_side();
    d->asks = plnx_create_depth_side();

    return d;
}

DepthSide * plnx_create_depth_side()
{
    DepthSide *side = (DepthSide *)malloc(sizeof(DepthSide));
    side->top = NULL;

    return side;
}

DepthRow * plnx_create_depth_row(double rate, double volume)
{
    DepthRow *row = (DepthRow *)malloc(sizeof(DepthRow));
    row->rate = rate;
    row->volume = volume;
    row->next = NULL;

    return row;
}

Trade * plnx_create_trade(unsigned int id, CurrencyPair *pair, TradeType type, double rate, double volume, unsigned int date)
{
    Trade *t = (Trade *)malloc(sizeof(Trade));
    t->id = id;
    t->pair = pair;
    t->rate = rate;
    t->volume = volume;
    t->date = date;

    return t;
}
