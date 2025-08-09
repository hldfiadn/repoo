#include <iostream>
#include <iomanip>
using namespace std;

class Person {
    private:
        string nama;
        int usia, tb;
        double bb;
    
    public:
        Person () 
        {nama = " "; usia = 0; tb = 0; bb = 0.0;}
        void set (string n, int u, int t, double b) 
        {nama = n; usia = u; tb = t; bb = b;}
        void show () 
        {cout <<  nama << " " << usia << endl;}
        int tinggiB () {return tb;}
};

int main () {
    int n, usia, tinggi;
    int counter = 0;
    string nama;
    double berat;
    cin >> n;
    Person* Manusia = new Person[n];

    for (int i = 0; i < n; i++) {
        cin >> nama >> usia >> tinggi >> berat;
        Manusia[i].set(nama, usia, tinggi, berat);
    }

    for (int i = 0; i < n; i++) {
        Manusia[i].show();
    }

    double totaltinggi;
    
    for (int i = 0; i < n; i++) {
        totaltinggi += Manusia[i].tinggiB();
    }
    
    cout << setprecision (2) << fixed << totaltinggi/n << endl;
    int tinggiBat;
    
    for (int i = 0; i < n; i++) {
        if (Manusia[i].tinggiB() > totaltinggi/n)
        {
            tinggiBat = Manusia[i].tinggiB();
            counter++;
        }
    }
    
    cout << counter << endl;
    return 0;
}