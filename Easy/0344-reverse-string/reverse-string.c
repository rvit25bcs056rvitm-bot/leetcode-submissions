void reverseString(char* s, int sSize) {
    int j = sSize - 1;
    for(int i = 0;i<=j; i++){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
    }
}