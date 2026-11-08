int heightChecker(int* heights, int heightsSize) {
    int n = heightsSize;
    int original[n];

    for(int i = 0; i < n; i++){
        original[i] = heights[i];
    }

    for(int i = 0; i<n-1; i++){ // for number of passes
        int rep = 0;
        for(int j = 0; j<n-i-1; j++){ //for number of comparissions
            if(heights[j] > heights[j+1]){
                int temp = heights[j];
                heights[j] = heights[j+1];
                heights[j+1] = temp;
                rep = 1;
            }
        }
        if(rep == 0){
            break;
        }
    }
    int dnm = 0;
    for(int i = 0; i<n; i++){
        if(heights[i] != original[i]){
            dnm++;
        }
    }
    return dnm;
}