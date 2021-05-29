import java.util.ArrayList;

class Trie {
    Node beginning;

    class Node {
        char character;
        ArrayList<Node> children;
        boolean isWord;
    }

    /** Initialize your data structure here. */
    public Trie() {
        beginning = new Node();
        beginning.children = new ArrayList<Node>();
        beginning.isWord = false;
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        if (search(word)) {
            return;
        } else {
            Node current = beginning;
            for (int i = 0; i < word.length(); i++) {
                boolean found = false;
                for (Node currNode : current.children) {
                    if (currNode.character == word.charAt(i)) {
                        if (i == word.length() - 1) {
                            currNode.isWord = true;
                        }
                        current = currNode;
                        System.out.println("BREAK" + word.charAt(i));
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    System.out.println(word.charAt(i));
                    Node temp = new Node();
                    temp.character = word.charAt(i);
                    if (i == word.length() - 1) {
                        temp.isWord = true;
                    } else {
                        temp.isWord = false;
                    }
                    temp.children = new ArrayList<Node>();
                    current.children.add(temp);
                    current = temp;
                }
            }
        }
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Node current = beginning;
        for (int i = 0; i < word.length(); i++) {
            boolean found = false;
            for (Node currNode : current.children) {
                if (currNode.character == word.charAt(i)) {
                    found = true;
                    if (i == word.length() - 1) {
                        return currNode.isWord;
                    }
                    current = currNode;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return false;
    }

    public boolean findWords(Node currNode) {
        if (currNode.isWord == true) {
            return true;
        }
        boolean found = false;
        for (Node child : currNode.children) {
            found = found | findWords(child);
        }
        return found;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        Node current = beginning;
        for (int i = 0; i < prefix.length(); i++) {
            boolean found = false;
            for (Node currNode : current.children) {
                if (currNode.character == prefix.charAt(i)) {
                    found = true;
                    if (i == prefix.length() - 1) {
                        return findWords(currNode);
                    }
                    current = currNode;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("hello");
        Trie obj = new Trie();
        obj.insert("apple");
        boolean param_2 = obj.search("apples");
        boolean param_3 = obj.startsWith("a");
        System.out.println(param_2);
        System.out.println(param_3);

    }
}

/**
 * Your Trie object will be instantiated and called as such: Trie obj = new
 * Trie(); obj.insert(word); boolean param_2 = obj.search(word); boolean param_3
 * = obj.startsWith(prefix);
 */