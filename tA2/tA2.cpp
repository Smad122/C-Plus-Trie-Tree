#include <iostream>
#include <string>


const int MaxBranchNum = 26;

class Node {
public:
    std::string word;
    
    Node* next[MaxBranchNum];

    Node()
    {
        word = "";
       
        memset(next, NULL, sizeof(Node*) * MaxBranchNum);
    }

};

class TrieTree {
private:
    Node* root;
public:
    TrieTree();
    TrieTree(std::string str);
    void insert(std:: string str);

    int search(std::string str);
   
    
    void printAll();
    void Print(Node* root);
 
    
};

TrieTree::TrieTree() 
{
    root = new Node();
}
TrieTree::TrieTree(std::string str)
{
    root = new Node();
    insert(str);

}






void TrieTree::insert(std::string str)
{
    if (str == "")
        return;
    std::string buf = str;
    Node* node = root;
    int index = 0;
    for (int i = 0; i < buf.length(); i++)
    {
        index = buf[i] - 'a';
        if (node->next[index] == nullptr)
        {
            node->next[index] = new Node();
        }
        node = node->next[index];  
    }

    node->word = str;
}

int TrieTree::search(std::string str)
{
    std::string buf = str;
    Node* node = root;
    int index = 0;
    
    for (int i = 0; i < buf.length(); i++)
    {
        index = buf[i] - 'a';
        if (node->next[index] != nullptr)
        {
            node = node->next[index];
        }
        else {
            return 0;
        }
    }
    return 1;

}



void TrieTree::Print(Node* node)
{
    if (node == nullptr)
        return;
    if (node->word != "")
    {
        std::cout << node->word << " "  << std::endl;
    }
    for (int i = 0; i < MaxBranchNum; i++)
    {
        Print(node->next[i]);
    }
}

void TrieTree::printAll()
{
    Print(root);
}


void main()
{
    std::string test;
    std::cin >> test;
    
    TrieTree trie(test);
    std::string str = "key";
    trie.insert(str);
    trie.insert(str);
    trie.insert(str);
    trie.insert("keyboard");
    trie.insert("knok");
    trie.insert("klay");
    trie.insert("klat");
    trie.printAll();
    std::cout << trie.search(test) << std::endl;
    std::cout << trie.search("aasa") << std::endl;
    

   
}