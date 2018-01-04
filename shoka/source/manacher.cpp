void manacher(char *text, int n) {
    palindrome[0] = 1;
    for (int i = 1, j = 0; i < n; ++ i) {
        if (j + palindrome[j] <= i) {
            palindrome[i] = 0;
        } else {
            palindrome[i] = min(palindrome[(j << 1) - i], j + palindrome[j] - i);
        }
        while (i - palindrome[i] >= 0 && i + palindrome[i] < n 
                && text[i - palindrome[i]] == text[i + palindrome[i]]) {
            palindrome[i] ++;
        }
        if (i + palindrome[i] > j + palindrome[j]) {
            j = i;
        }
    }
}
