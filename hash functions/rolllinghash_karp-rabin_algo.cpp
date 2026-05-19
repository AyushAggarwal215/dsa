#include <bits/stdc++.h>
using namespace std;

vector<int> rolling_hash(string s, int window_size, int base = 26, int mod = 1000000007)
{
    int n = s.length();
    vector<int> power(n + 1, 1);
    vector<int> hash_values(n - window_size + 1);

    // Precompute the powers of the base modulo the mod
    for (int i = 1; i <= n; i++)
    {
        power[i] = (power[i - 1] * base) % mod;
    }

    // Compute the hash value of the first window
    int current_hash = 0;
    for (int i = 0; i < window_size; i++)
    {
        current_hash = (current_hash * base + s[i]) % mod;
    }
    hash_values[0] = current_hash;

    // Compute the hash values of the rest of the substrings
    for (int i = 1; i <= n - window_size; i++)
    {
        // Remove the contribution of the first character in
        // the window
        current_hash = (current_hash - power[window_size - 1] * s[i - 1]) % mod;

        // Shift the window by one character and add the new
        // character to the hash
        current_hash = (current_hash * base + s[i + window_size - 1]) % mod;

        hash_values[i] = current_hash;
    }
    return hash_values;
}

// Driver code
int main()
{

    // Input string
    string s = "abcabcabc";

    // Window size
    int window_size = 3;

    // Calculate rolling hash values
    vector<int> hash_values = rolling_hash(s, window_size);

    // Print the hash values
    for (auto &val : hash_values)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// this code is contributed by Prajwal kandekar