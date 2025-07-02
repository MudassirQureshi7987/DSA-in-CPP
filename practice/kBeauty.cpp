int kBeauty(string num, int k)
{
    int n = num.size();
    int cnt = 0;
    for (int i = 0; i < n - k; i++) {
        if (num[i] == '0') continue; // Skip leading zeros
        int numValue = stoi(num.substr(i, k)); // Extract substring of length k
        if (numValue % stoi(num) == 0) {
            cnt++;

        }
        
    }
    return cnt;
}