import java.util.HashMap;

/**
 * A Node class for the Trie data structure implemented using
 * a HashMap to store the children nodes.
 *
 * Properties:
 *   - children - the hashmap of all children nodes.
 *   - terminates - a boolean flag which determines if a word is complete.
 *   - character - the character stored in this node.
 */
public class TrieNode {

    private HashMap<Character, TrieNode> children;
    private boolean terminates = false;
    private char character;

    public TrieNode() {
        children = new HashMap<>();
    }

    public TrieNode(final char character) {
        this();
        this.character = character;
    }

    public char getChar() {
        return character;
    }

    public TrieNode getChild(final char c) {
        return children.get(c);
    }

    public boolean terminates() {
        return terminates;
    }

    public void setTerminates(final boolean t) {
        terminates = t;
    }

    /**
     * Adds the given word to the Trie, and recursively
     * construct the child nodes.
     */
    public void addWord(final String word) {
        if (word == null || word.isEmpty()) return;

        char firstChar = word.charAt(0);
        TrieNode child = getChild(firstChar);

        if (child == null) {
            child = new TrieNode(firstChar);
            children.put(firstChar, child);
        }

        if (word.length() > 1) {
            child.addWord(word.substring(1));
        } else {
            child.setTerminates(true);
        }
    }
}
