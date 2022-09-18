void convertNumber(int n, int b) {
    /**
        chuyển đổi số nguyên n sang cơ số b
        n: số nguyên dương - n phải ở hệ cơ số 10
        b: hệ cơ số
    */
    if(n<0 || b<2 || b>16){
        cout << "ERROR";
        return ;
    }
    char arr[20];
    int count = 0,m,remainder = n,i;
    while (remainder > 0) {
        if (b>10){
            m = remainder%b;
            if (m >= 10) {
                arr[count] = (char) (m+CHAR_55);
                count++;
            } else {
                arr[count] = (char) (m+CHAR_48);
                count++;
            }
        }else{
            arr[count] = (char) ((remainder%b)+CHAR_48);
            count++;
        }
        remainder /= b;
    }
    // In ra hệ cơ số
    for (i = count-1; i >= 0; i--) {
        cout << arr[i];
    }
}