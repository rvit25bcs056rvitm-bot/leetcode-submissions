typedef struct {
    int price;
    int span;
} Pair;

typedef struct {
    Pair stack[10000];
    int top;
} StockSpanner;

// nexted structure only give u this attribute to write 2 structures in for loop

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = malloc(sizeof(StockSpanner));
    obj->top = -1;
    return obj;
}

// obj->stack[obj->top].price
// obj->stack[obj->top].span

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;

    while (obj->top != -1 && obj->stack[obj->top].price <= price) {
        span += obj->stack[obj->top].span;
        obj->top--;
    }

    obj->top++;
    obj->stack[obj->top].price = price;
    obj->stack[obj->top].span = span;

    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/