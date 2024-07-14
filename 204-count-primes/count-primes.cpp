class Solution {
public:
    int countPrimes(int n) {

//  Sieve of Eratosthenes algorithm is already one of the most efficient ways to find all prime numbers less than a given integer \U0001d45b
// n with a time complexity of O(nloglogn)
    if (n <= 2) {
        return 0;
    }
    
    int size = (n + 1) / 2;
    vector<bool> is_prime(size, true);
    is_prime[0] = false; // 1 is not a prime number

    for (int i = 1; (2 * i + 1) * (2 * i + 1) < n; ++i) {
        if (is_prime[i]) {
            int num = 2 * i + 1;
            for (int j = num * num; j < n; j += 2 * num) {
                is_prime[j / 2] = false;
            }
        }
    }

    int count = 1; // count 2 as a prime number
    for (int i = 1; 2 * i + 1 < n; ++i) {
        if (is_prime[i]) {
            ++count;
        }
    }

    return count;
    }
};