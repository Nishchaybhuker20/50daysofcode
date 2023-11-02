class Solution {
public:
    int matchingSubtreeCount = 0; 

    pair<int, int> calculateSubtreeValues(TreeNode* currentNode) {
        if (currentNode == nullptr)
            return {0, 0}; 

        
        auto leftSubtree = calculateSubtreeValues(currentNode->left);
        auto rightSubtree = calculateSubtreeValues(currentNode->right);

        int sumOfValues = leftSubtree.first + rightSubtree.first + currentNode->val;
        int numberOfNodes = leftSubtree.second + rightSubtree.second + 1;

        if (sumOfValues / numberOfNodes == currentNode->val)
            matchingSubtreeCount++; 

        return {sumOfValues, numberOfNodes}; 
    }

    int averageOfSubtree(TreeNode* root) {
        calculateSubtreeValues(root); 
        return matchingSubtreeCount; 
    }
};