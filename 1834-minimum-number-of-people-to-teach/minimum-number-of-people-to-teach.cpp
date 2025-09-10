class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Preprocess: store each person's languages in a set
        vector<unordered_set<int>> know(m);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                know[i].insert(lang);
            }
        }

        // Step 1: Find people in "broke" friendships
        unordered_set<int> broke;
        for (auto &f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;  // zero-indexed
            bool ok = false;
            for (int lang : know[u]) {
                if (know[v].count(lang)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                broke.insert(u);
                broke.insert(v);
            }
        }

        // If no broke friendships, no need to teach
        if (broke.empty()) return 0;

        // Step 2: Count for each language, how many in "broke" already know it
        vector<int> langspoken(n+1, 0);
        for (int person : broke) {
            for (int lang : know[person]) {
                langspoken[lang]++;
            }
        }

        // Step 3: Find the language with maximum existing speakers in "broke"
        int best = 0;
        for (int lang = 1; lang <= n; lang++) {
            best = max(best, langspoken[lang]);
        }

        // Step 4: Answer = total broke - already know best language
        return (int)broke.size() - best;
    }
};
