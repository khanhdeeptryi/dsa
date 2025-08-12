
#include <iostream>


#define MAX 10000
#define EMPTY 0
#define NIL 0
#define DELETED -1

using namespace std;

struct Hocsinh {
    int MSHS;
    string HoTen;
    int Namsinh;
    char Gioitinh;
    double Toan, Ly, Hoa, Anh;
};


struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh table[MAX];
};

void InputElement(Hocsinh &x) {
    cin >> x.MSHS;
    if (x.MSHS > 0)
        getline(cin>>ws, x.HoTen);
    else {
        x.HoTen = "";
    }

    cin >> x.Namsinh;
    if (x.MSHS > 0)
        cin >> x.Gioitinh;
    else
        x.Gioitinh = ' ';

    cin >> x.Toan;
    cin >> x.Ly;
    cin >> x.Hoa;
    cin >> x.Anh;
}

void OutputElement(Hocsinh x) {
    cout << x.MSHS << endl << x.HoTen << endl << x.Namsinh << endl << x.Gioitinh << endl
            << x.Toan << endl << x.Ly << endl << x.Hoa << endl << x.Anh << endl;
}

int Search(Hashtable, int);

int main()
{
    Hashtable ht;
    int m, n;

    cin >> m >> n;
    ht.n = n;
    ht.M = m;
    for (int i = 0; i < m; i++) {
        InputElement(ht.table[i]);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        cout << m << ' ' << Search(ht, m) << endl;
    }

    return 0;
}

int Search(Hashtable ht, int m) {
    int M = ht.M;
    int i = 0, k = 0;
    while (k < M) {
        int index = (m % M + i * i) % M;
        if (ht.table[index].MSHS == EMPTY) return -(k + 1);
        if (ht.table[index].MSHS == m) return k + 1;
        i++;
        k++;
    }
    return -k;
}
