#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class HuffmanCoder
{
private:
    unordered_map<char, string> encoder;
    unordered_map<string, char> decoder;

    class Node
    {
    public:
        char data;
        int cost;
        Node *left;
        Node *right;

        Node(char data, int cost)
        {
            this->data = data;
            this->cost = cost;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    void initEncoderDecoder(Node *node, string osf)
    {
        if (node == nullptr)
            return;
        if (node->left == nullptr && node->right == nullptr)
        {
            encoder[node->data] = osf;
            decoder[osf] = node->data;
        }
        initEncoderDecoder(node->left, osf + "0");
        initEncoderDecoder(node->right, osf + "1");
    }

public:
    HuffmanCoder(const string &str)
    {
        unordered_map<char, int> freqmap;
        for (char ch : str)
        {
            freqmap[ch]++;
        }

        auto comparator = [](const Node &a, const Node &b)
        {
            return a.cost > b.cost;
        };

        priority_queue<Node, vector<Node>, decltype(comparator)> minHeap(comparator);
        for (auto &entry : freqmap)
        {
            minHeap.push(Node(entry.first, entry.second));
        }

        while (minHeap.size() > 1)
        {
            Node first = minHeap.top();
            minHeap.pop();
            Node second = minHeap.top();
            minHeap.pop();
            Node *newNode = new Node('\0', first.cost + second.cost);
            newNode->left = new Node(first);
            newNode->right = new Node(second);
            minHeap.push(*newNode);
        }

        Node ft = minHeap.top();
        minHeap.pop();
        initEncoderDecoder(&ft, "");
    }

    string encode(const string &source)
    {
        string ans;
        for (char ch : source)
        {
            ans += encoder[ch];
        }
        return ans;
    }

    string decode(const string &codedString)
    {
        string key;
        string ans;
        for (char ch : codedString)
        {
            key += ch;
            if (decoder.find(key) != decoder.end())
            {
                ans += decoder[key];
                key.clear();
            }
        }
        return ans;
    }
};

int main()
{
    string input;
    cout << "Enter a string to compress: ";
    getline(cin, input);

    HuffmanCoder hf(input);
    string encoded = hf.encode(input);
    string decoded = hf.decode(encoded);

    cout << "Encoded: " << encoded << "\n";
    cout << "Decoded: " << decoded << "\n";

    return 0;
}