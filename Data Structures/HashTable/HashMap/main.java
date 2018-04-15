public class main {

    private static HashMap map;

    private static void testMapInsertion() {
        if (map == null) return;

        for (int i = 1; i <= 20; i++) {
            map.put(i * 3, i);
        }
    }

    private static void testMapRetrieval() {
        if (map == null) return;

        for (int i = 1; i <= 20; i++) {
            int key = i * 3;
            System.out.print("Getting value with key " + key + ": ");
            System.out.println(map.get(key));
        }
    }

    private static void testMapRemoval() {
        if (map == null) return;

        for (int i = 1; i <= 10; i++) {
            map.remove(i * 3);
        }
    }

    private static void testLinearProbing() {
        if (map == null) return;

        // test hash collision by inserting multiple entries with the same key
        map.put(1, 5);
        map.put(129, 5);
        map.put(257, 5);
        map.put(385, 5);

        map.enumerate();

        // get the cluster of (key, value) pairs inserted this way.
        System.out.println("Getting value with key 1: " + map.get(1));
        System.out.println("Getting value with key 129: " + map.get(129));
        System.out.println("Getting value with key 257: " + map.get(257));
        System.out.println("Getting value with key 385: " + map.get(385));

        // remove some of the entries in the cluster:
        map.remove(1);
        map.remove(257);

        map.enumerate();
    }

    public static void main(String... args) {
        System.out.println("Initializing the HashMap...");
        map = new HashMap();

        System.out.println("Inserting (key, value) pairs into the HashMap:");
        testMapInsertion();
        map.enumerate();

        System.out.println("Getting (key, value) pairs from the HashMap:");
        testMapRetrieval();

        System.out.println("Removing (key, value) pairs from the HashMap:");
        testMapRemoval();
        map.enumerate();

        System.out.println("Clearing the HashMap:");
        map.clear();
        map.enumerate();

        System.out.println("Testing Linear Probing:");
        testLinearProbing();

        map.clear();
    }
}
