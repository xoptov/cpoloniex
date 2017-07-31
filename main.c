#include "market.h"

int main() {

    Currency *base = plnx_currency_new("BTC", "Bitcoin");
    Currency *quote = plnx_currency_new("USD", "US Dollar");
    CurrencyPair *pair = plnx_currency_pair_new(base, quote);
    Depth *dph = plnx_depth_new();
    DepthItem *dItem1 = plnx_depth_item_new(2500, 1.5);
    DepthItem *dItem2 = plnx_depth_item_new(2550, 2);
    
    g_hash_table_insert(dph->bids, &dItem1->rate, dItem2);
    g_hash_table_insert(dph->bids, &dItem2->rate, dItem2);
			
    return 0;
}
