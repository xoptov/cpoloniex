#include "market.h"

int main() {

    Currency *base = plnx_create_currency("BTC", "Bitcoin");
    Currency *quote = plnx_create_currency("USD", "US Dollar");
    CurrencyPair *pair = plnx_create_currency_pair(base, quote);
    Depth *dph = plnx_create_depth();


    return 0;
}