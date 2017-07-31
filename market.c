#include <string.h>
#include <glib-2.0/glib.h>
#include "market.h"


Currency * plnx_currency_new(gchar *symbol, gchar *name)
{
    Currency *c = (Currency *)malloc(sizeof(Currency));
    c->symbol = g_string_new(symbol);
    c->name = g_string_new(name);
    
    return c;
}

CurrencyPair * plnx_currency_pair_new(Currency *base, Currency *quote)
{
    CurrencyPair *pair = (CurrencyPair *)malloc(sizeof(CurrencyPair));
    pair->base = base;
    pair->quote = quote;

    return pair;
}

Active * plnx_active_new(Currency *currency, double amount)
{
    Active *a = (Active *)malloc(sizeof(Active));
    a->currency = currency;
    a->amount = amount;

    return a;
}

Order * plnx_order_new(guint32 id, CurrencyPair *pair, OrderType type, double rate, double volume, GDateTime *createdAt)
{
    Order *o = (Order *)malloc(sizeof(Order));
    o->id = id;
    o->pair = pair;
    o->rate = rate;
    o->volume = volume;
    o->createdAt = createdAt;

    return o;
}

Depth * plnx_depth_new()
{
    Depth *d = (Depth *)malloc(sizeof(Depth));
    d->bids = g_hash_table_new(g_double_hash, g_double_equal);
    d->asks = g_hash_table_new(g_double_hash, g_double_equal);

    return d;
}

DepthItem * plnx_depth_item_new(double rate, double volume)
{
    DepthItem *item = (DepthItem *)malloc(sizeof(DepthItem));
    item->rate = rate;
    item->volume = volume;

    return item;
}

Trade * plnx_trade_new(guint32 id, CurrencyPair *pair, TradeType type, double rate, double volume, GDateTime *createdAt)
{
    Trade *t = (Trade *)malloc(sizeof(Trade));
    t->id = id;
    t->pair = pair;
    t->rate = rate;
    t->volume = volume;
    t->createdAt = createdAt;

    return t;
}
