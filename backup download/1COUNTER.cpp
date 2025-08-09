#include <iostream>
using namespace std;

class myClass {
    private:
        int a;
    public:
        myClass() {a=0;}
        void set(int p) {
            if (p<=0) a=0;
            else a=p;
            }
        void inc() {a++;}
        void dec() {
            if(a<=0) a=0;
            else a--;
            }
        void print() {cout << a << endl;}
};

int main() {
    int x=0, n;
    myClass objk;
    cin >> x;
    while (x != -9) {
        switch (x) {
            case 0: cin >> n; objk.set(n); break;
            case 1: objk.inc(); break;
            case -1: objk.dec(); break;
            case 9: objk.print(); break; 
        }
    cin >> x;
    }
return 0;
}