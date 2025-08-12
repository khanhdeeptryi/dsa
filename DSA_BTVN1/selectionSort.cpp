
#include <iostream>
//using namespace std;

class data{
private:
    int x;
    static int assignment_count;
    static int n;
public:

    friend std::ostream& operator<<(std::ostream &os, const data& a);
    friend std::istream& operator>>(std::istream &os, data& a)    ;
    static void set_n(int n){
        if (data::n == 0) data::n = n;
        else std::cout << "WRONG";
    }
    data& operator=(const data& a){
        assignment_count++;
        if (assignment_count > 3* data::n){
            std::cout << "WRONG";
        }
        this->x = a.x;
        return *this;
    }

    bool operator<(const data& a){
        return this->x < a.x;
    }
};
int data::assignment_count = 0;
int data::n = 0;

std::ostream& operator<<(std::ostream &os, const data& a){
    return os << a.x;
}
std::istream& operator>>(std::istream &os, data& a){
    return os >> a.x;
}

void select_sort(data *A, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            data tmp = A[i];
            A[i] = A[min_idx];
            A[min_idx] = tmp;
        }
    }
}


int main(){
    int n;
    std::cin >> n;
    data::set_n(n);

    data *A = new data[n];
    for (int i = 0; i < n; i++){
        std::cin >> A[i];
    }

    select_sort(A, n);

    for(int i = 0; i < n; i++){
        std::cout << A[i] << " " ;
    }
}
