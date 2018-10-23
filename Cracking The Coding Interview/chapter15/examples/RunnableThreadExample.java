public class RunnableThreadExample implements Runnable {
    public int count = 0;

    public void run() {
        System.out.println("Runnable thread starting.");
        try {
            while (count < 5) {
                System.out.println("Sleep 500.");
                Thread.sleep(500);
                count++;
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Runnable thread terminating.");
    }

    public static void main(String[] args) {
        final RunnableThreadExample instance = new RunnableThreadExample();
        final Thread thread = new Thread(instance);
        thread.start();

        // wait until the thread counts to 5:
        while (instance.count != 5) {
            try {
                System.out.println("Sleep 250.");
                thread.sleep(250);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
