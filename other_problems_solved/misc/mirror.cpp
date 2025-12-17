#include <vector>
#include <string> 
#include <algorithm>
#include <iostream>
#include <fstream>

void printSyntax(); 


class Image
{
public:
    Image(int numRows, int numCols){
    this->setNumRows(numRows);
    this->setNumCols(numCols);
    };

    Image() {};

    void addRow(std::string& row) {
        image.push_back(row);
    };
    void applyMirror() {
        std::reverse(image.begin(), image.end());  // reverse rows (up to down)

        // reverse columns (right to left)
        for (int i = 0; i < image.size(); i++) {
            std::reverse(image[i].begin(), image[i].end()); 
        }
    };
    std::vector<std::string> printMirror() {
        return image;
    };

    void setNumRows(int numRows) {
        this->numRows = numRows;
    }
    void setNumCols(int numCols) {
        this->numCols = numCols;
    };

    int getNumRows() { return this->numRows; }
    int getNumCols() { return this->numCols; }

private:
    int numRows;
    int numCols;
    std::vector<std::string> image;
};


int main(int argc, char **argv) {

    int n; 
    std::cin >> n; 
    Image image;
    for (int i = 1; i <= n; i++) {
        int numRows;
        int numCols;
        std::cin >> numRows >> numCols;

        Image image(numRows, numCols);

        for (int j = 0; j < numRows; j++) {
            std::string row;
            std::cin >> row;
            image.addRow(row);
        }
        image.applyMirror();
        std::cout << "Test " << i << std::endl;
        
        std::vector<std::string> mirrored = image.printMirror();
        for (int i = 0; i < mirrored.size(); i++) {
            std::cout << mirrored[i] << std::endl;
        }
    }
    return 0;
}

void printSyntax() {
    std::cout << "Syntax: " << std::endl;
    std::cout << "./main {mirror.in}" << std::endl;
}