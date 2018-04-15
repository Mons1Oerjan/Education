/**
 * Flags the HashEntry as deleted without setting
 * the entry to null.
 *
 * Solves the "Standard Deletion" problem in Linear Probing.
 */
public class DeletedEntry extends HashEntry {
    private static DeletedEntry entry = null;

    private DeletedEntry() {
        super(-1, -1);
    }

    public static DeletedEntry getLazyDeletedEntry() {
        if (entry == null) {
            entry = new DeletedEntry();
        }

        return entry;
    }
}
