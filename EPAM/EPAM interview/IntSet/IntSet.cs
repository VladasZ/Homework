using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IntSet
{
    class TreeNode
    {
        public TreeNode Left { get; set; }
        public TreeNode Right { get; set; }
        public TreeNode Parent { get; set; }
        public int Value { get; set; }

        public bool IsLeaf
        {
            get { return Right == null && Left == null; }
        }

        public bool IsRoot
        {
            get { return Parent == null; }
        }

        public void Remove()
        {
            if (Parent.Right == this)
                Parent.Right = null;

            else
                Parent.Left = null;
        }

        public void Replace(TreeNode node)
        {
            if (Parent.Right == this)
                Parent.Right = node;

            else
                Parent.Left = node;

            node.Parent = Parent;
        }

        public TreeNode OneChild()
        {
            if (Left == null && Right != null)
                return Right;

            if (Left != null && Right == null)
                return Left;

            return null;
        }
    }

    public class IntSet
    {
        TreeNode root;

        public int Count { get; private set; } = 0;

        int toArrayCounter;
        int[] array;

        public bool Add(int value)
        {
            if (root == null)
            {
                root = new TreeNode() { Value = value };

                Count++;
                return true;
            }

            TreeNode currentNode = root;
            TreeNode currentNodeParent = null;

            while (currentNode != null)
            {
                currentNodeParent = currentNode;

                if (value > currentNode.Value)
                    currentNode = currentNode.Right;

                else if (value < currentNode.Value)
                    currentNode = currentNode.Left;

                else if (value == currentNode.Value)
                    return false; //return false if such value already exists
            }

            TreeNode newTreeNode = new TreeNode()
            {
                Value = value,
                Parent = currentNodeParent
            };

            if (value > currentNodeParent.Value)
                currentNodeParent.Right = newTreeNode;

            else
                currentNodeParent.Left = newTreeNode;

            Count++;
            return true;
        }

        public bool Contains(int value)
        {
            if (FindNode(root, value) != null)
                return true;
            return false;
        }

        public bool Remove(int value)
        {
            return Remove(FindNode(root, value));
        }

        bool Remove(TreeNode deletingNode)
        {
            if (deletingNode == null)
                return false;

            if (deletingNode.IsLeaf)
            {
                if (deletingNode.IsRoot)
                {
                    root = null;
                    Count--;
                    return true;
                }

                deletingNode.Remove();
                Count--;
                return true;
            }

            TreeNode oneChild = deletingNode.OneChild();

            if (oneChild != null)
            {
                if (deletingNode.IsRoot)
                {
                    root = oneChild;
                    oneChild.Parent = null;
                    Count--;
                    return true;
                }

                deletingNode.Replace(oneChild);
                Count--;
                return true;
            }

            TreeNode minNodeOnRightBranch = FindMinNode(deletingNode.Right);
            deletingNode.Value = minNodeOnRightBranch.Value;
            return Remove(minNodeOnRightBranch);
        }

        public void Show()
        {
            if (root != null)
                ShowNode(root);
        }

        public int[] ToArray()
        {
            toArrayCounter = 0;
            array = new int[Count];

            NodeToArray(root);

            return array;
        }

        TreeNode FindNode(TreeNode node, int value)
        {
            if (node == null)
                return null;

            if (value > node.Value)
                return FindNode(node.Right, value);

            if (value == node.Value)
                return node;

            if (value < node.Value)
                return FindNode(node.Left, value);

            return null;
        }

        TreeNode FindMinNode(TreeNode node)
        {
            TreeNode minNode = node;

            while (minNode.Left != null)
                minNode = minNode.Left;

            return minNode;
        }









        void NodeToArray(TreeNode node)
        {
            if (node.Left != null)
                NodeToArray(node.Left);

            array[toArrayCounter++] = node.Value;

            if (node.Right != null)
                NodeToArray(node.Right);
        }

        void ShowNode(TreeNode node)
        {
            if (node.Left != null)
                ShowNode(node.Left);

            Console.WriteLine(node.Value);

            if (node.Right != null)
                ShowNode(node.Right);
        }

    }
}
