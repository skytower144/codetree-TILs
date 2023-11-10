#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> comb;

void Backtrack(int pushingNum, int count) {
    if (pushingNum > n) {
        if (count == m) {
            for (auto num : comb) cout << num << " ";
            cout << endl;
        }
        return;
    }
    comb.push_back(pushingNum);
    Backtrack(pushingNum + 1, count + 1);
    comb.pop_back();

    Backtrack(pushingNum + 1, count);
}

int main() {
    cin >> n >> m;
    Backtrack(1, 0);
    return 0;
}