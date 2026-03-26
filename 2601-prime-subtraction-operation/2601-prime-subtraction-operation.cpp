class Solution {
public:
    vector<int> primes;

    void sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        sieve(1000);

        int prev = 0;

        for (int &x : nums) {

            int diff = x - prev;

            // find best prime to subtract
            int best = 0;
            for (int p : primes) {
                if (p >= diff) break;
                best = p;
            }

            x -= best;

            if (x <= prev) return false;

            prev = x;
        }

        return true;
    }
};