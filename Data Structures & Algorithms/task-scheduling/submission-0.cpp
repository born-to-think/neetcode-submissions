class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int max_freq = 0;
        
        for (char c : tasks) {
            freq[c - 'A']++;
            max_freq = max(max_freq, freq[c - 'A']);
        }
        
        int count_of_max_freq_tasks = 0;
        for (int f : freq) {
            if (f == max_freq) count_of_max_freq_tasks++;
        }
        
        int base_time = (max_freq - 1) * (n + 1) + count_of_max_freq_tasks;
        int total_tasks = tasks.size();
        
        return max(base_time, total_tasks);
    }
};