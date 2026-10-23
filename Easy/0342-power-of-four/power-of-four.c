bool isPowerOfFour(int n) {
    if(n<=0){
        return false;
    }
    else{
        int count = 0;
        while((n&1) == 0){
            n = n>>1;
            count++;
        }
        if (n != 1) {
            return false;
        }
        if(count%2 == 1){
            return false;
        }
        else{
            return true;
        }
    }
}