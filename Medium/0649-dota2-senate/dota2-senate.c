#include <string.h>

char* predictPartyVictory(char* senate) {
    int i = 0; // for traversing
    int radient[10000];
    int rcount = 0;
    int dire[10000];
    int dcount = 0;
    while(senate[i] != '\0'){
        if(senate[i] == 'R'){
            radient[rcount] = i;
            rcount++;
        }
        else{
            dire[dcount] = i;
            dcount++;
        }
        i++;
    }

    int j = 0;// for radient count
    int k = 0;// for dire count
    int n = strlen(senate);
    while(j < rcount && k < dcount){
        if(radient[j]<dire[k]){
            int l = radient[j];
            k++;
            j++;
            radient[rcount] = l + n;
            rcount++;
        }
        else{
            int r = dire[k];
            k++;
            j++;
            dire[dcount] = r + n;
            dcount++;
        }
    }
    if (j < rcount)
        return "Radiant";
    else
        return "Dire";
}