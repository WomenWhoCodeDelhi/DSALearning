/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
/*
1. Find the root from preorder (first element)
2. Find root element in inorder array - index i
3. buildTreeLeft(inorder -> 0 - i)
                preorder( );
                
4. buildTreeRight(inorder -> i+1 end)
                preorder( );
*/
// TC O(n)
// SC O (n)

class Solution {
     public TreeNode buildTreeUtil(int[] preorder, int[] inorder, int startPre, int endPre, int startIn, int endIn, HashMap<Integer, Integer> map) {      
      //Base Case
         if(startIn>endIn){ 
            return null;     
         }
         TreeNode root=new TreeNode (preorder[startPre]);
         int index = map.get(root.val); // O(1)
         int noInLeft= index - startIn;
         root.left = buildTreeUtil(preorder, inorder, startPre+1, startPre+noInLeft, startIn, index-1, map );
         root.right = buildTreeUtil (preorder, inorder, startPre+noInLeft+1, endPre, index+1, endIn, map );
         return root;
        
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        HashMap<Integer, Integer> map=new HashMap<>();
        for(int i=0;i<inorder.length;i++){
            map.put(inorder[i],i);
        }
        return buildTreeUtil (preorder, inorder, 0, preorder.length-1, 0, inorder.length-1, map);
    }
}


