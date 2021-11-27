#include <iostream>
#include <vector>
#include <stack>

using namespace std;

using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vi As(N);
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;

        As[i] = a;
    }

    vi answers(N);
    stack<int> st{};

    for (int i = N - 1; 0 <= i; --i)
    {
        while (!st.empty() && st.top() <= As[i]) {
            st.pop();
        }

        if (st.empty()) {
            answers[i] = -1;
        }
        else {
            answers[i] = st.top();
        }

        st.push(As[i]);
    }

    for (const auto& v : answers)
    {
        cout << v << ' ';
    }

    return 0;
}