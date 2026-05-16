#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    return 0;
}

double mean(vector<double> v) {
    if (v.empty()) return 0.0;
    double sum = 0.0;
    for (double x : v) sum += x;
    return sum / v.size();
}

double variance(vector<double> v) {
    if (v.size() <= 1) return 0.0;
    double m = mean(v);
    double sum_sq = 0.0;
    for (double x : v) sum_sq += (x - m) * (x - m);
    return sum_sq / (v.size() - 1);
}

double pearson_r(vector<double> A, vector<double> B) {
    if (A.size() != B.size() || A.empty()) return 0.0;
    double meanA = mean(A), meanB = mean(B);
    double num = 0.0, denA = 0.0, denB = 0.0;
    for (size_t i = 0; i < A.size(); ++i) {
        double diffA = A[i] - meanA;
        double diffB = B[i] - meanB;
        num += diffA * diffB;
        denA += diffA * diffA;
        denB += diffB * diffB;
    }
    if (denA == 0.0 || denB == 0.0) return 0.0;
    return num / sqrt(denA * denB);
}

vector<char> dec_to_base(long long n, int base) {
    if (n == 0) return {'0'};
    bool is_neg = (n < 0);
    if (is_neg) n = -n;
    vector<char> res;
    while (n > 0) {
        int rem = n % base;
        if (rem < 10) res.push_back(rem + '0');
        else res.push_back(rem - 10 + 'A');
        n /= base;
    }
    if (is_neg) res.push_back('-');
    reverse(res.begin(), res.end());
    return res;
}

long long base_to_dec(vector<char> s, int base) {
    long long res = 0;
    bool is_neg = false;
    size_t start = 0;
    if (!s.empty() && s[0] == '-') { is_neg = true; start = 1; }
    for (size_t i = start; i < s.size(); ++i) {
        int val = 0;
        if (s[i] >= '0' && s[i] <= '9') val = s[i] - '0';
        else if (s[i] >= 'A' && s[i] <= 'F') val = s[i] - 'A' + 10;
        else if (s[i] >= 'a' && s[i] <= 'f') val = s[i] - 'a' + 10;
        res = res * base + val;
    }
    return is_neg ? -res : res;
}

vector<char> dec_to_septapus(int n) { return dec_to_base(n, 7); }
vector<char> dec_to_octopus(int n) { return dec_to_base(n, 8); }
vector<char> dec_to_hexakaidecapus(int n) { return dec_to_base(n, 16); }
vector<char> septapus_to_dec(vector<char> s) { return dec_to_base(base_to_dec(s, 7), 10); }
vector<char> octopus_to_dec(vector<char> s) { return dec_to_base(base_to_dec(s, 8), 10); }
vector<char> hexakaidecapus_to_dec(vector<char> s) { return dec_to_base(base_to_dec(s, 16), 10); }
vector<char> septapus_to_octopus(vector<char> s) { return dec_to_base(base_to_dec(s, 7), 8); }
vector<char> septapus_to_hexakaidecapus(vector<char> s) { return dec_to_base(base_to_dec(s, 7), 16); }
vector<char> octapus_to_septapus(vector<char> s) { return dec_to_base(base_to_dec(s, 8), 7); }
vector<char> octopus_to_hexakaidecapus(vector<char> s) { return dec_to_base(base_to_dec(s, 8), 16); }
vector<char> hexakaidecapus_to_septapus(vector<char> s) { return dec_to_base(base_to_dec(s, 16), 7); }
vector<char> hexakaidecapus_to_octopus(vector<char> s) { return dec_to_base(base_to_dec(s, 16), 8); }
