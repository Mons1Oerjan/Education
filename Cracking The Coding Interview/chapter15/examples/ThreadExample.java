public class ThreadExample extends Thread {
    public int count = 0;

    public void run() {
        System.out.println("Thread starting.");
        try {
            while (count < 5) {
                Thread.sleep(500);
                System.out.println("In thread, count is " + count);
                count++;
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Thread terminating.");
    }

    public static void main(String[] args) {
        final ThreadExample instance = new ThreadExample();
        instance.start();

        // wait until the thread counts to 5:
        while (instance.count != 5) {
            try {
                System.out.println("Sleep 250.");
                instance.sleep(250);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
