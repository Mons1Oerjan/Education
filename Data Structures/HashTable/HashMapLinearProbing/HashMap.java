package HashMapLinearProbing;

/**
 * Simple HashMap data structure using Linear Probing and
 * Open Addressing. Supports Integers only.
 *
 * Limitations:
 * - The table has a constant size of 128 slots which limits
 *   the # of key-value pairs that can be stored.
 * - The table only supports integer values.
 * - Hash collisions are resolved using linear probing, which is not
 *   the best technique to use when the table is of a constant size.
 *
 * Problems with Linear Probing:
 * - Tends to form clusters of data which increases search time.
 * - Worst case search = O(n) where n is the number of keys.
 * - Standard deletion cannot be done. Solution: Open Addressing, or
 *   "Lazy Deletion". Instead of deleting the item, flag the entry
 *   as deleted without making it null.
 */
public class HashMap {
    private static final int TABLE_SIZE = 128;

    private HashEntry[] table;

    HashMap() {
        table = new HashEntry[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = null;
        }
    }

    public int get(final int key) {
        int index = hash(key);
        int initialIndex = -1;

        while (continueLinearProbing(index, initialIndex, key)) {
            if (initialIndex == -1) {
                initialIndex = index;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        return (table[index] == null || index == initialIndex)
            ? -1
            : table[index].value();
    }

    public void put(final int key, final int value) {
        int index = hash(key);
        int initialIndex = -1;
        int indexOfDeletedEntry = -1;

        while (continueLinearProbing(index, initialIndex, key)) {
            if (initialIndex == -1) {
                initialIndex = index;
            }
            if (table[index] == DeletedEntry.getLazyDeletedEntry()) {
                indexOfDeletedEntry = index;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        if (
            (table[index] == null || index == initialIndex) &&
            indexOfDeletedEntry != -1
        ) {
            table[indexOfDeletedEntry] = new HashEntry(key, value);
        }
        else if (initialIndex != index) {
            if (
                table[index] != DeletedEntry.getLazyDeletedEntry() &&
                table[index] != null &&
                table[index].key() == key
            ) {
                table[index].setValue(value);
            } else {
                table[index] = new HashEntry(key, value);
            }
        }
    }

    /**
     * "Lazy Delete" the given key.
     *
     * @param key the key of the {@link HashEntry} to be removed.
     */
    public void remove(final int key) {
        int index = hash(key);
        int initialIndex = -1;

        while (continueLinearProbing(index, initialIndex, key)) {
            if (initialIndex == -1) {
                initialIndex = index;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        if (index != initialIndex && table[index] != null) {
            table[index] = DeletedEntry.getLazyDeletedEntry();
        }
    }

    public void enumerate() {
        System.out.println("{");
        for (HashEntry entry : table) {
            if (null == entry || null == entry.key())
                continue;
            System.out.println("\t" +
                String.valueOf(entry.key()) +
                ": " +
                String.valueOf(entry.value()));
        }
        System.out.println("}");
    }

    public void clear() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = null;
        }
    }

    private int hash(final int key) {
        return key % TABLE_SIZE;
    }

    private boolean continueLinearProbing(
            final int index,
            final int initialIndex,
            final int key) {
        return (index != initialIndex &&
            (table[index] == DeletedEntry.getLazyDeletedEntry() ||
            table[index] != null &&
            table[index].key() != key));
    }
}
