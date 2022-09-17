class Solution {
public:
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string> & words)
    {
        std::vector<std::string> storage;  
        storage.reserve(std::size(words));
        for (auto & word : words)
            storage.emplace_back(std::rbegin(word), std::rend(word));
        
        std::unordered_map<std::string_view, int> m;
        for (int i = 0; i < std::size(storage); ++i)
            m[storage[i]] = i;

        std::vector<std::vector<int>> result;
        for (int i = 0; i < std::size(words); ++i)
            if (!std::empty(words[i]))            
                for (int j = 0; j <= std::size(words[i]); ++j)
                {
                    const std::string_view left { words[i].c_str(), (size_t)j };
                    const std::string_view right { words[i].c_str() + j };

                    auto it = m.find(left);
                    if (it != std::end(m) && it->second != i && std::equal(std::begin(right), std::begin(right) + (std::size(right) >> 1), std::rbegin(right)))
                        result.emplace_back(std::vector<int> { i, it->second });

                    it = m.find(right);
                    if (it != std::end(m) && it->second != i && j && std::equal(std::begin(left), std::begin(left) + (std::size(left) >> 1), std::rbegin(left)))
                        result.emplace_back(std::vector<int> { it->second, i });
                }
        
        return result;
    }
};