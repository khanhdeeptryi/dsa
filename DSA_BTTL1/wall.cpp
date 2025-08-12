#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

// Giữ nguyên hàm can
bool can(ll h,
         const vector<ll> &a,
         const vector<ll> &b,
         bool want_record,
         vector<pair<int,int>> &record)
{
    if (h <= 0) {
        if (want_record) record.clear();
        return true;
    }

    int n = a.size();
    int m = b.size();
    int wood_ptr = 0;

    if (want_record) {
        record.clear();
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= h) {
            continue;
        }
        ll need = h - a[i];
        while (wood_ptr < m && b[wood_ptr] < need) {
            wood_ptr++;
        }
        if (wood_ptr == m) {
            return false;
        }
        if (want_record) {
            record.emplace_back(i + 1, wood_ptr + 1);
        }
        wood_ptr++;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m;
    cin >> m;
    vector<ll> b(m);
    for (int j = 0; j < m; j++) cin >> b[j];

    // Cấu trúc tìm kiếm nhị phân của bạn, đã được chứng minh là hiệu quả nhất
    ll lo = 0, hi = 200000001LL;

    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        vector<pair<int, int>> dummy_record;

        if (can(mid, a, b, false, dummy_record)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    // Bây giờ lo là h tối ưu.
    // Thực hiện truy vết cuối cùng, an toàn và chỉ một lần.
    vector<pair<int, int>> final_record;

    // Quan trọng: Thay vì chỉ gọi can(lo, ...), hãy gọi lại với giá trị đã được xác nhận là khả thi.
    // lo có thể là một giá trị biên mà can() có thể thất bại.
    // Ta đã biết rằng hi (trước khi vòng lặp kết thúc) là một giá trị chắc chắn thất bại.
    // lo là giá trị lớn nhất mà can() trả về true.

    bool possible = can(lo, a, b, true, final_record);

    // Đây là một kiểm tra an toàn cuối cùng. Mặc dù không nên xảy ra.
    if (!possible) {
        // Nếu vì lý do nào đó mà lo không còn khả thi
        // (điều này chỉ ra một lỗi sâu hơn), hãy thử với lo - 1.
        // Tuy nhiên, điều này sẽ làm sai đáp án h.
        // Do đó, cách tiếp cận gốc là đúng nhất.
    }

    cout << lo << " " << final_record.size() << "\n";
    for (const auto &p : final_record) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}