class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string result;
        int columns = encodedText.size() / rows;
        for (int startCol = 0; startCol < columns; ++startCol) {
            int row = 0;
            int col = startCol;
          
            while (row < rows && col < columns) {
                int index = row * columns + col;
                result += encodedText[index];
                row++;
                col++;
            }
        }
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
      
        return result;
    }
};
