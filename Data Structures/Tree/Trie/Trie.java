import java.util.ArrayList;

/**
 * A Trie data structure used for storing language dictionaries.
 * Tries are also known as Prefix Trees.
 * A trie is a special case of an n-ary tree where characters are
 * stored at each node, and every path down the tree may represent
 * a word in a real language (e.g. English). The paths that are
 * real words are flagged with the "terminates" boolean value.
 */
public class Trie {

    private TrieNode root;

    public Trie(final ArrayList<String> list) {
        root = new TrieNode();
        list.stream().forEach(word -> root.addWord(word));
    }

    public Trie(final String[] list) {
        root = new TrieNode();
        for (final String word : list) {
            root.addWord(word);
        }
    }

    public boolean contains(final String prefix, final boolean exact) {
        TrieNode lastNode = root;

        for (int i = 0; i < prefix.length(); i++) {
            lastNode = lastNode.getChild(prefix.charAt(i));
            if (lastNode == null) {
                return false;
            }
        }

        return !exact || lastNode.terminates();
    }

    public boolean contains(final String prefix) {
        return contains(prefix, false);
    }

    public TrieNode getRoot() {
        return root;
    }
}
