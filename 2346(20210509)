#include<iostream>
#include<deque>
using namespace std;
int main() {
    int n; cin >> n;
    deque<pair<int, int>> dq; // first : 이동 , second : 번째

    for (int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        dq.push_back(make_pair(tmp, i));
    }

    while (!dq.empty()) {
        int move = dq.front().first;
        int seq = dq.front().second;
        cout << seq << " ";


        dq.pop_front();
        if (move > 0) move--;


        while (move != 0) {
            if (move > 0) {
                dq.push_back(dq.front());
                dq.pop_front(); move -= 1;
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back(); move += 1;
            }
        }
    }
}
