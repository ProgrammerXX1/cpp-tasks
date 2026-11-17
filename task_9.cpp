#include <iostream>

using namespace std;
int main() {

    int N=2, K=4;
    int dp[38][40] = {0};
    dp[0][N] = 1;

    for (int step = 1; step <= K; ++step) {
    int start_pos = (step == K) ? 0 : 1;

        for (int pos = start_pos; pos <= 37; ++pos) {
            if (pos - 1 > 0) 
                dp[step][pos] += dp[step - 1][pos - 1];
            
            if (pos + 1 <= 37) 
                dp[step][pos] += dp[step - 1][pos + 1];
            
        }
    }

    cout << dp[K][0] << endl;

    return 0;
}
