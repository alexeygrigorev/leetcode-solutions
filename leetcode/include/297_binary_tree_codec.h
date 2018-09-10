#include "tree.h"
#include <string>
#include <sstream>

using namespace std;

class BinaryTreeCodec {
public:
    void traverse_serialize(TreeNode *node, stringstream &ss);
    string serialize(TreeNode *root);

    TreeNode *parse_recursive(string &data, int *pos);
    TreeNode *deserialize(string data);
};