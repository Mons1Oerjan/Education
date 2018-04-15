/**
 * A simple (Key, Value) pojo used as a single
 * entry in the HashTable.
 */
public class HashEntry {
    private Integer key;
    private Integer value;

    HashEntry(final int key, final int value) {
        this.key = key;
        this.value = value;
    }

    public Integer key() {
        return key;
    }

    public Integer value() {
        return value;
    }

    public void setValue(final int value) {
        this.value = value;
    }
}
