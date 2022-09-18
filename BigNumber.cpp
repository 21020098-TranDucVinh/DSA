int stringToNum(char c)     // chuyen char sang so
{
    return c - '0';
}
 
char numToString(int n)     // chuyen so sang char
{
    return (char)(n+48);
}
void chuanHoa(string &a, string &b) // lam 2 xau co do dai bang nhau
{
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2)
    {
        b.insert(0, l1-l2, '0');    // chen vao dau cua b cac ky tu '0'
    }
    else
    {
        a.insert(0, l2-l1, '0');    // chen vao dau cua a cac ky tu '0'
    }
}
 
string sum(string a, string b)  // tong 2 so
{
    string s = "";
    chuanHoa(a,b);      // chuan hoa
    int l = a.length();
     
    int temp = 0;
    for (int i=l-1; i>=0; i--)   // duyet va cong
    {
        temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;    // tinh tong tung doi mot
        s.insert(0,1,numToString(temp%10));         // gan phan don vi vao
        temp = temp/10;     // lay lai phan hang chuc
    }
    if (temp>0)  // neu hang chuc > 0 thi them vao KQ
    {
        s.insert(0,1,numToString(temp));
    } 
    return s;
}
 
// nhan so co 1 chu so voi so co nhieu chu so (VD 4 va 7826), lam tuong tu nhu phep cong
string nhanNho(char a, string b)    
{
    string s = "";
    int temp = 0;
    for (int i=b.length()-1; i>=0; i--)      
    {
        temp = stringToNum(a) * stringToNum(b[i]) + temp;
        s.insert(0,1,numToString(temp%10));
        temp = temp/10;
    }
     
    if (temp>0)
    {
        s.insert(0,1,numToString(temp));
    } 
    return s;
}
 
string nhan(string a, string b)     // nhan 2 so lon
{
    string s = "";
    int l = a.length();
    string s1[l];
     
    for (int i=l-1; i>=0; i--)   // nhan tung chu so cua a voi b sau do cong don vao
    {
        s1[i] = nhanNho(a[i], b);   // nhan tung so cua a voi b
        s1[i].insert(s1[i].length(), l-i-1, '0');   
        s = sum(s, s1[i]);  // cong don theo cach cong so lon
    }
    return s;
}