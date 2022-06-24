import java.io.*;
import java.util.*;
public class aryTree {

    public static class TreeNode {
        int val;
        boolean locked = false;
        TreeNode parent;
        Vector child;
        int lockedDescendent = 0;
    }

    static TreeNode newNode(int key) {

        TreeNode temp = new TreeNode();
        temp.val = key;
        temp.child = new Vector<TreeNode>();
        return temp;
    }

    public static boolean isLocked(TreeNode node) {

        return node.locked;
    }

    public static boolean lock(TreeNode node) {

        if (isLocked(node)) {

            return false;
        }

        if (!canLockOrUnlock(node)) {
            return false;
        }

        node.locked = true;

        TreeNode parentNode = node.parent;

        while (parentNode != null) {

            parentNode.lockedDescendent +=  1;
            parentNode = parentNode.parent;
        }


        return true;
    }

    public static boolean unLock(TreeNode node) {
        //in unlock we are only writing not reading

        if (!isLocked(node)) {
            return false;
        }
        node.locked = false;
        TreeNode parentNode = new TreeNode();


        while (parentNode != null) {
            parentNode.lockedDescendent -= 1;
            parentNode = parentNode.parent;
        }

        return true;
    }

    public static boolean canLockOrUnlock(TreeNode node) {

        if (node.lockedDescendent > 0) {
            return false;
        }

        TreeNode parentNode = new TreeNode();

        while (parentNode != null) {

            if (isLocked(parentNode)) {

                return false;

            }
            parentNode = parentNode.parent;

        }

        return true;
    }
    public static void main(String[] args){
        TreeNode root = newNode(1);
        System.out.println(lock(root));
    }
}
