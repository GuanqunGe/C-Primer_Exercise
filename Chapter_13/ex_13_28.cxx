//the question isn't very clear, so I honestly don't know what I should do
//given that this problem is for section 13.2.2 I thought I should construct 
//pointer like object for TreeNode, but that would require additional left/right leaf count
//so instead I will make it value-like, which makes sense b/c no tree node shares leaves.
//
#include <iostream>
#include <string>

class TreeNode{
public:
    TreeNode():left(nullptr), right(nullptr){}
    TreeNode(const std::string &s, int i):value(s), count(i), left(nullptr), right(nullptr){}

    //copy constructor
    TreeNode(const TreeNode &);

    //copy assignment
    TreeNode &operator=(const TreeNode &);

    //destructor
    ~TreeNode(){
        if(left) 
	    delete left; //this will happen recursively, as delete left will call the destructor of TreeNode.
	if(right)
	    delete right;
    }

    TreeNode *left;
private:
    std::string value;
    int count;
    TreeNode *right;
};

TreeNode::TreeNode(const TreeNode &tn):value(tn.value), count(tn.count){
    if(tn.left) //this will be a recursive function, as new TreeNode() use copy constructor
	left = new TreeNode(*tn.left);
    if(tn.right)
	right = new TreeNode(*tn.right);
}

TreeNode &TreeNode::operator=(const TreeNode &tn){
    value = tn.value;
    count = tn.count;

    TreeNode *temp = nullptr;
    if(tn.left) temp = new TreeNode(*tn.left);
    if(left)  delete left;
    left = temp;

    temp = nullptr;
    if(tn.right) temp = new TreeNode(*tn.right);
    if(right) delete right;
    right = temp;
	
    return *this;
}

class BinStrTree{
public:
    //default constructor
    BinStrTree(const TreeNode &tn = TreeNode()):root(new TreeNode(tn)){}

    //copy constructor
    BinStrTree(const BinStrTree &bst):root(new TreeNode(*bst.root)){}

    //copy assignment
    BinStrTree &operator=(const BinStrTree &bst){
	auto ptn = new TreeNode(*bst.root);
	delete root;
	root = ptn;
	return *this;
    }

    ~BinStrTree(){
	delete root;
    }
private:
    TreeNode *root;
};

int main(){

    TreeNode A;
    TreeNode B("Peter", 1);
    TreeNode C = B;

    BinStrTree T1(B);
    return 0;
}
