class TrieNode:
    def __init__(self):
        self.children = {}
        # Stores the index of the best matching word for this suffix path
        self.best_idx = -1 

class Solution:
    def stringIndices(self, wordsContainer: list[str], wordsQuery: list[str]) -> list[int]:
        root = TrieNode()
        
        # Track the absolute best fallback index (shortest word, then smallest index)
        global_best_idx = 0
        for i in range(1, len(wordsContainer)):
            if len(wordsContainer[i]) < len(wordsContainer[global_best_idx]):
                global_best_idx = i
        
        root.best_idx = global_best_idx
        
        # Helper function to check if word at idx_a is better than word at idx_b
        def is_better(idx_a, idx_b, words):
            if idx_b == -1:
                return True
            if len(words[idx_a]) != len(words[idx_b]):
                return len(words[idx_a]) < len(words[idx_b])
            return idx_a < idx_b

        # Step 1: Insert all container words in reverse order into the Trie
        for idx, word in enumerate(wordsContainer):
            curr = root
            # Traverse backwards to handle suffixes as prefixes
            for char in reversed(word):
                if char not in curr.children:
                    curr.children[char] = TrieNode()
                curr = curr.children[char]
                
                # Update the node's best index if the current word is a better match
                if is_better(idx, curr.best_idx, wordsContainer):
                    curr.best_idx = idx

        # Step 2: Process each query
        ans = []
        for query in wordsQuery:
            curr = root
            # Follow the reversed query path as deep as possible
            for char in reversed(query):
                if char in curr.children:
                    curr = curr.children[char]
                else:
                    break
            ans.append(curr.best_idx)
            
        return ans