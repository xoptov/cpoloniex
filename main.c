#include "market.h"

int main() {

    Currency *base = plnx_create_currency("BTC", "Bitcoin");
    Currency *quote = plnx_create_currency("USD", "US Dollar");
    CurrencyPair *pair = plnx_create_currency_pair(base, quote);
    Order *o = plnx_create_order(1123, pair, BID, 2500, 1, 123123144);

    return 0;
}