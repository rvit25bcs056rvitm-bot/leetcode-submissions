


typedef struct {
    int insInd;
    int delInd;
    int arr[10000];
} RecentCounter;

void insertion(RecentCounter* queue1, int value) {
    queue1->insInd++;
    queue1->arr[queue1->insInd] = value;
}

void deletion(RecentCounter* queue1) {
    queue1->delInd++;
}

RecentCounter* recentCounterCreate() {
    RecentCounter* queue1 = (RecentCounter*)malloc(sizeof(RecentCounter));
    if (queue1 == NULL) {
        return NULL;
    }
    queue1->insInd = -1;
    queue1->delInd = -1;
    return queue1;
}


int recentCounterPing(RecentCounter* obj, int t) {
    insertion(obj, t);

    while (obj->delInd < obj->insInd &&
           obj->arr[obj->delInd + 1] < t - 3000) {
        deletion(obj);
    }

    return obj->insInd - obj->delInd;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/