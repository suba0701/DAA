#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node {
    char data;
    float freq;
    Node *left, *right;
};

Node* createNode(char data, float freq) {
    Node* node = new Node();
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void getMin(Node* arr[], int size, int &i1, int &i2) {
    i1 = i2 = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == NULL) continue;
        if (i1 == -1 || arr[i]->freq < arr[i1]->freq) {
            i2 = i1;
            i1 = i;
        }
        else if (i2 == -1 || arr[i]->freq < arr[i2]->freq) {
            i2 = i;
        }
    }
}

Node* buildTree(char data[], float freq[], int n) {
    Node* arr[100];
    for (int i = 0; i < n; i++)
        arr[i] = createNode(data[i], freq[i]);

    int size = n;
    while (size > 1) {
        int i1, i2;
        getMin(arr, size, i1, i2);
        Node* left = arr[i1];
        Node* right = arr[i2];
        Node* parent = createNode('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        arr[i1] = parent;
        arr[i2] = arr[size - 1];
        arr[size - 1] = NULL;
        size--;
    }
    return arr[0];
}

// Map to store character codes
map<char, string> huffmanCodes;

void storeCodes(Node* root, string str) {
    if (!root) return;
    if (root->left == NULL && root->right == NULL) {
        huffmanCodes[root->data] = str;
    }
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

// Function to decode the bits back into text
string decodeString(Node* root, string encodedStr) {
    string decoded = "";
    Node* curr = root;
    for (int i = 0; i < (int)encodedStr.length(); i++) {
        if (encodedStr[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (curr->left == NULL && curr->right == NULL) {
            decoded += curr->data;
            curr = root;
        }
    }
    return decoded;
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char data[100];
    float freq[100];

    cout << "Enter characters (separated by space):\n";
    for (int i = 0; i < n; i++) cin >> data[i];

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++) cin >> freq[i];

    Node* root = buildTree(data, freq, n);
    storeCodes(root, "");

    // Print the code table using a standard iterator (compatible with old C++)
    cout << "\nHuffman Codes Table:\n";
    for (map<char, string>::iterator it = huffmanCodes.begin(); it != huffmanCodes.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    string word;
    cout << "\nEnter word to encode and decode (e.g., dad): ";
    cin >> word;

    // Encode the word manually
    string encodedVal = "";
    for (int i = 0; i < (int)word.length(); i++) {
        encodedVal += huffmanCodes[word[i]];
    }

    cout << "Encoded string: " << encodedVal << endl;

    // Decode the binary back to text
    string decodedVal = decodeString(root, encodedVal);
    cout << "Decoded string: " << decodedVal << endl;

    return 0;
}